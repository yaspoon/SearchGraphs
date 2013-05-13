/*Point.cpp
Brock York 14840261
Simple class to holds the points
found in the map file.
Points can also be compared to each other
for which is larger
*/
#include "Point.h"

Point::Point()
{
    //ctor
}

Point::~Point()
{
    //dtor
}

/*
Test if the given point is less
then this current one
*/
bool Point::operator>(Point inPoint)
{
    bool retVal = false;

    if(this->z > inPoint.z) //if this point is larger in the z direction (the only direction we care about) then set it to true
    {
        retVal = true;
    }

    return retVal;
}
