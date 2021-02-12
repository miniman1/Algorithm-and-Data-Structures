#include <stdio.h>
#include <stdlib.h>

typedef Struct UnionFind {
    int size; 
    // tracks the parent of each value
    int *id; 
} UnionFind; 

