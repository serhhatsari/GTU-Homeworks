#include "pegsolitaire.h"

namespace Games
{
    /* PegSolitaire MEMBER FUNCTIONS */
    PegSolitaire::PegSolitaire()
    {
        initialize(); // initializing the board
    }

    void PegSolitaire::playUser(string move)
    {
        int a, b, c, d;

        int col_ind = find_column_index(move[0]); // finding the index
        int row_ind = (move[1] - '0') + 1;        // calculating the row index
        char direction;
        direction = move[3]; // taking direction from move

        if (direction == 'L' || direction == 'l') // if left
            a = 0, b = 0, c = -2, d = -4;
        else if (direction == 'R' || direction == 'r') // if right
            a = 0, b = 0, c = 2, d = 4;
        else if (direction == 'U' || direction == 'u') // if up
            a = -1, b = -2, c = 0, d = 0;
        else if (direction == 'D' || direction == 'd') // if if down
            a = 1, b = 2, c = 0, d = 0;

        // making move
        board[row_ind][col_ind] = cellTypes::EMPTY;
        board[row_ind + a][col_ind + c] = cellTypes::EMPTY;
        board[row_ind + b][col_ind + d] = cellTypes::PEG;
    }

    void PegSolitaire::playAuto()
    {
        string directions = "LlRrUuDd";
        string columnLetters = "AaBbCcDdEeFfGg";

        bool legal_move = true;
        char direction, col_letter;
        int row_ind, col_ind, a, b, c, d;
        string autoMove;

        while (legal_move)
        { // checking if move is legal
            autoMove = "";
            row_ind = rand() % 7 + 1;                // finding random row index
            col_letter = columnLetters[rand() % 14]; // finding random col letter
            direction = directions[rand() % 8];      // finding random direction
            autoMove += col_letter;
            autoMove += to_string(row_ind);
            autoMove += "-";
            autoMove += direction;
            legal_move = check_move(autoMove, 2); // finding check move
        }

        col_ind = find_column_index(autoMove[0]); // finding column index
        row_ind = (autoMove[1] - '0') + 1;        // finding row index
        direction = autoMove[3];                  // finding direction

        if (direction == 'L' || direction == 'l') // if left
            a = 0, b = 0, c = -2, d = -4;
        else if (direction == 'R' || direction == 'r') // if right
            a = 0, b = 0, c = 2, d = 4;
        else if (direction == 'U' || direction == 'u') // if up
            a = -1, b = -2, c = 0, d = 0;
        else if (direction == 'D' || direction == 'd') // if down
            a = 1, b = 2, c = 0, d = 0;

        // making the move
        board[row_ind][col_ind] = cellTypes::EMPTY;
        board[row_ind + a][col_ind + c] = cellTypes::EMPTY;
        board[row_ind + b][col_ind + d] = cellTypes::PEG;
    }

    int PegSolitaire::find_column_index(char column_letter)
    {
        int column_index;

        if (column_letter == 'A' || column_letter == 'a')
        { // if a
            column_index = 2;
        }
        else if (column_letter == 'B' || column_letter == 'b')
        { // if b
            column_index = 4;
        }
        else if (column_letter == 'C' || column_letter == 'c')
        { // if c
            column_index = 6;
        }
        else if (column_letter == 'D' || column_letter == 'd')
        { // if d
            column_index = 8;
        }
        else if (column_letter == 'E' || column_letter == 'e')
        { // if e
            column_index = 10;
        }
        else if (column_letter == 'F' || column_letter == 'f')
        { // if f
            column_index = 12;
        }
        else if (column_letter == 'G' || column_letter == 'g')
        { // if g
            column_index = 14;
        }
        return column_index;
    }

    bool PegSolitaire::check_move(string move, int gameType)
    {
        int a, b, c, d;

        int col_ind = find_column_index(move[0]); // finding random column index
        int row_ind = (move[1] - '0') + 1;        // finding random row index
        char direction = move[3];                 // finding random direciton

        if (direction == 'L' || direction == 'l') // if left
            a = 0, b = 0, c = -2, d = -4;
        else if (direction == 'R' || direction == 'r') // if right
            a = 0, b = 0, c = 2, d = 4;
        else if (direction == 'U' || direction == 'u') // if up
            a = -1, b = -2, c = 0, d = 0;
        else if (direction == 'D' || direction == 'd') // if down
            a = 1, b = 2, c = 0, d = 0;

        if (board[row_ind][col_ind] == cellTypes::PEG)
        { // checking if it is a peg
            if (board[row_ind + a][col_ind + c] == cellTypes::NONCELL)
            { // checking the next index
                if (gameType == 1)
                { // game type
                    cout << endl;
                    print();
                    cerr << "YOUR MOVE IS INVALID! MAKE A NEW MOVE. \n \n";
                }
                return true;
            }

            else if (board[row_ind + a][col_ind + c] == cellTypes::EMPTY)
            {
                if (gameType == 1)
                { // game type equals 1
                    cout << endl;
                    print(); // printing board
                    cerr << "YOUR MOVE IS INVALID! MAKE A NEW MOVE. \n \n";
                }
                return true;
            }

            else if (board[row_ind + a][col_ind + c] == cellTypes::PEG)
            { // if next is peg
                if (board[row_ind + b][col_ind + d] == cellTypes::EMPTY)
                { // if the next to next is empty
                    return false;
                }

                else
                {
                    if (gameType == 1)
                    { // if game type equals one
                        cout << endl;
                        print(); // printing the board
                        cerr << "YOUR MOVE IS INVALID! MAKE A NEW MOVE. \n \n";
                    }
                    return true;
                }
            }
        }

        if (gameType == 1)
        { // if game type equals
            cout << endl;
            print();
            cerr << "YOUR MOVE IS INVALID! MAKE A NEW MOVE. \n \n";
        }
        return true;
    }

    bool PegSolitaire::check_input(string userInput, int gameType)
    {
        string directions = "LlRrUuDd";
        if (userInput.size() == 4)
        {
            if ((userInput[0] >= 'a' && userInput[0] <= 'g') || (userInput[0] >= 'A' && userInput[0] <= 'G'))
            {
                /* column letter should be between 'a' and some upper bound  like 'g' */
                if (userInput[1] >= '1' && userInput[1] <= '7')
                {
                    /* row index should be between 1 and max col*/
                    if (userInput[2] == '-')
                    {
                        for (int i = 0; i < directions.size(); i++)
                        {
                            if (userInput[3] == directions[i])
                                return false;
                        }
                    }
                }
            }
        }
        if (gameType == 1)
        {
            cout << endl;
            print();
            cerr << "INPUT FORMAT IS WRONG! MAKE A NEW MOVE ACCORDING TO EXAMPLES. \n";
            cout << "Examples:  E4-D , A2-U , C5-R , F3-L \n \n";
        }
        return true;
    }

    void PegSolitaire::print() const
    {
        sleep_until(system_clock::now() + milliseconds(150));

        cout << "\u001b[2J";
        cout << "\u001b[1000A";
        // ansi escape sequence
        int i = 0, k = 0;
        cout << "   A B C D E F G ";

        /* printing the upper string */

        for (i = 1; i < 10; i++) /* printing the board */
        {
            for (k = 1; k < 16; k++)
            {
                if (k == 1 && i > 1 && i < 9)
                    cout << i - 1 << " ";

                if (board[i][k] == cellTypes::EMPTY)
                    cout << ".";

                else if (board[i][k] == cellTypes::PEG)
                    cout << "P";

                else if (board[i][k] == cellTypes::NONCELL && i != 1)
                    cout << " ";
            }
            cout << endl;
        }
    }

    bool PegSolitaire::endGame()
    {
        int i, k;
        // checking if game is finished
        for (i = 0; i < 11; i++)
        {
            for (k = 0; k < 17; k++)
            {
                if (board[i][k] == cellTypes::PEG)
                { // checking if it is peg

                    if (board[i][k + 2] == cellTypes::PEG) /* right side check */
                        if (board[i][k + 4] == cellTypes::EMPTY)
                            return true;

                    if (board[i][k - 2] == cellTypes::PEG) /* left side check */
                        if (board[i][k - 4] == cellTypes::EMPTY)
                            return true;

                    if (board[i + 1][k] == cellTypes::PEG) /* down check */
                        if (board[i + 2][k] == cellTypes::EMPTY)
                            return true;

                    if (board[i - 1][k] == cellTypes::PEG) /* upper check */
                        if (board[i - 2][k] == cellTypes::EMPTY)
                            return true;
                }
            }
        }

        return false;
    }

    int PegSolitaire::boardScore()
    {
        int i = 0, k = 0;
        int count = 0;

        for (i = 0; i < 11; i++)
        { /* until max row */
            for (k = 0; k < 17; k++)
            { /* until max column */
                if (board[i][k] == cellTypes::PEG)
                    count++; /* incrementing the number of pegs */
            }
        }
        return count; // return the number of pegs that left
    }

    void PegSolitaire::initialize()
    {
        board = {
            // initializing the board
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::EMPTY, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::PEG, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
            {cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL, cellTypes::NONCELL},
        };
    }
}