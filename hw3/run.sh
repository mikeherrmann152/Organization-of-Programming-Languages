#!/bin/sh

# heapsort
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 heapsort <10000.sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 heapsort <10000.reverse_sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 heapsort <10000.random.dat

# mergesort
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 mergesort <10000.sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 mergesort <10000.reverse_sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 mergesort <10000.random.dat

# insertionsort
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 insertionsort <10000.sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 insertionsort <10000.reverse_sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 insertionsort <10000.random.dat


# quicksort
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 quicksort <10000.sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 quicksort <10000.reverse_sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 quicksort <10000.random.dat

# quicksort
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 quicksort2 <10000.sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 quicksort2 <10000.reverse_sorted.dat
/usr/bin/time -f "\t%E real,\t%U user,\t%S sys" ./hw3 quicksort2 <10000.random.dat

