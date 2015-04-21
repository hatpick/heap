#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

minHeap initMinHeap(int size) {
    minHeap hp ;
    hp.size = 0 ;
    return hp ;
}

void swap(node *n1, node *n2) {
    node temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

void heapify(minHeap *hp, int i) {
    int smallest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].data < hp->elem[i].data) ? LCHILD(i) : i ;
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].data < hp->elem[smallest].data) {
        smallest = RCHILD(i) ;
    }
    if(smallest != i) {
        swap(&(hp->elem[i]), &(hp->elem[smallest])) ;
        heapify(hp, smallest) ;
    }
}

void buildMinHeap(minHeap *hp, int *arr, int size) {
    int i;

    for(i = 0; i < size; i++) {
        if(hp->size) {
            hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
        } else {
            hp->elem = malloc(sizeof(node)) ;
        }
        node nd ;
        nd.data = arr[i] ;
        hp->elem[(hp->size)++] = nd ;
    }

    for(i = (hp->size - 1) / 2; i >= 0; i--) {
        heapify(hp, i) ;
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
    while(i && nd.data < hp->elem[PARENT(i)].data) {
        hp->elem[i] = hp->elem[PARENT(i)] ;
        i = PARENT(i) ;
    }
    hp->elem[i] = nd ;
}

void deleteNode(minHeap *hp) {
    if(hp->size) {
        printf("Deleting node %d\n\n", hp->elem[0].data) ;
        hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(node)) ;
        heapify(hp, 0) ;
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
    printf("%d ", hp->elem[i].data) ;
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

void heap_sort(minHeap *hp, int *arr, int size){    
    int i;
    for(i = size - 1; i >= 0; i--) {
        node root = hp->elem[0];
        arr[size - 1 - i] = root.data;
        hp->elem[0] = hp->elem[i];        
        hp->size -= 1;
        heapify(hp, 1); //Here is the bug
    }    
}