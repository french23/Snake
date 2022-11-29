#include "Point.h"

using namespace std;

// Constructors
Point::Point(){
    x = 0;
    y = 0;
}
Point::Point(int xVal, int yVal){
    x = xVal;
    y = yVal;
}

// Accessors
int Point::getX() const{
    return x;
}
int Point::getY() const{
    return y;
}

// Mutators
void Point::setX(const int xVal){
    x = xVal;
}
void Point::setY(const int yVal){
    y = yVal;
}



