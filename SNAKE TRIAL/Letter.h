#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED

#include "grid_square.h"
#include "SDL_Plotter.h"
#include "fstream"
#include "string"
#include <iostream>

using namespace std;

class Letter
{
public:
    /*
    * description: sets up the letter, default is A
    * return: none
    * precondition: none
    * postcondition: makes the letter
    *
    */
    Letter();

    /*
    * description: sets up the letter,
    * return: none
    * precondition: none
    * postcondition: makes the letter
    *
    */
    Letter(int font_size, char name, int box_size, Point_T starting_location);

    /*
    * description: draws the letter
    * return: none
    * precondition: takes in the file_name of the letter and draws the letter from the data
    * postcondition: draws the letter
    *
    */
    void draw_letter(string file_name, SDL_Plotter& g);

private:
    int m_font_size;
    char m_name;
    int m_box_size;
    Point_T m_starting_location;
};

#endif // LETTER_H_INCLUDED
