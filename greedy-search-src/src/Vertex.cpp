/*Vertex.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
Implements the vertex object functions
Vertex is used in both edges and standalone
within the graph object
*/
#include "Vertex.h"
#include <cmath>

Vertex::Vertex() //Default Constructor not very useful
{
    //ctor
}

Vertex::Vertex(std::string vertName) //Constructor Sets the name of the vertex
{
    name = vertName; //Gives the vertex the input name
    heuristic = -1; //Sets the heuristic to a default "NULL" value
}

Vertex::Vertex(std::string vertName, float vertHeuristic) //Constructor with both vertex name and heuristic given
{
    name = vertName; //Set name to given one
    heuristic = vertHeuristic; //Set heuritistic to given one
}

Vertex::Vertex(const Vertex& inVert):
name(inVert.name), heuristic(inVert.heuristic)
{

}

Vertex::~Vertex() //Destructor
{
    //dtor
}

void Vertex::setName(std::string newName) //Sets the vertexs name pretty self explanatory
{
    name = newName;
}

void Vertex::setHeuristic(float newHeuristic) //Sets the heuristic for this vertex
{
    heuristic = newHeuristic;
}

std::string Vertex::getName() //Returns the vertexs name used for comparing objects in some functions
{
    return name;
}

float Vertex::getHeuristic() //Returns the heuristic to the caller used in choosing what vertex to expand next
{
    return heuristic;
}

bool Vertex::operator==(Vertex inVertex) //Compares this vertex object to the given one
{
    bool retVal = false; //Assume they arn't equal by default
    float tollerance = 0.001f; //Needed for float comparison

    if( name == inVertex.getName()) //Compare the names
    {
        if( fabs(heuristic - inVertex.getHeuristic()) < tollerance) //If the names are the same check the heuristic distance
        {
            retVal = true; //They are equal in name and heuristic
        }
    }

    return retVal;
}

bool Vertex::operator!=(Vertex inVertex) //Same as == operator but checks if this vertex is not equal to the other
{
    bool retVal = false;

    if( name != inVertex.getName() || heuristic != inVertex.getHeuristic())
    {
        retVal = true;
    }

    return retVal;
}

void Vertex::operator=(Vertex inVert) //Copies the data from the given vertex into this one
{
    name = inVert.getName();
    heuristic = inVert.getHeuristic();
}

bool Vertex::operator<(Vertex inVert) //Checks if the given vertex is larger then this one
{
    bool retVal = true; //Assume it is less than
    //float tollerance = 0.001;

    if( (heuristic - inVert.getHeuristic()) > 0) //If the heuristic - the givens one is greater then 0 this object is larger
    {
        retVal = false;
    }

    return retVal;
}
