/*
* Author: Peter Whitcomb
* Assignment Title: Snake Game
* Assignment Description: Create the game Snake
* Due Date: 12/7/2022
* Date Created: 11/26/2022
* Date Last Modified: 12/7/2022
*/
#include "Segment.h"

using namespace std;

//Constructors
Segment::Segment()
{
    segS = 25;
    p = Point(0,0);
}
Segment::Segment(int s, Point pt)
{
    segS = s;
    p = pt;
}

// Accessors
int Segment::getSize() const
{
    return segS;
}
Point Segment::getPoint() const
{
    return p;
}
int Segment::getX()
{
    return p.getX();
}
int Segment::getY()
{
    return p.getY();
}

//Mutators
void Segment::setSize(const int s)
{
    segS = s;

}
void Segment::setPoint(const Point point_v)
{
    p = point_v;

}
void Segment::setX(int i)
{
    p.setX(i);
}
void Segment::setY(int i)
{
    p.setY(i);
}
// Methods
void Segment::draw(SDL_Plotter& plotter, int r, int g, int b)
{
    for(int y = 0; y < segS; y++)
    {
        for(int x = 0; x < segS; x++)
        {
            plotter.plotPixel(p.getX() + x, p.getY() + y, r, g, b);

        }
    }

}

void Segment::draw(SDL_Plotter& plotter, color input_color)
{
    for(int y = 0; y < segS; y++)
    {
        for(int x = 0; x < segS; x++)
        {
            plotter.plotPixel(p.getX() + x, p.getY() + y, input_color);

        }
    }

}
