//Maze will look like this
//+---+---+---+---+---+---+
//| .   .   . |           |
//+---+---+   +---+---+   +
//|       | .   .   . |   |
//+   +---+---+---+   +   +
//|               | . |   |
//+   +---+---+   +   +   +
//|   |   |       | . |   |
//+   +   +   +---+   +   +
//|       |         .   . |
//+---+---+---+---+---+---+

#include <bits/stdc++.h>
#include<windows.h>

using namespace std;

class Cell{

    int row_number;
    int col_number;
    bool visited;
    bool wall_right;
    bool wall_bottom;
    bool path;

public:
    Cell(int i, int j){
        row_number=i;
        col_number=j;
        visited=false;
        wall_right=true;
        wall_bottom=true;
        path=false;
    }

    bool get_visited(){
        return visited;
    }

    void set_wall_right(){
        wall_right=false;
    }

    void set_wall_bottom(){
        wall_bottom=false;
    }

    void set_visited(){
        visited=true;
    }

    void reset_visited(){
        visited=false;
    }

    void set_path(bool var){
        path=var;
    }

    bool get_path(){
        return path;
    }

    bool get_right_wall(){
        return wall_right;
    }

    bool get_bottom_wall(){
        return wall_bottom;
    }

    int get_row_number(){
        return row_number;
    }

    int get_col_number(){
        return col_number;
    }
};

class Grid{
    int rows;
    int cols;
    vector<vector<Cell>> cells;

public:
    Grid(int r, int c){
        rows=r;
        cols=c;
        for(int i=0; i<rows; i++)
            cells.push_back(vector<Cell>());
    }

    void placing_cells(){
        for(int i=0;i<rows;i++) {
            for (int j = 0; j < cols; j++) {
                cells[i].push_back(Cell(i,j));
            }
        }
    }

    void generate_Maze(){
        dfs(0, 0);
    }

    void dfs(int i, int j)
    {
        cells[i][j].set_visited();
        Cell nextVertex = randomUnvisitedNeighbour(i, j);

        while(nextVertex.get_row_number() != -1)
        {
            break_walls(i, j, cells[nextVertex.get_row_number()][nextVertex.get_col_number()].get_row_number(), cells[nextVertex.get_row_number()][nextVertex.get_col_number()].get_col_number());
            system("cls");
            print_grid();
            Sleep(100);
            dfs(cells[nextVertex.get_row_number()][nextVertex.get_col_number()].get_row_number(), cells[nextVertex.get_row_number()][nextVertex.get_col_number()].get_col_number());
            nextVertex = randomUnvisitedNeighbour(i, j);
        }

        return;
    }

    Cell randomUnvisitedNeighbour(int i, int j)
    {
        vector<Cell> c;
        if(i-1>=0 && !cells[i-1][j].get_visited()) //upper neighbour
            c.push_back(cells[i-1][j]);

        if(i+1<rows && !cells[i+1][j].get_visited()) //lower neighbour
            c.push_back(cells[i+1][j]);

        if(j-1>=0 && !cells[i][j-1].get_visited()) //left neighbour
            c.push_back(cells[i][j-1]);

        if(j+1<cols && !cells[i][j+1].get_visited()) //right neighbour
            c.push_back(cells[i][j+1]);

        if(c.size() == 0)
            return Cell(-1, -1);
        return c[rand() % c.size()];
    }

    void break_walls(int current_row, int current_col, int selected_row, int selected_col){
        if(current_row-1==selected_row && current_col==selected_col) //upper neigbour
            cells[selected_row][selected_col].set_wall_bottom();//need to break upper's bottom
        else if(current_row+1==selected_row && current_col==selected_col && current_row != rows-1) //lower neigbour
            cells[current_row][current_col].set_wall_bottom();//need to break current's bottom
        else if(current_row==selected_row && current_col-1==selected_col) //left neigbour
            cells[selected_row][selected_col].set_wall_right();//need to break left's wall
        else if(current_row==selected_row && current_col+1==selected_col && current_col != cols-1) //right neigbour
            cells[current_row][current_col].set_wall_right();//need to break current's wall

    }

    void reset_visited(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cells[i][j].reset_visited();
            }
        }
    }

    vector<Cell> Valid_pairs(int i, int j){ //will see the neigbouring indexes of passed cell and place it in an array
        vector<Cell> c;
        if(i-1>=0 && !cells[i-1][j].get_bottom_wall()) //upper neighbour
            c.push_back(cells[i-1][j]);
        if(i+1<rows && !cells[i][j].get_bottom_wall()) //lower neighbour
            c.push_back(cells[i+1][j]);
        if(j-1>=0 && !cells[i][j-1].get_right_wall()) //left neighbour
            c.push_back(cells[i][j-1]);
        if(j+1<cols && !cells[i][j].get_right_wall()) //right neighbour
            c.push_back(cells[i][j+1]);
        return c;
    }

    bool Find_path(){
        reset_visited();
        Find_path(0,0,rows-1,cols-1);
    }

    bool Find_path(int from_i, int from_j, int to_i, int to_j){
        system("cls");
        print_grid();
        Sleep(100);
        cells[from_i][from_j].set_path(true);
        cells[from_i][from_j].set_visited();
        if(from_i==to_i && from_j==to_j)
            return true;

        vector<Cell> valid_neighbours= Valid_pairs(from_i, from_j);
        for(int f=0;f<valid_neighbours.size();f++){
            if(!cells[valid_neighbours[f].get_row_number()][valid_neighbours[f].get_col_number()].get_visited())
                if(Find_path(valid_neighbours[f].get_row_number(),valid_neighbours[f].get_col_number(), to_i, to_j))
                    return true;
        }
        cells[from_i][from_j].reset_visited();
        cells[from_i][from_j].set_path(false);
        return false;
    }

    void print_grid(){
        for(int j=0;j<cols;j++){
            cout << "+";
            cout << "---";
        }
        cout << "+\n"; // printing the top
        for(int i=0;i<rows;i++){
            cout << "|";//first
            for(int k=0; k<cols; k++){
                if(cells[i][k].get_right_wall() && cells[i][k].get_path())
                    cout << " . |";
                else if(cells[i][k].get_right_wall() && !cells[i][k].get_path())
                    cout << "   |";
                else if(!cells[i][k].get_right_wall() && cells[i][k].get_path())
                    cout << " .  ";
                else
                    cout << "    ";
            }

            cout << "\n";

            for(int j=0;j<cols;j++){
                if(cells[i][j].get_bottom_wall()){
                    cout << "+";
                    cout << "---";
                }

                else
                    cout << "+   ";
            }
            cout << "+\n"; // printing the top

        }

    }
};

int main() {
    srand(time(0));
    int rows, cols;
    cout << "Enter The Number of Rows: ";
    cin >> rows;
    cout << "Enter The Number of Columns: ";
    cin >> cols;
    Grid g(rows,cols);
    g.placing_cells();
    g.generate_Maze();
    g.Find_path();
    system("pause");
    return 0;
}
