#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include <iostream>
#include <memory>

using namespace std;

namespace GTU_SARI
{

   template <typename T>
   class GTUIteratorConst
   {
   public:
      using pointer = const T *;
      using reference = const T &;
      using iterator_category = std::random_access_iterator_tag;
      using value_type = T;
      using difference_type = std::ptrdiff_t;

      GTUIteratorConst(T *ptrPos = nullptr)
      { // taking pointer as parameter
         position = ptrPos;
      }

      ~GTUIteratorConst()
      {
         // intentionally empty
      }

      GTUIteratorConst<T> &operator=(T *ptrPos)
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

      bool operator==(const GTUIteratorConst<T> &other) const
      {
         // overloading equaltiy operator
         return (position == other.position);
      }

      bool operator!=(const GTUIteratorConst<T> &other) const
      { // overloading not equality operator
         return (position != other.position);
      }

      GTUIteratorConst<T> &operator++()
      {
         // overloading increment operator
         ++position;
         return (*this);
      }

      GTUIteratorConst<T> operator++(int ignore)
      { // overloading increment operator
         GTUIteratorConst<T> temp(*this);
         ++position;
         return temp;
      }

      GTUIteratorConst<T> &operator--()
      {
         // overloading decrement operator
         --position;
         return (*this);
      }

      GTUIteratorConst<T> operator--(int ignore)
      {
         //overloading decrement operator
         GTUIteratorConst<T> temp(*this);
         --position;
         return temp;
      }

      GTUIteratorConst<T> operator+(const difference_type &other)
      {
         // overloading plus operator
         pointer oldPosition = position;
         position += other;
         GTUIteratorConst<T> temp(*this);
         position = oldPosition;
         return temp;
      }

      GTUIteratorConst<T> operator+(int other)
      {
         // overloading plus operator
         pointer oldPosition = position;
         position += other;
         GTUIteratorConst<T> temp(*this);
         position = oldPosition;
         return temp;
      }

      GTUIteratorConst<T> operator-(const difference_type &other)
      {
         // overloading minus operator
         pointer oldPosition = position;
         position -= other;
         GTUIteratorConst<T> temp(*this);
         position = oldPosition;
         return temp;
      }

      GTUIteratorConst<T> operator-(int other)
      {
         // overloading minus operator
         pointer oldPosition = position;
         position -= other;
         GTUIteratorConst<T> temp(*this);
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