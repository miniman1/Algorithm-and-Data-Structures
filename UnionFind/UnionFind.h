// return pointer to new UnionFind object, with 'size' amount of sets, and sets named from 0 to size-1 
// if size is invalid, return NULL
UnionFind *newUnionFind(int size); 

// given element x, determine what set x belongs to, whilst applying path compression if necessary
// if x is invalid, return -1 
int find(UnionFind* U, int x);
    
// given two sets, merge the sets together
// if x or y is invalid, do nothing
void union(UnionFind* U, int x, int y); 
