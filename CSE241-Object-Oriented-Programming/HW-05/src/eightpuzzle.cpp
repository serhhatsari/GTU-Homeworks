#include "eightpuzzle.h"

namespace Games
{ /* EightPuzzle MEMBER FUNCTIONS */
    EightPuzzle::EightPuzzle()
    {
        initialize(); // initiliazing the board
    }

    void EightPuzzle::playUser(string move)
    {
        int number = move[0] - '0'; // taking the first number
        int num_i, num_k, i, k;

        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                if (board[i][k] == number)
                {
                    num_i = i; // finding the index of the number
                    num_k = k;
                }
            }
        }

        if (move[1] == 'L' || move[1] == 'l')
        { // if left
            board[num_i][num_k] = 0;
            board[num_i][num_k - 1] = number;
        }
        else if (move[1] == 'R' || move[1] == 'r')
        { // if right
            board[num_i][num_k] = 0;
            board[num_i][num_k + 1] = number;
        }
        else if (move[1] == 'U' || move[1] == 'u')
        { // if up
            board[num_i][num_k] = 0;
            board[num_i - 1][num_k] = number;
        }
        else if (move[1] == 'D' || move[1] == 'd')
        { // if down
            board[num_i][num_k] = 0;
            board[num_i + 1][num_k] = number;
        }
    }

    void EightPuzzle::playAuto()
    {
        string directions = "LlRrUuDd";
        string nums = "12345678";

        bool legal_move = true;
        char direction, numLet;
        string autoMove;

        while (legal_move)
        { // checkinf if move is legal
            autoMove = "";
            numLet = nums[rand() % 8];          // random number
            direction = directions[rand() % 8]; // random direction
            autoMove += numLet;
            autoMove += direction;
            legal_move = check_move(autoMove, 2);
        }

        int number = autoMove[0] - '0';
        int num_i, num_k, i, k;

        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                if (board[i][k] == number)
                {
                    num_i = i;
                    num_k = k;
                }
            }
        }

        if (autoMove[1] == 'L' || autoMove[1] == 'l')
        { // if left
            board[num_i][num_k] = 0;
            board[num_i][num_k - 1] = number;
        }
        else if (autoMove[1] == 'R' || autoMove[1] == 'r')
        { // if right
            board[num_i][num_k] = 0;
            board[num_i][num_k + 1] = number;
        }
        else if (autoMove[1] == 'U' || autoMove[1] == 'u')
        { // if up
            board[num_i][num_k] = 0;
            board[num_i - 1][num_k] = number;
        }
        else if (autoMove[1] == 'D' || autoMove[1] == 'd')
        { // if down
            board[num_i][num_k] = 0;
            board[num_i + 1][num_k] = number;
        }
    }

    void EightPuzzle::print() const
    {
        int i, k;
        sleep_until(system_clock::now() + nanoseconds(10));

        cout << "\u001b[2J";
        cout << "\u001b[1000A";
        // printing the board
        cout << "-----------\n";
        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                if (k != 3)
                    cout << board[i][k] << "  ";
                else
                    cout << board[i][k];
            }
            cout << "\n\n";
        }
        cout << "-----------\n";
    }

    bool EightPuzzle::check_move(string move, int gameType)
    {
        int number = move[0] - '0';
        int num_i, num_k, i, k;

        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                if (board[i][k] == number)
                {
                    num_i = i;
                    num_k = k;
                }
            }
        }

        if (move[1] == 'L' || move[1] == 'l')
        { // check left side
            if (board[num_i][num_k - 1] == 0)
            {
                return false;
            }
        }
        else if (move[1] == 'R' || move[1] == 'r')
        { // check right side
            if (board[num_i][num_k + 1] == 0)
            {
                return false;
            }
        }
        else if (move[1] == 'U' || move[1] == 'u')
        { // check up side
            if (board[num_i - 1][num_k] == 0)
            {
                return false;
            }
        }
        else if (move[1] == 'D' || move[1] == 'd')
        { // check down side
            if (board[num_i + 1][num_k] == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool EightPuzzle::check_input(string userInput, int gameType)
    {

        string directions = "LlRrUuDd";

        if (userInput.size() == 2)
        { // checking input size
            if ((userInput[0] >= '1' && userInput[0] <= '8'))
            { // checking input
                for (int i = 0; i < directions.size(); i++)
                {
                    if (userInput[1] == directions[i])
                        return false;
                }
            }
        }

        return true;
    }

    bool EightPuzzle::endGame()
    {
        vector<int> linearBoard(9, 0);
        int i, k, j, inversion = 0;

        j = 0;
        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                linearBoard[j] = board[i][k]; // making linear
                j++;
            }
        }

        for (i = 0; i < 9; i++)
        {
            for (k = i; k < 9; k++)
            {
                if (linearBoard[k] != 0)
                {
                    if (linearBoard[i] > linearBoard[k])
                    {
                        inversion++; // incrementing inversion
                    }
                }
            }
        }

        if (inversion != 0)
        { // checking inversion
            return true;
        }
        else
        {
            if (linearBoard[8] == 0)
                return false;
        }
    }

    int EightPuzzle::boardScore()
    {
        vector<int> linearBoard(9, 0);
        int i, k, j, inversion = 0;

        j = 0;
        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                linearBoard[j] = board[i][k]; // making linear
                j++;
            }
        }

        for (i = 0; i < 9; i++)
        {
            for (k = i; k < 9; k++)
            {
                if (linearBoard[k] != 0)
                {
                    if (linearBoard[i] > linearBoard[k])
                    {
                        inversion++; // incrementing inversion
                    }
                }
            }
        }
        return inversion; // returning the inversion
    }

    void EightPuzzle::initialize()
    {

        int i, k, j, rand_val, inversion = 0;
        bool check, isExists, isSolvable = true;
        board.resize(5, vector<int>(5, -1));
        vector<int> linearBoard(8, -1);

        while (isSolvable)
        { // checking if it is solvable
            for (i = 0; i < 8; i++)
            {
                check = true;

                while (check)
                {
                    isExists = false;
                    rand_val = rand() % 8 + 1;
                    for (k = 0; k < i; k++)
                    {
                        if (rand_val == linearBoard[k])
                        {
                            isExists = true;
                        }
                    }
                    if (!isExists)
                        check = false;
                }
                linearBoard[i] = rand_val; // linear vector
            }

            for (i = 0; i < 8; i++)
            {
                for (k = i; k < 8; k++)
                {
                    if (linearBoard[k] != 0)
                    {
                        if (linearBoard[i] > linearBoard[k])
                        {
                            inversion++; // inversion count
                        }
                    }
                }
            }

            if (inversion % 2 == 0) // check inversion
                isSolvable = false;

            inversion = 0;
        }

        j = 0;
        for (i = 1; i < 4; i++)
        {
            for (k = 1; k < 4; k++)
            {
                if (k == 3 && i == 3)
                {
                    continue;
                }
                else
                {
                    board[i][k] = linearBoard[j];
                    j++;
                }
            }
        }

        board[3][3] = 0;
    }
}