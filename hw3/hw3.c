//-----------------------------------------------------------------------------
// Course: COMP.4040
// Author: Krishnan Seetharaman
// Hw3; Sample program for Sorting
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "heap.h"

#define DEFAULT_SIZE    1024

//-----------------------------------------------------------------------------
int* read_input(int* size)
// read input from stdin into array a; return size of array in size parameter;
//-----------------------------------------------------------------------------
{
    int *a = NULL;
    int next = 0;
    int sz = DEFAULT_SIZE;

    a = malloc(sizeof(int) * sz);
    if (a == NULL) {
        fprintf(stderr, "ERROR: malloc failed for size: %d\n", sz);
        exit(1);
    }

    while (!feof (stdin)) {
        int i = 0;
        if (scanf ("%d", &i) == EOF) {
            break;
        }

        a[next++] = i;
   
        // reached end of array--double size and allocate again;
        if (next == sz) {
            sz = 2 * sz;
            a = realloc(a, sizeof(int) * sz);
            if (a == NULL) {
                fprintf(stderr, "ERROR: malloc failed for size: %d\n", sz);
                exit(1);
            }
        }
    }

    *size = next; 

//    printf("READ %d elements into array\n", next);

    return a;
}


//-----------------------------------------------------------------------------
int merge(int* A, int p, int q, int r)
//-----------------------------------------------------------------------------
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = malloc(sizeof(int)*(n1+1));
    int *R = malloc(sizeof(int)*(n2+1));
    int i = 0;
    int j = 0;
    int k = 0;

    memset((void*)L, sizeof(int)*n1, 0x0);
    memset((void*)R, sizeof(int)*n2, 0x0);

    for (i = 0; i < n1; i++) {
        L[i] = A[p+i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
//    print_A(L, n1);
//    print_A(R, n2);

    i = 0;
    j = 0;

    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);

    return 0;
}

//-----------------------------------------------------------------------------
int msort(int *A, int p, int r)
//-----------------------------------------------------------------------------
{
    int q = 0;

    if (p < r) {
        q = (p + r) / 2;
        msort(A, p, q);
        msort(A, q+1, r);
        merge(A, p, q, r);
    }
    return 0;
}

//-----------------------------------------------------------------------------
int do_merge_sort(int a[], int size)
// mergesort driver function;
//-----------------------------------------------------------------------------
{

//    printf("BEGIN merge_sort...\n");

    // TO BE FILLED IN
    msort(a, 0, size-1);
//    printf("END merge_sort...\n");

    return 0;
}

#define MAX_HEAP_SIZE    1024

//-----------------------------------------------------------------------------
int create_heap (Heap* H, int a[], const int size)
// create a heap by reading input from stdin;
//-----------------------------------------------------------------------------
{
    int i;

    for (i = 0; i < size; i++) {
        heap_insert(H, a[i]);
    }
 
    return 0;
}

//-----------------------------------------------------------------------------
int do_heap_sort(int a[], int size)
// heapsort driver function;
//-----------------------------------------------------------------------------
{
    Heap H;
    int which;
    int i = 0;
    
    int *B = malloc(sizeof(int) * size);
    assert(B != NULL);
    
    heap_init(&H, MAX_HEAP, MAX_HEAP_SIZE);

    create_heap(&H, a, size);
    
    while (heap_size(&H) > 0) {
        which = heap_delete(&H);
        B[i++] = which;
    }

    heap_destroy(&H);
    return 0;
}

// compare function for qsort;
static int compare(const void *p1, const void *p2)
{
    int v1 = *((int*)p1);
    int v2 = *((int*)p2);
    return (v1 > v2);
}

//-----------------------------------------------------------------------------
int do_quick_sort2(int a[], int size)
// qiocksort driver function;
//-----------------------------------------------------------------------------
{
//    printf("BEGIN quick_sort...\n");

    qsort(a, size, sizeof(int), compare);
#if 0
    for (i=0; i < size; i++) {
        printf("%d\n", a[i]);
    }
#endif
    // TO BE FILLED IN

//    printf("END quick_sort...\n");

    return 0;
}

//-----------------------------------------------------------------------------
void swap(int *A, int i, int j)
// swap x and y;
//-----------------------------------------------------------------------------
{
    int temp;

    assert(A != 0);

    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//-----------------------------------------------------------------------------
int partition(int* A, int p, int r)
//-----------------------------------------------------------------------------
{
    int x = A[r];
    int i = p;
    int j = 0;
    int q = 0;

#ifdef QDEBUG
    printf("*****BEFORE partition loop: p=%d x=%d i=%d r=%d\n", p, x, i, r);
#endif
    for (j = p; j < r; j++) {
        if (A[j] <= x) {
#ifdef QDEBUG
             printf("BEFORE swap: A[%d]=%d A[%d]=%d\n", i, A[i], j, A[j]);
#endif
            swap(A, i, j);
#ifdef QDEBUG
            printf("AFTER swap: A[%d]=%d A[%d]=%d\n", i, A[i], j, A[j]);
#endif
            i++;
        };
    }
    q = i;
#ifdef QDEBUG
    printf("*****END partition loop: p=%d i=%d r=%d\n", p, i, r);
    printf("BEFORE swap: A[%d]=%d A[%d]=%d\n", q, A[q], r, A[r]);
#endif
    swap(A, q, r);
#ifdef QDEBUG
    printf("AFTER swap: A[%d]=%d A[%d]=%d\n", q, A[q], r, A[r]);
    print_A("In Partition p..q", A, p, q);
    printf("pivot=%d A[pivot]=%d\n", q, A[q]);    
    print_A("In Partition q+1..r", A, q+1, r);
    printf("pivot=%d A[%d]=%d\n", q, q, A[q]);
#endif
    
    return q;
}

//-----------------------------------------------------------------------------
int myqsort(int *A, int p, int r)
//-----------------------------------------------------------------------------
{
    int q = 0;

    if (p < r) {
        q = partition(A, p, r);
        myqsort(A, p, q-1);
        myqsort(A, q+1, r);
    }
    return 0;
}

//-----------------------------------------------------------------------------
int do_quick_sort1(int a[], int size)
// qiocksort driver function;
//-----------------------------------------------------------------------------
{
//    printf("BEGIN quick_sort...\n");

    myqsort(a, 0, size-1);

//    printf("END quick_sort...\n");

    return 0;
}

//-----------------------------------------------------------------------------
int isort(int *A, int n)
//-----------------------------------------------------------------------------
{
    int i = 0;
    int j = 0;
    int key = 0;

    for (j = 1; j < n; j++) {
        key = A[j];
        i = j - 1;
        while ((i >= 0) && (A[i] > key)) {
            A[i+1] = A[i];
            i--;
//            print_A(A, n);
        }
        A[i+1] = key;
//        print_A(A, n);
    }
    return 0;
}

//-----------------------------------------------------------------------------
int do_insertion_sort(int a[], int size)
// mergesort driver function;
//-----------------------------------------------------------------------------
{

//    printf("BEGIN insertion_sort...\n");

    // TO BE FILLED IN
    isort(a, size);
//    printf("END insertion_sort...\n");

    return 0;
}

//-----------------------------------------------------------------------------
int usage()
//-----------------------------------------------------------------------------
{

    char *usage_str = 
"./hw2 [-h] mergesort | heapsort | quicksort1  | quicksort2 | insertionsort"
"\n"
"Driver program to test different sort algorithn performance.\n"
"\n"
"Example\n"
"\n"
"./hw2 mergesort <100000.dat\n"
"\n"
"will test mergesrt\n"
;

    fprintf(stderr, "%s\n\n", usage_str);

    exit(1);
}

//-----------------------------------------------------------------------------
int main(int argc, char *argv[])
// driver function;
//-----------------------------------------------------------------------------
{
    int *a = NULL;
    int size;

    if (argc < 2) {
        fprintf(stderr, "ERROR: at least one argument needed\n");
        usage();
    }

    // read the input into array;
    a = read_input(&size);

    if (strcmp(argv[1], "mergesort") == 0) {
        do_merge_sort(a, size);
    }
    else if (strcmp(argv[1], "heapsort") == 0) {
        do_heap_sort(a, size);
    }
    else if (strcmp(argv[1], "quicksort") == 0) {
        do_quick_sort1(a, size);
    }
    else if (strcmp(argv[1], "quicksort2") == 0) {
        do_quick_sort2(a, size);
    }
    else if (strcmp(argv[1], "insertionsort") == 0) {
        do_insertion_sort(a, size);
    }
    else {
        fprintf(stderr, "ERROR: BAD argument\n");
        usage();
    }

    // free allocated memory
    if (a) {
        free(a);
    }

    exit(0);
}



