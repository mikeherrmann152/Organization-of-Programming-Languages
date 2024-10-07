#!/bin/sh

# heapsort
time -v -a -p -o hw3.out ./hw3 heapsort <10000.sorted.dat
time -v -a -p -o hw3.out ./hw3 heapsort <10000.reverse_sorted.dat
time -v -a -p -o hw3.out ./hw3 heapsort <10000.random.dat

# mergesort
time -v -a -p -o hw3.out ./hw3 mergesort <10000.sorted.dat
time -v -a -p -o hw3.out ./hw3 mergesort <10000.reverse_sorted.dat
time -v -a -p -o hw3.out ./hw3 mergesort <10000.random.dat

# insertionsort
time -v -a -p -o hw3.out ./hw3 insertionsort <10000.sorted.dat
time -v -a -p -o hw3.out ./hw3 insertionsort <10000.reverse_sorted.dat
time -v -a -p -o hw3.out ./hw3 insertionsort <10000.random.dat


# quicksort
time -v -a -p -o hw3.out ./hw3 quicksort <10000.sorted.dat
time -v -a -p -o hw3.out ./hw3 quicksort <10000.reverse_sorted.dat
time -v -a -p -o hw3.out ./hw3 quicksort <10000.random.dat

# quicksort
time -v -a -p -o hw3.out ./hw3 quicksort2 <10000.sorted.dat
time -v -a -p -o hw3.out ./hw3 quicksort2 <10000.reverse_sorted.dat
time -v -a -p -o hw3.out ./hw3 quicksort2 <10000.random.dat

