/*BranchSearch.
Brock York 14840261
AMI 300 Assignment Greedy Search
Definition for the BranchSearch class
Defines the interface to a branchSearch object.
Used to search a given graph using the branch and bound method
*/
#ifndef BRANCHSEARCH_H
#define BRANCHSEARCH_H

#include "Graph.h"


class BranchSearch
{
    public:
        BranchSearch();
        virtual ~BranchSearch();
        void setGraph(Graph inGraph);
        void search(std::string startVertex, std::string goalVertex);
        void printSetPath(Set<Path> inSet);
        void printPath(Path inPath);
    protected:
    private:
        Graph searchGraph;
};

#endif // BRANCHSEARCH_H
