#include "Board.hpp"
#include <string>
#include <iomanip>
#include <limits.h>
#include <iostream>
#include <map>
#include <climits>

using namespace std;
using namespace ariel;

void Board::post(unsigned int row, unsigned int col, Direction direction, string const &ad)
{
    theMaxRow = max(theMaxRow, row);
    theMaxCol = max(theMaxCol, col);
    theMinRow = min(theMinRow, row);
    theMinCol = min(theMinCol, col);
    /*if (ad.length() <= 0)
        return;*/
    if (direction == Direction::Horizontal)
    { //line
        unsigned int i = row;
        for (unsigned int j = 0; j < ad.length(); j++)
        {
            board[row][col] = ad.at(j);
            col++;
        }
    }
    if (direction == Direction::Vertical) //col
    {
        unsigned int j = col;

        for (unsigned int i = 0; i < ad.length(); i++)
        {
            board[row][col] = ad.at(i);
            row++;
        }
    }
}
string Board::read(unsigned int row, unsigned int col, Direction dire, unsigned int NumberOfChar)
{

    string answer;
    if (dire == Direction::Horizontal)
    { //line
        unsigned int i = row;
        unsigned int j = col;

        for (unsigned int ch = 0; ch < NumberOfChar; ch++)
        {
            char help = board[i][j];
            if (help == 0)
            {
                answer += '_';
            }
            else
            {
                answer += (help);
            }
            j++;
        }
    }
    else if (dire == Direction::Vertical)
    {
        unsigned int i = row;
        unsigned int j = col;
        for (unsigned int ch = 0; ch < NumberOfChar; ch++)
        {
            char help2 = board[i][j];
            if (help2 == 0)
            {
                answer += '_';
            }
            else
            {
                answer += (help2);
            }
            i++;
        }
    }

    return answer;
}

void Board::show()
{
    unsigned long j = theMinCol;
    for (unsigned long i = theMinRow; i < theMaxRow + 1; i++)
    {
        cout << i << ":";
        cout << read(i, j, Direction::Horizontal, theMaxCol + 25);
        cout << endl;
    }
}
