#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
#include "Apple.h"
#include "Game.h"
#include <cmath>
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
    Snake s(2);
    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));

    char key;
    Game gm(s,a);



    gm.initSounds(g);
    g.Sleep(3000);
    while(!g.getQuit()){
        gm.playClassicSnake(g);
    }


//    SDL_Plotter g(650, 900);
//    Snake s(5);
//    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));
//    char key;
//    bool isPaused = false;
//
//    s.setSegment(Segment(25, Point(900/2, 650/2)), 0);
//    s.setSegment(Segment(25, Point(900/2 + 25, 650/2 + 25)), 1);
//
//    //draw_letter_A_test(g);
//    s.initSounds(g);

//    while(!g.getQuit()){
//        if(!isPaused){
//            if(a.checkAppleCollision(s)){
//                a.eraseApple(g);
//                a.setPoint(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25)));
//                s.incrementLength();
//                g.playSound("SnakeMunchSound.wav");
//
//            }
//            if(g.kbhit()){
//               key = g.getKey();
//               s.setDirection(g, key);
//            }
//
//            s.checkSelfColision(g);
//            if(s.isSnakeDead()){
//                isPaused = true;
//
//            }
//
//            a.drawApple(g);
//            if(!isPaused){
//                s.eraseSnake(g);
//                s.drawSnake(g);
//            }
//
//
//            g.Sleep(100);
//            g.update();
//        }
//    }
//



    return 0;
}
