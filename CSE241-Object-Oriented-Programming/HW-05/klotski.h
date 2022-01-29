#ifndef KLOTSKI_H
#define KLOTSKI_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "boardgame2d.h"

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

namespace Games
{

    class Klotski : public BoardGame2D
    {
    public:
        Klotski();

        void playUser(string move); /*playUser takes a string as a parameterand plays the game accordingly */
        void playAuto();            /* playAuto plays the game by the computerfor one move. */
        void print() const;         /* prints the game on the screen starting from the top left corner of the terminal. */
        bool endGame();             /* endGamereturns true if the game is ended. */
        bool check_input(string userInput, int gameType);
        bool check_move(string move, int gameType);
        int boardScore(); /* boardScore returns an intscore value for the current board */
        void initialize(); /* initializes the board.  */

    private:
        vector<vector<int>> board;
        int move_num = 0;
    };

}

#endif // KLOTSKI_H