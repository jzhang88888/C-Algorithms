#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
/*Quick Sort
http://www.geeksforgeeks.org/quick-sort/
divide and conquer alg
O(nlog(n))*/

int i, j;
int temp;

void printArray (int* array, int s, int e, int pi);

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

/*1. set first element as pivot
  2. put all greater to the right, smaller left
  */
int partition(int* a, int l, int r) {
    
    int pivot = a[r];
    printf("pivot=%d\n ", a[r]);
    int i = l-1;
    
    for (j = l; j < r; j++) {
        if(a[j] < pivot) {
            i++;
            if(i!=j) {
                swap(&a[i], &a[j]);
                printf("swap i=%d and j=%d\n ", i, j);
            }
        }
    }
    
    if(i+1 != r) swap(&a[i+1], &a[r]);
    return i+1;
}

//low-starting index, high-ending index
void quickSort(int* a, int l, int r) {
   
   int j;
   if(l < r) {
       
       //printArray(a, l, r);
       
       j = partition (a, l, r);
       printArray(a, l, r, j);
       
       quickSort(a, l, j-1);
       //printArray(a, l, j-1);
       
       quickSort(a, j+1, r);
       //printArray(a, j+1, r);
   }
}

void printArray (int* array, int s, int e, int pi) {
    
    int i;
    printf("pi=%d: ", pi);
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
    
    
    printArray(array, 0, MAXSIZE-1,  MAXSIZE-1);
    quickSort(array, 0, MAXSIZE-1);
    
    for(i=0; i<MAXSIZE; i++) {
        printf("%d ", array[i]);
    }

	return 0;
}