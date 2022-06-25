#include "klotski.h"

namespace Games
{ /* Klotski MEMBER FUNCTIONS */
    Klotski::Klotski()
    {
        initialize(); // initialzing the board
    }

    void Klotski::playUser(string move)
    {

        int number = move[0] - '0';
        int i, k, temp;

        for (i = 1; i < 6; i++)
        { // until row
            for (k = 1; k < 5; k++)
            { // until column
                if (board[i][k] == number)
                {
                    if (move[1] == 'L' || move[1] == 'l')
                    { // if left
                        temp = board[i][k - 1];
                        board[i][k - 1] = board[i][k];
                        board[i][k] = temp;
                    }
                    else if (move[1] == 'U' || move[1] == 'u')
                    { // if up
                        temp = board[i - 1][k];
                        board[i - 1][k] = board[i][k];
                        board[i][k] = temp;
                    }
                }
            }
        }

        for (i = 5; i >= 1; i--)
        { // until row
            for (k = 4; k >= 1; k--)
            { // until column
                if (board[i][k] == number)
                {
                    if (move[1] == 'R' || move[1] == 'r')
                    { // if right
                        temp = board[i][k + 1];
                        board[i][k + 1] = board[i][k];
                        board[i][k] = temp;
                    }

                    else if (move[1] == 'D' || move[1] == 'd')
                    { // if down
                        temp = board[i + 1][k];
                        board[i + 1][k] = board[i][k];
                        board[i][k] = temp;
                    }
                }
            }
        }
        move_num++;
    }

    void Klotski::playAuto()
    {

        string directions = "LlRrUuDd";
        string nums = "0123456789";

        bool legal_move = true;
        char direction, numLet;
        string autoMove;
        int i, k, number, temp;

        while (legal_move)
        { // checking if move is legal or not
            autoMove = "";
            numLet = nums[rand() % 10];         // random number
            direction = directions[rand() % 8]; // rand direction
            autoMove += numLet;
            autoMove += direction;
            legal_move = check_move(autoMove, 2);
        }

        number = autoMove[0] - '0';
        for (i = 1; i < 6; i++)
        { // until row
            for (k = 1; k < 5; k++)
            { // until column
                if (board[i][k] == number)
                {
                    if (autoMove[1] == 'L' || autoMove[1] == 'l')
                    { // if left
                        temp = board[i][k - 1];
                        board[i][k - 1] = board[i][k];
                        board[i][k] = temp;
                    }
                    else if (autoMove[1] == 'U' || autoMove[1] == 'u')
                    { // if up
                        temp = board[i - 1][k];
                        board[i - 1][k] = board[i][k];
                        board[i][k] = temp;
                    }
                }
            }
        }

        for (i = 5; i >= 1; i--)
        { // until row
            for (k = 4; k >= 1; k--)
            { // until column
                if (board[i][k] == number)
                {
                    if (autoMove[1] == 'R' || autoMove[1] == 'r')
                    { // if right
                        temp = board[i][k + 1];
                        board[i][k + 1] = board[i][k];
                        board[i][k] = temp;
                    }

                    else if (autoMove[1] == 'D' || autoMove[1] == 'd')
                    { // if down
                        temp = board[i + 1][k];
                        board[i + 1][k] = board[i][k];
                        board[i][k] = temp;
                    }
                }
            }
        }
        move_num++;
    }

    void Klotski::print() const
    {
        int i, k;
        cout << "\u001b[2J";
        cout << "\u001b[1000A";

        sleep_until(system_clock::now() + nanoseconds(5));

        // printing the board

        cout << "-----------\n";
        for (i = 1; i < 6; i++)
        {
            for (k = 1; k < 5; k++)
            {

                if (k != 4)
                {
                    if (board[i][k] != -5)
                    {
                        cout << board[i][k] << "  ";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                else
                {
                    if (board[i][k] != -5)
                    {
                        cout << board[i][k];
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << "\n\n";
        }
        cout << "---     ----\n";
    }

    bool Klotski::check_input(string userInput, int gameType)
    {
        string directions = "LlRrUuDd";

        if (userInput.size() == 2)
        { // check input size
            if ((userInput[0] >= '0' && userInput[0] <= '9'))
            { // check input
                for (int i = 0; i < directions.size(); i++)
                {
                    if (userInput[1] == directions[i])
                        return false;
                }
            }
        }

        return true;
    }

    bool Klotski::check_move(string move, int gameType)
    {

        int number = move[0] - '0';
        int i, k;
        bool check = false;

        for (i = 1; i < 6; i++)
        {
            for (k = 1; k < 5; k++)
            {
                if (board[i][k] == number)
                {
                    if (move[1] == 'L' || move[1] == 'l')
                    { // if left
                        if (board[i][k - 1] != number && board[i][k - 1] != -5)
                        {
                            check = true;
                        }
                    }
                    else if (move[1] == 'R' || move[1] == 'r')
                    { // if right
                        if (board[i][k + 1] != number && board[i][k + 1] != -5)
                        {
                            check = true;
                        }
                    }
                    else if (move[1] == 'U' || move[1] == 'u')
                    { // if up
                        if (board[i - 1][k] != number && board[i - 1][k] != -5)
                        {
                            check = true;
                        }
                    }
                    else if (move[1] == 'D' || move[1] == 'd')
                    { // if down
                        if (board[i + 1][k] != number && board[i + 1][k] != -5)
                        {
                            check = true;
                        }
                    }
                }
            }
        }

        return check;
    }

    bool Klotski::endGame()
    {

        // checking the bottom indexes
        // check if the game has finished
        if (board[4][2] == 1 && board[4][3] == 1)
        {
            if (board[5][2] == 1 && board[5][3] == 1)
            {
                return false;
            }
        }
        return true;
    }

    int Klotski::boardScore()
    {
        if (!endGame())
            return 0;
        return move_num;
    }

    void Klotski::initialize()
    {

        // initialazing the board

        int i, k;
        board.resize(7, vector<int>(6, -1));
        for (i = 1; i < 6; i++)
        {

            for (k = 1; k < 5; k++)
            {
                switch (i)
                {

                case 1:
                    switch (k)
                    { // for first row
                    case 1:
                        board[i][k] = 0;
                        break;
                    case 2:
                        board[i][k] = 1;
                        break;
                    case 3:
                        board[i][k] = 1;
                        break;
                    case 4:
                        board[i][k] = 2;
                        break;
                    }
                    break;
                case 2:
                    switch (k)
                    { // for second row
                    case 1:
                        board[i][k] = 0;
                        break;
                    case 2:
                        board[i][k] = 1;
                        break;
                    case 3:
                        board[i][k] = 1;
                        break;
                    case 4:
                        board[i][k] = 2;
                        break;
                    }
                    break;
                case 3: // for third row
                    switch (k)
                    {
                    case 1:
                        board[i][k] = 3;
                        break;
                    case 2:
                        board[i][k] = 4;
                        break;
                    case 3:
                        board[i][k] = 4;
                        break;
                    case 4:
                        board[i][k] = 5;
                        break;
                    }
                    break;
                case 4: // for fourth row
                    switch (k)
                    {
                    case 1:
                        board[i][k] = 3;
                        break;
                    case 2:
                        board[i][k] = 6;
                        break;
                    case 3:
                        board[i][k] = 7;
                        break;
                    case 4:
                        board[i][k] = 5;
                        break;
                    }
                    break;
                case 5: // for fifth row
                    switch (k)
                    {
                    case 1:
                        board[i][k] = 8;
                        break;
                    case 2:
                        board[i][k] = -5;
                        break;
                    case 3:
                        board[i][k] = -5;
                        break;
                    case 4:
                        board[i][k] = 9;
                        break;
                    }
                    break;
                }
            }
        }
    }
}