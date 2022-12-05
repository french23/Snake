#ifndef GRID_SQUARE_H_INCLUDED
#define GRID_SQUARE_H_INCLUDED

#include <vector>
#include "Segment.h"

using namespace std;

// need to do this with the square class, this is a vector of squares or whatever their called
class grid_square
{
public:
    /*
    * description: sets the default vals
    * return: none
    * precondition: none
    * postcondition: sets grid_size to ten and sqr_size to ten and m_point to 0,0
    *
    */
    grid_square();

    /*
    * description: sets the default vals
    * return: none
    * precondition: size is a argument
    * postcondition: sets size to the input val
    *
    */
    grid_square(int grid_size, int sqr_size, Point location);

    /*
    * description: colors a square
    * return: none
    * precondition: the location and color of the sqr
    * postcondition: colors the sqr to the correct color
    *
    */
    void color_sqr(Point location, color fill_color, SDL_Plotter& g);

private:

    int m_grid_size;
    int m_sqr_size;
    vector<vector<Segment>> m_grid;
    Point m_point;

    /*
    * description: fills the vecor with pixel squares
    * return: none
    * precondition: fills the vecor with pixel squares
    * postcondition: vector is full
    *
    */
    void create_grid();

};
#endif // GRID_SQUARE_H_INCLUDED
