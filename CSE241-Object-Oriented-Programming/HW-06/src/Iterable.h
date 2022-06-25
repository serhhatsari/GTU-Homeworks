#ifndef ITERABLE_H
#define ITERABLE_H

#include "GTUIterator.h"
#include "GTUIteratorConst.h"

namespace GTU_SARI
{

    template <class T>
    class Iterable
    { // ABSTRACT ITERABLE CLASS
    public:
        virtual bool empty() = 0;
        //Test whether container is empty

        virtual int size() = 0;
        //Return container size

        virtual void erase(GTUIterator<T> iter) = 0;
        //Erase element pointed by the given iterator

        virtual void clear() = 0;
        //Clear all content

        virtual GTUIterator<T> begin() = 0;
        //Return iterator to beginning

        virtual GTUIterator<T> end() = 0;
        //Return iterator to end

        virtual GTUIteratorConst<T> cbegin() = 0;
        //Return a constant iterator to beginning

        virtual GTUIteratorConst<T> cend() = 0;
        //Return a constant iterator to end
    };

}

#endif