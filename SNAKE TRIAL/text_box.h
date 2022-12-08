/*
* Author: Benjamin Szabo, Peter Stuart
* Assignment Title: Snake Game
* Assignment Description: Create a snake game
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/5/2022
 */

#ifndef TEXT_BOX_H_INCLUDED
#define TEXT_BOX_H_INCLUDED

#include <string>
#include <vector>
#include "symbol.h"

using namespace std;

class textBox
{
private:
    string fontName = "font.txt";
    vector<symbol> text;
    string inputStr;
    Point startLoc;
    int fontSize;
public:

    /*
    * description: Constructor, set data member values
    * return: n/a
    * precondition: correct input
    * postcondition: sets data member values
    *
    */
    textBox(Point, int, string);

    /*
    * description: determines if the object was clicked
    * return: boolean: true/false
    * precondition: correct input Point object
    * postcondition: returns true if point is within text box
    *
    */
    bool isClicked(Point);

    /*
    * description: Draws the word specified
    * return: n/a
    * precondition: correct input
    * postcondition: draws word
    *
    */
    void draw(SDL_Plotter& g);

    /*
    * description: Draws the word specified
    *              overloaded with background color
    * return: n/a
    * precondition: correct input
    * postcondition: draws word
    *
    */
    void draw(SDL_Plotter& g, color border_color);

    /*
    * description: Draws the word specified
    *              overloaded with border and background
    * return: n/a
    * precondition: correct input
    * postcondition: draws word
    *
    */
    void draw(SDL_Plotter& g, color border_color, color background_color);

    /*
    * description: erases word
    * return: n/a
    * precondition: correct input
    * postcondition: erases word
    *
    */
    void eraseText(SDL_Plotter&, color);
};




#endif // TEXT_BOX_H_INCLUDED
