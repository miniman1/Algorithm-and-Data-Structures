#include "UnionFind.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "UnionFind.h"

void testSizeZero(); 
void testSizeOne(); 
void testSizeLarge(); 

int main(int argc, char* argv[]) {
    printf("Beginning Testing\n");
    testSizeZero(); 
    printf("Tests for size 0 successful\n"); 
    testSizeOne(); 
    printf("Tests for size 1 successful\n"); 
    testSizeLarge(); 
    printf("Tests for size large successful\n"); 
    printf("TestComplete"); 
    return 0;
}

void testSizeZero() {
    UnionFind U; 

    // invalid size
    U = newUnionFind(-1); 
    assert(U == NULL); 
    U = newUnionFind(0);
    assert(U == NULL); 
}

void testSizeOne() {
    UnionFind U; 
    // size == 1
    U = newUnionFind(1); 
    assert(U != NULL); 
    // invalid find
    assert(find(U, -1) == -1); 
    // valid find
    assert(find(U, 0) == 0); 

    // invalid union
    assert(Union(U, 0, 0) == false); 
    assert(Union(U, 0, 1) == false);  
    freeUnionFind(U); 
}

void testSizeLarge() {
    UnionFind U; 
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
    assert(Union(U, -1, 0) == false); 
    assert(Union(U, 0, -1) == false); 
    assert(Union(U, 0, 0) == false); 

    // valid union 
    assert(Union(U, 0, 1) == true); 
    assert(find(U, 0) == find(U, 1)); 
    assert(find(U, 2) != find(U, 1)); 
    assert(find(U, 3) != find (U, 1)); 
    assert(find(U, 3) != find(U, 2)); 

    assert(Union(U, 2, 3) == true); 
    assert(find(U, 2) == find(U, 3)); 
    assert(find(U, 1) != find(U, 2)); 
    assert(find(U, 1) != find(U, 3)); 
    assert(find(U, 1) == find(U, 0)); 
    assert(Union(U, 1, 2) == true); 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            assert(find(U, i) == find(U, j)); 
        }
    }
    freeUnionFind(U); 
}
