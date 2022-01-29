#include "hw1_lib.h"

void start_game(int gameType, int boardType)
{
    int column_index, row_index, boardRow, boardColumn;
    bool check_move, check_game = true, ch_input = true;
    char direction, side, column_letter;
    /* direction is the way of move, side is left or right */

    string leri_inp, move_input, upperString;
    /* inputs */

    vector<vector<cells>> board;
    /* 2D array of cells */

    vector<char> possibleDirections;

    get_board_info(boardType, board, boardRow, boardColumn, upperString, possibleDirections);
    /*assigning the values according to board type */

    print_board(board, boardRow, boardColumn, upperString);
    /* printing the board */

    while (check_game)
    {
        if (gameType == 1) /* check for the game type */
        {
            while (ch_input)
            {
                cout << "Examples:  E4-D , A2-U , C5-R , F3-L \n";
                cout << "Enter your move according to examples: ";
                cin >> move_input;
                ch_input = check_input(possibleDirections, boardType, 3, move_input);
            }
            /* taking the input and checking if it is valid or not */

            column_letter = move_input[0];
            row_index = move_input[1] - '0';
            direction = move_input[3];

            /*decomposing move input */

            ch_input = true;

            if ((direction == 'U' || direction == 'u' || direction == 'D' || direction == 'd') && boardType == 6)
            {
                while (ch_input)
                {
                    cout << "Right(R) or Left(L) \n";
                    cout << "Enter your direction (R or L): ";
                    cin >> leri_inp;
                    ch_input = check_input(possibleDirections, boardType, 4, leri_inp);
                } /* side check */

                side = leri_inp[0];
            }

            /* if its 6.th board and U,D. It will ask right or left */

            ch_input = true;

            find_column_index(boardType, column_letter, column_index);
            /* find the column index by looking column letter */

            row_index++;
        }

        else if (gameType == 2)
        {
            find_random_move(possibleDirections, boardRow, boardColumn, row_index, column_index, direction, side);

            /* if the game type is 2 */
            /* this function will find a new valid move */
        }

        check_move = check_legal_move(side, boardType, row_index, column_index, direction, board);

        /* it will check if our move is valid or invalid */

        if (check_move)
        {
            if (gameType == 2)
                print_move(boardType, row_index, column_index, direction);
            /* if it is computer game, it'll print the move */

            make_move(side, boardType, row_index, column_index, direction, board);
            /*this func will make the move on the board */

            cout << "\n";

            print_board(board, boardRow, boardColumn, upperString);
            /* printing the board */
        }
        else
        {
            if (gameType != 2)
            {
                /* if the move invalid, it will throw an error message */
                cout << "\n\n\n!!! That is an INVALID move! MAKE A NEW MOVE !!!\n\n";

                /* and it will print the board again to ask a new move */
                print_board(board, boardRow, boardColumn, upperString);
                cout << endl;
            }
        }

        check_game = check_if_finished(boardType, boardRow, boardColumn, board);
        /* it will check if any valid move is left or not */
    }
    print_result(boardRow, boardColumn, board);
    /* this func will count how many peg has left and print the result */
}

bool check_input(vector<char> possibleDirections, int board_number, int input_type, string user_input)
{
    int i = 0, max_directions = 8;
    char max_row = '9';
    char small_char = 'i', big_char = 'I';

    if (board_number == 1 || board_number == 4)
        small_char = 'g', big_char = 'G', max_row = '7';
    else if (board_number == '3')
        small_char = 'h', big_char = 'H', max_row = '8';
    else if (board_number == 6)
        max_row = '5', i = 4;

    /* some changes according to board type */
    /* board type will effect our upper bounds like max column and max row */

    if (input_type == 1) /* checking the whether the board type input is valid or not */
    {
        if (user_input.size() > 1) /* check of the input size */
        {
            cout << "\nINVALID INPUT!!!\n";
            return true;
        }
        else if (user_input[0] >= '1' && user_input[0] <= '6')
        {
            /* valid boards are 1 to 6, so it will check if input is between them*/
            return false;
        }
    }
    else if (input_type == 2) /* checking whether the game type input is valid or not */
    {
        if (user_input.size() > 1)
        {
            cout << "\nINVALID INPUT!!!\n";
            return true;
        }
        else if (user_input[0] >= '1' && user_input[0] <= '2')
        {
            /* valid game types are 1 and 2, so it will check if input is 1 or 2 */
            return false;
        }
    }
    else if (input_type == 3)
    {
        if (user_input.size() > 4)
        {
            cout << "\nINVALID INPUT!!! \n";
            return true;
        }
        if ((user_input[0] >= 'a' && user_input[0] <= small_char) || (user_input[0] >= 'A' && user_input[0] <= big_char))
        {
            /* column letter should be between 'a' and some upper bound  like 'g' */
            if (user_input[1] >= '1' && user_input[1] <= max_row)
            {
                /* row index should be between 1 and max col*/
                if (user_input[2] == '-')
                {
                    /*check if characther '-' is in the 2th index */
                    for (i = 0; i < max_directions; i++)
                    {
                        /* check for the directions */
                        if (user_input[3] == possibleDirections[i])
                            return false;
                    }
                }
            }
        }
    }
    else if (input_type == 4)
    {
        /*it will check the side input */

        if (user_input.size() > 1)
        {
            cout << "\nINVALID INPUT!!! \n";
            return true;
        }
        else if (user_input[0] == 'L' || user_input[0] == 'l')
        {
            return false;
        }

        else if (user_input[0] == 'R' || user_input[0] == 'r')
        {
            return false;
        }
        /* Left or Right input check */
    }

    cout << "\nINVALID INPUT!!!\n";
    return true;
}

void print_board(vector<vector<cells>> board, int row, int column, string upper_word)
{
    int i = 0, k = 0;
    cout << upper_word;
    /* printing the upper string */

    for (i = 1; i < row - 1; i++) /* printing the board */
    {
        for (k = 1; k < column - 1; k++)
        {
            if (k == 1 && i > 1 && i < row - 2)
                cout << i - 1 << " ";

            if (board[i][k] == cells::EMPTY)
                cout << ".";

            else if (board[i][k] == cells::PEG)
                cout << "P";

            else if (board[i][k] == cells::NONCELL && i != 1)
                cout << " ";
        }
        cout << endl;
    }
}

bool check_legal_move(char side, int board_number, int row_ind, int col_ind, char direction, vector<vector<cells>> board)
{
    int a, b, c, d;
    /*
     we will check the move by assigning
      some values to these variables
    */

    /*
     board[row_ind + a][col_ind + c]
     board[row_ind + b][col_ind + d]
    */

    /* some arrangments according to board type */

    if (board_number != 6)
    {
        if (direction == 'L' || direction == 'l')
            a = 0, b = 0, c = -2, d = -4;
        else if (direction == 'R' || direction == 'r')
            a = 0, b = 0, c = 2, d = 4;
        else if (direction == 'U' || direction == 'u')
            a = -1, b = -2, c = 0, d = 0;
        else if (direction == 'D' || direction == 'd')
            a = 1, b = 2, c = 0, d = 0;
    }
    else /* if it is 6.th board, itll go here */
    {
        if (direction == 'L' || direction == 'l')
        {
            a = 0, b = 0, c = -4, d = -8;
        }

        else if (direction == 'R' || direction == 'r')
        {
            a = 0, b = 0, c = 4, d = 8;
        }

        else if (direction == 'U' || direction == 'u')
        {
            if (side == 'L' || side == 'l')
                a = -1, b = -2, c = -2, d = -4;
            else if (side == 'R' || side == 'r')
                a = -1, b = -2, c = 2, d = 4;
        }

        else if (direction == 'D' || direction == 'd')
        {
            if (side == 'L' || side == 'l')
                a = 1, b = 2, c = -2, d = -4;
            else if (side == 'R' || side == 'r')
                a = 1, b = 2, c = 2, d = 4;
        }
    }

    /*checking whether move is valid or not */

    if (board[row_ind][col_ind] == cells::PEG)
    {
        if (board[row_ind + a][col_ind + c] == cells::NONCELL)
            return false;

        else if (board[row_ind + a][col_ind + c] == cells::EMPTY)
            return false;

        else if (board[row_ind + a][col_ind + c] == cells::PEG)
        {
            if (board[row_ind + b][col_ind + d] == cells::EMPTY)
                return true;

            else
                return false;
        }
    }

    return false;
}

void make_move(char side, int board_number, int row_ind, int col_ind, char direction, vector<vector<cells>> &board)
{
    int a, b, c, d;
    /*
     well make the move by assigning
     some values to these variables
     */

    /*
     board[row_ind + a][col_ind + c]
     board[row_ind + b][col_ind + d]
    */

    /* some arrangments according to board type */
    if (board_number != 6)
    {
        if (direction == 'L' || direction == 'l')
            a = 0, b = 0, c = -2, d = -4;
        else if (direction == 'R' || direction == 'r')
            a = 0, b = 0, c = 2, d = 4;
        else if (direction == 'U' || direction == 'u')
            a = -1, b = -2, c = 0, d = 0;
        else if (direction == 'D' || direction == 'd')
            a = 1, b = 2, c = 0, d = 0;
    }
    else
    { /* if board type is 6, itll go here */
        if (direction == 'L' || direction == 'l')
        {
            a = 0, b = 0, c = -4, d = -8;
        }

        else if (direction == 'R' || direction == 'r')
        {
            a = 0, b = 0, c = 4, d = 8;
        }

        else if (direction == 'U' || direction == 'u')
        {
            if (side == 'L' || side == 'l')
                a = -1, b = -2, c = -2, d = -4;
            else if (side == 'R' || side == 'r')
                a = -1, b = -2, c = 2, d = 4;
        }

        else if (direction == 'D' || direction == 'd')
        {
            if (side == 'L' || side == 'l')
                a = 1, b = 2, c = -2, d = -4;
            else if (side == 'R' || side == 'r')
                a = 1, b = 2, c = 2, d = 4;
        }
    }

    /*making the move */

    board[row_ind][col_ind] = cells::EMPTY;
    board[row_ind + a][col_ind + c] = cells::EMPTY;
    board[row_ind + b][col_ind + d] = cells::PEG;
}

bool check_if_finished(int board_number, int row, int column, vector<vector<cells>> board)
{
    int i, k;

    /*checking if any legal move has left */

    for (i = 0; i < row; i++)
    {
        for (k = 0; k < column; k++)
        {
            if (board[i][k] == cells::PEG)
            {
                if (board_number != 6)
                { /* if it is not the 6.th board type */

                    if (board[i][k + 2] == cells::PEG) /* right side check */
                        if (board[i][k + 4] == cells::EMPTY)
                            return true;

                    if (board[i][k - 2] == cells::PEG) /* left side check */
                        if (board[i][k - 4] == cells::EMPTY)
                            return true;

                    if (board[i + 1][k] == cells::PEG) /* down check */
                        if (board[i + 2][k] == cells::EMPTY)
                            return true;

                    if (board[i - 1][k] == cells::PEG) /* upper check */
                        if (board[i - 2][k] == cells::EMPTY)
                            return true;
                }
                else
                {

                    if (board[i][k + 4] == cells::PEG) /* right side check*/
                        if (board[i][k + 8] == cells::EMPTY)
                            return true;

                    if (board[i][k - 4] == cells::PEG) /* left side check */
                        if (board[i][k - 8] == cells::EMPTY)
                            return true;

                    if (board[i - 1][k + 2] == cells::PEG) /* right up check */
                        if (board[i - 2][k + 4] == cells::EMPTY)
                            return true;

                    if (board[i - 1][k - 2] == cells::PEG) /* left up check */
                        if (board[i - 2][k - 4] == cells::EMPTY)
                            return true;

                    if (board[i + 1][k - 2] == cells::PEG) /* left down check */
                        if (board[i + 2][k - 4] == cells::EMPTY)
                            return true;

                    if (board[i + 1][k + 2] == cells::PEG) /* right down check */
                        if (board[i + 2][k + 4] == cells::EMPTY)
                            return true;
                }
            }
        }
    }

    return false;
}

void find_random_move(vector<char> possibleDirections, int row, int column, int &row_ind, int &col_ind, char &direction, char &side)
{
    int random_side = rand() % 2;

    /*assigning random values */
    row_ind = rand() % row;
    col_ind = rand() % column;
    direction = possibleDirections[rand() % 8];

    /* if it is 6.th board and user chose up or down */
    /* it will go here and chosse a random side */

    if (direction == 'U' || direction == 'u' || direction == 'D' || direction == 'd')
    {
        if (random_side == 0)
            side = 'L';
        else if (random_side == 1)
            side = 'R';
    }
}

void print_move(int board_number, int row_index, int column_index, char direction)
{

    cout << "\nLAST MOVE: ";

    /* this switch will convert column_index to its original letter */
    /* 6.th board is exception so i need to check that too */

    switch (column_index)
    {
    case 2: /* if it is 2.th index */
        cout << "A";
        break;
    case 4: /* if it is 4.th index */
        if (board_number != 6)
            cout << "B";
        else
            cout << "A";
        break;
    case 6: /* if it is 6.th index */
        if (board_number != 6)
            cout << "C";
        else
            cout << "B";
        break;
    case 8: /* if it is 8.th index */
        if (board_number != 6)
            cout << "D";
        else
            cout << "C";

        break;
    case 10: /* if it is 10.th index */
        if (board_number != 6)
            cout << "E";
        else
            cout << "D";

        break;
    case 12: /* if it is 12.th index */
        if (board_number != 6)
            cout << "F";
        else
            cout << "E";

        break;
    case 14: /* if it is 14.th index */
        if (board_number != 6)
            cout << "G";
        else
            cout << "F";

        break;
    case 16: /* if it is 16.th index */
        if (board_number != 6)
            cout << "H";
        else
            cout << "G";
        break;
    case 18: /* if it is 18.th index */
        if (board_number != 6)
            cout << "I";
        else
            cout << "H";
        break;
    case 20: /* if it is 20.th index */
        if (board_number != 6)
            cout << "E";
        else
            cout << "I";
        break;
    }

    cout << row_index - 1 << "-" << direction << " MADE BY COMPUTER..."
         << "\n\n";
    /* printing the rest of the move */
}

void find_column_index(int board_number, char column_letter, int &column_index)
{

    /* this func will find the column index
        by looking at column letter */

    if (column_letter == 'A' || column_letter == 'a')
    {
        column_index = 2;
    }
    else if (column_letter == 'B' || column_letter == 'b')
    {
        column_index = 4;
    }
    else if (column_letter == 'C' || column_letter == 'c')
    {
        column_index = 6;
    }
    else if (column_letter == 'D' || column_letter == 'd')
    {
        column_index = 8;
    }
    else if (column_letter == 'E' || column_letter == 'e')
    {
        column_index = 10;
    }
    else if (column_letter == 'F' || column_letter == 'f')
    {
        column_index = 12;
    }
    else if (column_letter == 'G' || column_letter == 'g')
    {
        column_index = 14;
    }
    else if (column_letter == 'H' || column_letter == 'h')
    {
        column_index = 16;
    }
    else if (column_letter == 'I' || column_letter == 'i')
    {
        column_index = 18;
    }

    if (board_number == 6)
        column_index += 2;
    /* if it is 6.th board we should add 2 too */
}

void print_result(int row_ind, int column_ind, vector<vector<cells>> board)
{
    int i, k, PEG_count = 0;

    /* printing how many peg has left on the board */

    for (i = 0; i < row_ind; i++)
        for (k = 0; k < column_ind; k++)
            if (board[i][k] == cells::PEG)
                PEG_count++;

    cout << "\n************\n";
    cout << "\nGAME HAS FINISHED" << endl;
    cout << "THE NUMBER OF PEG: " << PEG_count;
    cout << "\n\n************\n";
}

void get_board_info(int board_type, vector<vector<cells>> &board, int &boardRow, int &boardColumn, string &upperString, vector<char> &possibleDirections)
{

    vector<string> boardStrings{
        /* upper string of the boards */
        "   A B C D E F G ",
        "   A B C D E F G H I ",
        "   A B C D E F G H ",
        "   A B C D E F G ",
        "   A B C D E F G H I ",
        "     A B C D E F G H I ",
    };

    vector<char> allDirections{
        /* possible directions peg can go */
        'L',
        'l',
        'R',
        'r',
        'U',
        'u',
        'D',
        'd',
    };

    possibleDirections = allDirections;
    upperString = boardStrings[board_type - 1];

    if (board_type == 1) /* if it is the first board */
    {
        board = {
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::EMPTY, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
        };
        boardRow = 11;    /* max row index of the first board */
        boardColumn = 17; /* max column index of the first board */
    }
    else if (board_type == 2) /* if it is the second board */
    {
        board = {
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::EMPTY, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},

        };
        boardRow = 13;    /* max row index of the second board */
        boardColumn = 21; /* max column index of the second board */
    }
    else if (board_type == 3) /* if it is the third board */
    {
        board = {
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::EMPTY, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},

        };
        boardRow = 12;    /* max row index of the third board */
        boardColumn = 19; /* max column index of the third board */
    }

    else if (board_type == 4) /* if it is the fourth board */
    {
        board = {
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::EMPTY, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},

        };
        boardRow = 11;    /* max row index of the fourth board */
        boardColumn = 17; /* max column index of the fourth board */
    }

    else if (board_type == 5) /* if it is the fifth board */
    {
        board = {
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::EMPTY, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},

        };
        boardRow = 13;    /* max row index of the fifth board */
        boardColumn = 21; /* max column index of the fifth board */
    }

    else if (board_type == 6) /* if it is the sixth board */
    {
        board = {
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::EMPTY, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::PEG, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},
            {cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL, cells::NONCELL},

        };
        boardRow = 9;     /* max row index of the sixth board */
        boardColumn = 25; /* max column index of the sixth board */
    }
}