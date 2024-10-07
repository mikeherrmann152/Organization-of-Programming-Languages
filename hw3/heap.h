//-----------------------------------------------------------------------------
// Course: COMP.4040 Algorithms
// Author: Krishnan Seetharaman
// Sample program for heap processing
//-----------------------------------------------------------------------------

#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

// which type of heap?
typedef enum {
    MIN_HEAP,
    MAX_HEAP
} HeapType;

// compare function;
typedef int (*COMPARE)(int, int);

// heap struct
typedef struct Heap_s {
    int      *data;           // actual data;
    HeapType heapType;        // whether min or max heap;
    COMPARE  compare;         // compare function;
    int      size;            // current size of the heap;
    int      last;            // last entry of heap--before deletes--used for heapsort
    int      capacity;        // maximum size of the heap;
} Heap;

void heap_init(Heap* h, HeapType heapType, const int capacity);
void heap_destroy(Heap* h);
HeapType heap_type(const Heap* h);
int  heap_size(const Heap* h);
int  heap_last(const Heap* h);
int  heap_capacity(const Heap* h);
int  heap_empty(const Heap* h);
int  heap_root(const Heap* h);
int  heap_min(const Heap* h, int* min);
int  heap_max(const Heap* h, int* max);
int  heap_height(const Heap *h);
void heap_insert(Heap* h, const int val);
int  heap_delete(Heap* h);
int  heap_print_level_order(const Heap *h);
int  heap_print_linear(const Heap *h, const int bPrintLast);
const char* heap_type_name(const Heap* h);
void heap_heapify(Heap* h, const int count);

#endif

