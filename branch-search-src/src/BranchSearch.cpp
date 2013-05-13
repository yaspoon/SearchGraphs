/*BranchSearch.cpp
Brock York 14840261
AMI 300 Assignment Branch Search
Implements the BranchSearch object
This object is used to search the graph using
the branch and bound style. It's use is identical
to the greedy search but the way it searches is different
*/
#include "BranchSearch.h"

#include "Set.h"
#include "Vertex.h"
#include "Path.h"
#include "Common.h"

BranchSearch::BranchSearch() //Default Constructor
{
    //ctor
}

BranchSearch::~BranchSearch() //Destructor
{
    //dtor
}

//Sets the graph to be searched to the one passed in
void BranchSearch::setGraph(Graph inGraph)
{
    searchGraph = inGraph;
}

/*
The search function is the main function of the object.
It does all the hard work to find the paths to the goal vertex
*/
void BranchSearch::search(std::string startVertex, std::string goalVertex)
{

    //Check to make sure the start and end vertexs exist in the graph, no point wasting time if a answer isn't even possible.
    if(searchGraph.contains(startVertex) && searchGraph.contains(goalVertex))
    {
        Pair<Vertex, bool> start = searchGraph.findVertexByName(startVertex); //Get the starting vertex from the vertices list
        Pair<Vertex, bool> endVertex = searchGraph.findVertexByName(goalVertex); //Get the goal vertex from the vertices list

        Set<Path> currentPaths; //Holds the current valid paths that we can jump to, the paths left in here when the search ends are the partial paths
        Set<Path> deadEndPaths; //The paths that end and go know where else, no need to keep searching them
        Set<Path> goalPaths;    //All the posible solution paths

        bool exhaustedAllPaths = false; //Did we go through every vertex possible and still not reach the goal, used to terminate search if it's a dosjoint graph
        bool goalFound = false;         //Did we find the goal in the end

        /*
            Little bit of hackery to start the search, it creates a new path from the start node.
            This way we have a path to begin searching at
        */
        Path tmp;
        tmp.add(start.first, 0);
        currentPaths.insert(tmp);

        /*
        The searching begins here, it will keep looping while there is paths left to take, the goal hasn't been found and there is still shorter paths to take
        */
        while(!exhaustedAllPaths && (goalPaths.size() == 0 || (currentPaths.smallest().getPathCost() < goalPaths.smallest().getPathCost())) )
        {
            if(debug) //Prints out the paths we can currently chooose from if debugging is enabled
            {
                std::cout << "Candidate Paths:\n";
                printSetPath(currentPaths);
            }

            if(currentPaths.size() == 0) //If we have no paths left then the graph must be disjoint, set flag and exit loop
            {
                exhaustedAllPaths = true; //Exits loop because there is no more paths to choose from
            }
            else
            {
                Path shortestPath = currentPaths.smallest(); //From the available paths find the smallest one

                if(debug) //Print the path we have found for debugging
                {
                    std::cout << "Selected shortest path:";
                    printPath(shortestPath);//Printout the path we chose
                }

                if(shortestPath.peak() == endVertex.first) //check if the vertex at the current end of the path is the goal
                {
                    //If the path contains the goal at the end
                    goalFound = true; //We did find a goal
                    goalPaths.insert(shortestPath); //Add the found path to the list of goal paths
                    currentPaths = currentPaths - goalPaths; //Remove the goal path from the current set of paths so we don't choose it again
                }
                else //The path chosen doesn't have the goal vertex at the end
                {
                    //Get the neighbours of the node at the end of the current path so we can continue down the path
                    Set<Vertex> neighbours = searchGraph.neighbours(shortestPath.peak().getName());
                    Set<Vertex> shortestPathAsSet;

                    /*
                    Bit of a hack, need to covert the current path from a stack object to a set.
                    That way we can remove any vertexs that are already in the path, i.e don't go
                    back to the vertex you came from.
                    */
                    for(Iterator<Vertex> iT = shortestPath.begin(); iT != shortestPath.end(); ++iT)
                    {
                        shortestPathAsSet.insert(iT.getData()); //Create the set
                    }
                    neighbours = neighbours - shortestPathAsSet; //Remove the already visited neighbours from the possible choices

                    if(neighbours.size() == 0) //If there are no neighbours to choose from this is a deadend so add it to the deadend paths and remove it from the possible choises
                    {
                        deadEndPaths.insert(shortestPath); //add the current path to the deadends list
                        currentPaths = currentPaths - deadEndPaths; //remove the dead end path from the choices of paths
                    }
                    else
                    {
                        //There are valid neighbours we can visit from this path
                        for(Iterator<Vertex> iT = neighbours.begin(); iT != neighbours.end(); ++iT)
                        {
                            /*
                            For each vertex in the possible candidates create a copy of the current path then add that candidate to the
                            end of the copy path, creating a new path to choose from
                            */
                            Vertex currentVertex = iT.getData(); //Get a neighbour
                            Vertex topVertex = shortestPath.peak(); //Get the current top vertex
                            Edge tmp = searchGraph.getEdge(topVertex.getName(), currentVertex.getName() );
                            //Find the edge that contains these two vertices so we can get the edge weight

                            Path tmpPath = shortestPath; //Make a copy of the current path
                            tmpPath.add( currentVertex, tmp.getWeight()); //add the vertex and it's weight to the path
                            if(tmpPath.peak() == goalVertex) //If the new path we explore is the goal add it to the goalpaths
                            {
                                goalPaths.insert( tmpPath );//add it
                            }
                            else
                            {
                                currentPaths.insert( tmpPath );//else just add the path to the set
                            }

                        }
                        currentPaths = currentPaths - shortestPath; //remove the path we used to get the new ones from the choice of paths
                    }
                }
            }
        }

        std::cout << "Dead end paths size:" << deadEndPaths.size() << std::endl;
        //Prints out the dead end paths to the user

        std::cout << "Deadend paths:\n";
        printSetPath(deadEndPaths);


        std::cout << "\nPartial paths size:" << currentPaths.size() << std::endl;

        //Print out whatever paths are left over which where never finieshed exploring
        std::cout << "Partial paths:\n";
        printSetPath(currentPaths);


        //Get the shortest goal path, ie the optimal path
        Path shortestPath = goalPaths.smallest();

        //Remove the optimal path the the set of solutions
        goalPaths = goalPaths - shortestPath;

        //Prints out the other possible solutions
        std::cout << "\nSolution paths:";
        printSetPath(goalPaths);
        //Print out final solution

        //If there was a shortest past or we didn't exhaust all the paths
        if(!exhaustedAllPaths || shortestPath.size() > 0)
        {
            //Print out hte final solution
            std::cout << std::endl << "Final solution:";
            printPath(shortestPath);
        }
        else
        {
            //Else tell the user we couldn't find the goal and that means the graph is disjoint
            std::cout << "Exhausted all possible paths and couldn't find the goal node, this means your graph is made of two disjoint sub graphs, and the start and end node are in different subgraphs" << std::endl;
        }
    }
    else
    {
        //Tell the user they screwed up the input
        std::cout << "The start or end vertex you specified doesn't exist in the graph please check your input, or graph files" << std::endl;
    }

}

//Give a a set of paths print out all the paths in that set
void BranchSearch::printSetPath(Set<Path> inSet)
{
    for(Iterator<Path> iT = inSet.begin(); iT != inSet.end(); ++iT)
    {
        //Get each path from the set then pass it to the print path function
        printPath(iT.getData());
    }
}

//Takes in a path and prints it out to the user
void BranchSearch::printPath(Path inPath)
{
    //because a path is a stack, the order is wrong so reverse the order
    Path tmp = inPath.reversePath();
    while(tmp.size() > 0)
    {
        //While there is still things left in the path keep printing them out
        std::cout << tmp.pop().getName();//get the top vertex and print out
        if(tmp.size() > 0)
        {
            std::cout << "->"; //if that's not the last vertex add a arrow to show the path to the next in the output
        }
    }
    std::cout << " cost:" << tmp.getPathCost() << std::endl; //print out the path cost

}
