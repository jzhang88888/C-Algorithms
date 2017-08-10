//Queue as linked list (FIFO)
/*http://www.geeksforgeeks.org/queue-set-2-linked-list-implementation/
http://ide.geeksforgeeks.org/2ZGzHE
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct queue {
    Node *front, *rear;
    int size;
} Queue;

Node* newNode(int value) {
    
    Node* temp = (Node*) malloc(sizeof(Node));
   
    temp->value = value;
    temp->next = NULL;
    return temp;
}
 
Queue* create() {
    
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    
    queue->size =0;
    
    return queue;
}
 
void enqueue (Queue* queue, int item) {
    
    Node* temp = newNode(item);
    
    if(queue->rear==NULL) {
        queue->front = queue->rear = temp;
        
    } else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
    
    queue->size++;
    printf("%d enqueue to queue\n", item);
}
 
Node* dequeue (Queue* queue) {
    
    if(queue->front ==NULL) return NULL;//queue isEmpty
    
    queue->size--;
    
    Node* temp = queue->front;
    queue->front = queue->front->next;
    
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    return temp;
}

int size(Queue* queue) {
    return queue->size;
}

bool isEmpty (Queue* queue) {
    //return queue->size==0;
    return queue->front==NULL;
}

int main() {
    
    Queue* queue = create ();
 
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    
    dequeue(queue);//ride the first item (5)
    dequeue(queue);//ride the first item (10)
    
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    Node* node = dequeue(queue);
 
    printf("\nOut: queue size = %d\n", queue->size);
    printf("Out: %d dequeued from queue\n", node->value);
    
    return 0;
}