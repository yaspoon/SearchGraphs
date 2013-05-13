/*Edge.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
Edge.cpp implements the Edge class
It is critical to the graph object
For it holds a single edges data two vertices and a weight
between them. This is then used for traversal of the graph
*/
#include "Edge.h"
#include <cmath>

Edge::Edge() //Default Constructor
{
    //ctor
}

/*Useful contructor that takes in two vertexs and a weight
and then makes this edge out of them by setting the class
variables using the input*/
Edge::Edge(Vertex inVertex1, Vertex inVertex2, float inWeight)
{
    vertex1 = inVertex1;
    vertex2 = inVertex2;
    weight = inWeight;
}

Edge::~Edge() //Destructor no heap data so does nothing
{
    //dtor
}

Vertex Edge::getVertex1() //Getter function to return first vertex object of the edge
{
    return vertex1;
}

Vertex Edge::getVertex2() //Ditto but for second vertex
{
    return vertex2;
}

float Edge::getWeight() //Getter for the edges weight
{
    return weight;
}

bool Edge::operator==(Edge inEdge) //Compares a given edge to this one and returns if they are equal
{
    bool retVal = false; //assume they are not equal
    float tollerance = 0.001f; //Needs a tollerance value because we are comparing floats, ie float infinity problem

    //Compare the vertexs to see if they match, order isn't important because the graph is undirected
    if( (vertex1 == inEdge.getVertex1() && vertex2 == inEdge.getVertex2()) || (vertex1 == inEdge.getVertex2() && vertex2 == inEdge.getVertex1()) )
    {
        //If the vertices match check the weights are the same
        if( fabs(weight - inEdge.getWeight()) < tollerance)
        {
            retVal = true; //The edges are equivalent return true
        }
    }

    return retVal;
}
