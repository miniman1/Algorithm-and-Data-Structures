#include <stdio.h>
#include <stdlib.h>
#include "UnionFind.h"

typedef struct UnionFindRep {
    // tracks the size of each set
    int *size; 
    // tracks the parent of each value
    int *id; 
} UnionFindRep; 



UnionFind newUnionFind(int size) {
    UnionFind U = malloc(sizeof(UnionFind));
    U->size = malloc(sizeof(int) * size); 
    U->id = malloc(sizeof(int) * size); 
    // initially, the parent of each value is itself
    for (int i = 0; i < size; i++) {
        U->id[i] = i; 
        U->size[i] = 1; 
    }
    return U; 
}

int find(UnionFind U, int x) {
    int curr = x; 
    // finding the parent
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
    // finding which set each node belongs to
    int px = find(U, x); 
    int py = find(U, y); 
    // combining the smaller set into the larger one
    if (U->size[px] < U->size[py]) {
        U->id[px] = py; 
        U->size[py] += U->size[px];
    } else {
        U->id[py] = px; 
        U->size[px] += U->size[py];
    }
}

void freeUnionFind(UnionFind U) {
    free(U->id); 
    free(U); 
} 