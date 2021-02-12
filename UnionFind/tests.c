#include "UnionFind.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void testSizeZero(); 
void testSizeOne(); 
void testSizeLarge(); 

int main(int argc, char* argv[]) {
    void testSizeZero(); 
    void testSizeOne(); 
    void testSizeLarge(); 
}

void testSizeZero() {
    UnionFind *U; 

    // invalid size
    U = newUnionFind(-1); 
    assert(U == NULL); 
    U = newUnionFind(0);
    assert(U == NULL); 

    // invalid find
    assert(find(U, 0) == -1); 

    // invalid union
    assert(union(U, 0, 1) == FALSE); 
    free(U); 
}

void testSizeOne() {
    // size == 1
    U = newUnionFind(1); 
    assert(U != NULL); 
    // invalid find
    assert(find(U, -1) == -1); 
    // valid find
    assert(find(U, 0) == 0); 

    // invalid union
    assert(union(U, 0, 0) == FALSE); 
    assert(union(U, 0, 1) == FALSE);  
}

void testSizeLarge() {
    // size > 1 (e.g. 4)
    U = newUnionFind(4); 
    assert(U != NULL); 

    // invalid find
    assert(find(U, -1) == -1); 
    assert(find(U, 4) == -1); 
    assert(find(U, 100) == -1); 

    // valid find
    for(int i = 0; i < 4; i++) {
        assert(find(U, i) == i); 
    }
    // invalid union
    assert(union(U, -1, 0) == FALSE); 
    assert(union(U, 0, -1) == FALSE); 
    assert(union(U, 0, 0) == FALSE); 

    // valid union 
    assert(union(U, 0, 1) == TRUE); 
    assert(find(U, 0) == find(U, 1)); 
    assert(find(U, 2) != find(U, 1)); 
    assert(find(U, 3) != find (U, 1)); 
    assert(find(U, 3) != find(U, 2)); 

    assert(union(U, 2, 3) == TRUE); 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            assert(find(U, i) == find(U, j)); 
        }
    }
}
