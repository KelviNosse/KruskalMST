#include "Kruskal.h"

Kruskal::Kruskal(int** graph, int size, vector<Edge*> edges){
    this->graph = graph;
    this->size = size;
    this->edges = edges;
}

int Kruskal::find(int vertex){
    return parent[vertex] == vertex ? parent[vertex] : find(parent[vertex]);
}

void Kruskal::merge(int v1, int v2){
    if(rank[v1] > rank[v2]){
        parent[v2] = v1;
    }else if(rank[v2] > rank[v1]){
        parent[v1] = v2;
    }else{
        parent[v1] = v2;
        rank[v2]++;
    }
}

void Kruskal::make_set(int vertex){
    this->parent[vertex] = vertex;
    this->rank[vertex] = 0;
}

void Kruskal::create_disjoint_set(){
    for(int i = 0; i < this->size; i++) make_set(i); //vertices label are indexes
}

int** Kruskal::initGraph()
{
    int **answer = new int* [this->size];
    for(int i=0;i<this->size;i++)
    {
        answer[i]=new int[this->size];
        for(int j=0;j<this->size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

int** Kruskal::getMST(){
    create_disjoint_set();
    int** result = initGraph();
    //assumes that edge list is sorted if not, needs to be sorted!
    for(Edge* e : this->edges){
        int v1 = find(e->source);
        int v2 = find(e->destination);
        if(v1 != v2){
            result[e->source][e->destination] = e->weight;
            result[e->destination][e->source] = e->weight;
            merge(v1, v2);
        }
    }
    
    return result;       
}


Kruskal::~Kruskal(){}