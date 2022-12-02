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
int Apple::getR(){
    return R;
}
int Apple::getG(){
    return G;
}
int Apple::getB(){
    return B;
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
    //Apple Corners + Leaf
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y, 255, 255, 255);
            g.plotPixel(appSeg.getX() + x+20, appSeg.getY() + y, 255, 255, 255);
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y+20, 255, 255, 255);
            g.plotPixel(appSeg.getX() + x+20, appSeg.getY() + y+20, 255, 255, 255);
            g.plotPixel(appSeg.getX() + x+14, appSeg.getY() - y-10, 92, 169, 4);
        }
    }
    //Apple Stem
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 10; y++){
            g.plotPixel(appSeg.getX() + x+10, appSeg.getY() - y, 128, 64, 0);
        }
    }

}
void Apple::eraseApple(SDL_Plotter& g){
    for(int y = 0; y < appleSize; y++){
        for(int x = 0; x < appleSize; x++){
            g.plotPixel(appSeg.getX() + x, appSeg.getY() + y, 255, 255, 255);
        }
    }
    //Apple Stem Erase
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 10; y++){
            g.plotPixel(appSeg.getX() + x+10, appSeg.getY() - y, 255, 255, 255);
        }
    }
    //Apple Leaf Erase
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            g.plotPixel(appSeg.getX() + x+14, appSeg.getY() - y-10, 255, 255, 255);
        }
    }
}

