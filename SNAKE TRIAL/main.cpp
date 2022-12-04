#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
#include "Apple.h"
#include "Game.h"
#include "text_box.h"
#include <cmath>
using namespace std;

/*string mainPage(SDL_Plotter& g)
{
    string return_comand = 'null';

    vector<textbox> test;

    return return_comand;
}
*/
int main(int argc, char **argv)
{

    SDL_Plotter g(800, 1200);
    Snake s(2);
    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));

    char key;
    Game gm(s,a);

    textBox my_hello(Point(100,200),12, "THIS IS SNAKE!!");
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

     color border_color;
    border_color.R = 0;
    border_color.G = 0;
    border_color.B = 0;

    gm.initSounds(g);
    g.Sleep(3000);
    while(!g.getQuit()){
        gm.playClassicSnake(g);
        my_hello.draw(g, border_color);//, background_color);
        if(g.mouseClick())
        {
            point temp = g.getMouseClick();
            if(my_hello.isClicked(Point(temp.x,temp.y)))
            {
                cout << "THE TEXT BOX WAS CLICKED!!" << endl;
            }
        }
    }

    return 0;
}
