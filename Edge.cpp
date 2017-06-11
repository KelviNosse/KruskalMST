#include "Edge.h"

Edge::Edge(int source, int destination, int weight)
{
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

Edge::~Edge()
{
    //dtor
}
