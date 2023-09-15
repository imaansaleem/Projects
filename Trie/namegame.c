#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TrieNode{
    struct TrieNode *children[26]; //one node can have maximum 26 childs
    int subtreeSum; //number of mangoes eaten by this node
    int nodeTotal; //no of childs a node has
};

struct TrieNode *New_Node(){ //creates a new node
    struct TrieNode *t_node = NULL; //initializing node to NULL
    t_node = (struct TrieNode *)malloc(sizeof(struct TrieNode)); //node creation

    if (t_node){ //if node is not NULL
        int i;

        for (i = 0; i < 26; i++){ 
            t_node->children[i] = NULL; //assigning node's all children to NULL
            t_node->nodeTotal=0; //assigning node's no of children = 0
            t_node->subtreeSum=0; //assigning node's mangoes = 0
        }
    }
    return t_node; //new node created is returned
};

void insert(struct TrieNode *root, char *string, int no_of_mangoes){ //inserting a string into trie
    int i;
    int index;

    struct TrieNode *t_traversal = root;

    for (i = 0; i < strlen(string); i++){ //traversing the whole string to be added
        index = ((int)string[i] - (int)'A'); //mapping each character to required index
        if (!t_traversal->children[index]){ //if root doesnot have any child
            t_traversal->children[index] = New_Node(); //create a new child node
            t_traversal->nodeTotal++; //root's child count is incremented
        }
        t_traversal = t_traversal->children[index];
        t_traversal->subtreeSum+=no_of_mangoes; //assigning mangoes to child node, if already exist the node then add in previous mangoes sum
    }
}

int Mangoes_Eaten(struct TrieNode *root, char *string){ //return the number of mangoes eaten by orangutan
    int i;
    int index;
    struct TrieNode *t_traversal = root;

    for (i = 0; i < strlen(string); i++){ //string traversal
        index = ((int)string[i] - (int)'A'); //mapping each character to required index
        if(t_traversal->children[index] == NULL) //if root doesnot have any child containing character to be searched return 0
            return 0; //string is not part of trie
        t_traversal = t_traversal->children[index];
    }

    return (t_traversal->subtreeSum); //return mangoes eaten
}

int Eliminate(struct TrieNode *root, char *string, int i, int *s){ //deleting string from trie

    if (root == NULL) { //if Trie is already empty return 0
        return 0;
    }

    if (i == strlen(string)){ // if iteration reaches to string end

        *s = root->subtreeSum; //saving no of mangoes eaten by orangutan
        
        if (root->nodeTotal == 0){ // if node's children count is equal to 0
            free(root);    // delete the node
            (root) = NULL; //root set to NULL
            return 1;       // delete the parent nodes
        }
 
        else {// if the current node has children
            int childWeight = 0, i;
            for(i=0; i<26; i++) //traversing through all its children
                if(root->children[i] != NULL) //if root has child
                    childWeight += root->children[i]->subtreeSum; 
                *s = (*s) - childWeight;
            root->subtreeSum -= *s;
            return 0;       // avoid deleting its parent nodes
        }
    }

    // if the end of the string is not reached
    int isDeleted = Eliminate(root->children[string[i] - (int)'A'], string, i+1, s);

    if (i > 0){
        if (root != NULL && root->children[string[i] - (int)'A'] != NULL )
        {
            if(isDeleted) // the returned was 1, delete the current node
                root->nodeTotal--; //decrement the count

            if (root->nodeTotal == 0){ // if node's children count is equal to 0
                free(root); // delete the node
                (root) = NULL; //root set to NULL
            }
            else {
                root->subtreeSum -= *s; //subtracting deleted node's value from parent nodes
            }
        }
        return isDeleted;
    }
 
    return 0;
}

int main()
{
    int no_of_orungutans, queries, type_of_query, orangutan_name, mangoes, eat;
    char name[20], updated_name[20]; //any name is at most 20 characters
    struct TrieNode *root = New_Node(); //root node of trie
    scanf("%d", &no_of_orungutans); //taking input
    scanf("%d", &queries);
    for(int i=0;i<queries;i++){ 
        scanf("%d",&type_of_query);
        if(type_of_query==1){ //for type 1 query add a string
            scanf("%s", name);
            scanf("%d", &mangoes);
            insert(root,name,mangoes);
        }

        else if(type_of_query==2){ //for type 2 query replace name of orangutans
            scanf("%s", name);
            scanf("%s", updated_name);
            int eat;
            Eliminate(root,name,0, &eat);
            insert(root,updated_name,eat);
        }  

        else if(type_of_query==3){ //for type 3 prints the mangoes eaten by orangutans
            scanf("%s", name);
            eat=Mangoes_Eaten(root,name);
            printf("%d\n", eat);
        }
    }

    return 0;
}
