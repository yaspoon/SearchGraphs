/*Vertex.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Vertex.h holds the class definition for the
Vertex object the vertex holds all the
information required to describe a vertex
Which is then used in edges as well
*/
#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Vertex
{
    public:
        Vertex();
        Vertex(std::string vertName);
        Vertex(std::string vertName, float vertHueristic);
        virtual ~Vertex();

        void setName(std::string newName);
        void setHeuristic(float newHeuristic);
        std::string getName();
        float getHeuristic();

        void copy(Vertex copyVert);

        bool operator==(Vertex inVert);
        bool operator!=(Vertex inVert);
        void operator=(Vertex inVert);
        bool operator<(Vertex inVert);
    protected:
    private:
        std::string name;
        float heuristic;
};

#endif // VERTEX_H
