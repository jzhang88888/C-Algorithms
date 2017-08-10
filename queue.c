//Queue (FIFO)
/*http://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
http://ide.geeksforgeeks.org/51uiWa
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CAPACITY 10000

typedef struct queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

 
Queue* create(unsigned capacity) {
    
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    
    queue->capacity = capacity;
    
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    
    queue->array = (int*) malloc(capacity * sizeof(int));
    
    return queue;
}
 
int isFull (Queue* queue) {return queue->size == queue->capacity;}
int isEmpty(Queue* queue) {return queue->size == 0;}
 
void enqueue (Queue* queue, int item) {
    
    if (isFull(queue)) return;
    
    queue->rear++;
    queue->rear %= queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    
    printf("%d enqueue to queue\n", item);
}
 
int dequeue (Queue* queue) {
    
    if (isEmpty(queue)) return INT_MIN;
    int item = queue->array[queue->front];
    
    queue->front++;
    queue->front %= queue->capacity;
    
    queue->size--;
    return item;
}

int front (Queue* queue) {
    if (isEmpty(queue)) return INT_MIN;
    return queue->array[queue->front];
}

int rear (Queue* queue) {
    if (isEmpty(queue)) return INT_MIN;
    return queue->array[queue->rear];
}

int main() {
    
    Queue* queue = create (CAPACITY);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
 
    printf("%d dequeue from queue\n", dequeue(queue));
    printf("%d front from queue\n", front(queue));
    printf("%d rear from queue\n", rear(queue));
    
    return 0;
}