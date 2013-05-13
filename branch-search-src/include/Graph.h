/*Graph.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Graph.h contains the definition of the
Graph Class which is the core of the greedy
search. It also defines the local data for the
graph object
*/
#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include <utility>
#include "Set.h"
#include "Edge.h"
#include <fstream>


class Graph
{
    public:
        Graph();
        virtual ~Graph();

        Set<Vertex> loadHeuristics(std::ifstream &heurFile); //after loading the graph get the hueristics

        bool adjacent(std::string vertex1, std::string vertex2); //Test if vertex1 and vertex2 are adjacent ie there is a edge connecting them
        Set<Vertex> neighbours(std::string vertex);      //List all vertexs connected to specified node
        bool addEdge(Vertex vertex1, Vertex vertex2, float weight); //Adds the edge from vertex1 to vertex2 if it isn't already in the graph also creates the vertexs returns true on successful add
        float getVertexHueristic(std::string vertex); //Get how far away the vertex is from the goal
        bool createGraph(const char* filepath);   //loads the given text file and creates a graph from it
        bool contains(std::string vertex); //Check if the vertex exists with the graph

        bool addVertex(Vertex newVert); //Checks if the vertex isn't already in the graph and then adds it
        Pair<Vertex, bool> findVertexByName(std::string vertex);
        Edge getEdge(std::string vertex1, std::string vertex2);
    protected:
    private:
        Set<Vertex> vertices; //The set of all vertices within the graph
        Set<Edge> edges; //The set of edges that connect the vertices

        Pair<Vertex, bool> findVertexByName(Set<Vertex> theSet, std::string vertex); //Helper function to find Vertexs used for converting a name to an actual object
};

#endif // GRAPH_H
