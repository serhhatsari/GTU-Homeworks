#ifndef GTUIterator_H
#define GTUIterator_H

#include <iostream>
#include <memory>

using namespace std;

namespace GTU_SARI
{

    template <typename T>
    class GTUIterator
    {
    public:
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;

        GTUIterator(T *ptrPos = nullptr)
        { // taking pointer as parameter
            position = ptrPos;
        }

        ~GTUIterator()
        {
            // intentionally empty
        }

        GTUIterator<T> &operator=(T *ptrPos)
        {
            //overloading assignment operator
            position = ptrPos;
            return (*this);
        }

        reference operator*()
        { // overloading star operator
            return *position;
        }

        pointer operator->()
        {
            // overloading arrow operator
            return position;
        }

        bool operator==(const GTUIterator<T> &other) const
        {
            // overloading equaltiy operator
            return (position == other.position);
        }

        bool operator!=(const GTUIterator<T> &other) const
        { // overloading not equality operator
            return (position != other.position);
        }

        GTUIterator<T> &operator++()
        {
            // overloading increment operator
            ++position;
            return (*this);
        }

        GTUIterator<T> operator++(int ignore)
        { // overloading increment operator
            GTUIterator<T> temp(*this);
            ++position;
            return temp;
        }

        GTUIterator<T> &operator--()
        {
            // overloading decrement operator
            --position;
            return (*this);
        }

        GTUIterator<T> operator--(int ignore)
        {
            //overloading decrement operator
            GTUIterator<T> temp(*this);
            --position;
            return temp;
        }

        GTUIterator<T> operator+(const difference_type &other)
        {
            // overloading plus operator
            pointer oldPosition = position;
            position += other;
            GTUIterator<T> temp(*this);
            position = oldPosition;
            return temp;
        }

        GTUIterator<T> operator+(int other)
        {
            // overloading plus operator
            pointer oldPosition = position;
            position += other;
            GTUIterator<T> temp(*this);
            position = oldPosition;
            return temp;
        }

        GTUIterator<T> operator-(const difference_type &other)
        {
            // overloading minus operator
            pointer oldPosition = position;
            position -= other;
            GTUIterator<T> temp(*this);
            position = oldPosition;
            return temp;
        }

        GTUIterator<T> operator-(int other)
        {
            // overloading minus operator
            pointer oldPosition = position;
            position -= other;
            GTUIterator<T> temp(*this);
            position = oldPosition;
            return temp;
        }

        operator bool() const
        {
            if (position)
                return true;
            else
                return false;
        }

    protected:
        pointer position;
    };

}

#endif