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
    // top left, reference point
    if(s.getSegment(0).getX() >= appSeg.getX() && s.getSegment(0).getX() <= appSeg.getX() + appleSize){
        if(s.getSegment(0).getY() >= appSeg.getY() && s.getSegment(0).getY() <= appSeg.getY() + appleSize){
            appleEaten = true;
        }
    }
    // top right
    if(s.getSegment(0).getX() + SIZE >= appSeg.getX() && s.getSegment(0).getX() + SIZE <= appSeg.getX() + appleSize){
        if(s.getSegment(0).getY() >= appSeg.getY() && s.getSegment(0).getY() <= appSeg.getY() + appleSize){
            appleEaten = true;
        }
    }
    // bottom left
    if(s.getSegment(0).getX() >= appSeg.getX() && s.getSegment(0).getX() <= appSeg.getX() + appleSize){
        if(s.getSegment(0).getY() + SIZE >= appSeg.getY() && s.getSegment(0).getY() + SIZE <= appSeg.getY() + appleSize){
            appleEaten = true;
        }
    }
    // bottum right
    if(s.getSegment(0).getX() + SIZE >= appSeg.getX() && s.getSegment(0).getX() + SIZE <= appSeg.getX() + appleSize){
        if(s.getSegment(0).getY() + SIZE >= appSeg.getY() && s.getSegment(0).getY() + SIZE <= appSeg.getY() + appleSize){
            appleEaten = true;
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

