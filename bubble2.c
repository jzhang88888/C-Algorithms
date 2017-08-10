#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 1000
/*Quick Sort*/

int i, j;
int temp;

/*O(n2)*/

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

void bubbleSort(int* array) {
   
   for (i=0; i < MAXSIZE; i++) {
       
       for(j=0; j < (MAXSIZE - i - 1); j++) {
           
           if(array[j] > array[j+1]) {
               swap((int*)(array+j), (int*)(array+j+1));
           }
       }
   } 
    
}

int main() {
    
    int array[MAXSIZE];
    int i;
    
    for(i=0; i<MAXSIZE; i++) {
        array[i] = rand();
    }
    
    bubbleSort(array);
    
    for(i=0; i<MAXSIZE; i++) {
        printf("array [%d] = %d\n", i, array[i]);
    }

	return 0;
}