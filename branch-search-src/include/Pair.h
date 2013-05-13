/*Pair.h
Brock York 14840261
AMI 300 Assignment Greedy Search
Pair object implemented as a template class
It is used to pass back more then on object upon return
It can hold upto two different objects whose type are
declared when the pair is created
i.e Pair<Vertex, bool> will create a pair that holds
a vertex in first and boolean in second
*/
#ifndef PAIR_H
#define PAIR_H

template <class T, class U>
class Pair
{
    public:
        Pair()
        {

        }

        virtual ~Pair()
        {

        }

        T first; //Has no accessors everyone has direct access if they hold the object
        U second;//It's not good by programming standards but it works well it's a very simple object
    protected:
    private:
};

#endif // PAIR_H
