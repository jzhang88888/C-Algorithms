#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 1000

int i, j;
int temp;

/*O(n2)*/

void bubbleSort(int* array) {
   
   for (i=0; i < MAXSIZE; i++) {
       
       for(j=0; j < (MAXSIZE - i - 1); j++) {
           
           if(array[j] > array[j+1]) {
               
               //temp = array[j];
               //array[j] = array[j+1];
               //array[j + 1] = temp;
               
               //swap array[j] and array[j+1] without temp
               array[j]     += array[j + 1];
               array[j + 1]  = array[j] - array[j + 1];
               array[j]     -= array[j + 1];
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