#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
#include "Apple.h"
#include "Game.h"
#include "text_box.h"
#include "PageFunctions.h"
#include <cmath>
using namespace std;

const int WIDTH = 800;
const int HIGHT = 1200;

int main(int argc, char **argv)
{

    SDL_Plotter g(WIDTH, HIGHT);
    string command = "main page";
    string input;
    Snake s(2);
    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    char key;
    Game gm(s,a);

    gm.initSounds(g);
    g.Sleep(300);

    while(!g.getQuit())
    {
        //cout << "in the while loop" << endl; system("pause");
        ///MAIN PAGE
        if(command == "main page")
        {
            input = mainPage(g, WIDTH, HIGHT);
            if(input == "start game")
            {
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HIGHT);
            }
            else if(input == "exit")
            {
                g.setQuit(true);
            }
            ///START NEW///
            else if(input == "load saved"){
                if(gm.loadGame("save1")){
                    command = "loaded game";
                }
                else{
                    command = "failed load";
                }
            }
            ///END NEW///
        }

        ///Classic Snake Game
        else if(command == "play snake")
        {
            gm.playClassicSnake(g);\



            ///START NEW STUFF BEN///
            if(gm.getIsPaused()){
                command = "pause game";
            }
            ///END NEW STUFF BEN///




            if(gm.getGameCond())
            {
                command = "game over";
                //cout << "game over" << endl;
            }
        }


        ///START NEW STUFF BEN///
        else if(command == "pause game"){
            fill_screen_with_color(g, background_color, WIDTH, HIGHT);
            input = pauseGamePage(g, WIDTH, HIGHT);

            if(input == "resume game")
            {

                command = "play snake";
                gm.setPause(false);
                fill_screen_with_color(g, background_color, WIDTH, HIGHT);

            }
            else if(input == "reset game")
            {
                command = "play snake";
                gm.setPause(false);
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HIGHT);
            }
            else if(input == "save game")
            {
                gm.setPause(false);
                gm.saveGame("save1");
                command = "save screen";

            }
            else if(input == "main page")
            {
                command = "main page";
                gm.setPause(false);
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HIGHT);
            }
        }

        else if(command == "save screen"){
            input = saveGamePage(g, WIDTH, HIGHT);
            if(input == "clicked"){
                command = "pause game";
            }
        }

        else if(command == "loaded game"){
            input = successLoadPage(g, WIDTH, HIGHT);
            if(input == "clicked"){
                command = "play snake";
                fill_screen_with_color(g, background_color, WIDTH, HIGHT);

            }
        }

        else if(command == "failed load"){
            input = failedLoadPage(g, WIDTH, HIGHT);
            if(input == "clicked"){
                command = "main page";
            }
        }
        ///END NEW STUFF BEN///










        ///Game Over
        else if(command == "game over")
        {
            input = gameOverPage(g, WIDTH, HIGHT);

            if(input == "play again")
            {
                command = "play snake";
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HIGHT);
            }
            else if(input == "main page")
            {
                command = "main page";
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HIGHT);
            }
        }

        g.update();
    }

    return 0;
}
