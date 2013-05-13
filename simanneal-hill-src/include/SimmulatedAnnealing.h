/*SimulatedAnnealing.cpp
Brock York 14840261
AMI 300 Assignment Simulated Annealing Search
Definition of the Simulated annealing class
used to search a given 3D map for a global maxima
*/
#ifndef SIMMULATEDANNEALING_H
#define SIMMULATEDANNEALING_H

#include <string>

#include "LinkedList.h"
#include "Point.h"


class SimmulatedAnnealing
{
    public:
        SimmulatedAnnealing(); //Defaul Constructor
        virtual ~SimmulatedAnnealing(); //Destructor

        bool loadMap(std::string filepath); //Loads the given map ready to search
        void loadArray(LinkedList<Point> list, int countX, int countY); //Creates the map array from the points loaded from the map file
        void search(); //Search the map for the maxima
        void setTemperatureDecrement(float newDec); //Modify the starting temperature of the search
        void setTemperature(float newTemp); //Modify how much the temperature cools by each iteration
    protected:
    private:
        Point** theMap; //The list of points in the map
        int numX;       //How many points in the X direction
        int numY;       //How many point in the Y direction
        float tempDecrement; //Holds ow much to decrement the temperatute by
        float temperature; //The temperature of the search
        int largest;    //used for testing and keeping track of largest possible value for comparison to value found
};

#endif // SIMMULATEDANNEALING_H
