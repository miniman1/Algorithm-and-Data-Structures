#include <stdio.h>
#include <stdlib.h>

typedef Struct UnionFind {
    int size; 
    // tracks the parent of each value
    int *id; 
} UnionFind; 


UnionFind *newUnionFind(int size) {
    UnionFind *U = malloc(sizeof(UnionFind));
    U->size = size; 
    U->id = malloc(sizeof(int) * size); 
    // initially, the parent of each value is itself
    for (int i = 0; i < size; i++) {
        U->id[i] = i; 
    }
    return size; 
}

int find(UnionFind* U, int x); 
    
int union(UnionFind* U, int x, int y); 

void freeUnionFind(UnionFind* U) {
    free(U->id); 
    free(U); 
} 
