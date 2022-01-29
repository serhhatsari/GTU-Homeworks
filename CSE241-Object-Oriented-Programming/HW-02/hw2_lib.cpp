#include "hw2_lib.h"

void start_game(int gameType, int boardType, bool is_load, const string &load_inp)
{
    int column_index = 0, row_index, boardColumn = 0;
    bool if_comp = false, check_move, check_game = true, ch_input = true, chh_input = true;
    int is_load_save;
    char direction, side, column_letter;
    auto number_of_moves = column_index;
    decltype(row_index) boardRow;
    number_of_moves = 0;
    string comp_save, human_or_comp, user_file_name, name_of_file;
    string leri_inp, move_input, upperString, h_g_inp;
    vector<vector<cells>> board;
    vector<char> possibleDirections;
    char a;

    if (!is_load)
    { /* if user didnt load in the first part it will go here */
        get_board_info(boardType, board, boardRow, boardColumn, upperString, possibleDirections);
    }
    else
    {
        /* if user load a game in the first part it will go here */
        load_game(load_inp, board, boardRow, boardColumn, upperString, possibleDirections, number_of_moves);

        print_board(board, boardRow, boardColumn, upperString);
        /* printing the board */

        chh_input = true;
        cout << endl;

        while (chh_input)
        { /* choosing human or computer after load */
            cout << "1- Human Player Game \n";
            cout << "2- Computer Game \n";
            cout << "Select the game type (1 or 2):  ";
            getline(cin, h_g_inp);

            is_load_save = check_load_save(h_g_inp);
            /* checking the input */

            if (is_load_save == 1)
            { /* if user wants to load  */
                cout << endl;
                start_game(1, 1, true, h_g_inp);
                return;
            }
            else if (is_load_save == 2)
            { /* if user wants to save */
                save_game(h_g_inp, board, boardRow, boardColumn, number_of_moves, human_or_comp);
                cout << "\n!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                print_board(board, boardRow, boardColumn, upperString);
                cout << "!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                continue;
            }

            chh_input = check_input(possibleDirections, 0, 2, h_g_inp);
            cout << "\n \n";
            /* It will check whether game type input is valid or not */
        }
        gameType = h_g_inp[0] - '0';
    }
    print_board(board, boardRow, boardColumn, upperString);
    check_game = check_if_finished(boardType, boardRow, boardColumn, board);
    /* checking if game has finished */

    if (gameType == 1)
        human_or_comp = "Human Game";
    else
        human_or_comp = "Computer Game";

    while (check_game)
    {
        if (gameType == 1)
        { /* if it is a human game */

            while (ch_input)
            {
                cout << "Examples:  E4-D , A2-U , C5-R , F3-L \n";
                cout << "Enter your move according to examples: ";
                getline(cin, move_input);
                cout << endl;
                is_load_save = check_load_save(move_input);
                if (is_load_save == 1)
                { /* if user chose load */

                    board.clear();
                    load_game(move_input, board, boardRow, boardColumn, upperString, possibleDirections, number_of_moves);
                    print_board(board, boardRow, boardColumn, upperString);

                    chh_input = true;
                    cout << endl;

                    while (chh_input)
                    { /* asking user if its gonna be human or computer */
                        cout << "1- Human Player Game \n";
                        cout << "2- Computer Game \n";
                        cout << "Select the game type (1 or 2):  ";
                        getline(cin, h_g_inp);

                        is_load_save = check_load_save(h_g_inp);

                        if (is_load_save == 1)
                        { /* if it is load */
                            cout << endl;
                            start_game(1, 1, true, h_g_inp);
                            return;
                        }
                        else if (is_load_save == 2)
                        { /* if it is save */
                            save_game(h_g_inp, board, boardRow, boardColumn, number_of_moves, human_or_comp);
                            cout << "\n!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                            print_board(board, boardRow, boardColumn, upperString);
                            cout << "!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                            continue;
                        }

                        chh_input = check_input(possibleDirections, 0, 2, h_g_inp);
                        cout << "\n \n";
                        /* It will check whether game type input is valid or not */
                    }

                    if (gameType == 1)
                    { /* if it is human game */
                        human_or_comp = "Human Game";
                    }
                    else
                    { /* if it is computer game */
                        human_or_comp = "Computer Game";
                    }
                    gameType = h_g_inp[0] - '0';
                    cout << endl;
                    check_game = check_if_finished(boardType, boardRow, boardColumn, board);
                    if_comp = true;
                    break;
                }
                else if (is_load_save == 2)
                { /* if user wants to save */
                    save_game(move_input, board, boardRow, boardColumn, number_of_moves, human_or_comp);
                    cout << "\n!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                    print_board(board, boardRow, boardColumn, upperString);
                    cout << "!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                    continue;
                }

                ch_input = check_input(possibleDirections, boardType, 3, move_input);
            }

            if (if_comp)
            { /* for program to continue */
                if_comp = false;
                continue;
            }
            column_letter = move_input[0];
            row_index = move_input[1] - '0';
            direction = move_input[3];

            ch_input = true;

            if ((direction == 'U' || direction == 'u' || direction == 'D' || direction == 'd') && boardType == 6)
            { /* if its 6.th board and user wants to go up or down */
                while (ch_input)
                {
                    cout << "Right(R) or Left(L) \n";
                    cout << "Enter your direction (R or L): ";
                    getline(cin, leri_inp);

                    is_load_save = check_load_save(leri_inp);

                    if (is_load_save == 1)
                    { /* if user wants to load smth */
                        board.clear();
                        load_game(leri_inp, board, boardRow, boardColumn, upperString, possibleDirections, number_of_moves);
                        print_board(board, boardRow, boardColumn, upperString);
                        chh_input = true;
                        cout << endl;

                        while (chh_input)
                        { /* taking input from user */
                            cout << "1- Human Player Game \n";
                            cout << "2- Computer Game \n";
                            cout << "Select the game type (1 or 2):  ";
                            getline(cin, h_g_inp);

                            is_load_save = check_load_save(h_g_inp);

                            if (is_load_save == 1)
                            { /* if it is a load */
                                cout << endl;
                                start_game(1, 1, true, h_g_inp);
                                return;
                            }
                            else if (is_load_save == 2)
                            { /* if it is a save */
                                save_game(h_g_inp, board, boardRow, boardColumn, number_of_moves, human_or_comp);
                                cout << "\n!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                                print_board(board, boardRow, boardColumn, upperString);
                                cout << "!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                                continue;
                            }

                            chh_input = check_input(possibleDirections, 0, 2, h_g_inp);
                            cout << "\n \n";
                            /* It will check whether game type input is valid or not */
                        }
                        gameType = h_g_inp[0] - '0';

                        if (gameType == 1)
                        {
                            human_or_comp = "Human Game";
                        }
                        else
                        {
                            human_or_comp = "Computer Game";
                        }

                        check_game = check_if_finished(boardType, boardRow, boardColumn, board);
                        if_comp = true;
                        break;
                    }

                    else if (is_load_save == 2)
                    {
                        save_game(leri_inp, board, boardRow, boardColumn, number_of_moves, human_or_comp);
                        cout << "\n!!!GAME HAS BEEN SAVED TO THE FILE!!! \n\n";
                        print_board(board, boardRow, boardColumn, upperString);
                        cout << "!!!GAME HAS BEEN SAVED TO THE FILE!!!\n\n";
                        continue;
                    }

                    ch_input = check_input(possibleDirections, boardType, 4, leri_inp);
                } /* side check */

                if (if_comp)
                {
                    if_comp = false;
                    continue;
                }
                side = leri_inp[0];
            }

            ch_input = true;

            find_column_index(boardType, column_letter, column_index);

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
            number_of_moves++;
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
                cerr << "\n\n\n!!! That is an INVALID move! MAKE A NEW MOVE !!!\n\n";

                /* and it will print the board again to ask a new move */
                print_board(board, boardRow, boardColumn, upperString);
                cout << endl;
            }
        }

        check_game = check_if_finished(boardType, boardRow, boardColumn, board);
        /* it will check if any valid move is left or not */
    }
    print_result(boardRow, boardColumn, board);

    if (gameType == 2)
    {
        cout << "\n\nYES : y \n";
        cout << "NO : n \n";
        cout << "Do you wanna save the game? (y or n)\n";
        cout << "Enter your input(y or n): ";
        cin >> comp_save;

        if (comp_save == "y")
        {
            cout << "What should be the name of the file? \n";
            cout << "Enter your input: ";
            cin >> user_file_name;
            name_of_file = "SAVE " + user_file_name;
            save_game(name_of_file, board, boardRow, boardColumn, number_of_moves, human_or_comp);
            cout << "\n GAME HAS BEEN SAVED TO THE FILE! \n\n";
        }
    }
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
            cerr << "\nINVALID INPUT!!!\n\n";
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
            cerr << "\nINVALID INPUT!!!\n\n";
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
            cerr << "\nINVALID INPUT!!!\n\n";
            return true;
        }
        else if ((user_input[0] >= 'a' && user_input[0] <= small_char) || (user_input[0] >= 'A' && user_input[0] <= big_char))
        {
            /* column letter should be between 'a' and some upper bound  like 'g' */
            if (user_input[1] >= '1' && user_input[1] <= max_row)
            {
                /* row index should be between 1 and max col*/
                if (user_input[2] == '-')
                {
                    /*check if characther '-' is in the 2th index */
                    for (; i < max_directions; i++)
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
            cerr << "\nINVALID INPUT!!!\n\n";
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

    cerr << "\nINVALID INPUT!!!\n\n";
    return true;
}

int check_load_save(string user_input)
{
    vector<string> words;
    ifstream check_file;

    string_parse(user_input, words);

    if (words.size() > 2)
    { /* checking size */
        return 0;
    }

    else if (words[0] == "LOAD")
    { /* checking if it is load command */
        check_file.open(words[1]);

        if (check_file)
        { /* checking if file exits */
            check_file.close();
            return 1;
        }
        else
        {
            check_file.close();
            cerr << "\nFILE DOESNT EXIST! \n";
            return 0;
        }
    }

    else if (words[0] == "SAVE")
    { /* checking if it is a save command */
        return 2;
    }

    return 0;
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

void string_parse(string user_input, vector<string> &words)
{
    string word = "";
    int i, k;
    /* this function extract words from string */
    for (i = 0; i < user_input.size(); i++)
    {
        if (user_input[i] != ' ')
        {

            word += user_input[i];
        }
        else
        {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
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

void load_game(const string &file_name, vector<vector<cells>> &board, int &boardRow, int &boardColumn, string &upperString, vector<char> &possibleDirections, int &number_of_moves)
{
    ifstream infile;
    vector<string> words;
    vector<string> num_of_move;
    string word, line_txt, num_move;
    int row = 0, column = 0, count = 0;
    int column_num = 0, row_num;
    int i = 0, k = 0;
    bool chck = true, chck_num = true;

    string_parse(file_name, words);
    /* parsing string */

    infile.open(words[1]);
    /* opening file */

    while (getline(infile, line_txt))
    { /* taking line by line from the txt */
        vector<cells> row_board;

        if (line_txt[0] == '-')
        { /* checking the - */
            row_num = row;
            chck_num = false;
        }
        if (chck_num)
        {
            while (line_txt[i] != '\0')
            { /* if it is the end of the line */

                if (line_txt[i] == ' ')
                { /* checking if it is space */
                    column++;
                    row_board.push_back(cells::NONCELL);
                }
                else if (line_txt[i] == 'P')
                {
                    column++;
                    row_board.push_back(cells::PEG);
                }
                else if (line_txt[i] == '.')
                {
                    column++;
                    row_board.push_back(cells::EMPTY);
                }
                i++;
            }

            if (chck)
            {
                column_num = line_txt.size();
            }

            chck = false;

            i = 0;
            row++;
            column = 0;
            board.push_back(row_board);
        }
        else
        {
            count++;
            if (count == 4)
            { /* if it is 4th line */
                string_parse(line_txt, num_of_move);
                number_of_moves = stoi(num_of_move[3]);
            }
        }
    }

    boardColumn = column_num;
    /* assigning column */
    boardRow = row_num;
    /* assigning row */

    vector<string> boardStrings{
        /* upper string of the boards */
        "   A B C D E F G ",
        "   A B C D E F G H I ",
        "   A B C D E F G H ",
        "   A B C D E F G ",
        "   A B C D E F G H I ",
        "     A B C D E F G H I ",
    };

    if (column_num == 17)
    { /* assigning strings */
        upperString = boardStrings[0];
    }
    else if (column_num == 19)
    { /* assigning strings */
        upperString = boardStrings[2];
    }
    else if (column_num == 21)
    { /* assigning strings */
        upperString = boardStrings[4];
    }
    else if (column_num == 25)
    { /* assigning strings */
        upperString = boardStrings[5];
    }

    possibleDirections = {
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

    infile.close();
}

void save_game(const string &file_name, vector<vector<cells>> board, int boardRow, int boardColumn, int number_of_moves, string human_or_comp)
{
    ofstream myfile;

    string board_txt;
    int i = 0, k = 0, count = 1;
    string load_save, rest_of_string;

    vector<string> words;
    string word;

    string_parse(file_name, words);
    /* parsing string */

    myfile.open(words[1]);
    /* opening file */

    /* this loop will print the board */
    for (i = 0; i < boardRow; i++)
    { /* until row */
        for (k = 0; k < boardColumn; k++)
        { /* until column */
            if (board[i][k] == cells::EMPTY)
                myfile << '.';

            else if (board[i][k] == cells::PEG)
                myfile << 'P';

            else if (board[i][k] == cells::NONCELL)
                myfile << ' ';
        }
        myfile << '\n';
    }
    /* printing the rest of the info */
    myfile << "---GAME INFO--- \n\n";
    myfile << "HUMAN OR COMPUTER: " << human_or_comp << "\n";
    myfile << "NUMBER OF MOVES: " << number_of_moves << " \n";
    myfile << "ROW NUMBER: " << boardRow << "\n";
    myfile << "COLUMN NUMBER: " << boardColumn << "\n";

    myfile.close();
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
        "   A B C D E F G",
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