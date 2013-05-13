/*Graph.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
This file implements the Graph objects functions
This is where the heavy lifting is done in the program.
Just about everything is handled in this object
It holds the vertices and edges of the graph
and performs operations like find neighbours
and loading the graph from the text files
*/
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Common.h"

//Constructor
Graph::Graph()
{
    //ctor
}

//Destructor
Graph::~Graph()
{
    //dtor
}

/*Takes in two vertexs names, then searches through the edge
connections to check whether the two specified vertices are
adjacent (connected)
Returns true when they are connected and false when not connected*/
bool Graph::adjacent(std::string vertex1, std::string vertex2)
{
    bool retVal = false; //By default assume they arn't connected

    //Need to find the vertexs to compare to, so search the vertices list using the given names
    Pair<Vertex, bool> vert1 = findVertexByName(vertex1);
    Pair<Vertex, bool> vert2 = findVertexByName(vertex2);

    /*Can't use set::find function sadly because it will test for the weight so we have to do it manually here....
    This is now fixed to use the weights but Still not going to use set::find() because this is known to work
    i.e don't fix what isn't broken*/
    for(Iterator<Edge> iT = edges.begin(); iT != edges.end(); ++iT)
    {
        Edge tmp = iT.getData(); //Get the edge held within the current list
        //Compare the vertices of the given edge to the ones specified and return true if they match
        if((vert1.first == tmp.getVertex1() && vert2.first == tmp.getVertex2()) || (vert1.first == tmp.getVertex2() && vert2.first == tmp.getVertex1()))
        {
            retVal = true;
        }
    }

    return retVal;
}

/*Neighbours is the core function of the greedysearch
Given a vertex name it then finds all connections that vertex
has to other vertices*/
Set<Vertex> Graph::neighbours(std::string vertex)
{
    Set<Vertex> neighbourList; //Holds the neighbours we found and will return it to the caller

    Pair<Vertex, bool> tempPair = findVertexByName(vertex);//Need find the vertex from the given name this way we have the actual vertex and it's weight makes comparison easier
    Vertex tmpVert = tempPair.first; //Get the vertex we found and put it in a temporary

    for(Iterator<Edge> iT = edges.begin(); iT != edges.end(); ++iT) //Iterate over all the edges
    {
        Edge tmpEdge = iT.getData();
        if(tmpVert == tmpEdge.getVertex1()) //if the first vertex is the one specified then the second one in the edge is it's neighbour so add it to the list
        {
            neighbourList.insert(tmpEdge.getVertex2());//Add the found vertex to the neighbour list
            if(debug)
            {
                std::cout << "\tFound neighbour \"" << tmpEdge.getVertex2().getName() << ":" << tmpEdge.getVertex2().getHeuristic() << "\" of \"" << vertex << "\"" << std::endl;
            }
        }
        else //Opposite case, if the second vertex is the one specified return vertex1 because that's it's neighbour
        {
            if(tmpVert == tmpEdge.getVertex2())
            {
                neighbourList.insert(tmpEdge.getVertex1());//Add the found vertex to the neighbour list
                if(debug)
                {
                    std::cout << "\tFound neighbour \"" << tmpEdge.getVertex1().getName() << ":" << tmpEdge.getVertex1().getHeuristic() << "\" of \"" << vertex << "\"" << std::endl;
                }
            }
        }
    }

    return neighbourList;
}

/*Adds the two vertexs to the vertices list, if they exist in the list they arn't added
    then creates a edge object from those vertexs and adds it to the list it's not added if it already exists
*/
bool Graph::addEdge(Vertex vertex1, Vertex vertex2, float weight)
{
    bool retVal = false; //By default assume we can't add the edge

    addVertex(vertex1); //Add the vertexs to the vertices list
    addVertex(vertex2);

    Edge newEdge(vertex1, vertex2, weight); //Create the new edge object from the given data

    //Check if the edge is added to the set, it isn't added if it already exists
    if(edges.insert(newEdge) == true)
    {
        retVal = true;
        if(debug)
        {
            std::cout << "Successfully added edge " << vertex1.getName() << ":" << vertex1.getHeuristic() << " -> " << vertex2.getName() << ":" << vertex2.getHeuristic() << " with a weight of " << weight << std::endl;
        }
    }
    else
    {
        if(debug)
        {
            std::cout << "Edge " << vertex1.getName() << " -> " << vertex2.getName()<< " with weight " << weight << " wasn't added to the set because it's a duplicate" << std::endl;
        }
    }

    return retVal;
}

/*Given a vertex object
adds it to the vertices set
and checks whether it was added successfully
If no that means it's a suplicate
*/
bool Graph::addVertex(Vertex newVert)
{
    bool retVal = false; //Assume by default it fails to insert

    //If the vertex wasn't added to the set because it already exists let them know if debugging is enabled
    if(vertices.insert(newVert) == false && debug)
    {
        std::cout << "Failed to insert vertex " << newVert.getName() << " into vertices set, because it already exists within the set" << std::endl;
    }
    else
    {
        retVal = true;

        if(debug)
        {
            std::cout << "Successfully added " << newVert.getName() << " into vertices set" << std::endl;
        }
    }

    return retVal;
}

/*Finds the given vertex then gets it's heuristic
if the vertex exists that is*/
float Graph::getVertexHueristic(std::string vertex)
{
    float retVal = -1; //Default value for the graph meaning NULL ie not found probalby should change this to a pair object
    Pair<Vertex, bool> foundVert; //temporary to store the found vertex

    foundVert = findVertexByName(vertex); //Try and find specified vertex

    if(foundVert.second != false) //Check if a vertex was found
    {
        retVal = ((foundVert.first)).getHeuristic(); //Set the return value to the one found
    }

    return retVal;
}

/*Another core function the CreateGraph fucntion
Takes in two file paths then opens them and gets the helper function
loadHeuristic to load the heuristic graph, then if that succeeds it
loads the graph file and creates the vertices and egdes*/
bool Graph::createGraph(const char* filepath)
{
    std::ifstream graphFile; //File stream objects to hold the open file data from the OS
    bool retVal = false; //By default assume we failed to load the files

    graphFile.open(filepath, std::ios::in); //Open the input file for reading to create the graph

    if(graphFile.is_open()) //If we opened the file ie found it.
    {
        do
        {
            std::string line;
            std::getline(graphFile, line); //Reads a line from the input file into a string

            if(!graphFile.fail()) //If the filestream hasn't thrown a error flag keep reading
            {
                std::stringstream convert(line); //Create a string stream object from the string we read in.

                std::string vert1Name; //temp variable to store first vertex name
                std::string vert2Name; //temp variable to store second vertex name
                float weight;        //temp variable to store weight of the edge between them

                convert >> vert1Name; //String stream will read the string looking for a string to put in vertex1
                convert >> vert2Name; //Ditto
                convert >> weight;  //looks for a float or number

                Vertex vert1; //Holds the vertexs we find
                Vertex vert2;

                vert1 = Vertex(vert1Name, -1.0f); //Create a fake vertex that is going to break the search if it's not the goal vertex
                vert2 = Vertex(vert2Name, -1.0f);//Create a fake vertex that is going to break the search if it's not the goal vertex

                //Give the data we found to addEdge so it can create and add the edge
                addEdge(vert1, vert2, weight);
            }


        }
        while(!graphFile.eof()); //While the filestream isn't at the end of the file keep reading

        graphFile.close();  //Now that we are done with the file close it so we don't have dangling files open.

        retVal = true; //We loaded the file successfully, well we think so anyway
    }
    else //Failed to find start and end within graph
    {
        std::cout << "Failed to open file " << filepath << " please check the file path given" << std::endl;
        retVal = false;
    }

    return retVal;
}

/*Load heuristic is a helper function for loading the heuristic
file and returning a set of the vertexs that it loaded*/
Set<Vertex> Graph::loadHeuristics(std::ifstream &heurFile)
{
    Set<Vertex> vertexs; //Store the loaded vertices here

    if(heurFile.is_open()) //
    {
        std::string line; //holds a line of the text file

        /*The heuristic file has a horrible mixture of unix \n and mac os 9 \r.
        The first line is terminated using two \r (return carriage) so we first have to get these out the way
        then we resume our normal string parsing by delimiting by \n.
        This causes problems meaning that the file format must follow this EXACT format or everything will break horribly
        */
        std::getline(heurFile, line, '\r'); //Read off the first \r and ignore it
        std::getline(heurFile, line, '\r'); //Read off the second \r and ignore it

        do
        {

            std::getline(heurFile, line); //Get a line of text should be delimited by \n

            if(!heurFile.fail()) //if we did read a line of text and it's didn't fail miserably
            {
                std::stringstream convert(line); //Create a stringstream object from the read string

                std::string vertex; //Place holders to hold the read value from stringstream
                float heuristic;

                convert >> vertex; //Try and read the vertex name
                if(!convert.fail()) //If it didn't fail reading the name continue
                {
                    convert >> heuristic; //Read the heuristic value
                    if(!convert.fail()) //If we didn't fail to read eitehr of them then
                    {
                        Vertex tmp(vertex, heuristic); //Create the vertex object
                        vertexs.insert(tmp); // Add it to the vertices list
                    }
                }
            }
        }
        while(!heurFile.eof()); //Keep reading the file till we reach the end

        heurFile.close(); //Close it before we exit
    }

    return vertexs;
}

/*Overloaded function that finds a vertex within the specified Set based on a name alone
This is useful because it finds the vertex object with that name and returns
it this object can then be used for comparisons when iterating over a list*/
Pair<Vertex, bool> Graph::findVertexByName(Set<Vertex> theSet, std::string vertex)
{
    Pair<Vertex, bool> retVal; //Store what we found here
    retVal.second = false; //assume by default we didn't find the vertex

    for(Iterator<Vertex> iT = theSet.begin(); iT != theSet.end(); ++iT)
    {
        Vertex tmp = iT.getData(); //Get the currently held vertex
        if(tmp.getName() == vertex) //Test if it's the one we are looking for...Makes me think of droids dammit starwars
        {
            retVal.first = tmp; //Set the return vertex to the one we found
            retVal.second = true; //Say yes we found it
        }
    }

    return retVal;
}

/*Same as above but instead it default searches only the
vertices set held within the graph instead of a specified Set*/
Pair<Vertex, bool> Graph::findVertexByName(std::string vertex)
{
    Pair<Vertex, bool> retVal;
    retVal.second = false;

    for(Iterator<Vertex> iT = vertices.begin(); iT != vertices.end(); ++iT)
    {
        Vertex tmp = iT.getData();
        if(tmp.getName() == vertex)
        {
            retVal.first = tmp;
            retVal.second = true;
        }
    }

    return retVal;
}

/*Helper function that checks if the graph contains the given vertex
It's used to check if the start and end vertex specified actually exist
within the graph*/
bool Graph::contains(std::string vertex)
{
    bool retVal = false; //assume it doesn't exist

    Pair<Vertex, bool> vert = findVertexByName(vertices, vertex); //Search the graph for the vertex

    if(vert.second == true) //If we found the vertex return true
    {
        retVal =true;
    }

    return retVal;
}

Edge Graph::getEdge(std::string vertex1, std::string vertex2)
{
    Edge tmp;

    Pair<Vertex, bool> vert1 = findVertexByName(vertex1);
    Pair<Vertex, bool> vert2 = findVertexByName(vertex2);

    for(Iterator<Edge> iT = edges.begin(); iT != edges.end(); ++iT)
    {
        Edge iTedge = iT.getData();

        if( (vert1.first == iTedge.getVertex1() && vert2.first == iTedge.getVertex2()) || (vert2.first == iTedge.getVertex1() && vert1.first == iTedge.getVertex2()))
        {
            tmp = iTedge;
        }
    }

    return tmp;
}
