#include <bits/stdc++.h>

using namespace std;

class Node{

public:
    //date members
    int x;
    Node *zero_branch;
    Node *one_branch;
    Node *two_branch;
    Node *three_branch;

    Node(int data, Node *z=NULL, Node *o=NULL, Node *tw=NULL, Node *th=NULL){ //constructor
        x=data;
        zero_branch=z;
        one_branch=o;
        two_branch=tw;
        three_branch=th;
    }
};


class QuartTree{
    Node *root; //data member

public:
    QuartTree(Node *r=NULL){ //constructor
        root=r;
    }

    void construct_tree(vector<int> V , int k){ //wrapper function
        construct_tree(V,k,0);
    }

    void construct_tree(vector<int> V , int k, int i){ //constructs a tree
        Node *temp = root;
        if(i==V.size()) // traverse the vector v untill all indexes are done
            return;

        if(root == NULL) // if root node is null place the first value inside root
            root = new Node(V[i]);

        else if(V[i]%k==0) { //if mod is 0 add a node to zero_branch
            while (temp->zero_branch!=NULL) { //traverse until we get a space for new value in zero_branch
                temp = temp->zero_branch;
            }
            temp->zero_branch = new Node(V[i]); //placing value
        }

        else if(V[i]%k==1) { //if mod is 1 add a node to one_branch
            while (temp->one_branch!=NULL) { //traverse until we get a space for new value in one_branch
                temp = temp->one_branch;
            }
            temp->one_branch = new Node(V[i]); //placing value
        }

        else if(V[i]%k==2) { //if mod is 2 add a node to two_branch
            while (temp->two_branch!=NULL) { //traverse until we get a space for new value in two_branch
                temp = temp->two_branch;
            }
            temp->two_branch = new Node(V[i]); //placing value
        }

        else if(V[i]%k==3) { //if mod is 3 add a node to three_branch
            while (temp->three_branch!=NULL) { //traverse until we get a space for new value in three_branch
                temp = temp->three_branch;
            }
            temp->three_branch = new Node(V[i]); //placing value
        }
        construct_tree(V,k,i+1);
    }

    void traverse_abcdw(){ //wrapper function
        traverse_abcdw(root);
    }

    void traverse_abcdw(Node *node){
        if(node == NULL)
            return;
        cout << node->x << ' ';
        traverse_abcdw(node->zero_branch); //traverse through all the zero_branches untill all done
        traverse_abcdw(node->one_branch); //then traverse through all the one_branches untill all done
        traverse_abcdw(node->two_branch); //then traverse through all the two_branches untill all done
        traverse_abcdw(node->three_branch); //then traverse through all the three_branches untill all done
    }

    int leaf_count(){ //wrapper function
        return leaf_count(root);
    }

    int leaf_count(Node* node){
        if(node == NULL) //If node is NULL then return 0.
            return 0;

        if(node->zero_branch == NULL && node->one_branch == NULL && node->two_branch == NULL && node->three_branch == NULL)
            return 1; //If all branches are NULL that is a leaf then return 1

        else
            return leaf_count(node->zero_branch)+leaf_count(node->one_branch)+leaf_count(node->two_branch)+leaf_count(node->three_branch);
        //Leaf count of a tree = sum of leaf counts of all branches
    }

    bool is_tree_full(){
        return is_tree_full(root);
    }

    bool is_tree_full(Node* node){

        if (root == NULL) //if tree is empty
            return true;

        if (node->zero_branch == NULL && node->one_branch == NULL && node->two_branch == NULL && node->three_branch == NULL)
            return true; //if node is a leaf node return true

        // If all branches are not NULL, and subtrees from those branches are full
        if (node->zero_branch != NULL && node->one_branch != NULL && node->two_branch != NULL && node->three_branch != NULL)
            return (is_tree_full(node->zero_branch) && is_tree_full(node->one_branch) && is_tree_full(node->two_branch) && is_tree_full(node->three_branch));

        return false; //if all above possibilities are not true return false
    }

    int largest_integer(){ //wrapper function
        return largest_integer(root,-999);
    }

    int largest_integer(Node *node, int max){
        if(node == NULL)
            return max;
        if(node->x>max)
            max=node->x;
        max = largest_integer(node->zero_branch, max); //find max through all the zero_branches untill all done
        max = largest_integer(node->one_branch, max); //find max through all the one_branches untill all done
        max = largest_integer(node->two_branch, max); //find max through all the two_branches untill all done
        max = largest_integer(node->three_branch, max); //find max through all the three_branches untill all done
    }

    int count_degree_n_nodes(int n)
    {
        return count_degree_n_nodes(root, n, 0);
    }

    int count_child(Node* n){
        int count = 0;
        if(n->zero_branch != NULL)  count++;
        if(n->one_branch != NULL)  count++;
        if(n->two_branch != NULL)  count++;
        if(n->three_branch != NULL)  count++;
        return count;
    }

    int count_degree_n_nodes(Node* node, int n, int count){
        if(node == NULL)
            return count;

        if( count_child(node) == n )
            count++;

        count = count_degree_n_nodes(node->zero_branch, n, count); //count through all the zero_branches untill all done
        count = count_degree_n_nodes(node->one_branch, n, count); //then count through all the one_branches untill all done
        count = count_degree_n_nodes(node->two_branch, n, count); //then count through all the two_branches untill all done
        count = count_degree_n_nodes(node->three_branch, n, count); //then count through all the three_branches untill all done
    }
};

int main(){
    vector<int> V = {8,5,7,2,1,6,3,4,7,9,5};
    QuartTree T;
    T.construct_tree(V, 3);
    T.traverse_abcdw();
    cout << endl;
    cout << T.leaf_count() << endl;
    cout << T.count_degree_n_nodes(2) << endl;
    cout << T.is_tree_full() << endl;
    cout << T.largest_integer() << endl;
    system("pause");
    return 0;
}
