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
    //system("PAUSE");
    symbol letterS("font.txt",'S',font_size,Point(200,250));
    letterS.draw_symbol(g);

    symbol letterN("font.txt",'N',font_size,Point(300,250));
    letterN.draw_symbol(g);

    symbol letterA("font.txt",'A',font_size,Point(400,250));
    letterA.draw_symbol(g);

    symbol letterK("font.txt",'K',font_size,Point(500,250));
    letterK.draw_symbol(g);

    symbol letterE("font.txt",'E',font_size,Point(600,250));
    letterE.draw_symbol(g);

    symbol letterExclomation("font.txt",'!',font_size,Point(700,250));
    letterExclomation.draw_symbol(g);
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

    //draw_letter_A_test(g);
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
