#ifndef GTUARRAY_H
#define GTUARRAY_H

#include <iostream>
#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"
#include "Exceptions.h"

using namespace std;

namespace GTU_SARI
{

    template <class T, int SIZE>
    class GTUArray : public Iterable<T>
    {
    public:
        GTUArray();
        //default constructer

        GTUArray(const GTUArray<T, SIZE> &other);
        // copy constructer

        GTUArray(GTUArray<T, SIZE> &&other);
        // move constructer

        GTUArray<T, SIZE> &operator=(const GTUArray<T, SIZE> &other);
        // copy assignment

        GTUArray<T, SIZE> &operator=(GTUArray<T, SIZE> &&other);
        // move assignment

        ~GTUArray();
        // destructer

        T &operator[](int index);
        // index operator overloading

        bool empty() override;
        //Test whether container is empty

        void erase(GTUIterator<T> iter) override;
        //Erase element pointed by the given iterator

        int size() override;
        //Return container size

        void clear() override;
        //Clear all content

        GTUIterator<T> begin() override;
        //Return iterator to beginning

        GTUIterator<T> end() override;
        //Return iterator to end

        GTUIteratorConst<T> cbegin() override;
        //Return a constant iterator to beginning

        GTUIteratorConst<T> cend() override;
        //Return a constant iterator to end

    private:
        int coSize;
        shared_ptr<T> container;
    };

    template <class T, int SIZE>
    GTUArray<T, SIZE>::GTUArray()
    {
        coSize = SIZE; // assign size
        shared_ptr<T> temp(new T[SIZE + 1], default_delete<T[]>());
        container = temp;
        // create new shared ptr
    }

    template <class T, int SIZE>
    GTUArray<T, SIZE>::GTUArray(const GTUArray<T, SIZE> &other)
    {
        int i;
        coSize = other.coSize; // assign size
        container = shared_ptr<T>(new T[coSize], default_delete<T[]>());
        //create new shared ptr
        for (i = 0; i < coSize; i++)
        {
            container.get()[i] = other.container.get()[i];
            // assign data
        }
        // deep copy
    }

    template <class T, int SIZE>
    GTUArray<T, SIZE>::GTUArray(GTUArray<T, SIZE> &&other)
    {
        int i;
        coSize = other.coSize;       // assign size
        container = other.container; // assign data
        // shallow copy
    }

    template <class T, int SIZE>
    GTUArray<T, SIZE> &GTUArray<T, SIZE>::operator=(const GTUArray<T, SIZE> &other)
    {
        int i;
        coSize = other.coSize; // assign size
        container = shared_ptr<T>(new T[coSize], default_delete<T[]>());
        // create new shared ptr
        for (i = 0; i < coSize; i++)
        {
            container.get()[i] = other.container.get()[i];
            // assign data
        }
        // deep copy
        return *this;
    }

    template <class T, int SIZE>
    GTUArray<T, SIZE> &GTUArray<T, SIZE>::operator=(GTUArray<T, SIZE> &&other)
    {
        int i;
        coSize = other.coSize;       // assign size
        container = other.container; // assign data
        // shallow copy
        return *this;
    }

    template <class T, int SIZE>
    GTUArray<T, SIZE>::~GTUArray()
    {
        // intentionally empty
    }

    template <class T, int SIZE>
    T &GTUArray<T, SIZE>::operator[](int index)
    {
        if (index >= 0 && index < coSize)
        { // check for index
            return container.get()[index];
        }
        else
        {
            throw InvalidIndex("INVALID INDEX, INDEX IS NOT AVAILABLE!");
        }
    }

    template <class T, int SIZE>
    bool GTUArray<T, SIZE>::empty()
    {
        if (coSize == 0) // check if array is empty
            return true;
        else
            return false;
    }

    template <class T, int SIZE>
    int GTUArray<T, SIZE>::size()
    {
        return coSize; // return size
    }

    template <class T, int SIZE>
    void GTUArray<T, SIZE>::clear()
    {
        coSize = 0; // make size 0
    }

    template <class T, int SIZE>
    void GTUArray<T, SIZE>::erase(GTUIterator<T> iter)
    {
        if (coSize == 0) // check if it is empty array
            exit(1);
        shared_ptr<T> temp(new T[coSize], default_delete<T[]>());
        int i = 0;
        // create new shared ptr
        for (GTUIterator<T> it = begin(); it != end(); ++it, i++)
        {
            if (it == iter)
            {
                i--;
                continue;
            }
            temp.get()[i] = *it;
        }
        container = temp;
        coSize--;
        // decrement size
    }

    template <class T, int SIZE>
    GTUIterator<T> GTUArray<T, SIZE>::begin()
    {
        // return the first index
        return GTUIterator<T>(container.get());
    }

    template <class T, int SIZE>
    GTUIterator<T> GTUArray<T, SIZE>::end()
    {
        // return the last index
        return GTUIterator<T>(container.get() + coSize);
    }

    template <class T, int SIZE>
    GTUIteratorConst<T> GTUArray<T, SIZE>::cbegin()
    {
        // return the first index as const
        return GTUIteratorConst<T>(container.get());
    }

    template <class T, int SIZE>
    GTUIteratorConst<T> GTUArray<T, SIZE>::cend()
    {
        // return the last index as const
        return GTUIteratorConst<T>(container.get() + coSize);
    }

}
#endif