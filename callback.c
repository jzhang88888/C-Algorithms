#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void proc (void (*cb)(int, float), float start);
void proc (void (*cb)(int, float), float s) {
    int i;
    for(i=0; i<10; i++) (*cb)(i, s);
}

void callback (int v, float init) {
    printf("integer value=%d\n", v);
    printf("init value=%f\n", init);
}

void callbackB(int v, float init) {
    printf("callback b value=%d\n", v);
    printf("callback b init value=%f\n", init);
}

int main() {
    
    proc(callback, 10);
    proc(callbackB, 10);
	return 0;
}