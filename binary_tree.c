//Binary Tree
/*http://www.geeksforgeeks.org/binary-tree-set-2-properties/
http://ide.geeksforgeeks.org/d408oj
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* newNode(int data) {
    
    Node* node = (Node*) malloc(sizeof(Node));
    node->left = node->right = NULL;
    
    return node;
}

int main() {
    
    Node* root = newNode (1);
    
    root->left = newNode (2);
    Node* right1    = root->right = newNode (3);
    
    root->left->left = newNode (4);
    
    //printf("Out: %d dequeued from queue\n", node->value);
    return 0;
}