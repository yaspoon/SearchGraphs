/*Path.cpp
Brock York 14840261
AMI 300 Assignment Greedy Search
Implements the functionality of the path
object. The path object is core to the branch and bound
search because it is used to determine a path and it's cost
this allows the search to easily find the smallest path cost
*/
#include "Path.h"

Path::Path()//default ocnstructor
{
    pathCost = 0; //the paths cost starts at 0
}

Path::~Path() //deconstructor
{
    //dtor
}

//Add a vertex to the path and add the cost to the total cost
void Path::add(Vertex inVertex, float cost)
{
    thePath.push(inVertex);
    pathCost = pathCost + cost;
}

//Returns the current end of the path and removes it from the path
Vertex Path::pop()
{
    return thePath.pop();
}

//Returns the end of the path but doens't remove it.
//used for finding neighbours
Vertex Path::peak()
{
    Vertex retVal;

    retVal = thePath.peak();

    return retVal;
}

//Returns a iterator object for this path object
Iterator<Vertex> Path::begin()
{
    return thePath.begin();
}

/*returns a iterator that points to the end of the list useful
useful for iterating over the path so the iterator knows when it's at the end
*/
Iterator<Vertex> Path::end()
{
    return thePath.end();
}


//Get the size of the path (The number of vertices in the path)
int Path::size()
{
    return thePath.size();
}


//Compares this path with a given one for equality
bool Path::operator==(Path inPath)
{
    bool retVal = true; //by default tey're equal
    if(size() == inPath.size()) //If they have the same number of elements
    {

        /*
        Get a iterator to both paths, the get each element in order and compare them to each other
        if all the elements match in the same order that paths are equal
        */
        Iterator<Vertex> iT = thePath.begin();
        Iterator<Vertex> inPathiT = inPath.begin();

        for(; iT != thePath.end() && inPathiT != inPath.end(); ++iT, ++inPathiT)
        {
            if(iT.getData() != inPathiT.getData())
            {
                retVal = false;
            }
        }
    }
    else //they don't have the same amount for elements so not equal
    {
        retVal = false;
    }

    return retVal;
}


/*
COmpare this path to the given one for inequality
*/
bool Path::operator!=(Path inPath)
{
    bool retVal = false;

    //Check if the number of elements is the same
    if(size() == inPath.size())
    {
        /*
        Get a iterator to each list and compare their elements if at least one
        set of elements don't match return true that they are inequal
        */
        Iterator<Vertex> iT = thePath.begin();
        Iterator<Vertex> inPathiT = inPath.begin();

        for(; iT != thePath.end() && inPathiT != inPath.end(); ++iT, ++inPathiT)
        {
            if(iT.getData() != inPathiT.getData())
            {
                retVal = true;
            }
        }
    }
    else //THey're not equal in size so return true
    {
        retVal = true; //Just to make sure ;)
    }

    return retVal;

}

/*Compare this path with another to test if it less then the other
This path is smaller if it's cost is less then the others or
if the cost is the same if it has less elements it is less
if the cost and numver of elements is the same compare the last element
and see which is smaller, else this is larger by default
*/
bool Path::operator<(Path inPath)
{
    bool retVal = false;

    if( (pathCost - inPath.getPathCost()) < 0.001 && (pathCost - inPath.getPathCost()) > -0.001 )//Check If they are equal in cost
    {
        if(this->size() < inPath.size()) //If this one is smaller in size
        {
                retVal = true;
        }
        else
        {   //We need to do a tie breaker because they seem exactly the same, check there first elemetn and see which is smaller
            if(this->peak().getName() < inPath.peak().getName())
            {
                retVal = true;
            }
        }

    }
    else
    {
        //if the path costs are equal check if this ones is smaller
        if( pathCost < inPath.getPathCost())
        {
            retVal = true;
        }
    }


    return retVal;
}

//Return the current cost of the path
float Path::getPathCost()
{
    return pathCost;
}

//PUsh a vertex onto the path
//helper function for printing stuff out
void Path::push(Vertex inVertex)
{
    thePath.push(inVertex);
}

/*Another helper functions for printing out
Reverses the current path so it makes sense when it is
printed out
*/
Path Path::reversePath()
{
    Path tmp;

    while(thePath.size() > 0)
    {
        tmp.push(thePath.pop());
    }

    tmp.setPathCost(pathCost);

    return tmp;
}

//used for transfer another path into this one
//sets the current path cost to the one passed in
void Path::setPathCost(float cost)
{
    pathCost = cost;
}
