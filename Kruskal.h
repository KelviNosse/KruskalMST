#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>
#include "Edge.h"
using namespace std;

class Kruskal{
    public:
        int** graph;
        int size;
        vector<Edge*> edges;
        int** getMST();
        Kruskal(int** graph, int size, vector<Edge*> edges);
        virtual ~Kruskal();
    private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        void make_set(int vertex);
        int find(int vertex);
        void create_disjoint_set();
        void merge(int v1, int v2);
        int** initGraph();
};

#endif //KRUSKAL_H