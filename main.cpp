#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    return (new Kruskal(graph, size, edges))->getMST();
}

int main ()
{
    test();
    return 0;
}
