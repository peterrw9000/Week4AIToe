#include <iostream>

using namespace std;

class TicTacToe
{
public:
    // TTT board, empty by default
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // used for keeping track what's in each space, and what value each player has
    enum Entry
    {
        EMPTY = ' ',
        PLAYER_ONE = 'x',
        PLAYER_TWO = 'o'
    };

    // has the board been completely filled?
    bool isFull()
    {
        bool result = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == Entry::EMPTY)
                    result = false;
            }
        }

        return result;
    }

    // has someone won?
    bool isVictory(Entry e)
    {

        // first col
        if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == (char)e)
        {
            return true;
        }

        // second col
        else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == (char)e)
        {
            return true;
        }

        // third col
        else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // first row
        else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        // second row
        else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == (char)e)
        {
            return true;
        }

        // third row
        else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 1
        else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 2
        else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        return false;
    }

    // return size of the board; mostly just in case I wanted to make the board expandable
    int getSize()
    {
        return 3;
    }


    void dump()
    {
        cout << "----------------------------------------" << endl << endl;
        for (int i = 0; i < getSize(); i++)
        {
            for (int j = 0; j < getSize(); j++)
            {
                cout << " | " << board[i][j] << " | ";
            }

            cout << endl;
        }
        cout << "----------------------------------------" << endl << endl;
    }

};

static bool getHumanMove(int maxValue, TicTacToe::Entry human, TicTacToe& t)
{
    // check if player is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    int rowChoice = 0;
    int colChoice = 0;

    do {

        do {

            cout << "Enter column number (x) : 0 ... 2 : ";
            cin >> colChoice;
            cout << endl;

        } while (colChoice > maxValue || colChoice < 0);

        do {

            cout << "Enter row number (y) : 0 ... 2 : ";
            cin >> rowChoice;
            cout << endl;

        } while (rowChoice > maxValue || rowChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)human;

            return false;
        }

        else
        {
            cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

bool potentialVictory(TicTacToe::Entry computer, TicTacToe& t, int& row, int& col)
{
    // first col
    if (t.board[0][0] == (char)computer && t.board[0][1] == (char)computer)
    {
        row = 0;
        col = 2;
        return true;
    }
    else if (t.board[0][0] == (char)computer && t.board[0][2] == (char)computer)
    {
        row = 0;
        col = 1;
        return true;
    }
    else if (t.board[0][1] == (char)computer && t.board[0][2] == (char)computer)
    {
        row = 0;
        col = 0;
        return true;
    }
    // second col
    else if (t.board[1][0] == (char)computer && t.board[1][1] == (char)computer)
    {
        row = 1;
        col = 2;
        return true;
    }
    else if (t.board[1][0] == (char)computer && t.board[1][2] == (char)computer)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)computer && t.board[1][2] == (char)computer)
    {
        row = 1;
        col = 0;
        return true;
    }
    // third col
    else if (t.board[2][0] == (char)computer && t.board[2][1] == (char)computer)
    {
        row = 2;
        col = 2;
        return true;
    }
    else if (t.board[2][0] == (char)computer && t.board[2][2] == (char)computer)
    {
        row = 2;
        col = 1;
        return true;
    }
    else if (t.board[2][1] == (char)computer && t.board[2][2] == (char)computer)
    {
        row = 2;
        col = 0;
        return true;
    }
    // first row
    else if (t.board[0][0] == (char)computer && t.board[1][0] == (char)computer)
    {
        row = 2;
        col = 0;
        return true;
    }
    else if (t.board[0][0] == (char)computer && t.board[2][0] == (char)computer)
    {
        row = 1;
        col = 0;
        return true;
    }
    else if (t.board[1][0] == (char)computer && t.board[2][0] == (char)computer)
    {
        row = 0;
        col = 0;
        return true;
    }
    // second row
    else if (t.board[0][1] == (char)computer && t.board[1][1] == (char)computer)
    {
        row = 2;
        col = 1;
        return true;
    }
    else if (t.board[0][1] == (char)computer && t.board[2][1] == (char)computer)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)computer && t.board[2][1] == (char)computer)
    {
        row = 0;
        col = 1;
        return true;
    }
    // third row
    else if (t.board[0][2] == (char)computer && t.board[1][2] == (char)computer)
    {
        row = 2;
        col = 2;
        return true;
    }
    else if (t.board[0][2] == (char)computer && t.board[2][2] == (char)computer)
    {
        row = 1;
        col = 2;
        return true;
    }
    else if (t.board[1][2] == (char)computer && t.board[2][2] == (char)computer)
    {
        row = 0;
        col = 2;
        return true;
    }
    // diagonal 1
    else if (t.board[0][0] == (char)computer && t.board[1][1] == (char)computer)
    {
        row = 2;
        col = 2;
        return true;
    }
    else if (t.board[0][0] == (char)computer && t.board[2][2] == (char)computer)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)computer && t.board[2][2] == (char)computer)
    {
        row = 0;
        col = 0;
        return true;
    }
    // diagonal 2
    else if (t.board[0][2] == (char)computer && t.board[1][1] == (char)computer)
    {
        row = 2;
        col = 0;
        return true;
    }
    else if (t.board[0][2] == (char)computer && t.board[2][0] == (char)computer)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)computer && t.board[2][0] == (char)computer)
    {
        row = 0;
        col = 2;
        return true;
    }
    return false;
}

bool blockEnemyWin(TicTacToe::Entry computer, TicTacToe::Entry human, TicTacToe& t, int& row, int& col)
{
    // first col
    if (t.board[0][0] == (char)human && t.board[0][1] == (char)human)
    {
        row = 0;
        col = 2;
        return true;
    }
    else if (t.board[0][0] == (char)human && t.board[0][2] == (char)human)
    {
        row = 0;
        col = 1;
        return true;
    }
    else if (t.board[0][1] == (char)human && t.board[0][2] == (char)human)
    {
        row = 0;
        col = 0;
        return true;
    }
    // second col
    else if (t.board[1][0] == (char)human && t.board[1][1] == (char)human)
    {
        row = 1;
        col = 2;
        return true;
    }
    else if (t.board[1][0] == (char)human && t.board[1][2] == (char)human)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)human && t.board[1][2] == (char)human)
    {
        row = 1;
        col = 0;
        return true;
    }
    // third col
    else if (t.board[2][0] == (char)human && t.board[2][1] == (char)human)
    {
        row = 2;
        col = 2;
        return true;
    }
    else if (t.board[2][0] == (char)human && t.board[2][2] == (char)human)
    {
        row = 2;
        col = 1;
        return true;
    }
    else if (t.board[2][1] == (char)human && t.board[2][2] == (char)human)
    {
        row = 2;
        col = 0;
        return true;
    }
    // first row
    else if (t.board[0][0] == (char)human && t.board[1][0] == (char)human)
    {
        row = 2;
        col = 0;
        return true;
    }
    else if (t.board[0][0] == (char)human && t.board[2][0] == (char)human)
    {
        row = 1;
        col = 0;
        return true;
    }
    else if (t.board[1][0] == (char)human && t.board[2][0] == (char)human)
    {
        row = 0;
        col = 0;
        return true;
    }
    // second row
    else if (t.board[0][1] == (char)human && t.board[1][1] == (char)human)
    {
        row = 2;
        col = 1;
        return true;
    }
    else if (t.board[0][1] == (char)human && t.board[2][1] == (char)human)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)human && t.board[2][1] == (char)human)
    {
        row = 0;
        col = 1;
        return true;
    }
    // third row
    else if (t.board[0][2] == (char)human && t.board[1][2] == (char)human)
    {
        row = 2;
        col = 2;
        return true;
    }
    else if (t.board[0][2] == (char)human && t.board[2][2] == (char)human)
    {
        row = 1;
        col = 2;
        return true;
    }
    else if (t.board[1][2] == (char)human && t.board[2][2] == (char)human)
    {
        row = 0;
        col = 2;
        return true;
    }
    // diagonal 1
    else if (t.board[0][0] == (char)human && t.board[1][1] == (char)human)
    {
        row = 2;
        col = 2;
        return true;
    }
    else if (t.board[0][0] == (char)human && t.board[2][2] == (char)human)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)human && t.board[2][2] == (char)human)
    {
        row = 0;
        col = 0;
        return true;
    }
    // diagonal 2
    else if (t.board[0][2] == (char)human && t.board[1][1] == (char)human)
    {
        row = 2;
        col = 0;
        return true;
    }
    else if (t.board[0][2] == (char)human && t.board[2][0] == (char)human)
    {
        row = 1;
        col = 1;
        return true;
    }
    else if (t.board[1][1] == (char)human && t.board[2][0] == (char)human)
    {
        row = 0;
        col = 2;
        return true;
    }
    return false;
}

void fillCorner(TicTacToe& t, int& row, int& col)
{
    if (t.board[0][0] == t.EMPTY)
    {
        row = 0;
        col = 0;
    }
    else if (t.board[0][2] == t.EMPTY)
    {
        row = 0;
        col = 2;
    }
    else if (t.board[2][0] == t.EMPTY)
    {
        row = 2;
        col = 0;
    }
    else
    {
        row = 2;
        col = 2;
    }
}

static bool getComputerMove(TicTacToe::Entry computer, TicTacToe::Entry human, TicTacToe& t)
{
    // check if computer is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    // handle computer's move

    int rowChoice = 0;
    int colChoice = 0;

    do {
        if (potentialVictory(computer, t, rowChoice, colChoice))
        {
            // chooses the winning move
        }
        else if (blockEnemyWin(computer, human, t, rowChoice, colChoice))
        {
            // chooses the move that blocks the human
        }
        else if (t.board[1][1] == t.EMPTY)
        {
            // chooses the center
            rowChoice = 1;
            colChoice = 1;
        }
        else if (t.board[0][0] == t.EMPTY || t.board[0][2] == t.EMPTY || t.board[2][0] == t.EMPTY || t.board[2][2] == t.EMPTY)
        {
            fillCorner(t, rowChoice, colChoice);
        }
        else
        {
            // choose at random until we find a space that's empty
            do {

                rowChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (rowChoice > t.getSize() || rowChoice < 0);

            do {

                colChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (colChoice > t.getSize() || colChoice < 0);
        }
        
        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)computer;

            return false;
        }

        else
        {
            //cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

// ----------------------------
// main
// ----------------------------

int main()
{
    TicTacToe t;
    TicTacToe::Entry human = TicTacToe::PLAYER_ONE;
    TicTacToe::Entry computer = TicTacToe::PLAYER_TWO;

    int maxValue = t.getSize();

    cout << "----------------------------------------" << endl;

    cout << "You are '" << (char)human << "', " <<
        "the computer is: '" << (char)computer << "'" << endl;

    cout << "----------------------------------------" << endl << endl;

    // run the game until one player isn't able to go again
    do
    {
        // show board
        t.dump();
    } while (!getHumanMove(maxValue, human, t) && !getComputerMove(computer, human, t));


    t.dump();

    cout << endl;

    if (t.isVictory(human))
        cout << "Human Victory" << endl;

    else if (t.isVictory(computer))
        cout << "Computer Victory" << endl;

    else if (t.isFull())
        cout << "Tie" << endl;

    return(0);
}