#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

/*
* Author: Peter Stewart
* Assignment Title: Snake
* Assignment Description: make a snake game
* Due Date: 12/7/2022
* Date Created: 11/14/2022
* Date Last Modified: 12/7/2022
 */

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
    symbol(string fileName,char input_symbol, int fount_size, Point starting_location);

    /*
    * description: print the symbol
    * return: none
    * precondition: g is given to the function
    * postcondition: draws the letter to the screen
    *
    */
    void draw_symbol(SDL_Plotter& g);

    /*
    * description: erase the temple
    * return: none
    * precondition: g is given to the function and the backgroud color
    * postcondition: erasees the letter to the screen
    *
    */
    void erase_symbol(SDL_Plotter& g, color background_color);

    /*
    * description: get the m_size
    * return: int
    * precondition: none
    * postcondition: the lenght of the grid sqr is retured
    *
    */
    int get_size() const;

private:
    int m_size;
    int m_fount_size;
    char m_input_symbol;
    Point m_starting_location;
    string m_fileName;
    vector<color> m_colors;
    vector<Point> m_v_sqr_points;
    vector<color> m_v_sqr_colors;

    /*
    * description: parses the file and sets up the letter
    * return: none
    * precondition: m_fileName is set
    * postcondition: a gridSquare is returned full.
    *
    */
    void parse_and_fill_file();
};

#endif // SYMBOL_H_INCLUDED
