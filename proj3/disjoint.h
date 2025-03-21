/* disjoint.h
   Interface and subclass specification for disjoint sets.
   James S. Plank
   Tue Sep 25 15:48:18 EDT 2018
 */

#pragma once

#include <vector>

using namespace std;

class DisjointSet {
  public:
    virtual ~DisjointSet() {};
    virtual int Union(int s1, int s2) = 0;
    virtual int Find(int element) = 0;  
    virtual void Print() = 0;
};

/* We will use Dr. Plank's third subclass implementation -- Union-by-Rank with path compression. */

class DisjointSetByRankWPC : public DisjointSet {
  public:
    DisjointSetByRankWPC(int nelements);
    int Union(int s1, int s2);
    int Find(int element); 
    void Print();

  protected:
    vector <int> links;
    vector <int> ranks;
};
