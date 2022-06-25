#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <string>

using namespace std;
namespace GTU_SARI
{
    class InvalidIndex
    {
    public:
        // if given index is not valid it will throw an error
        InvalidIndex(string msg)
        {
            message = msg;
        }
        string getMessage()
        {
            return message;
        }

    private:
        string message;
    };
}
#endif