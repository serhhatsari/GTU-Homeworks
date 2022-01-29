#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include <iostream>
#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"
#include "Exceptions.h"

using namespace std;

namespace GTU_SARI
{

    template <class T>
    class GTUVector : public Iterable<T>
    {
    public:
        GTUVector();
        //default constructer

        GTUVector(int cap);
        // constructer that take size

        GTUVector(const GTUVector<T> &other);
        // copy constructer

        GTUVector(GTUVector<T> &&other);
        // move constructer

        GTUVector<T> &operator=(const GTUVector<T> &other);
        // copy assignment

        GTUVector<T> &operator=(GTUVector<T> &&other);
        // move assignment

        ~GTUVector();
        // destructer

        void add(const T &addedValue);
        // add method

        T &operator[](int index);
        // index overloading

        bool empty() override;
        //Test whether container is empty

        int size() override;
        //Return container size

        void erase(GTUIterator<T> iter) override;
        //Erase element pointed by the given iterator

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

    template <class T>
    GTUVector<T>::GTUVector()
    {
        coSize = 0; // size become 0
        shared_ptr<T> temp(new T[0], default_delete<T[]>());
        container = temp;
        // creating new share ptr
    }

    template <class T>
    GTUVector<T>::GTUVector(int cap)
    {
        coSize = cap; // size become cap
        shared_ptr<T> temp(new T[cap], default_delete<T[]>());
        container = temp;
        // creating new shared ptr
    }

    template <class T>
    GTUVector<T>::GTUVector(const GTUVector<T> &other)
    {
        int i;
        coSize = other.coSize; // assigning size
        container = shared_ptr<T>(new T[coSize + 1], default_delete<T[]>());
        // create new shared ptr
        for (i = 0; i < coSize; i++)
        {
            container.get()[i] = other.container.get()[i];
            // assign data
        }

        // deep copy
    }

    template <class T>
    GTUVector<T>::GTUVector(GTUVector<T> &&other)
    {
        int i;
        coSize = other.coSize;       // assign size
        container = other.container; // assign data
        other.coSize = 0;            // other size become 0
        other.container = nullptr;   // other data become nullptr
        // shallow copy
    }

    template <class T>
    GTUVector<T> &GTUVector<T>::operator=(const GTUVector &other)
    {
        int i;
        coSize = other.coSize;
        container = shared_ptr<T>(new T[coSize + 1], default_delete<T[]>());
        // create new shared ptr
        for (i = 0; i < coSize; i++)
        {
            container.get()[i] = other.container.get()[i];
            // assign data
        }
        return *this;
        // deep copy
    }

    template <class T>
    GTUVector<T> &GTUVector<T>::operator=(GTUVector &&other)
    {
        coSize = other.coSize;       // assign size
        container = other.container; // assign data
        other.coSize = 0;
        other.container = nullptr;
        return *this;
        // shallow copy
    }

    template <class T>
    GTUVector<T>::~GTUVector()
    {
        //intentionally empty
    }

    template <class T>
    void GTUVector<T>::add(const T &addedValue)
    {
        shared_ptr<T> temp(new T[coSize + 1], default_delete<T[]>());
        int i;
        // create new temp shared ptr
        for (i = 0; i < coSize; i++)
        {
            temp.get()[i] = container.get()[i];
            // assign old data
        }

        temp.get()[coSize] = addedValue;
        // assign new value
        coSize++;
        // incrementing the size
        container = temp;
        // assign the temp data to our data
    }

    template <class T>
    T &GTUVector<T>::operator[](int index)
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

    template <class T>
    bool GTUVector<T>::empty()
    {
        if (coSize == 0) // check if cosize is zero
            return true;
        else
            return false;
    }

    template <class T>
    int GTUVector<T>::size()
    {
        return coSize; // return size
    }

    template <class T>
    void GTUVector<T>::clear()
    {
        coSize = 0; // make size 0
        shared_ptr<T> temp(new T[0], default_delete<T[]>());
        container = temp;
        // delete the all shared ptr
    }

    template <class T>
    void GTUVector<T>::erase(GTUIterator<T> iter)
    {
        if (coSize == 0) // if size 0 dont erase anything
            return;
        shared_ptr<T> temp(new T[coSize + 1], default_delete<T[]>());
        int i = 0;

        for (GTUIterator<T> it = begin(); it != end(); ++it, i++)
        {
            if (it == iter)
            { // find the value
                i--;
                continue;
            }
            temp.get()[i] = *it;
        }
        container = temp;
        coSize--;
        // decrementing the size
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::begin()
    {
        // return the beginning index of the data
        return GTUIterator<T>(container.get());
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::end()
    {
        // return the end index of the data
        return GTUIterator<T>(container.get() + coSize);
    }

    template <class T>
    GTUIteratorConst<T> GTUVector<T>::cbegin()
    {
        // return the beginning index of the data as const
        return GTUIteratorConst<T>(container.get());
    }

    template <class T>
    GTUIteratorConst<T> GTUVector<T>::cend()
    {
        // return the end index of the data as const
        return GTUIteratorConst<T>(container.get() + coSize);
    }

}

#endif