/*Stack.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Implements a generic Stack data structure
It uses the linkedlist object
To hold the data and always pushes to the front
and pops from the front of the list
*/
#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template<class T>
class Stack
{
    public:
        Stack() //Default constructor doesn't need to do anything
        {

        }

        virtual ~Stack() //Destructor
        {

        }

        void push(T element) //Push the given element to the front of the list i.e top of the stack
        {
            theStack.pushFront(element); //Tell the list to push this to the front
        }

        T pop() //Get the element on the top of the stack remove it and give it to the caller
        {
            return theStack.popFront(); //Ask the list to do the work for us <3
        }

        T peak() //Look at what is on top of the list, but don't remove it and return it to the caller
        {
            T tmp; //Object to return to caller
            if(size() > 0) //If the list isn't empty
            {
                tmp = theStack.begin().getData(); //Get a iterator to the start of the list and get a copy of the top object
            }

            return tmp; //Return the object, can be a blank object if the list is empty!
        }

        Iterator<T> begin() //Get a iterator to the start of the stack from the list it contains
        {
            return theStack.begin();
        }

        Iterator<T> end() //Get a iterator to the end of the stack, this way you can compare to iterators to check if it has reached the end of the list
        {
            return theStack.end();
        }

        bool operator==(Stack<T> inStack) //Compare this stack with the given one for equality
        {
            bool retVal = true; //By default assume they are equivalent, easier to implement via contradiction
            if(this->size() == inStack.size()) //If they're not the same size they're not equal
            {
                Iterator<T> thisiT;
                Iterator<T> iT;

                //Get a iterator to each stack, then compare each element in order if one doesn't match then the stacks dont match
                //ie via contradiction Exists(x) where Stack1.Not(x) || Stack2.Not(x) is true
                for(thisiT = theStack.begin(),iT = inStack.begin(); thisiT != theStack.end() && iT != inStack.end(); ++thisiT, ++iT)
                {
                    if(thisiT.getData() != iT.getData())
                    {
                        retVal = false;
                    }
                }
            }
            else
            {
                retVal = false; //They're not the same size, not equal then
            }

            return retVal;
        }

        int size() //Returns the size of the list
        {
            return theStack.noElements();
        }
    protected:
    private:
        LinkedList<T> theStack; //The list that the stack wraps around
};

#endif // STACK_H
