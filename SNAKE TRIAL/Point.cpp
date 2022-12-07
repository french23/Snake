 /*
 * Author: Peter Whitcomb
 * Assignment Title: Snake Game
 * Assignment Description: Create the game Snake
 * Due Date: 12/7/2022
 * Date Created: 11/26/2022
 * Date Last Modified: 12/7/2022
 */
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

void Point::operator=(const Point& other)
{
     this->x = other.getX();
     this->y = other.getY();
}

bool Point::operator==(const Point& other){
    bool isEqual = false;
    if(x == other.getX() && y == other.getY()){
        isEqual = true;
    }
    return isEqual;
}




