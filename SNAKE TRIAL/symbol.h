#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

#include "grid_square.h"
#include <fstream>

using namespace std;
class symbol
{
public:
    /*
    * description: sets up the grid_squares and
    * return: none
    * precondition: the filename of the fount and the plotter and the symbol we are looking for
    * postcondition: sets grid_size
    *
    */
    symbol(string fileName,char input_symbol, SDL_Plotter& g);

    /*
    * description: parses the file and sets up the letter
    * return: none
    * precondition: m_fileName is set
    * postcondition: a gridSquare is returned full.
    *
    */
    grid_square parse_and_fill_file();

private:
    grid_square m_canvas;
    int m_size;
    char m_input_symbol;
    string m_fileName;

};

#endif // SYMBOL_H_INCLUDED
