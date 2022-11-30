#include "Apple.h"


using namespace std;

/// Constructors ///
Apple::Apple(){
    appleSize = 25;
    appSeg = Segment(appleSize, Point(0,0));
    beenHit = false;
    R = 0;
    G = 0;
    B = 0;
}
Apple::Apple(int size, Point p, int r , int g , int b ){
    appleSize = size;
    appSeg = Segment(appleSize, p);
    beenHit = false;
    R = r;
    G = g;
    B = b;
}

/// Accessors ///
Segment Apple::getSegment(){
    return appSeg;
}
bool Apple::hasBeenHit(){
    return beenHit;
}
int Apple::getAppleSize(){
    return appleSize;
}

/// Mutators ///
void Apple::setSegment(const Segment s){
    appSeg = s;
}
void Apple::setPoint(const Point p){
    appSeg.setPoint(p);
}
void Apple::setColor(int r, int g , int b){
    R = r;
    G = g;
    B = b;
}
void Apple::setAppleColision(const bool b){
    beenHit = b;
}

/// Methods ///
bool Apple::checkAppleCollision(Snake s){
    bool appleEaten = false;

    //Checks every point of the snake against the evey point of the apple
    if(s.getSegment(0).getPoint() == appSeg.getPoint() ||
       s.getSegment(0).getPoint() == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
       s.getSegment(0).getPoint() == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
       s.getSegment(0).getPoint() == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize)){
        if(Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == appSeg.getPoint() ||
           Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
           Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
           Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()) == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize)){
            if(Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == appSeg.getPoint() ||
               Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
               Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
               Point(s.getSegment(0).getX(), s.getSegment(0).getY() + s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize)){
                if(Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == appSeg.getPoint() ||
                   Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY())  ||
                   Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == Point(appSeg.getX(), appSeg.getY() + appleSize) ||
                   Point(s.getSegment(0).getX() + s.getSegment(0).getSize(), s.getSegment(0).getY()+ s.getSegment(0).getSize()) == Point(appSeg.getX() + appleSize, appSeg.getY() + appleSize)){
                    appleEaten = true;
                }
            }
        }
    }


    return appleEaten;
}
void Apple::drawApple(SDL_Plotter& g){
    for(int y = 0; y < appleSize; y++){
        for(int x = 0; x < appleSize; x++){
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y, R, G, B);
        }
    }
}
void Apple::eraseApple(SDL_Plotter& g){
    for(int y = 0; y < appleSize; y++){
        for(int x = 0; x < appleSize; x++){
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y, 255, 255, 255);
        }
    }
}

