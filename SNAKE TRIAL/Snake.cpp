/*
* Author: Peter Whitcomb
* Assignment Title: Snake Game
* Assignment Description: Create the game Snake
* Due Date: 12/7/2022
* Date Created: 11/26/2022
* Date Last Modified: 12/7/2022
*/
#include "Snake.h"
/// Constructors ///
Snake::Snake()
{
    length = 1;
    isDead = false;
    dir = RIGHT;
    key = rightKey;
    prevKey = rightKey;
    R = 255;
    G = 255;
    B = 255;
    seg[0].setPoint(Point((650 / 2), (900/2)));
}
Snake::Snake(int size, int red, int green, int blue)
{
    length = size;
    isDead = false;
    dir = RIGHT;
    key = rightKey;
    prevKey = rightKey;
    R = red;
    G = green;
    B = blue;
    for(int i = 0; i < length; i++)
    {
        seg[i].setPoint(Point((650 / 2 + (25 * i)), (900/2) + (25 * i)));
    }
}

/// Accessors ///
int Snake::getLength() const
{
    return length;
}
Segment Snake::getSegment(int i)
{
    return seg[i];
}
bool Snake::isSnakeDead() const
{
    return isDead;
}
Direction Snake::getDirection() const
{
    return dir;
}

/// Mutators ///
void Snake::setLength(const int l)
{
    length = l;
}
void Snake::incrementLength()
{
    length++;
}
void Snake::setSegment(const Segment s, int i)
{
    seg[i] = s;
}
void Snake::setSnakeDeath(const bool b)
{
    isDead = b;
}
void Snake::setRefPoint(int i, Point p)
{
    seg[i].setPoint(p);
}
void Snake::setDirection(SDL_Plotter& g, char k)
{
    prevKey = key;
    key = k;

    /// Makes sure snake cant go in opposite direction

    if(prevKey == upKey && key == downKey )
    {
        key = prevKey;
    }
    else if(prevKey == downKey && key == upKey)
    {
        key = prevKey;
    }
    else if(prevKey == leftKey && key == rightKey)
    {
        key = prevKey;
    }
    else if(prevKey == rightKey && key == leftKey)
    {
        key = prevKey;
    }



    switch(key)
    {
    case upKey :
        dir = UP;
        if(prevKey != key)
        {
            g.playSound("up.mp3");
        }
        break;

    case downKey:
        dir = DOWN;
        if(prevKey != key)
        {
            g.playSound("down.mp3");
        }
        break;

    case leftKey :
        dir = LEFT;
        if(prevKey != key)
        {
            g.playSound("left.mp3");
        }
        break;

    case rightKey:
        dir = RIGHT;
        if(prevKey != key)
        {
            g.playSound("right.mp3");
        }
        break;
    }
}
void Snake::setDirection(Direction d)
{
    dir = d;
}
void Snake::setKey(const char k)
{
    key = k;
}

/// Methods///
void Snake::checkSelfColision(SDL_Plotter& g)
{
    for(int i = 1; i < length; i++)
    {
        if(seg[0].getX() == seg[i].getX()
                && seg[0].getY() == seg[i].getY())
        {
            g.playSound("death.mp3");
            isDead = true;
        }
    }
}
void Snake::drawSnake(SDL_Plotter& g)
{
    //Copy Cell Locations
    for(int i = length-1; i > 0; i--)
    {
        seg[i].setPoint(seg[i - 1].getPoint());

    }
    //cout << dir << endl;
    switch(dir)
    {
    case RIGHT:
        seg[0].setX(seg[0].getX() + SIZE);
        break;
    case LEFT :
        seg[0].setX(seg[0].getX() - SIZE);
        break;
    case UP   :
        seg[0].setY(seg[0].getY() - SIZE);
        break;
    case DOWN :
        seg[0].setY(seg[0].getY() + SIZE);
        break;

    }
    //cout << "(" << seg[0].getPoint().getX() << ", " << seg[0].getPoint().getY() << ")" << endl;

    /// Snake Draw
    for(int i = 0; i < length; i++)
    {
        for(int y = 0; y < SIZE; y++)
        {
            for(int x = 0; x < SIZE; x++)
            {
                g.plotPixel(seg[i].getPoint().getX() + x,
                            seg[i].getPoint().getY() + y, 2, 155, 161);
            }
        }
        //EYES-Left-Right
        if(dir == RIGHT || dir == LEFT)
        {
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+8, seg[0].getPoint().getY() + k+16);
                }
            }
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+8, seg[0].getPoint().getY() + k+5);
                }
            }

            /*

            //Tongue Right
            if(dir == RIGHT){
                for(int x = 0; x < 10; x++){
                    for(int y = 0; y < 4; y++){
                        g.plotPixel(seg[0].getPoint().getX() + x+25, seg[0].getPoint().getY() + y+11, 139, 0, 0);
                        g.plotPixel(seg[0].getPoint().getX() + x+31, seg[0].getPoint().getY() + y+9, 139, 0, 0);
                    }
                }
            }//Tongue Left
            if(dir == LEFT){
                for(int x = 0; x < 10; x++){
                    for(int y = 0; y < 4; y++){
                        g.plotPixel(seg[0].getPoint().getX() + x-9, seg[0].getPoint().getY() + y+11, 139, 0, 0);
                        g.plotPixel(seg[0].getPoint().getX() + x-19, seg[0].getPoint().getY() + y+9, 139, 0, 0);
                    }
                }

            }

            */

        }//EYES-Up-Down
        else
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 10; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+16, seg[0].getPoint().getY() + k+8);
                }
            }
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 10; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+5, seg[0].getPoint().getY() + k+8);
                }
            }
        }


    }


}
void Snake::eraseSnake(SDL_Plotter& g)
{
    /// Snake erase
    for (int i = 0; i < length; i++)
    {
        for(int y = 0; y < SIZE; y++)
        {
            for(int x = 0; x < SIZE; x++)
            {
                g.plotPixel(seg[i].getPoint().getX() + x,
                            seg[i].getPoint().getY() + y, 55,2,82);

            }
        }
        //EYES-Left-Right
        if(dir == RIGHT || dir == LEFT)
        {
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+8, seg[0].getPoint().getY() + k+16, 255, 255, 255);
                }
            }
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+8, seg[0].getPoint().getY() + k+5, 255, 255, 255);
                }
            }


        }//EYES-Up-Down
        else
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 10; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+16, seg[0].getPoint().getY() + k+8, 255, 255, 255);
                }
            }
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 10; k++)
                {
                    g.plotPixel(seg[0].getPoint().getX() + j+5, seg[0].getPoint().getY() + k+8, 255, 255, 255);
                }
            }

        }
    }
}




