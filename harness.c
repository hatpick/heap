#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int nondet_int();
unsigned int nondet_unsigned_int();

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]){  
    int i, v;    
    /* unsigned int s = nondet_unsigned_int();
    __CPROVER_assume(s < SIZE);
    printf ("LOG: size=%d\n", s);*/    
    int *hsort_arr = (int *) malloc(sizeof(int) * SIZE);
    int *qsort_arr = (int *) malloc(sizeof(int) * SIZE);

    /* generate random numbers to be sorted */
    for(i = 0; i < SIZE; i++) {
        v = nondet_int();
        hsort_arr[i] = v;
        qsort_arr[i] = v;
        printf ("LOG: arr[%d] = %d\n", i, v);
    }    

    /* initiate min heap */
    minHeap hp = initMinHeap(SIZE);
    /* build min heap */
    buildMinHeap(&hp, hsort_arr, SIZE);

    /* check heap properties */
    int minElementValue = hp.elem[0]->data;
    for(i = 0; i < SIZE; i++){
        assert(minElementValue <= hp.elem[i]->data);
    }

    /* sort the array in place: HEAP SORT */
    heap_sort(&hp, hsort_arr, SIZE);
    /* sort the array in place: QSORT */
    qsort(qsort_arr, SIZE, sizeof(int), cmpfunc);

    /* compare sorts */
    for(i = 0; i < SIZE ; i++) {        
        assert(hsort_arr[i] == qsort_arr[i]);
        printf("LOG: (HSORT, QSORT) %d, %d\n", hsort_arr[i], qsort_arr[i]);
    }        
    return 0;
}