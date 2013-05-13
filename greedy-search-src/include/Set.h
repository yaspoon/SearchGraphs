/*Set.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Generic set class implemented using templates
Allows you to create a set from any given objects
As long as the given objects can compare each other
ie implement == and != functions
Used extensively in the graph and greedysearch objects
for searching
*/
#ifndef SET_H
#define SET_H

#include "LinkedList.h"
#include "Pair.h"
#include "Stack.h"

template <class T>
class Set
{
    public:
        Set()//Default constructor
        {

        }

        virtual ~Set() //Destructor
        {

        }

        bool insert(T newElement) //Inserts a given element into the set if it doesn't already exist in the set, this set implentation has unique elements
        {
            bool retVal = false; //By default assume we failed to insert

            if(find(newElement).second == false) //Search the list to check if the element isn't already in the set
            {
                currentSet.pushFront(newElement); //We didn't find the element in the set so add it
                retVal = true;
            }

            return retVal;
        }

        //Total rip off of std pair but whatevs <3 std libs
        //Searches the set for a given element and returns a pair object which contains the found element and true
        //or the second element in the pair is set to false
        Pair<Iterator<T>, bool> find(T element)
        {
            Pair<Iterator<T>, bool> retVal; //Return object for the user
            retVal.first = currentSet.end(); //By default if nothing is found the end of the set is returned.
            retVal.second = false; //By default we didn't find it

            for(Iterator<T> iter = currentSet.begin(); iter != currentSet.end(); ++iter) //Iterate over the list
            {
                T tmp = iter.getData(); //Get the current element
                if(tmp == element) //Test If it's the element we are after
                {
                    retVal.first = iter; //Set the return object to the one we found
                    retVal.second = true; //Say we found the object
                }

            }

            return retVal;
        }

        Iterator<T> begin() //Returns a iterator to the start of the list
        {
            return currentSet.begin();
        }

        Iterator<T> end() //Returns a iterator to the end of the list
        {
            return currentSet.end();
        }

        int size() //Get the size of the set
        {
            return currentSet.noElements();
        }

        Set<T> operator-(Set<T> inSet) //Subtract a given set from this one and return the new set, used in the greedysearch to remove neighbours we've already been to
        {
            Set<T> tmp; //Set to return
            for(Iterator<T> iT = currentSet.begin(); iT != currentSet.end(); ++iT) //Iterate over this set
            {
                Pair<Iterator<T>, bool> vert = inSet.find(iT.getData()); //If the current element isn't in the other set then add it to the set to return
                if(vert.second == false) //If we don't find the element within the given set
                {
                    tmp.insert(iT.getData()); //Insert the element into the return set
                }
            }

            return tmp;
        }

        //Subtracts a stack object from this set, used in greedysearch to remove any vertexs already within current search path so it doesn't go
        //back to them when neighbours is called
        Set<T> operator-(Stack<T> inStack)
        {
            Set<T> tmp;
            Set<T> theSet;
            theSet.currentSet = currentSet;

            //Get all the elements from the stack and put them into a set so we can then call the
            // set - set function, code reuse ;)
            while(inStack.size() > 0)
            {
                tmp.insert(inStack.pop()); //Insert stack element into tmp set
            }

            return theSet - tmp; //Subtract the two sets from each other
        }

        //Finds the smallest element within the set, used by greedy search to find which neighbour
        //of the current node has the smallest heuristic and which it should choose
        T smallest()
        {
            T small = currentSet.begin().getData(); //By default set the smallest to the start of the list

            for(Iterator<T> iT = currentSet.begin(); iT != currentSet.end(); ++iT) //Iterate over the set comparing each element
            {
                if(iT.getData() < small) //If the current element is smaller then the current smallest, then set smallest to the current found element
                {
                    small = iT.getData();
                }
            }

            return small;
        }



    protected:
    private:
        LinkedList<T> currentSet; //The linkedlist that the set wraps around
};

#endif // SET_H
