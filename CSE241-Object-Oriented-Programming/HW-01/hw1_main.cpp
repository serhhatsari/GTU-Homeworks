#include "hw1_lib.h"

int main()
{
    srand(time(NULL));

    int boardType, gameType;
    string board_inp, game_inp;
    bool ch_input = true;
    vector<char> possibleDirections;

    while (ch_input)
    {
        cout << "Which board do you wanna play in (1 to 6):  ";
        cin >> board_inp;
        ch_input = check_input(possibleDirections, 0, 1, board_inp);

        /* It will check whether board type input is valid or not */
    }

    boardType = board_inp[0] - '0';

    /* Converting char to int */

    ch_input = true;

    cout << endl;

    while (ch_input)
    {
        cout << "1- Human Player Game \n";
        cout << "2- Computer Game \n";
        cout << "Select the game type (1 or 2):  ";
        cin >> game_inp;

        ch_input = check_input(possibleDirections, 0, 2, game_inp);

        /* It will check whether game type input is valid or not */
    }

    gameType = game_inp[0] - '0';
    /* Converting char input to int */

    cout << "\nGOOD LUCK!\n\n";

    start_game(gameType, boardType);
    /* Starting the game */

    return 0;
}
