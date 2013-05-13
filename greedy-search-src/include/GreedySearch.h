/*GreedySearch.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Header definition of GreedySearch object
Defines the interface to the search object
Which is called by main to search the graph
*/
#ifndef GREEDYSEARCH_H
#define GREEDYSEARCH_H

#include "Graph.h"


class GreedySearch
{
    public:
        GreedySearch(); //Default constructor nothing to setup
        virtual ~GreedySearch();//Destructor
        void setGraph(Graph inGraph); //Set the graph object so we can search it
        void search(std::string start, std::string end); //Search the graph and find the path from the start and end if a path exists
    protected:
    private:
        Graph searchGraph; //The graph searched
};

#endif // GREEDYSEARCH_H
