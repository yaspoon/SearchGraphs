#include "SimmulatedAnnealing.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "Point.h"
#include "LinkedList.h"

#include "cmath"

extern bool debug; //Do we print debug messages to the user
extern bool testing; //Used to run bulk tests on the search and compare its results

/*
Default constrcutor sets up sane defaults for
the temperature decrement and temperature variables
*/
SimmulatedAnnealing::SimmulatedAnnealing()
{
    tempDecrement = 1.0f;
    temperature = 100.0f;
}

SimmulatedAnnealing::~SimmulatedAnnealing()
{

}

/*
Takes in a file path then attempts to open and load the points
found in that file, the loaded points are put into a linked list
to then be put into the map array
*/
bool SimmulatedAnnealing::loadMap(std::string filepath)
{
    std::fstream mapfile; //File stream to use for the map file
    bool retVal = false; //Did we succedd in loading a map

    LinkedList<Point> tmpMap; //Linked list to hold the points loaded from the map

    mapfile.open(filepath.c_str(), std::ios::in); //Attempt to open the map file

    largest = 0; //What is the largest Z point possible in the map, used for comparison to what the search actually finds

    int prevX = 0; //The previos X point that was loaded from the map file, used to determine how large the array needs to be in the X direction

    int countX = 0; //How many Y points are there
    int countY = 0;

    bool firstX = true; //Is this the first X coordinate that has been loaded, used for counting the X

    if(mapfile.is_open()) //Check if the map file opened successfully
    {
        do  //While there is more stuff to read from the file keep reading
        {
            std::string line; //Temporary storage of the line read from the file
            std::getline(mapfile, line); //Read a line

            if(!mapfile.fail()) //If it didn't fail to read try to get the values
            {
               int x; //temporary storage
               int y;
               int z;

                std::stringstream convert(line); //Conver the line into a string stream

                convert >> x;       //Try to read the X coordinate
                if(!convert.fail()) //If it succeeded in reading the x coordinate continue loading
                {
                    convert >> y;       //Ditto for Y
                    if(!convert.fail())
                    {
                        convert >> z; //Ditto for z
                        if(z > largest) //Is this the largest Z we have come accross
                        {
                            largest = z; //yes it is store it for reference later
                        }
                    }
                }

                Point newPoint; //Create a new point from the given values
                newPoint.x = x;
                newPoint.y = y;
                newPoint.z = z;

                if(debug) //Tell the user about the new point in debug mode
                {
                    std::cout << "Created new point(" << x << "," << y << "," << z << ")" << std::endl;
                }

                if(x != prevX || firstX) //If the x value has changed and it's not the first, increment the x counter
                {
                    firstX = false;
                    prevX = x;
                    countX++;
                }

                tmpMap.pushBack(newPoint);
            }
        }
        while(!mapfile.eof()); //While there is stuff to read

        countY = tmpMap.noElements() / countX; //The number of Y coordinates is the total lines read / number of x unique coordinates

        loadArray(tmpMap, countX, countY); //Create the map array from the given linked list

        if(debug) //Tell the user the stuff we found if in debug mode
        {
            std::cout << "size of map:" << tmpMap.noElements() << std::endl;
            std::cout << "Largest z value loaded from list:" << largest << std::endl;
        }

        retVal = true; //return true if we loaded successfully

        mapfile.close(); //Close the map file we read
    }
    else //Failed to open the file, let the user know
    {
        std::cout << "Failed to open specified map file:" << filepath << std::endl;
    }

    return retVal;
}

/*
Takes in the link list of points and then creates a
array from the points, this allows O(1) lookup and alot
easy to find neighbours
*/
void SimmulatedAnnealing::loadArray(LinkedList<Point> list, int countX, int countY)
{
    numX = countX;
    numY = countY;
    theMap = new Point*[countX]; //Create a array of pointers because it will be a 2D array

    for(int i = 0; i < countX; i++)
    {
        theMap[i] = new Point[countY];  //Filled the 2D array with points
    }

    Point start = list.begin().getData(); //Get the start point
    int currentX = start.x; //Set the currentX to start with

    int i = 0;
    int j = 0;

    for(Iterator<Point> iT = list.begin(); iT != list.end(); ++iT) //Iterate over the list to create the array
    {
        Point temp = iT.getData(); //Get the next point from the list

        if(temp.x == currentX) //If the X is the same as the previous
        {
            theMap[i][j] = temp; //Add this point to the end
            j++;
        }
        else //Else this is a new X so change the X value then add the point
        {
            currentX = temp.x;
            i++;
            j = 0;

            theMap[i][j] = temp;
            j++;
        }
    }

    /*
    If debug is enabled output the points we created for the map
    */
    if(debug)
    {
        for(int i = 0; i < countX; i++)
        {
            for(int j = 0; j < countY; j++)
            {
                std::cout << "Point[" << theMap[i][j].x << "," << theMap[i][j].y << "," << theMap[i][j].z << "]" << std::endl;
            }
        }
    }

}

/*
Sets the temperature to use during search
*/
void SimmulatedAnnealing::setTemperature(float newTemp)
{
    temperature = newTemp;
}

/*
Set the devrementing factor or cooling of the searching
*/
void SimmulatedAnnealing::setTemperatureDecrement(float newDec)
{
    tempDecrement = newDec;
}

/*
The actual search function that finds the maxima
by randoming over the map until it runs out of energy
*/
void SimmulatedAnnealing::search()
{
    std::fstream outputFile;
    outputFile.open("./seq.txt", std::ios::out); //Outputs the path we took to get to the goal

    int probCount = 0; //How many times did we accept a bad node
    Point largestPoint; //Keeps a track of the largest point we came accross for comparing to the final point it came to

    if(outputFile.is_open())
    {
        srand(time(NULL)); //Initialise random number

        Point currentPoint = theMap[rand() % numX][rand() % numY]; //Choose a random point on the map and bound the possible points by the size of the array bounds
        largestPoint = currentPoint; //Set the largest point found so far to the current selected on

        if(debug)
        {
            std::cout << "Starting temperature " << temperature << std::endl;
            std::cout << "Temperature decrement " << tempDecrement << std::endl;
            std::cout << "Starting point [" << currentPoint.x << "," << currentPoint.y << "," << currentPoint.z << "]" << std::endl;
        }

        outputFile << currentPoint.x << " " << currentPoint.y << " " << currentPoint.z << std::endl; //Dont' forget to add this point to the list we visited

        while(temperature > 0) //While we are still hot keep searching!
        {
            Point next = theMap[rand() % numX][rand() % numY]; //Randomly choose the next point

            int energy = next.z - currentPoint.z; //Check how much "energy" the new point has, ie is it a better value

            if(energy > 0) // if the energy is larger always choose it
            {
                outputFile << next.x << " " << next.y << " " << next.z << std::endl; //Add this point to the output file

                if(next > largestPoint) //Check if it's the largest we have visited, for comparison later
                {
                    largestPoint = next;
                }

                currentPoint = next; //Set the current point to this new better point
            }
            else //The energy is lower but we may still choose it if the probability is right
            {
                float probability = exp(energy/temperature); //Calculate the probaility we should choose this bad point
                probability = probability * 100; // turn it to a percentage
                if(probability > rand() % 100) //Random a number and if the probability is larger then the random probablilty then choose this bad node
                {
                    probCount++; //Keep track of how many bad nodes we choose

                    currentPoint = next; //set the current point to the bad one

                    if(next > largestPoint) //See if this is the largest point we have visited, this should never trigger or something went screwy
                    {
                        largestPoint = next;
                    }

                    outputFile << next.x << " " << next.y << " " << next.z << std::endl; // output this point as part of the path it chose
                }
            }

            temperature = temperature - tempDecrement; //Decrement the temperature so we eventually stop
        }

        if(debug) //Output we chose a bad point
        {
            std::cout << "Chose a bad point " << probCount << " times" << std::endl;
        }

        //Output the final findings to the user
        std::cout << "Largest point we crossed:" << largestPoint.x << "," << largestPoint.y << "," << largestPoint.z << std::endl;
        std::cout << "Current point at end of search:" << currentPoint.x << "," << currentPoint.y << "," << currentPoint.z << std::endl;

        outputFile.close(); //Close the point outputfile

        if(testing) //If we are running bulk tests output to this test file we can do averages
        {
            if(largest == currentPoint.z)
            {
                std::fstream testFile;
                testFile.open("./testing", std::ios::out | std::ios::app);
                testFile << "true" << std::endl; //write true to the file if we did find the largest possible value
                testFile.close();
            }
        }
    }
    else //We couldn't open the output file so tell the user and exit
    {
        std::cout << "Failed to open output file seq.txt" << std::endl;
    }
}
