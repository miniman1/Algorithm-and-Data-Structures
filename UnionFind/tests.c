#include "UnionFind.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "UnionFind.h"

void testSizeOne(); 
void testSizeLarge(); 

int main(int argc, char* argv[]) {
    testSizeOne(); 
    printf("Tests for size 1 successful\n"); 
    testSizeLarge(); 
    printf("Tests for size large successful\n"); 
    printf("TestComplete"); 
    return 0;
}

void testSizeOne() {
    UnionFind U; 
    // size == 1
    U = newUnionFind(1); 
    assert(U != NULL); 
 
    // valid find
    assert(find(U, 0) == 0); 

    freeUnionFind(U); 
}

void testSizeLarge() {
    UnionFind U; 
    // size > 1 (e.g. 4)
    U = newUnionFind(4); 
    assert(U != NULL); 

    // valid find
    for(int i = 0; i < 4; i++) {
        assert(find(U, i) == i); 
    }

    // valid union 
    Union(U, 0, 1);
    assert(find(U, 0) == find(U, 1)); 
    assert(find(U, 2) != find(U, 1)); 
    assert(find(U, 3) != find (U, 1)); 
    assert(find(U, 3) != find(U, 2)); 

    Union(U, 2, 3); 
    assert(find(U, 2) == find(U, 3)); 
    assert(find(U, 1) != find(U, 2)); 
    assert(find(U, 1) != find(U, 3)); 
    assert(find(U, 1) == find(U, 0)); 
    Union(U, 1, 2); 
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            assert(find(U, i) == find(U, j)); 
        }
    }
    freeUnionFind(U); 
}
