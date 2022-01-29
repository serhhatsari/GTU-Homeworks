#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

namespace Games
{
    class BoardGame2D
    {
    public:
        virtual void playUser(string move) = 0; /*playUser takes a string as a parameterand plays the game accordingly */

        virtual void playUser() final;

        virtual void playAuto() = 0; /* playAuto plays the game by the computerfor one move. */

        virtual void playAutoAll() final; /* It plays the game until it is over. */

        virtual void print() const = 0; /* prints the game on the screen starting from the top left corner of the terminal. */

        friend ostream &operator<<(ostream &outputStream, const BoardGame2D &obj);

        virtual bool endGame() = 0; /* endGame returns true if the game is ended. */

        virtual int boardScore() = 0; /* boardScore returns an intscore value for the current board */

        virtual void initialize() = 0; /* initializes the board.  */

        virtual bool check_input(string userInput, int gameType) = 0; /* this func check input format */

        virtual bool check_move(string move, int gameType) = 0; /* this func check the validity of the move */

        static void playVector(vector<BoardGame2D *> objs);

    private:
    };

}
#endif // BOARDGAME2D_H