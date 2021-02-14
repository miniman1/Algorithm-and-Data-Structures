#include <stdio.h>
#include <stdlib.h>
#include "UnionFind.h"

typedef struct UnionFindRep {
    int size; 
    // tracks the parent of each value
    int *id; 
} UnionFindRep; 



UnionFind newUnionFind(int size) {
    UnionFind U = malloc(sizeof(UnionFind));
    U->size = size; 
    U->id = malloc(sizeof(int) * size); 
    // initially, the parent of each value is itself
    for (int i = 0; i < size; i++) {
        U->id[i] = i; 
    }
    return U; 
}

int find(UnionFind U, int x) {
    int curr = x; 
    while (U->id[curr] != curr) {
        curr = U->id[curr]; 
    }

    int parent = curr; 
    curr = x; 

    // path compression
    while (U->id[curr] != curr) {
        U->id[curr] = parent; 
        curr = U->id[curr]; 
    }
    return parent; 
} 
    
void Union(UnionFind U, int x, int y) {
    int px = find(U, x); 
    int py = find(U, y); 
    U->id[px] = py; 
}

void freeUnionFind(UnionFind U) {
    free(U->id); 
    free(U); 
} 