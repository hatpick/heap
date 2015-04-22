#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x -1) / 2

typedef struct node {
    int data ;
} node ;

typedef struct minHeap {
    int size ;
    node *elem ;
} minHeap ;

minHeap initMinHeap(int);
void bubbleUp(minHeap *, int);
void bubbleDown(minHeap *, int);
void buildMinHeap(minHeap *, int *, int);
void insertNode(minHeap *, int);
void deleteNode(minHeap *);
int getMaxNode(minHeap *, int);
void deleteMinHeap(minHeap *);
void inorderTraversal(minHeap *, int);
void preorderTraversal(minHeap *, int);
void postorderTraversal(minHeap *, int);
void levelorderTraversal(minHeap *);
void heap_sort(minHeap *, int *);