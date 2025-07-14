/*

Trying to implement DFS without using recursion !
YES, its not practical, is very rigid and inefficient but for the sake of understanding and exploring its good !

*/

#include<iostream>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    bool visited; //needed for DFS without recursion or need to use external data structure to track visited nodes.

    Node() {}
    Node(int val) :
        data(val),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        visited(false) {}

}node;

void traverse(node* root){
    //trying a DFS traversal

    node* current = root;

    while(current != nullptr){

        //visit a node if it is not visited
        if(!current->visited){
            std::cout << current->data << std::endl;
            current->visited = true; //set visited to true
        }

        //if there exists a left node and its not visited
        if(current->left && !current->left->visited){
            current = current->left; //move current to that node (move down by 1 level)
        }

        //if there is no left node left we gotta visit the right ones, branch down right by one node.
        else if(current->right && !current->right->visited){
            current = current->right;
        }

        //backtrack ! If one of the levels are all visited we backtrack my moving current up by one level.
        else{
            current = current->parent;
        }

        //current becomes null pointer when it backtracks to the root node and enters the else block because all the child nodes are already visited.
        //current node's parent is set to be nullptr by node structure therefore it becomes nullptr.
    }
}

int main(){

    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(15);

    //setting the parent pointers
    root->left->parent = root;
    root->right->parent = root;

    //done this to avoid `->` chaining for better readability at the cost of 2 extra pointers in memory
    node* leftSubTree = root->left;
    node* rightSubTree = root->right;

    //left sub tree
    leftSubTree->left = new node(3);
    leftSubTree->right = new node(5);
    leftSubTree->left->parent = leftSubTree; //setting parent for left subtree
    leftSubTree->right->parent = leftSubTree;

    //right sub tree
    rightSubTree->left = new node(12);
    rightSubTree->right = new node(14);
    rightSubTree->left->parent = rightSubTree; //setting parent for right subtree
    rightSubTree->right->parent = rightSubTree;

    traverse(root);

    //free memory
    delete leftSubTree->left;
    delete leftSubTree->right;

    delete rightSubTree->left;
    delete rightSubTree->right;

    delete leftSubTree;
    delete rightSubTree;

    delete root;

    return 0;
}
