#include <string>
#include "Direction.hpp"
#include <map>
#include <iostream>
#include <climits>

using namespace std;

namespace ariel
{

    class Board
    {
    private:
        unsigned int theMaxRow, theMinRow;
        unsigned int theMaxCol,theMinCol;
        map<unsigned int, map<unsigned int, char>> board;

      public:
        Board()
        {
            theMaxRow = 0;
            theMaxCol = 0;
            theMinRow = UINT_MAX;
            theMinCol = UINT_MAX;
        }

        void post(unsigned int row, unsigned int col, Direction direction, string const &ad);
        string read(unsigned int row, unsigned int col, Direction dire, unsigned int NumberOfChar);
        void show();
    };
}