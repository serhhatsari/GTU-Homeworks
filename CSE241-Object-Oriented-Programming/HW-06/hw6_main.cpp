#include <iostream>
#include <memory>
#include <algorithm>
#include <set>
#include <array>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "GTUVector.h"
#include "GTUSet.h"
#include "GTUArray.h"
#include "Exceptions.h"

using namespace std;
using namespace GTU_SARI;

void printinForEach(int i)
{
    // its for std::for_each method
    // for each method takes this as parameter
    cout << i << endl;
}

void testVector();
void testSet();
void testArray();
void testExceptions();

int main()
{
    testVector();
    testSet();
    testArray();
    testExceptions();
    return 0;
}

void testVector()
{
    /* TESTING GTUVECTOR METHODS */
    cout << "\tTESTING GTUVector METHODS\n\n";

    // Creating GTUVector object
    cout << "Testing default constructer for GTUVector\n";
    GTUVector<int> vc;
    cout << "Default constructer worked.. \n\n";
    cout << "Testing  constructer with different type\n";
    GTUVector<string> strvc;
    cout << "Constructer also worked with different type.. \n\n";
    cout << "Testing constructer that takes parameter..\n";
    GTUVector<int> vc1(10);
    cout << "It created an object with the given size..\n\n";
    cout << "Testing copy constructer with vc2 and vc1 vectors\n";
    GTUVector<int> vc2(vc1);
    cout << "It copied every data of vc1 to vc2, deep copy\n\n";
    cout << "Testing copy assignment with vc3 and vc2\n";
    GTUVector<int> vc3;
    vc3 = vc2;
    cout << "It copied every data of vc2 to vc3, deep copy\n\n";
    cout << "Testing move constructer \n";
    GTUVector<int> vc4(move(vc3));
    cout << "It transport every data of vc3 to vc4, shallow copy\n\n";
    cout << "Testing move assignment with vc5 and vc4 \n";
    GTUVector<int> vc5;
    vc5 = move(vc4);
    cout << "It transport every data of vc4 to vc5, shallow copy\n\n";

    //Creating GTUIterator and GTUIteratorConst object
    cout << "\n\nCreating GTUIterator and GTUIteratorConst object.. \n";
    GTUIterator<int> vecIter;
    GTUIteratorConst<int> vecConstIter;
    cout << "GTUIterator and GTUIterator object has been created..\n";

    GTUVector<int> vec;
    cout << "\n\nLets create a vector called vec and test all method of GTUVector with it\n";

    //testing .add() method
    cout << "\n\n1) Testing .add() method for GTUVector \n";
    cout << "Adding 12, 153, 7 and 25 to our GTUVector using .add() method\n";
    vec.add(12);
    vec.add(153);
    vec.add(7);
    vec.add(25);
    cout << "Printing the values in GTUVector to see the result:\n";
    for (auto iter : vec)
        cout << iter << endl;

    // testing operator[] overloaded method
    cout << "\n\n2) Testing operator[] method for GTUVector \n";
    cout << "Lets print the elements using operator[]:\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    //testing .size() method
    cout << "\n\n3) Testing .size() method for GTUVector \n";
    cout << "Printing the size using .size():\n";
    cout << "Size is: " << vec.size() << endl;

    //testing .empty() method
    cout << "\n\n4) Testing .empty() method for GTUVector \n";
    cout << "Checking if our GTUVector is empty or not using .empty() method: \n";
    if (vec.empty())
        cout
            << "VECTOR IS EMPTY" << endl;
    else
        cout << "VECTOR IS NOT EMPTY" << endl;

    //testing .erase() method
    cout << "\n\n5) Testing .erase() method for GTUVector \n";
    cout << "Erasing the first element of the GTUVector using .erase() method \n";
    vec.erase(vec.begin());
    cout << "Printing the values in GTUVector too see the result:\n";
    for (auto iter : vec)
        cout << iter << endl;

    // testing begin and end methods in for loop
    cout << "\n\n6) Testing .begin() and .end() method for GTUVector \n";
    cout << "Testing begin and end methods using for loop and printing the elements \n";
    for (vecIter = vec.begin(); vecIter != vec.end(); vecIter++)
    {
        cout << *vecIter << endl;
    }

    // testing cbegin and cend methods in for loop
    cout << "\n\n7) Testing .cbegin() and .cend() method for GTUVector \n";
    cout << "Testing cbegin and cend methods using for loop and printing the elements \n";
    for (vecConstIter = vec.cbegin(); vecConstIter != vec.cend(); vecConstIter++)
    {
        cout << *vecConstIter << endl;
    }

    // testing std::for_each method with GTUVector
    cout << "\n\n8) Testing std::for_each method with the GTUVector \n";
    cout << "In every iteration printinforeach func will be called and print the value \n";
    for_each(vec.begin(), vec.end(), printinForEach);

    // testing std::find with GTUVector
    cout << "\n\n9) Testing std::find() method with a value that doesnt exist\n";
    cout << "std::find method searching for '30' \n";
    vecIter = find(vec.begin(), vec.end(), 30);
    if (vecIter != vec.end())
        cout << "Element found in myvector: " << *vecIter << '\n';
    else
        cout << "Element not found in myvector\n";

    // testing std::find with GTUVector one more time
    cout << "\n\n10) Testing std::find() method with a value that exists \n";
    cout << "std::find method searching for '153' \n";
    vecIter = find(vec.begin(), vec.end(), 153);
    if (vecIter != vec.end())
        cout << "Element found in vec: " << *vecIter << '\n';
    else
        cout << "Element not found in vec\n";

    // testing std::sort with GTUVector
    cout << "\n\n11) Testing std::sort() method with GTUVector \n";
    sort(vec.begin(), vec.end());
    cout << "Sort is done, lets print the sorted GTUVector \n";
    for (auto iter : vec)
        cout << iter << endl;

    // testing range based loop with GTUVector
    cout << "\n\n12) Testing range based loop with GTUVector \n";
    cout << "Lets print all elements using range based loop \n";
    for (auto iter : vec)
        cout << iter << endl;

    // testing .clear() method
    cout << "\n\n13) Testing .clear() method for GTUVector \n";
    cout << "Clear all content of our GTUVector using .clear() method \n";
    vec.clear();
    cout << "Printing the values in GTUVector too see the result:\n";
    for (auto iter : vec)
        cout << iter << endl;
    cout << "as you can see, all content has been deleted \n";
}

void testSet()
{

    /* TESTING GTUSet METHODS */
    cout << "\n\n\tTESTING GTUSet METHODS\n\n";

    // Creating GTUSet object
    cout << "Testing default constructer for GTUSet\n";
    GTUSet<int> sc1;
    cout << "Default constructer worked.. \n\n";
    cout << "Testing constructer with different type\n";
    GTUSet<string> strSet;
    cout << "Constructer also worked with different type.. \n\n";
    cout << "Testing copy constructer with sc2 and sc1 sets\n";
    GTUSet<int> sc2(sc1);
    cout << "It copied every data of sc1 to sc2, deep copy\n\n";
    cout << "Testing copy assignment with sc3 and sc2\n";
    GTUSet<int> sc3;
    sc3 = sc2;
    cout << "It copied every data of sc2 to sc3, deep copy\n\n";
    cout << "Testing move constructer \n";
    GTUSet<int> sc4(move(sc3));
    cout << "It transport every data of sc3 to sc4, shallow copy\n\n";
    cout << "Testing move assignment with sc5 and sc4 \n";
    GTUSet<int> sc5;
    sc5 = move(sc4);
    cout << "It transport every data of sc4 to sc5, shallow copy\n\n";

    //Creating GTUIterator and GTUIteratorConst object
    cout << "\n\nCreating GTUIterator and GTUIteratorConst object.. \n";
    GTUIterator<int> setIter;
    GTUIteratorConst<int> setConstIter;
    cout << "GTUIterator and GTUIterator object has been created..\n";

    // Creating GTUSet object
    GTUSet<int> set;
    cout << "\n\nNow, lets create a GTUSet named set and test all GTUSet methods with it\n";
    //testing .add() method
    cout
        << "\n\n1) Testing .add() method \n";
    cout << "Adding 12,121,70,121 ,25 and 50 to our GTUSet using .add() method\n";
    set.add(12);
    set.add(121);
    set.add(7);
    set.add(121);
    set.add(25);
    set.add(50);
    cout << "Printing the values in GTUSet to see the result:\n";
    for (auto iter : set)
        cout << iter << endl;
    cout << "As you can see, we try to add '121' two times\n";
    cout << "but because of set elements should be unique, we didnt add the second one \n";

    //testing .size() method
    cout << "\n\n2) Testing .size() method for GTUSet \n";
    cout << "Printing the size using .size():\n";
    cout << "Size is: " << set.size() << endl;

    //testing .empty() method
    cout << "\n\n3) Testing .empty() method for GTUSet\n";
    cout << "Checking if our GTUSet is empty or not using .empty() method: \n";
    if (set.empty())
        cout
            << "SET IS EMPTY" << endl;
    else
        cout << "SET IS NOT EMPTY" << endl;

    //testing .erase() method
    cout << "\n\n4) Testing .erase() method for GTUSet\n";
    cout << "Erasing the first element of the GTUSet using .erase(set.begin()) method \n";
    set.erase(set.begin());
    cout << "Printing the values in GTUSet too see the result:\n";
    for (auto iter : set)
        cout << iter << endl;

    //testing .delete() method
    cout << "\n\n5) Testing .delete() method for GTUSet\n";
    cout << "delete() method will find for a value '54' if he finds it, it will delete it\n";
    set.deleteSet(54);
    cout << "Printing the values in GTUSet too see the result:\n";
    for (auto iter : set)
        cout << iter << endl;
    cout << "As you can see, it didnt delete anything, because there is no value '54' in the set \n";

    //testing .delete() method
    cout << "\n\n6) Testing .delete() method for GTUSet one more time\n";
    cout << "delete() method will find for a value '7' if he finds it, it will delete it\n";
    set.deleteSet(7);
    cout << "Printing the values in GTUSet too see the result:\n";
    for (auto iter : set)
        cout << iter << endl;
    cout << "As you can see, it deleted the value '7' in the set \n";

    // testing begin and end methods in for loop
    cout << "\n\n7) Testing .begin() and .end() method for GTUSet \n";
    cout << "Testing begin and end methods using for loop and printing the elements \n";
    for (setIter = set.begin(); setIter != set.end(); setIter++)
    {
        cout << *setIter << endl;
    }

    // testing cbegin and cend methods in for loop
    cout << "\n\n8) Testing .cbegin() and .cend() method for GTUSet \n";
    cout << "Testing cbegin and cend methods using for loop and printing the elements \n";
    for (setConstIter = set.cbegin(); setConstIter != set.cend(); setConstIter++)
    {
        cout << *setConstIter << endl;
    }

    // testing std::for_each method with GTUSet
    cout << "\n\n9) Testing std::for_each method with the GTUSet \n";
    cout << "In every iteration printinforeach func will be called and print the value \n";
    for_each(set.begin(), set.end(), printinForEach);

    // testing std::find with GTUSet
    cout << "\n\n10) Testing std::find() method with a value that doesnt exist\n";
    cout << "std::find method searching for '523' \n";
    setIter = find(set.begin(), set.end(), 523);
    if (setIter != set.end())
        cout << "Element found in set: " << *setIter << '\n';
    else
        cout << "Element not found in set\n";

    // testing std::find with GTUSet one more time
    cout << "\n\n11) Testing std::find() method with a value that exists \n";
    cout << "std::find method searching for '121' \n";
    setIter = find(set.begin(), set.end(), 121);
    if (setIter != set.end())
        cout << "Element found in set: " << *setIter << '\n';
    else
        cout << "Element not found in set\n";

    // testing std::sort with GTUSet
    cout << "\n\n12) Testing std::sort() method with GTUSet \n";
    sort(set.begin(), set.end());
    cout << "Sorting is done \n";
    cout << "Lets print all elements using range based loop \n";
    for (auto iter : set)
        cout << iter << endl;

    // testing range based loop with GTUSet
    cout << "\n\n13) Testing range based loop with GTUSet \n";
    cout << "Lets print all elements using range based loop \n";
    for (auto iter : set)
        cout << iter << endl;

    // testing .clear() method
    cout << "\n\n14) Testing .clear() method \n";
    cout << "Clear all content of our GTUSet using .clear() method \n";
    set.clear();
    cout << "Printing the values in GTUSet too see the result:\n";
    for (auto iter : set)
        cout << iter << endl;
    cout << "as you can see, there is no element left to be printed\n";
    cout << "all content has been deleted\n";

    //testing intersect() method
    cout << "\n\n15) Testing intersect() method \n";
    cout << "Lets create a set named firstSet with values : 64 , 43, 5, 523, 21 \n";
    GTUSet<int> firstSet;
    firstSet.add(64);
    firstSet.add(43);
    firstSet.add(5);
    firstSet.add(523);
    firstSet.add(21);
    cout << "Lets print the elements of the firstSet \n";
    for (auto iter : firstSet)
        cout << iter << endl;
    cout << "Then, lets create a set named secondSet with values : 3 , 21, 1235, 64, 95 \n";
    GTUSet<int> secondSet;
    secondSet.add(3);
    secondSet.add(21);
    secondSet.add(1235);
    secondSet.add(64);
    secondSet.add(95);
    cout << "Lets print the elements of the secondSet \n";
    for (auto iter : secondSet)
        cout << iter << endl;
    cout << "Now, we will find the intersect set of firstSet and secondSet \n";
    cout << "Then assign it to the set named thirdSet \n";
    GTUSet<int> thirdSet;
    thirdSet = firstSet.intersectSet(secondSet);
    cout << "Lets print the elements of the thirdSet \n";
    for (auto iter : thirdSet)
        cout << iter << endl;
    cout << "As you can see, intersectSet has 21 and 64 \n";

    //testing unionset() method
    cout << "\n\n16) Testing union() method \n";
    cout << "Lets create a set named setFirst with values : 64 , 43, 5, 523, 21 \n";
    GTUSet<int> setFirst;
    setFirst.add(64);
    setFirst.add(43);
    setFirst.add(5);
    setFirst.add(523);
    setFirst.add(21);
    cout << "Lets print the elements of the setFirst \n";
    for (auto iter : setFirst)
        cout << iter << endl;
    cout << "Then, lets create a set named setSecond with values : 3 , 21, 1235, 64, 95 \n";
    GTUSet<int> setSecond;
    setSecond.add(3);
    setSecond.add(21);
    setSecond.add(1235);
    setSecond.add(64);
    setSecond.add(95);
    cout << "Lets print the elements of the secondSet \n";
    for (auto iter : setSecond)
        cout << iter << endl;
    cout << "Now, we will find the union set of setFirst and setSecond \n";
    cout << "Then assign it to the set named setThird \n";
    GTUSet<int> setThird;
    setThird = setFirst.unionSet(setSecond);
    cout << "Lets print the elements of the thirdSet \n";
    for (auto iter : setThird)
        cout << iter << endl;
    cout << "As you can see, union has 64,43,5,523,21,3,1235,95 \n";
    cout << "* 21 and 64 only added once \n";
}

void testArray()
{
    /* TESTING GTUArray METHODS */
    cout << "\n\n\tTESTING GTUArray METHODS\n\n";

    // Creating GTUArray object
    cout << "Testing default constructer for GTUArray\n";
    GTUArray<int, 4> ar1;
    cout << "Default constructer worked.. \n\n";
    cout << "Testing constructer with different type\n";
    GTUArray<string, 4> strArr;
    cout << "Constructer also worked with different type.. \n\n";
    cout << "Testing copy constructer with ar2 and ar1 sets\n";
    GTUArray<int, 4> ar2(ar1);
    cout << "It copied every data of ar1 to ar2, deep copy\n\n";
    cout << "Testing copy assignment with ar3 and ar2\n";
    GTUArray<int, 4> ar3;
    ar3 = ar2;
    cout << "It copied every data of ar2 to ar3, deep copy\n\n";
    cout << "Testing move constructer \n";
    GTUArray<int, 4> ar4(move(ar3));
    cout << "It transport every data of ar3 to ar4, shallow copy\n\n";
    cout << "Testing move assignment with ar5 and ar4 \n";
    GTUArray<int, 4> ar5;
    ar5 = move(ar4);
    cout << "It transport every data of ar4 to ar5, shallow copy\n\n";

    //Creating GTUIterator and GTUIteratorConst object
    cout << "\n\nCreating GTUIterator and GTUIteratorConst object.. \n";
    GTUIterator<int> arrIter;
    GTUIteratorConst<int> arrConstIter;
    cout << "GTUIterator and GTUIterator object has been created..\n";

    GTUArray<int, 4> arr;
    cout << "\n\nNow lets create an array named arr and test all GTUArray methods with it \n";

    //i add index operator overloading to add new values
    cout << "\n\n1) Testing operator [] to add new values\n";
    cout << "Adding 12, 153, 7 and 46 to our GTUArray using operator [] \n";
    arr[0] = 12;
    arr[1] = 153;
    arr[2] = 7;
    arr[3] = 46;

    cout << "Printing the values in GTUArray too see the result:\n";
    for (auto iter : arr)
        cout << iter << endl;

    //testing .size() method
    cout << "\n\n2) Testing .size() method for GTUArray \n";
    cout << "Printing the size using .size():\n";
    cout << "Size is: " << arr.size() << endl;

    //testing .empty() method
    cout << "\n\n3) Testing .empty() method for GTUArray\n";
    cout << "Checking if our GTUArray is empty or not using .empty() method: \n";
    if (arr.empty())
        cout
            << "ARRAY IS EMPTY" << endl;
    else
        cout << "ARRAY IS NOT EMPTY" << endl;

    //testing .erase() method
    cout << "\n\n4) Testing .erase() method for GTUArray\n";
    cout << "Erasing the first element of the GTUArray using .erase() method \n";
    arr.erase(arr.begin());
    cout << "Printing the values in GTUArray too see the result:\n";
    for (auto iter : arr)
        cout << iter << endl;

    // testing begin and end methods in for loop
    cout << "\n\n5) Testing .begin() and .end() method for GTUArray using GTUIterator\n";
    cout << "Testing begin and end methods using for loop and printing the elements \n";
    for (arrIter = arr.begin(); arrIter != arr.end(); arrIter++)
    {
        cout << *arrIter << endl;
    }

    // testing cbegin and cend methods in for loop
    cout << "\n\n6) Testing .cbegin() and .cend() method for GTUArray using GTUIteratorConst \n";
    cout << "Testing cbegin and cend methods using for loop and printing the elements \n";
    for (arrConstIter = arr.cbegin(); arrConstIter != arr.cend(); arrConstIter++)
    {
        cout << *arrConstIter << endl;
    }

    // testing std::for_each method with GTUArray
    cout << "\n\n7) Testing std::for_each method with the GTUArray \n";
    cout << "In every iteration printinforeach func will be called and print the value \n";
    for_each(arr.begin(), arr.end(), printinForEach);

    // testing std::find with GTUArray
    cout << "\n\n8) Testing std::find() method with a value that doesnt exist\n";
    cout << "std::find method searching for '43' \n";
    arrIter = find(arr.begin(), arr.end(), 43);
    if (arrIter != arr.end())
        cout << "Element found in set: " << *arrIter << '\n';
    else
        cout << "Element not found in set\n";

    // testing std::find with GTUArray one more time
    cout << "\n\n9) Testing std::find() method with a value that exists \n";
    cout << "std::find method searching for '153' \n";
    arrIter = find(arr.begin(), arr.end(), 153);
    if (arrIter != arr.end())
        cout << "Element found in set: " << *arrIter << '\n';
    else
        cout << "Element not found in set\n";

    // testing std::sort with GTUArray
    cout << "\n\n10) Testing std::sort() method with GTUArray \n";
    sort(arr.begin(), arr.end());
    cout << "Sort is done, lets print the sorted GTUArray \n";
    for (auto iter : arr)
        cout << iter << endl;

    // testing range based loop with GTUArray
    cout << "\n\n11) Testing range based loop with GTUArray \n";
    cout << "Lets print all elements using range based loop \n";
    for (auto iter : arr)
        cout << iter << endl;

    // testing .clear() method
    cout << "\n\n12) Testing .clear() method \n";
    cout << "Clear all content of our GTUArray using .clear() method \n";
    arr.clear();
    cout << "Printing the values in GTUArray too see the result:\n";
    for (auto iter : arr)
        cout << iter << endl;
    cout << "as you can see, there is no element left to be printed\n";
    cout << "all content has been deleted\n";
}

void testExceptions()
{
    // TESTING EXCEPTIONS
    cout << "\n\nLETS TEST SOME EXCEPTIONS! \n";
    cout << "Lets say we have an vector named vec with size 2, GTUVector<int> vec(2) \n";
    cout << "And try to reach an index  that is not valid\n";

    GTUVector<int> vec(2);
    cout << "vec size : " << vec.size() << endl;
    cout << "Lets try to reach the third index: \n";
    try
    {
        cout << vec[3] << endl;
    }
    catch (InvalidIndex e)
    {
        cout << e.getMessage() << endl;
    }
    cout << "As you can see, it throw an error. \n";

    // TESTING EXCEPTIONS
    cout << "\n\nLets say we have an array named arrE with size 4, GTUArr<int,4> arrE\n";
    cout << "And try to reach an index  that is not valid\n";

    GTUArray<int, 4> arrE;
    cout << "Array size : " << arrE.size() << endl;
    cout << "Lets try to reach the sixth index: \n";
    try
    {
        cout << arrE[6] << endl;
    }
    catch (InvalidIndex e)
    {
        cout << e.getMessage() << endl;
    }
    cout << "As you can see, it throw an error. \n";

    cout << "\nTHAT WAS ALL.. thank you so much... \n";
}