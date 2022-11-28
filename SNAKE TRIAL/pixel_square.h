#ifndef PIXEL_SQUARE_H_INCLUDED
#define PIXEL_SQUARE_H_INCLUDED

#include "Point_T.h"
#include "SDL_Plotter.h"

class pixel_square
{
public:

    /*
    * description: constructor to make the pixel grid
    * return: none
    * precondition: takes the size of the sqr and the origin point
    * postcondition: sets the vars
    *
    */
    pixel_square(Point_T sqr_origin, int size);

    /*
    * description: constructor to make the pixel grid
    * return: none
    * precondition: none, defaults the values to origin and 10;
    * postcondition: sets the vars
    *
    */
    pixel_square();

    /*
    * description: returns the size of the sqr
    * return: none
    * precondition: none
    * postcondition: returns the size val;
    *
    */
    void get_size();

    // needs to take a color and a reference to the screen
    void fill_with_color()

private:

    Point_T m_sqr_origin;
    int m_size;

};


#endif // PIXEL_SQUARE_H_INCLUDED
