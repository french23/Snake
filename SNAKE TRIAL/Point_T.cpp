#include "Point_T.h"

Point_T::Point_T(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point_T::setX(int input)
{
    x = input;
}

 void Point_T::setY(int input)
 {
     y = input;
 }

 int Point_T::getX()
 {
     return x;
 }

 int Point_T::getY()
 {
     return y;
 }
