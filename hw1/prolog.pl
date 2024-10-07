*/ prolog form rosettacode/*

:- use_module(library(clpfd)). */ includes this library so we are able to use the clpfd fucntion/*
 
comb_clpfd(L, M, N) :-
    length(L, M), */ getting the length of the list L with length of M/*
    L ins 1..N,   */ puts a 1 at the beginning of every pairing of the list/*
    chain(L, #<), */ chains together the remaining of the paris the list has to create to be complete/*
    label(L).     */ labels the pairs and outputs them to the output screen/*
