#include "boardgame2d.h"
#include "pegsolitaire.h"
#include "eightpuzzle.h"
#include "klotski.h"

using namespace Games;

int main()
{
    srand(time(NULL));

    /* TEST PLAY VECTOR */
    cout << "\u001b[2J";
    cout << "\u001b[1000A";

    cout << "vector<BoardGame2D*> variable has been created." << endl;
    cout << "Lets test vector<BoardGame2D*> function! \n";
    cout << "Waiting 5 seconds.. \n";
    sleep_until(system_clock::now() + seconds(6));

    PegSolitaire p1, p2;
    EightPuzzle e1, e2;
    Klotski k1, k2;

    vector<BoardGame2D *> objs(6);
    objs[0] = &p1;
    objs[1] = &p2;
    objs[2] = &e1;
    objs[3] = &e2;
    objs[4] = &k1;
    objs[5] = &k2;
    BoardGame2D::playVector(objs);

    /* TEST PEG SOLITAIRE PLAY USER FUNCTION*/
    cout << "\u001b[2J";
    cout << "\u001b[1000A";

    PegSolitaire p3;
    cout << "The Peg Solitaire object has been created." << endl;
    cout << "Lets test PegSolitaire BoardGame2D::PlayUser() function!" << endl;
    cout << "Waiting 5 seconds.. \n";
    sleep_until(system_clock::now() + seconds(5));

    cout << "\u001b[2J";
    cout << "\u001b[1000A";
    p3.BoardGame2D::playUser();
    sleep_until(system_clock::now() + seconds(3));

    /* TEST EIGHT PUZZLE PLAY USER FUNCTION */
    cout << "\u001b[2J";
    cout << "\u001b[1000A";

    EightPuzzle e3;
    cout << "The Eight Puzzle object has been created." << endl;
    cout << "Lets test EightPuzzle BoardGame2D::PlayUser() function!" << endl;
    cout << "Waiting 5 seconds.. \n";
    sleep_until(system_clock::now() + seconds(5));

    cout << "\u001b[2J";
    cout << "\u001b[1000A";
    e3.BoardGame2D::playUser();
    sleep_until(system_clock::now() + seconds(3));

    /* TEST KLOTSKI PLAY USER FUNCTION */
    cout << "\u001b[2J";
    cout << "\u001b[1000A";

    Klotski k3;
    cout << "The Klotski object has been created." << endl;
    cout << "Lets test Klotski BoardGame2D::PlayUser() function!" << endl;
    cout << "Waiting 5 seconds.. \n";
    sleep_until(system_clock::now() + seconds(5));

    cout << "\u001b[2J";
    cout << "\u001b[1000A";
    k3.BoardGame2D::playUser(); 
}