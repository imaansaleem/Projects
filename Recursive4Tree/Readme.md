## RECURSIVE 4-TREE

Write a C++ implementation for a recursive 4-tree in the form of a C++ class, in which each node can have at most 4 branches leaving it. Each branch is labeled: 0, 1, 2, 3. They serve as pointers to the subsequent nodes on the next level. Initially, all branches are set to equal "NULL".

- Each node contains data, here labeled x, which denotes an integer.
- You may use additional structures if you need them, but you must have a C++ class, called QuartTree, which implements the tree object. 
- The data for the construction of a QuartTree is an STL vector of integers V. In addition, your code must contain six class-member functions, listed below. An instance of the QuartTree should initially be empty until it was filled by the construct tree() method using values in the vector V and the integer k.

### Class Method Description

#### construct_tree(vector < int > V , int k)
- First element in vector V becomes the root node. All other elements in V are placed recursively inside the tree until all integers in vector V have been processed, using the following rule: 
  - If a new integer in V modulo k equals 0, branch "0" is used and a new node containing the current integer is created at the next free point along branch "0".
  - If a new integer in V modulo k equals 1, branch "1" is used and a new node containing the current integer is created at the next free point along branch "1".
  - If a new integer in V modulo k equals 2, branch "2" is used and a new node containing the current integer is created at the next free point along branch "2".
  - If a new integer in V modulo k equals 3, branch "3" is used and a new node containing the current integer is created at the next free point along branch "3". 
  - Note that the integer argument (k) can only assume values 1, 2, 3, 4.

#### traverse_abcdw()
- Traverses an instance of the object QuartTree recursively. The recursion rules abcdw stand for: traverse branch "0", traverse branch "1", traverse branch "2", traverse branch "3", and write the node’s integer value (print it to the screen). That is, traverse all "0" branches as far as possible, then traverse all "1" branches as far as possible, then traverse all "2" branches as far as possible, then traverse all "3" branches as far as possible, and only then write the node’s integer value to the screen.

#### leaf_count()
- Returns the number of leaves for an instance of the object QuartTree. As a reminder, leaf nodes are nodes that have no edges coming out of them. In other words, they are at the periphery of the tree.

#### is_tree_full()
- Returns Boolean "true" if each level in the tree is completely filled, that is, if each node in the QuartTree has all its branches occupied and all branches of leaf nodes are set to NULL. Otherwise, the function returns "false".

#### largest_integer()
- Returns the largest integer in the tree. Note, you must traverse the tree in order to determine this, and NOT just process the vector V!

Your main function must look as given below. Provide the output for the main function below as part of your project solution, written as a C++ comment below each method. In addition, make sure that your code works for vectors V with different integers and different k values during the construction of the tree.

```cpp
// we will test your code on several versions of vector V and values of k.
int main(){
    vector<int> V = {8,5,7,2,1,6,3,4,7,9,5};
    QuartTree T;
    T.construct_tree(V, 3);
    T.traverse_abcdw();
    cout << T.leaf_count() << endl;
    cout << T.count_degree_n_nodes(2) << endl;
    cout << T.is_tree_full() << endl;
    cout << T.largest_integer() << endl;
    return 0;
} 
