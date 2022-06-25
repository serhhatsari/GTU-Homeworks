#include "boardgame2d.h"

namespace Games
{

    /* Board2D MEMBER FUNCTIONS */

    void BoardGame2D::playUser()
    {
        string userMove;
        bool check_inp, check_mov;

        while (endGame()) // checking if game is finished or not
        {
            print(); // printing the board
            check_inp = true;
            check_mov = true;

            while (1)
            {
                cout << "Enter your move: ";
                cin >> userMove; // taking move from the user
                check_inp = check_input(userMove, 1);
                if (!check_inp) // checking if input format is valid
                {
                    check_mov = check_move(userMove, 1); // checking if input is valid

                    if (!check_mov)
                    {
                        break;
                    }
                }
            }
            playUser(userMove); // making the move
            cout << endl;
        }
        print(); // printing the board after game is finished
        cout << "GAME HAS FINISHED \n \n";
        cout << "Board Score: " << boardScore() << "\n \n"; // printing board score
        cout << "Wait a 5 second in here...\n";
        sleep_until(system_clock::now() + seconds(5)); // sleeping
    }

    void BoardGame2D::playAutoAll()
    {
        while (endGame()) // checking if game is finished or not
        {
            print();    // printing the board
            playAuto(); // making a random move
        }
        print(); // printing the board after game finished
        cout << "GAME HAS FINISHED \n";
        cout << "Board Score: " << boardScore() << "\n"; // board score
        cout << "Waiting 5 second in here...\n";
        sleep_until(system_clock::now() + seconds(5)); // sleeeping
    }

    ostream &operator<<(ostream &outputStream, const BoardGame2D &obj)
    {
        obj.print(); // printing
        return outputStream;
    }

    void BoardGame2D::playVector(vector<BoardGame2D *> objs)
    {
        for (size_t i = 0; i < objs.size(); i++)
        {
            objs[i]->playAutoAll(); // playing games one by one
        }
    }
}