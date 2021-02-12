// return pointer to new UnionFind object, with 'size' amount of sets, and sets named from 0 to size-1 
UnionFind *newUnionFind(int size); 

// given element x, determine what set x belongs to, whilst applying path compression if necessary
int find(UnionFind* U, int x);
    
// given two sets, merge the sets together
void union(UnionFind* U, int x, int y); 
