#include "hw2_lib.h"

int main()
{
    srand(time(0));

    cout << "WELCOME TO THE GAME!\n\n";
    cout << "VALID SAVE COMMAND FORMAT: \n";
    cout << "SAVE FILE_NAME\n";
    cout << "example: if you want to save a file named MYFILE\n";
    cout << "you can save it with the SAVE MYFILE command\n\n";
    cout << "VALID LOAD COMMAND FORMAT:\n";
    cout << "LOAD FILE_NAME\n";
    cout << "example: if you have a board file named BOARD.txt\n";
    cout << "you can load this file with the LOAD BOARD.txt command\n\n";

    cout << "LETS GO!\n\n";
    int boardType, gameType;
    string board_inp, game_inp;
    bool ch_input = true;
    int is_load_save;
    vector<char> possibleDirections;

    while (ch_input)
    {
        cout << "Which board do you wanna play in (1 to 6):  ";
        getline(cin, board_inp);
        /* taking the board input */

        is_load_save = check_load_save(board_inp);

        /*checking if it is a load or save command */

        if (is_load_save == 1)
        { /*if load */
            cout << endl;
            start_game(1, 1, true, board_inp);
            return 0;
        }
        else if (is_load_save == 2)
        { /* if save */
            cerr << "\n\nYOU CANT SAVE BOARD IN THIS STEP OF THE GAME!\n \n";
            continue;
        }

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
        getline(cin, game_inp);

        /* taking the game type input */

        is_load_save = check_load_save(game_inp);

        /* checking if it is a load or save command */

        if (is_load_save == 1)
        {
            cout << endl;
            start_game(1, 1, true, game_inp);
            return 0;
        }
        else if (is_load_save == 2)
        {
            cerr << "\n\nYOU CANT SAVE BOARD IN THIS STEP OF THE GAME!\n \n";
            continue;
        }

        ch_input = check_input(possibleDirections, 0, 2, game_inp);

        /* It will check whether game type input is valid or not */
    }

    gameType = game_inp[0] - '0';
    /* Converting char input to int */

    cout << "\nGOOD LUCK!\n\n";

    start_game(gameType, boardType, false, " ");
    /* Starting the game */

    return 0;
}
