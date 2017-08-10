//Binary Search Tree (BST)
/*http://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
http://ide.geeksforgeeks.org/C0cnEd

*/

/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int key;
    struct node *left, *right;
} Node;

Node* newNode(int key) {
    
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    
    return node;
}

void inorder(Node* root) {
    
    if(root != NULL) {
        inorder(root->left);
        printf("node key=%d \n", root->key);
        inorder(root->right);
    }
}

Node* insert(Node* node, int key) {
    
    if(node == NULL) return newNode(key);
    
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right, key);
    
    return node;
}

int main() {
    
    Node* root = NULL;
    
    root = insert(root, 50);
    Node* node1 = insert(root, 30);
    Node* node2 = insert(root, 10);
    Node* node3 = insert(root, 80);
    Node* node4 = insert(root, 100);
    
    inorder(node2);
    printf("Out: %d node\n", node3->key);
    return 0;
}