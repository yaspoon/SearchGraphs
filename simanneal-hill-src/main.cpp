/*Main.cpp
Brock York 14840261
AMI 300 Assignment Simulated Annealing Search
Starting point of the program, receives input from the
user then passes this input to the search program and then begins
the search
*/

#include <iostream>
#include "SimmulatedAnnealing.h"
#include <fstream>
#include <string.h>

using namespace std;

bool debug;
bool testing;

int main(int argc, char* argv[])
{
    debug = false;
    testing = false;
    SimmulatedAnnealing simsearch;
    std::fstream mapfile;
    std::string filepath;
    bool filePathSet = false;

    for(int i = 0; i < argc; i++) //Read in the command line args so we don't have to retrieve them interactively
    {
        if(strcmp(argv[i], "-debug") == 0) //should we ouput debug info
        {
            debug = true;
        }

        if(strcmp(argv[i], "-map") == 0 || strcmp(argv[i], "-m") == 0) //Did the user specify a map
        {
            if(argc >= (i + 1) )
            {
                filePathSet = true;
                filepath = argv[i+1];
            }
        }

        if(strcmp(argv[i], "-startTemp") == 0) //set the defaul start temperature
        {
            if(argc >= (i + 1) )
            {
                simsearch.setTemperature(atof(argv[i+1]));
            }
        }

        if(strcmp(argv[i], "-tempDec") == 0) //set the temperature decrement or cooling
        {
            if(argc >= (i + 1) )
            {
                simsearch.setTemperatureDecrement(atof(argv[i+1]));
            }
        }

        if(strcmp(argv[i], "-testing") == 0) //set the temperature decrement or cooling
        {
            testing = true;
        }
    }

    bool loaded = false; //while we haven't successfully loaded a file keep prompting the user

    while(!loaded)
    {
        if(!filePathSet) //if the file path wasnt set prompt the user for one
        {
            std::cout << "Please enter the map file path" << std::endl;
            std::cin >> filepath;
        }

        if(simsearch.loadMap(filepath)) //attempt to load the given file
        {
            loaded = true;
        }
        else //keep prompting the user till it succeeds
        {
            std::cout << "Failed to load map file specified on command line try again" << std::endl;
            filePathSet = false;
        }

    }

    simsearch.search(); //Do the search on the given map
    return 0;
}
