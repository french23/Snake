#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
#include "symbol.h"
using namespace std;

void draw_letter_A_test(SDL_Plotter& g)
{
    Point starting_location(400,100);

    grid_square my_letter(8,15, starting_location);
    color my_color;


    //237, 5, 156
    my_color.R = 230;
    my_color.G = 21;
    my_color.B = 49;

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

void draw_word_snake(SDL_Plotter& g,int font_size)
{
    char key;
    color backgroud_color;
    backgroud_color.R = 55;
    backgroud_color.G = 2;
    backgroud_color.B = 82;
    bool print = true;
            symbol letterS("font.txt",'S',font_size,Point(200,250));
            symbol letterN("font.txt",'N',font_size,Point(300,250));
            symbol letterA("font.txt",'A',font_size,Point(400,250));
            symbol letterK("font.txt",'K',font_size,Point(500,250));
            symbol letterE("font.txt",'E',font_size,Point(600,250));
            symbol letterExclomation("font.txt",'!',font_size,Point(700,250));

    while(!g.getQuit())
    {
        if(g.kbhit())
           key = g.getKey();
        if(print == true)
        {
            letterS.draw_symbol(g);
            letterN.draw_symbol(g);
            letterA.draw_symbol(g);
            letterK.draw_symbol(g);
            letterE.draw_symbol(g);
            letterExclomation.draw_symbol(g);
            print = false;
        }
        else
        {
            letterS.erase_symbol(g,backgroud_color);
            letterN.erase_symbol(g,backgroud_color);
            letterA.erase_symbol(g,backgroud_color);
            letterK.erase_symbol(g,backgroud_color);
            letterE.erase_symbol(g,backgroud_color);
            letterExclomation.erase_symbol(g,backgroud_color);
            print = true;
        }
        g.update();

        g.Sleep(700);
    }
}

void draw_background(SDL_Plotter& g){
    for(int i = 0; i < 900; i++){
        for(int j = 0; j < 650; j++){
            g.plotPixel(i, j, 55, 2, 82);
        }
    }

}

int main(int argc, char **argv)
{
    SDL_Plotter g(650, 900);
   // Snake s(4);
    char key;
    /*s.getSegment(0).setX(650/2);
    s.getSegment(0).setY(900/2);*/

    draw_background(g);
    draw_word_snake(g,8);

    while(!g.getQuit()){
        if(g.kbhit()){
           key = g.getKey();
          // s.setDirection(key);
        }
       /* s.eraseSnake(g);
        s.drawSnake(g);*/
        g.Sleep(125);
        g.update();
    }
    return 0;
}
