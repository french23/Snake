#include <iostream>
#include "SDL_Plotter.h"

using namespace std;

const int NUM_ROW = 800;
const int NUM_COL = 800;

const int SIZE = 25;
const int APPLESIZE = 26;

enum Direction {UP, DOWN, LEFT, RIGHT,STILL};

int main(int argc, char **argv)
{
    char key;
    int length = 10;
    SDL_Plotter g(NUM_ROW, NUM_COL);
    int R=20, G=20, B=255;
    //int xLoc = NUM_COL/2, yLoc = NUM_ROW/2;
    int xLoc[NUM_ROW/SIZE * NUM_COL/SIZE];
    int yLoc[NUM_ROW/SIZE * NUM_COL/SIZE];
    int prevX, prevY;
    Direction dir = RIGHT;
    int speed = 90;
    int skip = 0, skip_val = 10;

    xLoc[0] = NUM_COL/2;//head of snake
    xLoc[1] = NUM_COL/2 - SIZE;

    yLoc[0] = (NUM_ROW/2);
    yLoc[1] = (NUM_ROW/2);

//    yLoc[0] = NUM_ROW/2;
//    yLoc[1] = NUM_ROW/2;

    int appleX = rand() % 750;
    int appleY = rand() % 750;
    int oldAppleX;
    int oldAppleY;
    bool appleEaten = false;
    bool gameover = false;

    while(!g.getQuit() and !gameover)
    {

        //user input
        if(g.kbhit())
        {
            key = g.getKey();
            R = rand() % 255;
            G = rand() % 255;
            B = rand() % 255;

            oldAppleX = appleX;
            oldAppleY = appleY;
//            appleX = rand() % 785;
//            appleY = rand() % 785;
            switch(key)
            {
            case UP_ARROW   :
                dir = UP;
                break;
            case DOWN_ARROW :
                dir = DOWN;
                break;
            case LEFT_ARROW :
                dir = LEFT;
                break;
            case RIGHT_ARROW:
                dir = RIGHT;
                break;

            }
        }


        /// Apple Collision ///

        // top left, reffrece point
        if((xLoc[0] >= appleX && xLoc[0] <= appleX + APPLESIZE)
                and (yLoc[0] >= appleY && yLoc[0] <= appleY + APPLESIZE))
        {
            appleEaten = true;
            cout << "Apple twas Eaten! - top left corner" << endl;

        }
        // top right
        else if(xLoc[0] + SIZE >= appleX && xLoc[0] + SIZE <= appleX + APPLESIZE
                and (yLoc[0] >= appleY && yLoc[0] <= appleY + APPLESIZE))
        {
            appleEaten = true;
            cout << "Apple twas Eaten! - top right corner" << endl;

        }
        // Bottom left
        else if((xLoc[0] >= appleX and xLoc[0] <= appleX + APPLESIZE)
                and ((yLoc[0]+SIZE) >= appleY and (yLoc[0]+SIZE) <= appleY + APPLESIZE))
        {
            appleEaten = true;
            cout << "Apple twas Eaten! - bottom left corner" << endl;
        }
        // Bottom Right
        else if(((xLoc[0]+SIZE) >= appleX and (xLoc[0]+SIZE) <= appleX + APPLESIZE)
                and ((yLoc[0]+SIZE) >= appleY and (yLoc[0]+SIZE) <= appleY + APPLESIZE))
        {
            appleEaten = true;
            cout << "Apple twas Eaten! - bottom right corner" << endl;
        }


        // Run only when an apple is eaten
        if(appleEaten)
        {
            /// Apple Erase
            for(int y = 0; y < APPLESIZE; y++)
            {
                for(int x = 0; x < APPLESIZE; x++)
                {
                    g.plotPixel(appleX + x, appleY + y, 255,255,255);
                }
            }

            /// set new apple pos
            appleX = rand() % 750;
            appleY = rand() % 750;

            /// Reset apple Eaten

            appleEaten = false;

            /// increment lenght //
            length++;
            xLoc[length] = (prevX);
            yLoc[length] = (prevY);
        }




        /// Snake erase
        for (int i = 0; i < length; i++)
        {
            for(int y = 0; y < SIZE; y++)
            {
                for(int x = 0; x < SIZE; x++)
                {
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, 255,255,255);

                }
            }
        }

        // Snake self colision
        if((xLoc[0] >= xLoc[5] and xLoc[0] <= xLoc[5] + SIZE)
           and (yLoc[0] >= yLoc)) // PICK UP HERE
        {
            cout << "colision!! game over, hit lenght number" << 5 << endl;
            gameover = true;
        }



        // Snake wall colision
        if(xLoc[0] >= 800-SIZE or xLoc[0] <= 0 or yLoc[0] <= 0 or yLoc[0] >= 800 - SIZE)
        {
            gameover = true;
            cout << "wall colision, game over!"<< endl;
        }

        if(!gameover)
        {
            //Copy Cell Locations

            for(int i = length-1; i > 0; i--)
            {
                xLoc[i] = xLoc[i-1];
                yLoc[i] = yLoc[i-1];
            }

            switch(dir)
            {
            case RIGHT:
                xLoc[0]+= SIZE;
                break;
            case LEFT :
                xLoc[0]-= SIZE;
                break;
            case UP   :
                yLoc[0]-= SIZE;
                break;
            case DOWN :
                yLoc[0]+= SIZE;
                break;
            }
        }


        //Draw snake
        for(int i = 0; i < length; i++)
        {
            for(int y = 0; y < SIZE; y++)
            {
                for(int x = 0; x < SIZE; x++)
                {
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, R,G,B);

                }
            }
        }


        // Draw Apple
        for(int y = 0; y < APPLESIZE; y++)
        {
            for(int x = 0; x < APPLESIZE; x++)
            {
                g.plotPixel(appleX + x, appleY + y);
            }
        }

        //Draw snake segment lines
        for(int i = 0; i < NUM_COL;i++)
        {
            g.plotPixel(xLoc[5],i);
            g.plotPixel(xLoc[5] + SIZE,i);
        }

        g.update();
        g.clear();
        g.Sleep(speed);//pauses for 'speed' nanoseconds


    }

    // Keeps the program running
    cout << "SCORE = " << length -2 << endl;
    system("PAUSE");
    return 0;
}
