/*GreedySearch.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
Greedy search is the object that implements the actual
searching required for this assignment.
It uses the graph object to find the path and vertexs
*/
#include "GreedySearch.h"
#include "Set.h"
#include "Stack.h"
#include "Common.h"
#include <unistd.h>

//Default constructor does nothing useful anyway.
GreedySearch::GreedySearch()
{
    //ctor
}

//Destructor No pointers or heap data so nothing to clean up manually.
GreedySearch::~GreedySearch()
{
    //dtor
}

//Set the graph to use for searching. Can't do anything if this isn't set.
void GreedySearch::setGraph(Graph inGraph)
{
    searchGraph = inGraph;
}

//The actual search function for greedy
void GreedySearch::search(std::string start, std::string end)
{
    if(searchGraph.contains(start) && searchGraph.contains(end)) //Make sure the specified nodes even exist in the graph...
    {
        if(debug) //If debug mode is enabled tell the user we found the nodes in the graph successfully
        {
            std::cout << "The start vertex \"" << start << "\" and \"" << end << "\" were found in the graph time to start searching\n" << std::endl;
        }

        /*Because it is only passed the names of the start and end vertexs
        it first has to search through the graph and find the actual vertex
        objects which has there heuristic*/
        Pair<Vertex, bool> startVert = searchGraph.findVertexByName(start);
        Pair<Vertex, bool> endVert = searchGraph.findVertexByName(end);

        Vertex currentVertex = startVert.first; //Set the current vertex we are working on to the start vertex we were given
        Vertex theEnd = endVert.first; //My only friend

        Stack<Vertex> currentPath; //The current vertexs we have visited to get where we are
        Set<Vertex> visited; //Ditto but these vertexs can also be ones that have been culled because they are dead ends

        /*While we haven't found the goal vertex and the current vertex isn't empty
        because we ran out of vertexs to search, this happens when goal and start vertex are in seperate
        disjoint subgraph of the graph*/
        while(currentVertex != theEnd && currentVertex.getName() != "")
        {
            currentPath.push(currentVertex);   //We are currently at the start node we don't want to jump back to it so add it as the first node to not go back to.
            visited.insert(currentVertex);  //We don't want to get back to a cycle so ditto

            Set<Vertex> neighbours = searchGraph.neighbours(currentVertex.getName()); //Get the neighbours of the currentVertex so we can choose where to go next

            neighbours = neighbours - visited; //Subtract away the already visited vertexs from the candidate set so we don't go back to where we have already been

            if(neighbours.size() != 0) //If we have some neighbours we can still visit
            {
                if(debug) //Tell the use we found neighbours if they wanted to know
                {
                    std::cout << "\tFound \"" << neighbours.size() << "\" usefull neighbours for \"" << currentVertex.getName() << std::endl;
                }

                Vertex smallestVert = neighbours.smallest(); //Vecause we are greedy we choose the neighbour with the smallest cost

                currentVertex = smallestVert; //The next vertex to expand is the smallest neighbour so set it as the next

                if(debug) //Tell the user about this if they wanted to know
                {
                    std::cout << "Setting currentVertex to \"" << smallestVert.getName() << "\"" << std::endl;
                }

            }
            else    //If we get here we have hit a dead end time to back track because the vertex
            {       //has no useful neighbours, ie no neighbours we havne't alreadt reached

                if(debug)//Tell the user about this dilema
                {
                    std::cout << "\tNo usefull neighbours found for \"" << currentVertex.getName() << "\" time to backtrack!" << std::endl;
                }

                currentPath.pop(); //Get rid of this dead end node
                currentVertex = currentPath.peak(); //Set the node to expand next to the one we came from to get to this dead end

                if(debug) //Tell the user what we are doing
                {
                    std::cout << "Setting currentVertex to \"" << currentPath.peak().getName() << "\"" << std::endl;
                }

                currentPath.pop();//workaround because if we back track the vertex we backtrack to will be added to the stack again if we don't pop it off...

            }

        } //ENd of while loop, we should have found a valid path, if not then if means we can't get to the goal vertex from the given start

        if(currentPath.size() > 0)  //If the currentPath size is 0 that means no path was found so the start and end node must be in disjoint graphs
        {
            currentPath.push(currentVertex); //We end when we expand the goal vertex so we need to add it to the path

            Stack<Vertex> endStack; //A temporary stack holding the actual visited order

            /*Reverses the given path stack so it can be printed out in correct
            order it's inefficient but the only way to do it*/
            while(currentPath.size() > 0)
            {
                endStack.push(currentPath.pop());
            }

            std::cout << "Path to goal: ";

            //Print out the found path
            while(endStack.size() > 0)
            {
                std::cout << endStack.pop().getName();
                if(endStack.size() > 0)
                {
                    std::cout << "->";
                }
                else
                {
                    std::cout << std::endl;
                }
            }
        }
        else //If we get here let the user know we think there graph is broken because we exhausted all paths yet couldn't get a connection
        {   //to the goal vertex so the graph much be disjoint
            std::cout << "It seems that the graph is disjoint and the start and end vertexs are in different subtrees, please rectify this to get a valid result" << std::endl;
        }
    }
    else //If we get here the user didn't specify valid start and end vertexs
    {
        std::cout << "The start vertex \"" << start << "\" or end vertex \"" << end << "\" isn't in the graph are you sure you entered it correctly" << std::endl;
    }
}
