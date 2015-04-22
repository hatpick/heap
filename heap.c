#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

minHeap initMinHeap(int size) {
    minHeap hp ;
    hp.size = size ;    
    return hp ;
}

void swap(node *n1, node *n2) {
    node temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

void bubbleUp(minHeap *hp, int i) {    
    if(i <= 0) return;
    int parentIndex = PARENT(i);
    if(hp->elem[i].data < hp->elem[parentIndex].data){
        swap(&(hp->elem[i]), &(hp->elem[parentIndex])) ;
        bubbleUp(hp, parentIndex) ;
    }  
}

void bubbleDown(minHeap *hp, int i) {     
    int leftIndex = LCHILD(i);
    int rightIndex = RCHILD(i);
    int hasRight = 0;
    if(leftIndex > hp->size){        
        return;
    }
    if(rightIndex > hp->size) hasRight = 1;
    int smaller = leftIndex;
    if(hasRight){
        smaller = (hp->elem[leftIndex].data <= hp->elem[rightIndex].data) ? leftIndex : rightIndex;
    }

    if(hp->elem[smaller].data < hp->elem[i].data){
        swap(&(hp->elem[i]), &(hp->elem[smaller]));        
        bubbleDown(hp, smaller);
    }

}

void buildMinHeap(minHeap *hp, int *arr, int size) {
    int i;
    hp->elem = malloc(sizeof(node) * size) ;
    for(i = 0; i < size; i++) {        
        node nd;
        nd.data = arr[i] ;        
        hp->elem[i] = nd ;           
        bubbleUp(hp, i);        
    }       
}

void insertNode(minHeap *hp, int data) {
    if(hp->size) {
        hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
    } else {
        hp->elem = malloc(sizeof(node)) ;
    }

    node nd ;
    nd.data = data ;

    int i = (hp->size)++ ;
    hp->elem[i] = nd;
    bubbleUp(hp, i);    
}

void deleteNode(minHeap *hp) {
    if(hp->size) {
        printf("Deleting node %d\n\n", hp->elem[0].data) ;
        hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(node)) ;
        bubbleDown(hp, 0) ;
    } else {
        printf("\nMin Heap is empty!\n") ;
        free(hp->elem) ;
    }
}

int getMaxNode(minHeap *hp, int i) {
    if(LCHILD(i) >= hp->size) {
        return hp->elem[i].data ;
    }

    int l = getMaxNode(hp, LCHILD(i)) ;
    int r = getMaxNode(hp, RCHILD(i)) ;

    if(l >= r) {
        return l ;
    } else {
        return r ;
    }
}

void deleteMinHeap(minHeap *hp) {
    free(hp->elem) ;
}

void inorderTraversal(minHeap *hp, int i) {    
    if(LCHILD(i) < hp->size) {
        inorderTraversal(hp, LCHILD(i)) ;
    }
    printf("LOG:%d ", hp->elem[i].data) ;
    if(RCHILD(i) < hp->size) {
        inorderTraversal(hp, RCHILD(i)) ;
    }    
}

void preorderTraversal(minHeap *hp, int i) {
    if(LCHILD(i) < hp->size) {
        preorderTraversal(hp, LCHILD(i)) ;
    }
    if(RCHILD(i) < hp->size) {
        preorderTraversal(hp, RCHILD(i)) ;
    }
    printf("%d ", hp->elem[i].data) ;
}

void postorderTraversal(minHeap *hp, int i) {
    printf("%d ", hp->elem[i].data) ;
    if(LCHILD(i) < hp->size) {
        postorderTraversal(hp, LCHILD(i)) ;
    }
    if(RCHILD(i) < hp->size) {
        postorderTraversal(hp, RCHILD(i)) ;
    }
}

void levelorderTraversal(minHeap *hp) {
    int i ;
    for(i = 0; i < hp->size; i++) {
        printf("%d ", hp->elem[i].data) ;
    }
}

void heap_sort(minHeap *hp, int *arr){    
    int i, j;  
    int topIndex = hp->size - 1;    

    for(i = topIndex; i >= 0; i--) {        
        arr[topIndex - i] = hp->elem[0].data;        
        swap(&(hp->elem[0]), &(hp->elem[i]));        
        if(i > 0) {
            bubbleDown(hp, 0);
        }
    }
}