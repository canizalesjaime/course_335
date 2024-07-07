#ifndef DISJSETS_H
#define DISJSETS_H

#include<vector>

class DisjSets
{

public:
/* Construct the disjoint sets object .
 * @param numElements is the initial number of disjoint sets .
 */
    DisjSets(int numElements );   // Default Construtor

/** Union two disjoint sets.
  * Assume root1 and root2 are distinct and represent set names.
  * param root1 is the root of set 1.
  * param root2 is the root of set 2. */
    void Union(int root1, int root2);

/**
  * Perform a recursive find with path compression.
  * param x is the element to be found
  * return the set containing x. */
    int find(int x);

    void print();

private:
    std::vector<int> s;
};

#endif /* DISJSETS_H */
