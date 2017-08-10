#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 1000

/*http://www.geeksforgeeks.org/insertion-sort/
O(n2)*/

void insertionSort (int* array) {
   
   int i, j, key;
   for (i=1; i < MAXSIZE; i++) {
       
      key = array[i];
      j = i - 1;
      
      while (j >=0 && array[j] > key) {
          array[j+1] = array [j];
          j--;
      }
      
      array[j + 1] = key;
           
   } 
    
}

int main() {
    
    int array[MAXSIZE];
    int i;
    
    for(i=0; i<MAXSIZE; i++) {
        array[i] = rand();
    }
    
    insertionSort(array);
    
    for(i=0; i<MAXSIZE; i++) {
        printf("array [%d] = %d\n", i, array[i]);
    }

	return 0;
}