#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
    
/*http://www.thegeekstuff.com/2012/08/c-linked-list-example/*/

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* head = NULL;
Node* curr = NULL;

Node* create (int val) {
    
    Node* ptr = (Node*) malloc (sizeof(Node));
    if(ptr==NULL) return NULL;
    
    ptr->val =val;
    ptr->next = NULL;
    
    head = curr = ptr;
    
    return ptr;
}

Node* add(int val, bool addToEnd) {
    
    if(NULL == head) return create(val);
    
    Node* ptr = (Node*) malloc(sizeof(Node));
    if(NULL==ptr) return NULL;
    
    ptr->val = val;
    ptr->next = NULL;
    
    if(addToEnd) {
        curr->next = ptr;
        curr = ptr;
        
    } else {
        ptr->next = head;
        head = ptr;
    }
    
    return ptr;
    
}

Node* search(int val, Node** prev) {
    
    Node* ptr = head;
    Node* temp = NULL;
    bool found = false;
    
    while (ptr != NULL) {
        
        if(ptr->val == val) {
            found = true;
            break;
            
        } else {
            temp = ptr;
            ptr = ptr->next;
        }
    }
    
    if(found) {
        
        if(prev) *prev = temp;
        return ptr;
    } 
    
    return NULL;
}

int main() {
    
    Node* ptr = create(5);
    Node* prev = NULL;
    
    add(4, false);
    add(6, true);
    
    Node* hitPtr = search(5, &prev);
    
    printf("found value: %d\n", hitPtr->val);
    printf("prev value: %d\n", prev->val);
    
	return 0;
}