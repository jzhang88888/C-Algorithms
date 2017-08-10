#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float a1[3][4], **a2;

int main() {
    
    a2 = (float**) malloc(3*sizeof(float*));
    int i;
    for(i=0; i<3; i++) a2[i] = a1[i]; /* a2[i] contains the *address* of a1[i];*/ 
 
    free(a2);
	return 0;
}