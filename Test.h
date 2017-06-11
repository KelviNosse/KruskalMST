#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <queue>
#include <list>
#include "Edge.h"
#include "Kruskal.h"

using namespace std;

void test();
int** getKruskalMST(int** graph, int size, vector<Edge*> edges);

#endif // EVALUADOR_H
