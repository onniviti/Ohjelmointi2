#include <iostream>
#include <vector>

using namespace std;

const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';

// Muuttaa annetun numeerisen merkkijonon vastaavaksi kokonaisluvuksi
// (kutsumalla stoi-funktiota).
// Jos annettu merkkijono ei ole numeerinen, palauttaa nollan.
//
// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns zero.
unsigned int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// Tulostaa pelilaudan rivi- ja sarakenumeroineen.
//
// Prints the game board with row and column numbers.
void print(const /*vector of vectors or a compatible type*/& gameboard)
{
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int i = 0; i < BOARD_SIDE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < BOARD_SIDE; ++j)
        {
            if(gameboard.at(i).at(j) == 0)
            {
                cout << EMPTY << " ";
            }
            else
            {
                cout << gameboard.at(i).at(j) << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}

int main()
{
    return 0;
}
