//-----------------------------------------------------------------------------
// Course: COMP.4040 Algorithms
// Author: Krishnan Seetharaman
// Sample program for heap processing
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

#include "util.h"
#include "heap.h"

//-----------------------------------------------------------------------------
int lessthan(int x, int y)
// compare function;
//-----------------------------------------------------------------------------
{
    return (x < y);
}

//-----------------------------------------------------------------------------
int greaterthan(int x, int y)
// compare function;
//-----------------------------------------------------------------------------
{
    return (x > y);
}

//-----------------------------------------------------------------------------
void heap_init(Heap* h, HeapType heapType, const int capacity)
// initialize heap;
//-----------------------------------------------------------------------------
{
    // error checking
    // TBD
    assert(h != 0);

    h->data = malloc(sizeof(int) * capacity);
    if (h->data == NULL) {
        die("error in malloc heap");
    }
    memset((void*)h->data, 0, sizeof(int) * capacity);
    h->heapType = heapType;
    h->compare = NULL;
    switch (h->heapType) {
        case MIN_HEAP:
             h->compare = greaterthan;
             break;
        case MAX_HEAP:
             h->compare = lessthan;
             break;
        default:
             die("bad heapType");
             break;
    };
    h->capacity = capacity;
    h->size     = 0;
    h->last     = 0;
}

//-----------------------------------------------------------------------------
void heap_destroy(Heap* h)
// destroy heap;
//-----------------------------------------------------------------------------
{
    // error checking
    // TBD
    assert(h != 0);

    if (h->data) {
        free(h->data);
    };
    h->capacity = 0;
    h->size     = 0;
    h->last     = 0;
}

//-----------------------------------------------------------------------------
HeapType heap_type(const Heap* h)
// return type of the heap;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    return (h->heapType); 
}

//-----------------------------------------------------------------------------
const char* heap_type_name(const Heap* h)
// return displayable type for heap;
//-----------------------------------------------------------------------------
{
    static char *heapTypeNames[] = {"MinHeap", "MaxHeap"};

    assert(h != 0);
    return (heapTypeNames[h->heapType]); 
}

//-----------------------------------------------------------------------------
int heap_size(const Heap* h)
// return current size of heap;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    return (h->size);
}

//-----------------------------------------------------------------------------
int heap_last(const Heap* h)
// return the index of last entry in the heap array;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    return (h->last);
}

//-----------------------------------------------------------------------------
int heap_capacity(const Heap* h)
// return current capacity of heap;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    return (h->capacity);
}

//-----------------------------------------------------------------------------
int heap_empty(const Heap* h)
// return true if heap is empty;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    return (h->size == 0);
}

//-----------------------------------------------------------------------------
int heap_root(const Heap* h)
// return root value of heap;
//-----------------------------------------------------------------------------
{
    assert(h != 0);

    int val = h->data[0];

    return val;
}

//-----------------------------------------------------------------------------
int heap_min(const Heap* h, int* min)
// return min value of heap;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    assert(min != 0);

    if (h->heapType != MIN_HEAP) {
        return -1;
    }
    *min = h->data[0];

    return 0;
}

//-----------------------------------------------------------------------------
int heap_max(const Heap* h, int* max)
// return max value of heap;
//-----------------------------------------------------------------------------
{
    assert(h != 0);
    assert(max != 0);

    if (h->heapType != MAX_HEAP) {
        return -1;
    }
    *max = h->data[0];

    return 0;
}

//-----------------------------------------------------------------------------
int parent(const int i) 
// return index of parent of node at index i
//-----------------------------------------------------------------------------
{
    return (i-1)/2; 
}
 
//-----------------------------------------------------------------------------
int left(const int i) 
// return index of left child of node at index i
//-----------------------------------------------------------------------------
{
    return (2*i + 1); 
}
 
//-----------------------------------------------------------------------------
int right(const int i) 
// returnget index of right child of node at index i
//-----------------------------------------------------------------------------
{
    return (2*i + 2); 
}

//-----------------------------------------------------------------------------
int heap_height(const Heap *h)
// return heap height;
//-----------------------------------------------------------------------------
{
    int height;

    height = (int)(log2(h->size));

    return height;
}

//-----------------------------------------------------------------------------
int heap_print_linear(const Heap *h, const int bPrintLast)
// print the heap in array order;
//-----------------------------------------------------------------------------
{
    int i;
    int n;

    assert(h != 0);

    // how many entries to print from array;
    n = (bPrintLast) ? (h->last) : (h->size);

    if (!bPrintLast) {
        printf("Heap Type: %s Heap Capacity: %d Current Size: %d\n", 
                heap_type_name(h), h->capacity, h->size);
        printf("Heap in ARRAY form:\n");
        if (h->size == 0) {
            printf("\n");
            return 0;
        }
    }
    else {
        printf("%s Heapsort:\n", (h->heapType == MIN_HEAP) ? "DESCENDING" : "ASCENDING");
        if (h->last == 0) {
            printf("\n");
            return 0;
        }
    }

    // print the data;
    for (i = 0; i < n; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");

    return 0;
}

//-----------------------------------------------------------------------------
int heap_print_level_order(const Heap *h)
// print the heap in tree form level by level;
//-----------------------------------------------------------------------------
{
    int i;
    int j;
    int height;
    int level;

    assert(h != 0);

    printf("Heap Type: %s Heap Capacity: %d Current Size: %d\n", 
            heap_type_name(h), h->capacity, h->size);
    printf("Heap in TREE form:\n");
    if (h->size == 0) {
        printf("\n");
        return 0;
    }
    height = heap_height(h);
    printf("Heap Height: %d\n", height);
    printf("%d\n", h->data[0]);
    for (level = 1; level <= height; level++) {
        // starting offset in array for this level;
        j = (1<<level)-1;

        // print the nodes at this level;
        for (i = 0; i < 1<<level; i++) {
            if (j < h->size) {
                printf("%d ", h->data[j++]);
            }
        }
        printf("\n");
    }
    return 0;
}

//-----------------------------------------------------------------------------
void hswap(int *x, int *y)
// hswap x and y;
//-----------------------------------------------------------------------------
{
    int temp;

    assert(x != 0);
    assert(y != 0);

    temp = *x;
    *x = *y;
    *y = temp;
}

//-----------------------------------------------------------------------------
void heap_insert(Heap *h, const int val)
// Inserts element to the heap
//-----------------------------------------------------------------------------
{
    int index;

    assert(h != 0);

    // double the heap capacity if needed;
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = realloc(h->data, sizeof(int) * h->capacity);
        if (h->data == NULL) {
            die("realloc error");
        }
    }

    // trivial case;
    if (h->size == 0) {
        h->data[h->size++] = val;
        h->last++;
        return;
    }

    // add the new value to end of array;    
    h->data[h->size++] = val;
    index = h->size - 1;

    // keep track of last entry for use in heapsort;
    h->last++;

    // Fix the min heap property if it is violated
    while ((index != 0) && (h->compare(h->data[parent(index)], h->data[index]))) {
       hswap(&(h->data[index]), &(h->data[parent(index)]));
       index = parent(index);
    }
}

//-----------------------------------------------------------------------------
int heap_delete(Heap *h)
// remove the lowest value from heap and return value;
//-----------------------------------------------------------------------------
{
    assert(h != 0);

    // edge case 
    if (h->size == 0) {
        return INT_MAX;
    }
    // trivial case;
    if (h->size == 1) {
        return h->data[--(h->size)];
    }
 
    // get the value at root (index 0), move last item to index 0 and heapify;
    int min = h->data[0];
    h->data[0] = h->data[--h->size];
    heap_heapify(h, 0);
    h->data[h->size] = min;
 
    return min;
}

//-----------------------------------------------------------------------------
void heap_heapify(Heap* h, const int pos)
// Heapifies the heap so that the heap property is satisfied; do this recursively;
// pos is the current node we are looking at;
//-----------------------------------------------------------------------------
{
    int l;
    int r;
    int which;

    assert(h != 0);
 
    // figure out which is the smallest between pos and its two children;
    l = left(pos);
    r = right(pos);
    which = pos;
    if ((l < h->size) && (h->compare(h->data[pos], h->data[l]))) {
        which = l;
    }
    if ((r < h->size) && (h->compare(h->data[which], h->data[r]))) {
        which = r;
    }

    // hswap if pos is not the posand call heapify again;
    if (pos != which) {
        hswap(&(h->data[pos]), &(h->data[which]));
        heap_heapify(h, which);
    }
}



