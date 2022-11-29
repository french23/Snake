#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
using namespace std;

void draw_letter_A_test(SDL_Plotter& g)
{
    Point starting_location(400,100);

    grid_square my_letter(8,15, starting_location);
    color my_color;

    my_color.R = 230;
    my_color.B = 49;
    my_color.G = 21;

    my_letter.color_sqr(Point(1,6), my_color, g);
    my_letter.color_sqr(Point(1,5), my_color, g);
    my_letter.color_sqr(Point(1,4), my_color, g);
    my_letter.color_sqr(Point(1,3), my_color, g);
    my_letter.color_sqr(Point(1,2), my_color, g);
    my_letter.color_sqr(Point(1,1), my_color, g);
                        
    my_letter.color_sqr(Point(2,0), my_color, g);
    my_letter.color_sqr(Point(3,0), my_color, g);
    my_letter.color_sqr(Point(4,0), my_color, g);
                        
    my_letter.color_sqr(Point(5,6), my_color, g);
    my_letter.color_sqr(Point(5,5), my_color, g);
    my_letter.color_sqr(Point(5,4), my_color, g);
    my_letter.color_sqr(Point(5,3), my_color, g);
    my_letter.color_sqr(Point(5,2), my_color, g);
    my_letter.color_sqr(Point(5,1), my_color, g);
                        
    my_letter.color_sqr(Point(2,3), my_color, g);
    my_letter.color_sqr(Point(3,3), my_color, g);
    my_letter.color_sqr(Point(4,3), my_color, g);

    my_color.R = 222;
    my_color.B = 159;
    my_color.G = 151;

    my_letter.color_sqr(Point(0,1), my_color, g);
    my_letter.color_sqr(Point(0,2), my_color, g);
    my_letter.color_sqr(Point(0,3), my_color, g);
    my_letter.color_sqr(Point(0,4), my_color, g);
    my_letter.color_sqr(Point(0,5), my_color, g);
    my_letter.color_sqr(Point(0,6), my_color, g);
    my_letter.color_sqr(Point(0,7), my_color, g);

    my_letter.color_sqr(Point(2,1), my_color, g);
    my_letter.color_sqr(Point(3,1), my_color, g);
    my_letter.color_sqr(Point(4,1), my_color, g);
    my_letter.color_sqr(Point(4,2), my_color, g);

    my_letter.color_sqr(Point(2,4), my_color, g);
    my_letter.color_sqr(Point(3,4), my_color, g);
    my_letter.color_sqr(Point(4,4), my_color, g);
    my_letter.color_sqr(Point(4,5), my_color, g);
    my_letter.color_sqr(Point(4,6), my_color, g);
    my_letter.color_sqr(Point(4,7), my_color, g);

}

int main(int argc, char **argv)
{
    SDL_Plotter g(650, 900);
    Snake s(4);
    char key;
    s.getSegment(0).setX(650/2);
    s.getSegment(0).setY(900/2);

    draw_letter_A_test(g);

    while(!g.getQuit()){
        if(g.kbhit()){
           key = g.getKey();
           s.setDirection(key);
        }
        s.eraseSnake(g);
        s.drawSnake(g);
        g.Sleep(125);
        g.update();
    }
    return 0;
}
