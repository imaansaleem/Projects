#include <stdio.h>
#include <ctype.h>
#include "stop.c"
#include "linkedlist.c"

struct stop stops[10,000];
int no_of_stops;
struct Career array[200];
int career_no=0;

void string_input(char str[50]);
void input_p();
void input_l();
void input_c();
void print_stop(struct stop s);
void print_all_stops();
int find_stop(char stop_name[50]);
int find_career(char car[50]);
//void caps_to_small(char str[50]);

int main()
{
    char command;
    do{
        command = getchar();
        command = tolower(command);
        if (command == 'p')
            input_p();
        else if (command == 'c')
            input_c();
        else if (command == 'l')
            input_l();
        else if(command!= 'q')
            printf("Invalid Input :( \nTry Again! ");
    } while (command!= 'q');

    printf("\nExiting Program...\n");
    return 0;
}

void input_p(){

    char str[MAX_LENGTH];
    char stop_name[50];
    fgets(str, MAX_LENGTH, stdin);

    //in case of no argument
    if(str[0]=='\n')
        print_all_stops();

    else{
        int i=1, j=0;
        if(str[i]!='"'){
            while (str[i] != ' ' && str[i] != '\n') {
                stop_name[j++] = str[i];
                i++;
            }

            stop_name[j] = '\0';

            //in case of one argument
            if(str[i]=='\n'){
                int find = find_stop(stop_name);
                if(find == -1)
                    printf("\nStop Name not found!");
                else{
                    printf("%.12f ", stops[find].latitude);
                    printf("%.12f ", stops[find].longitude);
                }
            }

                //in case of three arguments
            else{
                float la, lo;
                sscanf(str, " %s %f %f\n", stop_name, &la, &lo);

                struct stop new_node;
                strcpy(new_node.name, stop_name);
                new_node.latitude = la;
                new_node.longitude = lo;
                new_node.number_of_careers=0;
                stops[no_of_stops++] = new_node;
            }
        }

        else{
            i=i+1;
            int j=0;
            while (str[i] != '"') {
                stop_name[j++] = str[i];
                i++;
            }

            stop_name[j] = '\0';

            //in case of one argument
            if(str[i+1]=='\n'){
                int find = find_stop(stop_name);
                if(find == -1)
                    printf("\nNo such stop exists!");
                else{
                    printf("%.12f ", stops[find].latitude);
                    printf("%.12f ", stops[find].longitude);
                }
            }

                //in case of three arguments
            else{
                int find = find_stop(stop_name);
                if(find != -1) { //in case stop name already there
                    printf("\nStop already exists. Stop is not added to list\n");
                    return;
                }

                float la, lo;
                sscanf(str, " \"%[^\"]\" %f %f\n", stop_name, &la, &lo);

                struct stop new_node;
                strcpy(new_node.name, stop_name);
                new_node.latitude = la;
                new_node.longitude = lo;
                new_node.number_of_careers = 0;
                stops[no_of_stops++] = new_node;
            }
        }
    }
}

void input_l(){
    char career[50], source_stop[50], destination[50];
    float cost, duration;
    getchar();
    string_input(career);
    string_input(source_stop);
    string_input(destination);

    scanf("%f", &cost);
    scanf("%f", &duration);
    getchar();
    int find = find_career(career);
    int s = find_stop(source_stop);
    int l = find_stop(destination);

    if(cost < 0 || duration < 0)
        printf("Negative cost or duration\n");

    else if(find!=-1){
        add(&array[find], &stops[s], &stops[l], cost, duration);
    }
    else
        printf("There is no career with the given name\n");
}

void input_c(){
    char str[MAX_LENGTH];
    char career[50];
    fgets(str, MAX_LENGTH, stdin);

    //in case of no argument
    if(str[0]=='\n') {
        for(int i=0;i<career_no;i++){
            printf("%s ", array[i].name);
            print_list(&array[i]);
        }
    }

    else{
        int i=1, j=0;
        while(str[i]!=' ' && str[i]!='\n'){
            career[j++] = str[i];
            i++;
        }
        career[j]='\0';

        if(str[i]=='\n'){
            int find = find_career(career);
            if(find == -1) {
                struct Career c;
                strcpy(c.name, career);
                c.head = NULL;
                c.tail = NULL;
                array[career_no++] = c;
            }
            else
                print_stops_name(&array[find]);
        }

        else{
            i=i+1, j=0;
            char in[10];
            while(str[i]!='\n'){
                in[j++] = str[i];
                i++;
            }

            if(strcmp("i",in)==0 || strcmp("n",in)==0 || strcmp("v",in)==0 || strcmp("inverse",in)==0) {
                int find = find_career(career);
                if(find == -1) {
                    struct Career c;
                    strcpy(c.name, career);
                    array[career_no++] = c;
                }
                else
                    print_stops_name_inverse(&array[find]);
            }
        }
    }
}

void print_stop(struct stop s){
    printf("%s: ", s.name);
    printf("%.12f ", s.latitude);
    printf("%.12f ", s.longitude);
    printf("%d ", s.number_of_careers);
}

void print_all_stops(){
    if(no_of_stops==0)
        printf("No stops have been created yet!\n");

    else{
        for(int i=0;i<no_of_stops;i++){
            print_stop(stops[i]);
            printf("\n");
        }
    }
}

int find_career(char car[50]){
    for(int i=0;i<career_no;i++){
        if(strcmp(array[i].name, car)==0)
            return i;
    }
    return -1;
}

int find_stop(char stop_name[50]){
    for(int i=0;i<no_of_stops;i++){
        if(!strcmp(stops[i].name,stop_name))
            return i;
    }
    return -1;
}

void caps_to_small(char str[50]){
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


void string_input(char str[50]){

    char c = getchar();
    if(c=='"'){
        int i=0;
        // Loop until " is encountered
        while ((str[i] = getchar()) != '"') {
            i++;
        }
        getchar();
        // Add null terminator at end of string
        str[i] = '\0';
    }

    else{
        // Loop until space is encountered
        int i=0;
        str[i++] = c;
        while ((str[i] = getchar()) != ' ') {
            i++;
        }
        // Add null terminator at end of string
        str[i] = '\0';
    }
}
