#include <iostream>
#include "SDL_Plotter.h"
#include "Letter.h"

using namespace std;

const int NUM_ROW = 800;
const int NUM_COL = 800;

int main(int argc, char **argv)
{

    // this is here
    char key;
    SDL_Plotter g(NUM_ROW, NUM_COL);

    Point_T starting_location(400,100);
    Letter letter_A(15, 'A', 8, starting_location);

    letter_A.draw_letter("font.txt",g);

   /*
    grid_square my_letter(8,15, starting_location);
    color my_color;

    my_color.R = 230;
    my_color.B = 49;
    my_color.G = 21;

    my_letter.color_sqr(Point_T(1,6), my_color, g);
    my_letter.color_sqr(Point_T(1,5), my_color, g);
    my_letter.color_sqr(Point_T(1,4), my_color, g);
    my_letter.color_sqr(Point_T(1,3), my_color, g);
    my_letter.color_sqr(Point_T(1,2), my_color, g);
    my_letter.color_sqr(Point_T(1,1), my_color, g);

    my_letter.color_sqr(Point_T(2,0), my_color, g);
    my_letter.color_sqr(Point_T(3,0), my_color, g);
    my_letter.color_sqr(Point_T(4,0), my_color, g);

    my_letter.color_sqr(Point_T(5,6), my_color, g);
    my_letter.color_sqr(Point_T(5,5), my_color, g);
    my_letter.color_sqr(Point_T(5,4), my_color, g);
    my_letter.color_sqr(Point_T(5,3), my_color, g);
    my_letter.color_sqr(Point_T(5,2), my_color, g);
    my_letter.color_sqr(Point_T(5,1), my_color, g);

    my_letter.color_sqr(Point_T(2,3), my_color, g);
    my_letter.color_sqr(Point_T(3,3), my_color, g);
    my_letter.color_sqr(Point_T(4,3), my_color, g);

    my_color.R = 222;
    my_color.B = 159;
    my_color.G = 151;

    my_letter.color_sqr(Point_T(0,1), my_color, g);
    my_letter.color_sqr(Point_T(0,2), my_color, g);
    my_letter.color_sqr(Point_T(0,3), my_color, g);
    my_letter.color_sqr(Point_T(0,4), my_color, g);
    my_letter.color_sqr(Point_T(0,5), my_color, g);
    my_letter.color_sqr(Point_T(0,6), my_color, g);
    my_letter.color_sqr(Point_T(0,7), my_color, g);

    my_letter.color_sqr(Point_T(2,1), my_color, g);
    my_letter.color_sqr(Point_T(3,1), my_color, g);
    my_letter.color_sqr(Point_T(4,1), my_color, g);
    my_letter.color_sqr(Point_T(4,2), my_color, g);

    my_letter.color_sqr(Point_T(2,4), my_color, g);
    my_letter.color_sqr(Point_T(3,4), my_color, g);
    my_letter.color_sqr(Point_T(4,4), my_color, g);
    my_letter.color_sqr(Point_T(4,5), my_color, g);
    my_letter.color_sqr(Point_T(4,6), my_color, g);
    my_letter.color_sqr(Point_T(4,7), my_color, g);

    */

    while(!g.getQuit())
    {
        if(g.kbhit())
        {
            key = g.getKey();
        }

        g.update();
    }

    return 0;
}
