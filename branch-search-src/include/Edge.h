/*Edge.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
Edge.h contains the definition of the edge object
Edge is a core part of the graph for searching for neighbours
and adjacency.
*/
#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"


class Edge
{
    public:
        Edge(); //Default Constructor pretty useless
        Edge(Vertex inVertex1, Vertex inVertex2, float inWeight); //Constructor to create an actual useful edge

        Vertex getVertex1(); //Returns vertex 1
        Vertex getVertex2(); //Ditto but for vertex 2
        float getWeight(); //Ditto but for edge weight

        bool operator==(Edge inEdge); //Compares given vertex to this one
        virtual ~Edge();
    protected:
    private:
        //Data that defines a edge
        Vertex vertex1; //First vertex of the edge
        Vertex vertex2; //Second vertex
        float weight; //Weight between them
};

#endif // EDGE_H
