#ifndef GTUSET_H
#define GTUSET_H

#include <iostream>
#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"

using namespace std;

namespace GTU_SARI
{

    template <class T>
    class GTUSet : public Iterable<T>
    { //GTU SET CLASS
    public:
        GTUSet();
        // default constructer

        GTUSet(shared_ptr<T> newCont, int newSize);
        // constructer that take shared ptr and size

        GTUSet(const GTUSet<T> &other);
        // copy constructer

        GTUSet(GTUSet<T> &&other);
        // move constructer

        GTUSet<T> &operator=(const GTUSet &other);
        // copy assignment

        GTUSet<T> &operator=(GTUSet &&other);
        // move assignment

        ~GTUSet();
        // destructer

        void add(const T &addedValue);
        // adds the value to the set

        GTUIterator<T> searchSet(const T &value);
        // search the value given by the user and return the iterator pointing that value

        void deleteSet(const T &other);
        // delete the value given by the user if the value exists in the set    

        GTUSet<T> intersectSet(const GTUSet<T> &other);
        // return the intersect set of 2 sets

        GTUSet<T> unionSet(const GTUSet<T> &other);
        // return the union of 2 sets

        bool empty() override;
        //Test whether container is empty

        int size() override;
        //Return container size

        void clear() override;
        //Clear all content

        void erase(GTUIterator<T> iter) override;
        //Erase element pointed by the given iterator

        GTUIterator<T> begin() override;
        //Return iterator to beginning

        GTUIterator<T> end() override;
        //Return iterator to end

        GTUIteratorConst<T> cbegin() override;
        //Return a constant iterator to beginning

        GTUIteratorConst<T> cend() override;
        //Return a constant iterator to end

    private:
        int coSize;              // size of the array
        shared_ptr<T> container; // our shared ptr array
    };

    template <class T>
    GTUSet<T>::GTUSet()
    {
        coSize = 0; // size become 0 at the beginning
        shared_ptr<T> temp(new T[0], default_delete<T[]>());
        container = temp; // assigning shared ptr to data
    }

    template <class T>
    GTUSet<T>::GTUSet(shared_ptr<T> newCont, int newSize)
    {
        coSize = newSize;    // assign size
        container = newCont; // assign container data
    }

    template <class T>
    GTUSet<T>::GTUSet(const GTUSet<T> &other)
    {
        int i;
        coSize = other.coSize; // assign size
        container = shared_ptr<T>(new T[coSize + 1], default_delete<T[]>());
        // assign new shared ptr to container data
        for (i = 0; i < coSize; i++)
        {
            container.get()[i] = other.container.get()[i];
            // assign new data to our data
        }

        // this is deep copy
    }

    template <class T>
    GTUSet<T>::GTUSet(GTUSet<T> &&other)
    {
        int i;
        coSize = other.coSize;       // assign size
        container = other.container; //assign container data
        other.coSize = 0;            // make other containers size 0
        other.container = nullptr;   // make other containers data null
    }

    template <class T>
    GTUSet<T>::~GTUSet()
    {
        // intentionally empty
    }

    template <class T>
    GTUSet<T> &GTUSet<T>::operator=(const GTUSet &other)
    {
        int i;
        coSize = other.coSize; // assign size
        container = shared_ptr<T>(new T[coSize + 1], default_delete<T[]>());
        // create new shared ptr
        for (i = 0; i < coSize; i++)
        {
            container.get()[i] = other.container.get()[i];
            // assign new data to our data
        }
        return *this;
        // return our data
    }

    template <class T>
    GTUSet<T> &GTUSet<T>::operator=(GTUSet &&other)
    {
        int i;
        coSize = other.coSize;       // assign size
        container = other.container; // assign data
        other.coSize = 0;            // others size 0
        other.container = nullptr;   // others data null
        return *this;
    }

    template <class T>
    void GTUSet<T>::add(const T &addedValue)
    {
        int i;
        for (i = 0; i < coSize; i++)
        { // check if added value is exist in our set
            if (addedValue == container.get()[i])
            {
                // if it exists, dont add it
                return;
            }
        }

        shared_ptr<T> temp(new T[coSize + 1], default_delete<T[]>());
        // create a new shared ptr array

        for (i = 0; i < coSize; i++)
        {
            temp.get()[i] = container.get()[i];
            // assign old values to it
        }

        temp.get()[coSize] = addedValue;
        // add the new value to the set
        coSize++;
        // incrementing the size
        container = temp;
        // assigning temp shared ptr to original shared ptr
    }

    template <class T>
    bool GTUSet<T>::empty()
    {
        if (coSize == 0) // check if size equals 0
            return true;
        else
            return false;
    }

    template <class T>
    int GTUSet<T>::size()
    {
        return coSize; // return size
    }

    template <class T>
    void GTUSet<T>::clear()
    {
        coSize = 0; // make size 0
        shared_ptr<T> temp(new T[0], default_delete<T[]>());
        container = temp;
        // create a new shared ptr and assign it to original shared ptr
    }

    template <class T>
    void GTUSet<T>::erase(GTUIterator<T> iter)
    {
        if (coSize == 0) // check if size equals 0
            exit(1);
        shared_ptr<T> temp(new T[coSize + 1], default_delete<T[]>());
        // create a new shared ptr
        int i = 0;

        for (GTUIterator<T> it = begin(); it != end(); ++it, i++)
        {
            if (it == iter)
            { // find the given iterator and dont add it to new one
                i--;
                continue;
            }
            temp.get()[i] = *it;
        }

        container = temp;
        coSize--;
        // decrementing size
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::searchSet(const T &other)
    {
        int i;
        T *ptr;
        for (i = 0; i < coSize; i++)
        { // search var the given value
            if (other == container.get()[i])
            {
                // return the index of that value
                ptr = &container.get()[i];
                return GTUIterator<T>(ptr);
            }
        }

        // if you dont find it return the beginning index
        return GTUIterator<T>(container.get());
    }

    template <class T>
    void GTUSet<T>::deleteSet(const T &other)
    {
        int i, ind;
        bool isExist = false;

        // if the given value exists, it will delete it

        for (i = 0; i < coSize; i++)
        {
            if (other == container.get()[i])
            {
                isExist = true;
                ind = i;
            }
        }
        if (isExist)
        {
            for (i = ind; i <= coSize - 2; i++)
            {
                container.get()[i] = container.get()[i + 1];
            }
            coSize--; // incrementing size
        }
    }

    template <class T>
    GTUSet<T> GTUSet<T>::intersectSet(const GTUSet<T> &other)
    {
        int i, k, z = 0;

        // intersecting 2 sets

        shared_ptr<T> temp(new T[other.coSize + coSize + 1], default_delete<T[]>());
        // create a new shared ptr

        if (coSize > other.coSize)
        {
            for (i = 0; i < coSize; i++)
            { // checking elements
                for (k = 0; k < other.coSize; k++)
                { // checking elements
                    if (container.get()[i] == other.container.get()[k])
                    {
                        // if both has the value
                        // then add it
                        temp.get()[z] = container.get()[i];
                        z++;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < other.coSize; i++)
            { // checking elements
                for (k = 0; k < coSize; k++)
                { // checking elements
                    if (container.get()[k] == other.container.get()[i])
                    {
                        // if both has the value
                        // then add it
                        temp.get()[z] = container.get()[k];
                        z++;
                    }
                }
            }
        }

        // return the intersection set

        return GTUSet<T>(temp, z);
    }

    template <class T>
    GTUSet<T> GTUSet<T>::unionSet(const GTUSet<T> &other)
    {
        shared_ptr<T> temp(new T[other.coSize + coSize + 1], default_delete<T[]>());
        int i, k, z = 0;
        bool isExists = false;

        // union of 2 set

        for (i = 0; i < coSize; i++)
        { // checking elements
            isExists = false;

            for (k = 0; k < z; k++)
            { // checking elements
                if (container.get()[i] == temp.get()[k])
                {
                    isExists = true;
                }
            }
            if (!isExists)
            { // if not exists for both
                // then add it
                temp.get()[z] = container.get()[i];
                z++;
            }
        }

        for (i = 0; i < other.coSize; i++)
        { // checking elements
            isExists = false;

            for (k = 0; k < z; k++)
            { // checking elements
                if (other.container.get()[i] == temp.get()[k])
                {
                    isExists = true;
                }
            }
            if (!isExists)
            {
                // if not exists for both
                // then add it
                temp.get()[z] = other.container.get()[i];
                z++;
            }
        }

        // return the union set

        return GTUSet<T>(temp, z);
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::begin()
    {
        // return the beginning index
        return GTUIterator<T>(container.get());
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::end()
    {
        // return the end index
        return GTUIterator<T>(container.get() + coSize);
    }

    template <class T>
    GTUIteratorConst<T> GTUSet<T>::cbegin()
    {
        // return the beginning const index
        return GTUIteratorConst<T>(container.get());
    }

    template <class T>
    GTUIteratorConst<T> GTUSet<T>::cend()
    {
        // return the end const index
        return GTUIteratorConst<T>(container.get() + coSize);
    }
}
#endif