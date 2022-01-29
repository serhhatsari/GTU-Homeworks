#include "hw3_lib.h"

/*Peg Solitaire Methods and Constructers */
int PegSolitaire::num_all_pegs = 0;

PegSolitaire::PegSolitaire(string gameName)
{
    game_name = gameName;
}

PegSolitaire::PegSolitaire(int board_type)
{
    boardType = board_type;
}

PegSolitaire::PegSolitaire(int row_side, int column_side)
{
    boardSide = row_side;
}

PegSolitaire::PegSolitaire()
{
}

void PegSolitaire::print_board() const
{
    int i = 0, k = 0;
    cout << upper_word;
    /* printing the upper string */

    for (i = 0; i < max_row; i++) /* printing the board */
    {
        for (k = 0; k < max_column; k++)
        {
            if (i > 1 && i < max_row - 2 && k == 0)
                cout << i - 1;

            if ((board[i][k]).get_type() == cellTypes::EMPTY)
                cout << ".";

            else if ((board[i][k]).get_type() == cellTypes::PEG)
                cout << "P";

            else if ((board[i][k]).get_type() == cellTypes::NONCELL && i != 1)
                cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::play()
{
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

    bool legal_move = true;
    int col_ind, row_ind, side;
    char direction, l_or_r = 'R';
    int a, b, c, d;

    while (legal_move)
    { /* finding legal move */
        row_ind = rand() % max_row;
        col_ind = rand() % max_column;
        direction = allDirections[rand() % 8];
        side = rand() % 2;

        if (side == 0)
            l_or_r = 'L';
        else
            l_or_r = 'R';

        legal_move = check_move(col_ind, row_ind, direction, l_or_r, 1);
    }

    legal_move = true;

    /* some assignments according to move */
    if (boardType != 6)
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
    {
        /* some assignments according to move */
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
            if (side == 0)
                a = -1, b = -2, c = -2, d = -4;
            else if (side == 1)
                a = -1, b = -2, c = 2, d = 4;
        }
        else if (direction == 'D' || direction == 'd')
        {
            if (side == 0)
                a = 1, b = 2, c = -2, d = -4;
            else if (side == 1)
                a = 1, b = 2, c = 2, d = 4;
        }
    }
    /* making the move */

    (board[row_ind][col_ind]).set_type(cellTypes::EMPTY);
    (board[row_ind + a][col_ind + c]).set_type(cellTypes::EMPTY);
    (board[row_ind + b][col_ind + d]).set_type(cellTypes::PEG);
}

void PegSolitaire::play(string move)
{
    int a, b, c, d;

    int col_ind = find_column_index(move[0]);
    int row_ind = move[1] - '0';
    row_ind++;
    char direction, side;
    direction = move[3];
    side = move[4];

    /* some assignments according to move */

    if (boardType != 6)
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
    { /* some assignments according to move */
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
    /* making the move */

    (board[row_ind][col_ind]).set_type(cellTypes::EMPTY);
    (board[row_ind + a][col_ind + c]).set_type(cellTypes::EMPTY);
    (board[row_ind + b][col_ind + d]).set_type(cellTypes::PEG);
}

void PegSolitaire::playGame()
{
    print_board();
    while (check_finished())
    { /* it will play until the end of the game */
        play();
        print_board();
    }
    /* board info */
    cout << "GAME HAS FINISHED! \n";
    cout << endl;
}

int PegSolitaire::number_of_pegs() const
{
    int i = 0, k = 0;
    int count = 0;

    for (i = 0; i < max_row; i++)
    { /* until max row */
        for (k = 0; k < max_column; k++)
        { /* until max column */
            if ((board[i][k]).get_type() == cellTypes::PEG)
                count++; /* incrementing the number of pegs */
        }
    }
    return count;
}

int PegSolitaire::number_of_empty() const
{
    int i = 0, k = 0;
    int count = 0;

    for (i = 0; i < max_row; i++)
    {
        for (k = 0; k < max_column; k++)
        {
            if ((board[i][k]).get_type() == cellTypes::EMPTY)
                count++; /* incrementing the number of empties */
        }
    }
    return count;
}

int PegSolitaire::number_of_taken_pegs() const
{
    int i = 0, k = 0;
    int count = 0;
    /* find the number of pegs that taken */

    for (i = 0; i < max_row; i++)
    {
        for (k = 0; k < max_column; k++)
        {
            if ((board[i][k]).get_type() == cellTypes::EMPTY)
                count++;
        }
    }
    return count - 1;
}

bool PegSolitaire::check_finished() const
{
    int i, k;
    /*checking if any legal move has left */
    for (i = 0; i < max_row; i++)
    {
        for (k = 0; k < max_column; k++)
        {
            if (boardType != 6)
            { /* if it is not 6th board */
                if ((board[i][k]).get_type() == cellTypes::PEG)
                {

                    if ((board[i][k + 2]).get_type() == cellTypes::PEG) /* right side check */
                        if ((board[i][k + 4]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i][k - 2]).get_type() == cellTypes::PEG) /* left side check */
                        if ((board[i][k - 4]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i + 1][k]).get_type() == cellTypes::PEG) /* down check */
                        if ((board[i + 2][k]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i - 1][k]).get_type() == cellTypes::PEG) /* upper check */
                        if ((board[i - 2][k]).get_type() == cellTypes::EMPTY)
                            return true;
                }
            }
            else
            { /* if it is 6th board */

                if ((board[i][k]).get_type() == cellTypes::PEG)
                {
                    if ((board[i][k + 4]).get_type() == cellTypes::PEG) /* right side check*/
                        if ((board[i][k + 8]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i][k - 4]).get_type() == cellTypes::PEG) /* left side check */
                        if ((board[i][k - 8]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i - 1][k + 2]).get_type() == cellTypes::PEG) /* right up check */
                        if ((board[i - 2][k + 4]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i - 1][k - 2]).get_type() == cellTypes::PEG) /* left up check */
                        if ((board[i - 2][k - 4]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i + 1][k - 2]).get_type() == cellTypes::PEG) /* left down check */
                        if ((board[i + 2][k - 4]).get_type() == cellTypes::EMPTY)
                            return true;

                    if ((board[i + 1][k + 2]).get_type() == cellTypes::PEG) /* right down check */
                        if ((board[i + 2][k + 4]).get_type() == cellTypes::EMPTY)
                            return true;
                }
            }
        }
    }

    return false;
}

bool PegSolitaire::check_move(int col_ind, int row_ind, char direction, char side, int flag)
{
    int a, b, c, d;

    if (flag == 0)
        row_ind++;

    if (boardType != 6)
    { /* if it is  not 6th board, it will go here */
        /* some assignments according to move */
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
    { /* if it is will go here */
        /* some assignments according to move */
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

    /* this will check all possibilities */
    if ((board[row_ind][col_ind]).get_type() == cellTypes::PEG)
    { /* checking if the current index is peg or not */
        if ((board[row_ind + a][col_ind + c]).get_type() == cellTypes::NONCELL)
        {
            if (flag == 0)
                cerr << "\n\n INVALID MOVE! MAKE A NEW MOVE! \n";
            return true;
        }

        else if ((board[row_ind + a][col_ind + c]).get_type() == cellTypes::EMPTY)
        {
            if (flag == 0)
                cerr << "\n\n INVALID MOVE! MAKE A NEW MOVE! \n";
            return true;
        }

        else if ((board[row_ind + a][col_ind + c]).get_type() == cellTypes::PEG)
        {
            if ((board[row_ind + b][col_ind + d]).get_type() == cellTypes::EMPTY)
            {
                return false;
            }

            else
            {
                if (flag == 0)
                    cerr << "\n\n INVALID MOVE! MAKE A NEW MOVE! \n\n";
                return true;
            }
        }
    }

    return true;
}

void PegSolitaire::save_board(string file_name) const
{
    ofstream myfile;
    int i = 0, k = 0;

    myfile.open(file_name);
    /* opening file */

    /* this loop will print the board */
    for (i = 0; i < max_row; i++)
    { /* until row */
        for (k = 0; k < max_column; k++)
        { /* until column */
            if ((board[i][k]).get_type() == cellTypes::EMPTY)
                myfile << '.';

            else if ((board[i][k]).get_type() == cellTypes::PEG)
                myfile << 'P';

            else if ((board[i][k]).get_type() == cellTypes::NONCELL)
                myfile << ' ';
        }
        myfile << '\n';
    }
    /* printing the rest of the info */
    myfile << "---GAME INFO--- \n\n";
    myfile << "GAME NAME:" << game_name << "."
           << "\n";
    myfile << "BOARD TYPE:" << boardType << "."
           << "\n";
    myfile << "UPPER WORD:" << upper_word << "."
           << "\n";
    myfile << "ROW NUMBER:" << max_row << "."
           << "\n";
    myfile << "COLUMN NUMBER:" << max_column << "."
           << "\n";
    myfile << "GAME TYPE:" << gameType << "."
           << "\n";

    myfile.close();
}

void PegSolitaire::load_board(string file_name)
{

    ifstream infile;
    vector<vector<Cell>> file_board;
    string word, line_txt;
    int count = 0, i = 0;
    bool chck_num = true;

    infile.open(file_name); /* opening file */

    while (getline(infile, line_txt))
    { /* taking line by line from the file */
        vector<Cell> row_board;

        if (line_txt[0] == '-')
        { /* checking for - */
            chck_num = false;
        }
        if (chck_num)
        {

            while (line_txt[i] != '\0')
            { /* parsing line and asasigning it ot cell array */

                if (line_txt[i] == ' ')
                {
                    row_board.push_back(Cell(' ', 0, cellTypes::NONCELL));
                }
                else if (line_txt[i] == 'P')
                {
                    row_board.push_back(Cell(' ', 0, cellTypes::PEG));
                }
                else if (line_txt[i] == '.')
                {
                    row_board.push_back(Cell(' ', 0, cellTypes::EMPTY));
                }
                i++;
            }

            i = 0;
            file_board.push_back(row_board);
        }

        else
        {
            count++;
            if (count == 3)
            { /* taking game name from the file */
                game_name = string_parse(line_txt);
            }
            else if (count == 4)
            { /* taking board type from the file */
                boardType = stoi(string_parse(line_txt));
            }

            else if (count == 5)
            { /* taking upper word from the file */
                upper_word = string_parse(line_txt);
            }

            else if (count == 6)
            { /* taking maw row from the file */
                max_row = stoi(string_parse(line_txt));
            }

            else if (count == 7)
            { /* taking max coljumn from the file */
                max_column = stoi(string_parse(line_txt));
            }
            else if (count == 8)
            { /* taking game type from the file */
                gameType = (string_parse(line_txt))[0];
            }
        }
    }

    board = file_board;
    print_board();
    infile.close();
}

string PegSolitaire::string_parse(string user_input)
{
    string word = "";
    int i;
    bool check_start = false;

    /* this func will parse the string that user entered */

    for (i = 0; i < user_input.size(); i++)
    {
        if (user_input[i] == ':')
        {
            check_start = true;
            continue;
        }

        if (check_start)
        {
            if (user_input[i] == '.')
            {
                return word;
            }
            else
            {
                word += user_input[i];
            }
        }
    }
}

int PegSolitaire::num_of_all_pegs(vector<PegSolitaire> games)
{
    int i = 0;

    num_all_pegs = 0;
    /* this will keep the number of all pegs in all games */
    for (i = 0; i < games.size(); i++)
    {
        num_all_pegs += games[i].number_of_pegs();
    }

    return num_all_pegs;
}

bool PegSolitaire::compare_games(PegSolitaire other_game) const
{
    /* this will compare 2 peg solitaire games */
    if (number_of_pegs() > other_game.number_of_pegs())
        true;
    else
        false;
}

bool PegSolitaire::check_input(int input_type, string user_input, const vector<PegSolitaire> &existingGames)
{
    ifstream check_file;

    char big_char;
    char maxRow, small_char;
    int i = 0;

    maxRow = ((max_row - 4) + '0');
    big_char = upper_word[upper_word.size() - 1];
    small_char = (upper_word[upper_word.size() - 1]) + 32;

    vector<char> possibleDirections{
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

    if (input_type == 1)
    {
        if (user_input.size() > 1) /* check of the input size */
        {
            cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-6)\n\n";
            return true;
        }
        else if (user_input[0] >= '1' && user_input[0] <= '6')
        {
            /* valid boards are 1 to 6, so it will check if input is between them*/
            return false;
        }
        cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-6)\n\n";
    }

    else if (input_type == 2)
    {
        if (user_input.size() > 1) /* check of the input size */
        {
            cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-8)\n\n";
            return true;
        }
        else if (user_input[0] >= '1' && user_input[0] <= '9')
        {
            /* valid boards are 1 to 9, so it will check if input is between them*/
            return false;
        }
        cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-8)\n\n";
    }

    else if (input_type == 3)
    {
        for (i = 0; i < existingGames.size(); i++)
        {

            if ((existingGames[i]).get_name() == user_input)
            {
                return false;
            }
        }
        cerr << "THERE IS NO EXISTING GAME NAMED " << user_input << endl;
    }

    else if (input_type == 4)
    {

        if (user_input.size() > 4)
        {
            cerr << "\nINVALID MOVE INPUT! Correct format: B3-D , E5-U \n\n";
            return true;
        }
        else if ((user_input[0] >= 'a' && user_input[0] <= small_char) || (user_input[0] >= 'A' && user_input[0] <= big_char))
        {
            /* column letter should be between 'a' and some upper bound  like 'g' */
            if (user_input[1] >= '1' && user_input[1] <= maxRow)
            {
                /* row index should be between 1 and max col*/
                if (user_input[2] == '-')
                {
                    for (i = 0; i < possibleDirections.size(); i++)
                    {
                        if (user_input[3] == possibleDirections[i])
                            return false;
                    }
                }
            }
        }
        cout << endl;

        print_board();

        cerr << "\nINVALID MOVE INPUT! Correct format: B3-D , E5-U \n\n";
    }

    else if (input_type == 5)
    {

        if (user_input == "q")
        {
            cout << "\n\nOK. I guess there is no loadable file!\n\n";
            return false;
        }
        check_file.open(user_input);

        if (check_file)
        {
            load_board(user_input);
            cout << "\n\n!!! FILE HAS BEEN LOADED TO THE GAME !!!\n\n";
            check_file.close();

            return false;
        }
        else
        {
            cerr << "\n!!! FILE DOESNT EXIST !!!\n";
            return true;
        }
    }

    else if (input_type == 6)
    {
        if (user_input.size() > 1)
        {
            cerr << "\nINVALID INPUT! VALID INPUTS: (L, l, R, r)\n\n";
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

    else if (input_type == 7)
    {
        if (user_input.size() > 1) /* check of the input size */
        {
            cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-2)\n\n";
            return true;
        }
        else if (user_input[0] >= '1' && user_input[0] <= '2')
        {
            /* valid boards are 1 to 6, so it will check if input is between them*/
            return false;
        }

        cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-2)\n\n";
    }

    else if (input_type == 8)
    {
        if (user_input.size() > 1) /* check of the input size */
        {
            cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-2)\n\n";
            return true;
        }
        else if (user_input[0] >= '1' && user_input[0] <= '7')
        {
            /* valid boards are 1 to 7, so it will check if input is between them*/
            return false;
        }

        cerr << "\nINVALID INPUT! ENTER A NUMBER BETWEEN (1-7)\n\n";
    }

    return true;
}

void PegSolitaire::set_cell(char column_letter, int row_number, cellTypes cell_type)
{
    /* setting the cell object */
    cell.set_column_letter(column_letter);
    cell.set_row_num(row_number);
    cell.set_type(cell_type);
}

void PegSolitaire::set_board(int board_type)
{
    int i, k;

    if (board_type == 1)
    { /* if it is the first board */
        vector<vector<Cell>> firstBoard = {
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell('C', 1, cellTypes::PEG), Cell(' ', 1, cellTypes::NONCELL), Cell('D', 1, cellTypes::PEG), Cell(' ', 1, cellTypes::NONCELL), Cell('E', 1, cellTypes::PEG), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL)},
            {Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell('B', 2, cellTypes::PEG), Cell(' ', 2, cellTypes::NONCELL), Cell('C', 2, cellTypes::PEG), Cell(' ', 2, cellTypes::NONCELL), Cell('D', 2, cellTypes::PEG), Cell(' ', 2, cellTypes::NONCELL), Cell('E', 2, cellTypes::PEG), Cell(' ', 2, cellTypes::NONCELL), Cell('F', 2, cellTypes::PEG), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL)},
            {Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell('A', 3, cellTypes::PEG), Cell(' ', 3, cellTypes::NONCELL), Cell('B', 3, cellTypes::PEG), Cell(' ', 3, cellTypes::NONCELL), Cell('C', 3, cellTypes::PEG), Cell(' ', 3, cellTypes::NONCELL), Cell('D', 3, cellTypes::EMPTY), Cell(' ', 3, cellTypes::NONCELL), Cell('E', 3, cellTypes::PEG), Cell(' ', 3, cellTypes::NONCELL), Cell('F', 3, cellTypes::PEG), Cell(' ', 3, cellTypes::NONCELL), Cell('G', 3, cellTypes::PEG), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL)},
            {Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::NONCELL), Cell('A', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell('B', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell('C', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell('D', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell('E', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell('F', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell('G', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::NONCELL)},
            {Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::NONCELL), Cell('A', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell('B', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell('C', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell('D', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell('E', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell('F', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell('G', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::NONCELL)},
            {Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL), Cell('B', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell('C', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell('D', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell('E', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell('F', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL)},
            {Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell('C', 7, cellTypes::PEG), Cell(' ', 7, cellTypes::NONCELL), Cell('D', 7, cellTypes::PEG), Cell(' ', 7, cellTypes::NONCELL), Cell('E', 7, cellTypes::PEG), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
        };

        /* assigning some info about the first board */

        board = firstBoard;
        max_row = 11;
        max_column = 17;
        upper_word = "   A B C D E F G";
        boardType = board_type;
    }

    else if (board_type == 2)
    {
        /* if it is the second board */
        vector<vector<Cell>> secondBoard = {
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::NONCELL), Cell(' ', 1, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::NONCELL), Cell(' ', 2, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::NONCELL), Cell(' ', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::PEG), Cell(' ', 4, cellTypes::NONCELL), Cell(' ', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::PEG), Cell(' ', 5, cellTypes::NONCELL), Cell(' ', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::EMPTY), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::PEG), Cell(' ', 6, cellTypes::NONCELL), Cell(' ', 6, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::NONCELL), Cell(' ', 7, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::NONCELL), Cell(' ', 8, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::NONCELL), Cell(' ', 9, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
        };
        /* assigning some info about the second board */

        board = secondBoard;
        max_row = 13;
        max_column = 21;
        upper_word = "   A B C D E F G H I";
        boardType = board_type;
    }

    else if (board_type == 3)
    {
        /* if it is the third board */
        vector<vector<Cell>> thirdBoard = {
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::EMPTY), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
        };
        /* assigning some info about the third board */

        board = thirdBoard;
        max_row = 12;
        max_column = 19;
        upper_word = "   A B C D E F G H";
        boardType = board_type;
    }

    else if (board_type == 4)
    {
        /* if it is the fourth board */
        vector<vector<Cell>> fourthBoard = {
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 1, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 1, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 1, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 2, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 2, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 2, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('A', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('B', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('F', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('G', 3, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('A', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('B', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 4, cellTypes::EMPTY), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('F', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('G', 4, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('A', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('B', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('F', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('G', 5, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 6, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 6, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 6, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell('C', 7, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('D', 7, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell('E', 7, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
        };
        /* assigning some info about the fourth board */

        board = fourthBoard;
        max_row = 11;
        max_column = 17;
        upper_word = "   A B C D E F G";
        boardType = board_type;
    }

    else if (board_type == 5)
    {
        /* if it is the fifth board */
        vector<vector<Cell>> fifthBoard = {
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::EMPTY), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
        };
        /* assigning some info about the fifth board */

        board = fifthBoard;
        max_row = 13;
        max_column = 21;
        upper_word = "   A B C D E F G H I";
        boardType = board_type;
    }

    else if (board_type == 6)
    {
        /* if it is the sixth board */
        vector<vector<Cell>> sixthBoard = {
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::EMPTY), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::PEG), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},
            {Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL), Cell(' ', 0, cellTypes::NONCELL)},

        };
        /* assigning some info about the sixth board */
        board = sixthBoard;
        max_row = 9;
        max_column = 25;
        upper_word = "     A B C D E F G H I";
        boardType = board_type;
    }
}

int PegSolitaire::find_column_index(char column_letter)
{

    /* this func will find the column index
        by looking at column letter */
    int column_index;

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

    if (boardType == 6)
        column_index += 2;
    /* if it is 6.th board we should add 2 too */
    return column_index;
}

/* CELL CLASS METHODS AND CONSTRUCTERS */

PegSolitaire::Cell::Cell(char column_letter, int row_number, cellTypes cell_type)
{
    /* cell clas constructer */
    columnLetter = column_letter;
    rowNumber = row_number;
    cellType = cell_type;
}

PegSolitaire::Cell::Cell(cellTypes cell_type)
{
    cellType = cell_type;
}

PegSolitaire::Cell::Cell()
{
}
