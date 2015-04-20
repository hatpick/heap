#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) x / 2

typedef struct node {
    int data ;
} node ;

typedef struct minHeap {
    int size ;
    node *elem ;
} minHeap ;

minHeap initMinHeap(int size);
void heapify(minHeap *hp, int i);
void buildMinHeap(minHeap *hp, int *arr, int size);
void insertNode(minHeap *hp, int data);
void deleteNode(minHeap *hp);
int getMaxNode(minHeap *hp, int i);
void deleteMinHeap(minHeap *hp);
void inorderTraversal(minHeap *hp, int i);
void preorderTraversal(minHeap *hp, int i);
void postorderTraversal(minHeap *hp, int i);
void levelorderTraversal(minHeap *hp);
void heap_sort(minHeap *hp, int *arr, int size);