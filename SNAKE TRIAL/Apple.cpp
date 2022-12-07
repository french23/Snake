/*
* Author: Peter Whitcomb
* Assignment Title: Snake Game
* Assignment Description: Create the game Snake
* Due Date: 12/7/2022
* Date Created: 11/26/2022
* Date Last Modified: 12/7/2022
*/
#include "Apple.h"

using namespace std;

/// Constructors ///
Apple::Apple()
{
    appleSize = 25;
    appSeg = Segment(appleSize, Point(0,0));
    beenHit = false;
    R = 0;
    G = 0;
    B = 0;
}
Apple::Apple(int size, Point p, int r, int g, int b )
{
    appleSize = size;
    appSeg = Segment(appleSize, p);
    beenHit = false;
    R = r;
    G = g;
    B = b;
}

/// Accessors ///
Segment Apple::getSegment()
{
    return appSeg;
}
bool Apple::hasBeenHit()
{
    return beenHit;
}
int Apple::getAppleSize()
{
    return appleSize;
}

/// Mutators ///
void Apple::setSegment(const Segment s)
{
    appSeg = s;
}
void Apple::setPoint(const Point p)
{
    appSeg.setPoint(p);
}
void Apple::setColor(int r, int g, int b)
{
    R = r;
    G = g;
    B = b;
}
void Apple::setAppleColision(const bool b)
{
    beenHit = b;
}

/// Methods ///
bool Apple::checkAppleCollision(Snake s)
{
    bool appleEaten = false;


    //Checks every point of the snake against the evey point of the apple
    if(s.getSegment(0).getPoint() == appSeg.getPoint() ||
            s.getSegment(0).getPoint() == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
            s.getSegment(0).getPoint() == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
            s.getSegment(0).getPoint() == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize))
    {
        if(Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == appSeg.getPoint() ||
                Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
                Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
                Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize))
        {
            if(Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == appSeg.getPoint() ||
                    Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
                    Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
                    Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize))
            {
                if(Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == appSeg.getPoint() ||
                        Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
                        Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
                        Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize))
                {
                    appleEaten = true;
                }
            }
        }
    }


    return appleEaten;
}
void Apple::drawApple(SDL_Plotter& g)
{
    for(int y = 0; y < appleSize; y++)
    {
        for(int x = 0; x < appleSize; x++)
        {
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y, R, G, B);
        }
    }
    //Apple Corners
    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            g.plotPixel(appSeg.getX() + x+1, appSeg.getY() + y+3, 55, 2, 82);//Top-Left
            g.plotPixel(appSeg.getX() + x+18, appSeg.getY() + y+3, 55, 2, 82);//Top-Right
            g.plotPixel(appSeg.getX() + x+1, appSeg.getY() + y+20, 55, 2, 82);//Bottom-Left
            g.plotPixel(appSeg.getX() + x+18, appSeg.getY() + y+20, 55, 2, 82);//Bottom-Right
        }
        //Apple Resizing
        for(int x = 0; x < appleSize; x++)
        {
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y-1, 55, 2, 82);//Top
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y+23, 55, 2, 82);//Bottom
            g.plotPixel(appSeg.getX() + y-3, appSeg.getY() + x, 55, 2, 82);//Left
            g.plotPixel(appSeg.getX() + y+22, appSeg.getY() + x, 55, 2, 82);//Right

        }
    }
    //Apple Stem
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            g.plotPixel(appSeg.getX() + x+11, appSeg.getY() - y+3, 133, 51, 45);
        }
    }
    //Apple Leaf
    for(int y = 0; y < 3; y++)
    {
        for(int x = 0; x < 3; x++)
        {
            g.plotPixel(appSeg.getX() + x+12, appSeg.getY() - y, 55, 155, 161);//Leaf
        }
    }

}

void Apple::eraseApple(SDL_Plotter& g)
{
    for(int y = 0; y < appleSize; y++)
    {
        for(int x = 0; x < appleSize; x++)
        {
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y, 55, 2, 82);
        }
    }
    //Apple Stem Erase
    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            g.plotPixel(appSeg.getX() + x+10, appSeg.getY() - y, 55, 2, 82);
        }
    }
    //Apple Leaf Erase
    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            g.plotPixel(appSeg.getX() + x+14, appSeg.getY() - y-10, 55, 2, 82);
        }
    }
}
Point Apple::createPoint(Snake s)
{
    Point p;
    bool isValid = false;
    srand(time(0));
    while(!isValid)
    {
        isValid = true;
        p = Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25));
        for(int i = 0; i < s.getLength(); i++)
        {
            if(s.getSegment(i).getPoint() == p)
            {
                isValid = false;
            }
        }
    }
    return p;
}

