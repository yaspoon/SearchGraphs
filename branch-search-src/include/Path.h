/*Path.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Defines the Path class so that other
objects can interface with the path objects
It is core to the branch and bound search
because it holds one of the current paths that branch and bound is exploring
*/
#ifndef PATH_H
#define PATH_H

#include "Vertex.h"
#include "Stack.h"


class Path
{
    public:
        Path();
        virtual ~Path();

        void add(Vertex inVertex, float cost);
        Vertex peak();
        Iterator<Vertex> begin();
        Iterator<Vertex> end();
        Vertex pop();

        bool operator==(Path inPath);
        bool operator!=(Path inPath);
        bool operator<(Path inPath);

        Path reversePath();

        void push(Vertex inVertex);

        float getPathCost();
        int size();

    protected:
    private:
        Stack<Vertex> thePath;
        float pathCost;
        void setPathCost(float cost);
};

#endif // PATH_H
