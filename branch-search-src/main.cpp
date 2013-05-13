/*Main.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
The main gets input from the user then uses that input
to load the graph and then start the search algorithm.
Like all programs that are usefull, they start in the main
*/
#include <iostream>
#include "Graph.h"
#include "Common.h"
#include <string.h>
#include "Edge.h"
#include "Vertex.h"
#include "BranchSearch.h"

using namespace std;

bool debug; //Global flag whether to print out debugging information

int main(int argc, char* argv[])
{
    debug = false;  //By default they probably don't want verbose output
    bool badInput = true;   //Bad input is used to keep asking for input till a graph can successfuly be loaded i.e bug user till it works.

    //These hold the input from the user for use in the graph/search for searching.
    string startVertex;
    string endVertex;
    string graphpath;
    string heurpath;

    //The graph object used to load the graph data file and used by the search algorithm to traverse the graph
    Graph greedyGraph;

    //Flags to tell if input was passed from the command line so we can skipp asking the user for it
    bool graphFlag = false; //These are used to keep track of whether or not the argument was set from the command line
    bool heurFlag = false;
    bool startFlag = false;
    bool endFlag = false;

    //Read any flags from the command line and set the appropriate option
    for(int i = 0; i < argc; i++)
    {
        if(strcmp((argv[i]), "-debug") == 0)    //Check if debug flag passed
        {
            cout << "Enabling debug mode" << endl;
            debug = true;
        }

        if(strcmp((argv[i]), "-graph") == 0)    //Check if graph path was passed
        {
            cout << "Setting graph path to " << argv[i+1] << endl;
            graphpath = argv[i+1];
            graphFlag = true;
        }

        if(strcmp((argv[i]), "-heuristic") == 0)    //CHeck if heuristic path was passed
        {
            cout << "Setting heuristic path to " << argv[i+1] << endl;
            heurpath = argv[i+1];
            heurFlag = true;
        }

        if(strcmp((argv[i]), "-start") == 0)    //Did the user give us a starting vertex
        {
            cout << "Setting start vertex to " << argv[i+1] << endl;
            startVertex = argv[i+1];
            startFlag = true;
        }

        if(strcmp((argv[i]), "-end") == 0)  //Did the user give us a end vertex
        {
            cout << "Setting end vertex to " << argv[i+1] << endl;
            endVertex = argv[i+1];
            endFlag = true;
        }


    }

    if(!graphFlag || !heurFlag) //If it wasn't set on the command line ask nicely for input
    {
        while(badInput) //If the graph failed to load properly keep asking for valid input
        {
            cout << "Enter the path to the graph file to load" << endl;
            cin >> graphpath;
            cout << "Enter the path to the heuristics file to load" << endl;
            cin >> heurpath;
            if(greedyGraph.createGraph(graphpath.c_str(), heurpath.c_str())) //Try and load the given fails and create a graph, keep asking for input and try again
            {
                badInput = false;
            }
            else
            {
                cout << "Failed to create graph, please try again" << endl;
                greedyGraph = Graph(); //Create a new fresh graph incase things were left over
            }
        }
    }
    else
    {
        do
        {
            if(greedyGraph.createGraph(graphpath.c_str(), heurpath.c_str()))    //If we get here the user passed command line arguments for graph and heur and we try and create a graph from those arguments
            {
                badInput = false; //If the graph successfully loaded then exit the loop and move onto the start/end node inut
            }
            else
            {
                //If we get here the graph failed to load, ask for input and try again till it's right
                cout << "Failed to create graph, please try again" << endl;
                greedyGraph = Graph(); //Create a new graph incase things were left over
                cout << "Enter the path to the graph file to load" << endl;
                cin >> graphpath;
                cout << "Enter the path to the heuristics file to load" << endl;
                cin >> heurpath;
            }
        }
        while(badInput);//While the graph fails to load keep asking for input
    }

    if(!startFlag) //If the start vertex wasn't passed on the command line ask for it
    {
        cout << "Enter the starting vertex:" << endl;
        cin >> startVertex;
    }

    if(!endFlag) //Ditto but for the end vertex
    {
        cout << "Enter the goal vertex:" << endl;
        cin >> endVertex;
    }


    BranchSearch theSearch; //Create a greedy search object so we can do a search
    theSearch.setGraph(greedyGraph); //Give it the graph we loaded
    theSearch.search(startVertex, endVertex); //Tell it to search for a path from the given start vertex to the given end vertex

    return 0; //If get here let the calling program know we didn't fail miserably.
}
