#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
/*Merge Sort
http://www.geeksforgeeks.org/merge-sort/
divide and conquer alg
O(nlog(n))
Memory = 2n and linear*/

int i, j;
int temp;

void printArray (int* array, int s, int e);

/*1. 
  */
void merge (int* a, int l, int m, int r) {
   
    int i, j, k;
    
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i=0; i<n1; i++) L[i] = a[l+i];
    for (i=0; i<n2; i++) R[i] = a[m+1+i];
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        a[k++] = L[i] < R [j] ? L [i++] : R[j++];
    }
    
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

//low-starting index, high-ending index
void mergeSort (int* a, int l, int r) {
   
   if(l < r) {
       int m = l + (r - l)/2; //same as (r+l)/2
       mergeSort (a, l, m);
       mergeSort (a, m + 1, r);
       merge (a, l, m, r);
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
    mergeSort (array, 0, MAXSIZE-1);
    
    for(i=0; i<MAXSIZE; i++) {
        printf("%d ", array[i]);
    }

	return 0;
}