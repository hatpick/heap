#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int nondet_int();
unsigned int nondet_unsigned_int();

/*int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}*/

void main(){  
    int i, v;    
    unsigned int s = SIZE;    
    printf ("LOG: size=%d\n", s);
    int *hsort_arr = (int *) malloc(sizeof(int) * s);
    int *hsorted_arr = (int *) malloc(sizeof(int) * s);
    /* int *qsort_arr = (int *) malloc(sizeof(int) * s); */

    /* generate random numbers to be sorted */
    for(i = 0; i < s; i++) {
        v = nondet_int();
        hsort_arr[i] = v;        
        /*qsort_arr[i] = v;*/
        __CPROVER_assume(hsort_arr[i] < 70000 && hsort_arr[i] > 0);
        printf ("LOG: arr[%d] = %d\n", i, v);
    }        

    /* initiate min heap */
    minHeap hp = initMinHeap(s);

    /* build min heap */
    buildMinHeap(&hp, hsort_arr, s);    
    inorderTraversal(&hp, 0);    

    /* check heap properties */
    int minElementValue = hp.elem[0].data;
    for(i = 1; i < s; i++){        
        assert(minElementValue <= hp.elem[i].data);
    }

    /* sort the array in place: HEAP SORT */
    heap_sort(&hp, hsort_arr);
    /* sort the array in place: QSORT */
    /* qsort(qsort_arr, s, sizeof(int), cmpfunc); */

    /* compare sorts */
    for(i = 0; i < s ; i++) {        
        printf("LOG: sorted arr[%d]: %d\n", i, hsort_arr[i]);
        assert((i == 0) || hsort_arr[i] >= hsort_arr[i-1]);        
    }
}