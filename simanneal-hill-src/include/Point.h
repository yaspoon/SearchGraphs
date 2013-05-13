/*Point.h
Brock York 14840261
The definition of the point class
used by the search program to hold the point
data loaded from the map
*/
#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(); //Default constructor
        virtual ~Point();//Destructor
        bool operator>(Point inPoint);//check if the inpoint is less then this one
        int x; //x coordinate
        int y; //y coordinate
        int z; //z coordinate
    protected:
    private:
};

#endif // POINT_H
