#include "Point_T.h"

Point_T::Point_T(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point_T::Point_T()
{
    this->x = 0;
    this->y = 0;
}

void Point_T::setX(int input)
{
    x = input;
}

 void Point_T::setY(int input)
 {
     y = input;
 }

 int Point_T::getX() const
 {
     return x;
 }

 int Point_T::getY() const
 {
     return y;
 }

 Point_T Point_T::operator=(const Point_T& other)
 {
     this->x = other.getX();
     this->y = other.getY();
 }
