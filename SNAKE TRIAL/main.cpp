#include <iostream>
#include "SDL_Plotter.h"

using namespace std;

const int NUM_ROW = 800;
const int NUM_COL = 800;

const int SIZE = 25;
const int APPLESIZE = 25;

enum Direction {UP, DOWN, LEFT, RIGHT};

int main(int argc, char **argv)
{
    char key;
    int length = 5;
    SDL_Plotter g(NUM_ROW, NUM_COL);
    int R=20, G=20, B=255;
    //int xLoc = NUM_COL/2, yLoc = NUM_ROW/2;
    int xLoc[100000], yLoc[100000];///large size prevents breaking of snake as length increments. temp solution, but could be perm.
    int prevX, prevY;
    Direction dir = RIGHT;
    int speed = 150;
    int skip = 0, skip_val = 10;

    xLoc[0] = NUM_COL/2;//head of snake
    xLoc[1] = NUM_COL/2 - SIZE;

    yLoc[0] = NUM_ROW/2;
    yLoc[1] = NUM_ROW/2;

    int appleX = rand() % 750;
    int appleY = rand() % 750;
    int oldAppleX;
    int oldAppleY;
    bool appleEaten = false;

    while(!g.getQuit()){

        //user input
        if(g.kbhit()){
            key = g.getKey();
            R = rand() % 255;
            G = rand() % 255;
            B = rand() % 255;

            oldAppleX = appleX;
            oldAppleY = appleY;
//            appleX = rand() % 785;
//            appleY = rand() % 785;
            switch(key){
                case UP_ARROW   : dir = UP;
                                  break;
                case DOWN_ARROW : dir = DOWN;
                                  break;
                case LEFT_ARROW : dir = LEFT;
                                  break;
                case RIGHT_ARROW: dir = RIGHT;
                                  break;

            }
        }


        /// Apple Collision ///

        // top left, reffrece point
        if(xLoc[0] >= appleX && xLoc[0] <= appleX + APPLESIZE){
           if(yLoc[0] >= appleY && yLoc[0] <= appleY + APPLESIZE){
            appleEaten = true;
            cout << "Apple twas Eaten! " << endl;
           }

        }
        // top right
        else if(xLoc[0] + SIZE >= appleX && xLoc[0] + SIZE <= appleX + APPLESIZE){
           if(yLoc[0] >= appleY && yLoc[0] <= appleY + APPLESIZE){
            appleEaten = true;
            cout << "Apple twas Eaten! " << endl;

           }

        }
        // bottom left
        else if(xLoc[0] >= appleX && xLoc[0] <= appleX + APPLESIZE){
            //if(yLoc[0] + SIZE >= appleY && yLoc[0] + SIZE <= appleY + APPLESIZE)
                {
                appleEaten = true;
                cout << "Apple twas Eaten! " << endl;
            }
        }
        // bottum right
        else if(xLoc[0] + SIZE >= appleX && xLoc[0] + SIZE <= appleX + APPLESIZE){
            //if(yLoc[0] + SIZE >= appleY && yLoc[0] + SIZE <= appleY + APPLESIZE)
                {
                appleEaten = true;
                cout << "Apple twas Eaten! " << endl;
            }
        }


        if(appleEaten){
            /// Apple Erase
            for(int y = 0; y < APPLESIZE; y++){
                for(int x = 0; x < APPLESIZE; x++){
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
        }








        //Copy Cell Locations

        for(int i = length-1; i > 0; i--){
            xLoc[i] = xLoc[i-1];
            yLoc[i] = yLoc[i-1];
        }

        switch(dir){
            case RIGHT: xLoc[0]+= SIZE;
                        break;
            case LEFT : xLoc[0]-= SIZE;
                        break;
            case UP   : yLoc[0]-= SIZE;
                        break;
            case DOWN : yLoc[0]+= SIZE;
                        break;

        }

        //Draw
        for(int i = 0; i < length; i++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, R,G,B);

                }
            }
        }


        //Draw Apple
        for(int y = 0; y < APPLESIZE; y++){
            for(int x = 0; x < APPLESIZE; x++){
                g.plotPixel(appleX + x, appleY + y);
            }
        }

        g.update();
        g.Sleep(speed);//pauses for 'speed' nanoseconds

        /// Snake erase
        for (int i = 0; i < length; i++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, 255,255,255);

                }
            }
        }

    }
    return 0;
}
