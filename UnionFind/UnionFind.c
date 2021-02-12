#include <stdio.h>
#include <stdlib.h>

typedef Struct UnionFind {
    int size; 
    // tracks the parent of each value
    int *id; 
} UnionFind; 


UnionFind *newUnionFind(int size) {
    if (size <= 0) { return NULL; }
    UnionFind *U = malloc(sizeof(UnionFind));
    U->size = size; 
    U->id = malloc(sizeof(int) * size); 
    // initially, the parent of each value is itself
    for (int i = 0; i < size; i++) {
        U->id[i] = i; 
    }
    return size; 
}

int find(UnionFind* U, int x) {
    if ((x < 0) or (x >= U->size)) { return -1; }
    while (U->id[x] != x) {
        x = U->id[x]; 
    }
    return x; 
} 
    
int union(UnionFind* U, int x, int y) {
    if ((x < 0) || (y < 0) || (x >= U->size) || (y >= U->size)) { return FALSE; }
    if (find(x) == find(y)) { return TRUE }; 
    px = find(x); 
    py = find(y); 
    for (int i = 0; i < U->size; i++) {
        if (find(i) == px) {
            U->id[i] = py; 
        }
    }
    return TRUE; 
}

void freeUnionFind(UnionFind* U) {
    free(U->id); 
    free(U); 
} 
