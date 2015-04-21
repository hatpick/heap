# heap
min heap &amp; heapsort &amp; cbmc model checker

# heap.h
header file for binary heap tree implementation

# heap.c
implementation of binary heap tree using arrays

# evilheap.c
implementation of binary heap tree using arrays, sort function is compromised!

# harness.c
cbmc code to check heap sort
This part of the code is for checking heap code behavior. First we are building a min heap. To check if the code is doing the right thing, we need to see if the properties of a min heap are there or not. The main property of a min heap is that the root of the tree always has the smallest value. Second, the tree should be balanced, meaning `|h(L) - h(R)| <= 1` where L is the left subtree and R is the right subtree.
The second function that we are verifying in this code is heapsort. We use cbmc to check of the heapsort is doing what it's supposed to do or not? To do this, we can either check all the elements in the sorted arrat to make sure: `arr[i] <= arr[i+1], i from 0 to n-1` where n is the size of the array OR compare the sorted array with a verified sort function such as standard library quicksort. Latter is good enough for our purpose.

Since we are using *malloc*, appropriate header files have to be provided. These header files contain *declarations* of the functions that are to be used. Also appropriate *definitions* have to be provided as well. CBMC verified our implementation of min heap and its sort function.

CBMC was able to detect the bug we introduced in the sort function (*evilheap*). Unfortunately CBMC verified some of the evil mutations we generated as well.

