#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20
/*Heap Sort
http://www.geeksforgeeks.org/heap-sort/
O(nlog(n))
Memory = ??*/

int i, j;
int temp;

void printArray (int* array, int s, int e);

/*1. 
  */
  
/* n is size of heap, node index i*/
void swap (int* a, int* b) {
    
    /*
    int temp = *a;
    *a = *b;
    *b = temp;
    */
    
    //without temp
    *a += *b;
    *b  = *a - *b;
    *a -= *b;
}

void heapify (int* a, int n, int i) {
   
    int largest = i;     // largest as root;
    
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    
    if(largest != i) {//if largest is not root
       swap(a + i, a + largest);
       heapify(a, n, largest);
    }
}

//
void heapSort (int* a, int n) {

    int i;
    for (i=n/2-1; i>=0; i--) heapify(a, n, i);
    for (i=n-1; i>=0; i--) {
        //swap(&a[0], &a[i]);
        if (i!=0) swap(a, a+i);
        heapify(a, i, 0);
    }
}

void printArray (int* array, int s, int e) {
    
    int i;
    for(i=s; i<=e; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    
    int i;
    int array[MAXSIZE];
    
    for(i=0; i<MAXSIZE; i++) {
        array[i] = (int) rand()%(10*MAXSIZE);
    }
    
    
    printArray(array, 0, MAXSIZE-1);
    heapSort (array, MAXSIZE);
    
    for(i=0; i<MAXSIZE; i++) {
        printf("%d ", array[i]);
    }

	return 0;
}