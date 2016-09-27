//----------------------------------------------------------------------
//                        Disjoint-set data structure 
// File:                        union_find.cpp
//----------------------------------------------------------------------
// Copyright (c) 2016 Michael Hahsler, Matt Piekenbrock. All Rights Reserved.
//
// This software is provided under the provisions of the
// GNU General Public License (GPL) Version 3
// (see: http://www.gnu.org/licenses/gpl-3.0.en.html)

// Class definition based off of data-structure described here:  
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure

#include "union_find.h"

UnionFind::UnionFind(const size_t size) : parent(size), rank(size)
{
  for (size_t i = 0; i < size; ++i)
  { parent[i] = i, rank[i] = 0; }
}
  
// Destructor not needed w/o dynamic allocation
UnionFind::~UnionFind() { }
  
void UnionFind::Union(const size_t x, const size_t y)
{
  const size_t xRoot = Find(x);
  const size_t yRoot = Find(y);
  if (xRoot == yRoot)
   return; 
  else if (rank[xRoot] > rank[yRoot])
    parent[yRoot] = xRoot; 
  else if (rank[xRoot] < rank[yRoot]) 
    parent[xRoot] = yRoot; 
  else if (rank[xRoot] == rank[yRoot])
  {
    parent[yRoot] = parent[xRoot];
    rank[xRoot] = rank[xRoot] + 1;
  }
}

const size_t UnionFind::Find(const size_t x)
{
  if (parent[x] == x)
    return x; 
  else
  {
    parent[x] = Find(parent[x]);
    return parent[x];
  }
}