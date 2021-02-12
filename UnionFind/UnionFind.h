// return pointer to new UnionFind object, with 'size' amount of sets, and sets named from 0 to size-1 
// if size is invalid, return NULL
UnionFind *newUnionFind(int size); 

// given element x, determine what set x belongs to, whilst applying path compression if necessary
// if x or U is invalid, return -1 
int find(UnionFind* U, int x);
    
// given two sets, merge the sets together, return true if successful
// if x or y is invalid, return false
int union(UnionFind* U, int x, int y); 

void freeUnionFind(UnionFind* U); 

