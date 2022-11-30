#include "Snake.h"
/// Constructors ///
Snake::Snake(){
    length = 1;
    isDead = false;
    dir = RIGHT;
    key = rightKey;
    R = 255;
    G = 255;
    B = 255;
}
Snake::Snake(int size, int red, int green, int blue){
    length = size;
    isDead = false;
    dir = RIGHT;
    key = rightKey;
    R = red;
    G = green;
    B = blue;
}

/// Accessors ///
int Snake::getLength() const{
    return length;
}
Segment Snake::getSegment(int i){
    return seg[i];
}
bool Snake::isSnakeDead() const{
    return isDead;
}
Direction Snake::getDirection() const{
    return dir;
}

/// Mutators ///
void Snake::setLength(const int l){
    length = l;
}
void Snake::incrementLength(){
    length++;
}
void Snake::setSegment(const Segment s, int i){
    seg[i] = s;
}
void Snake::setSnakeDeath(const bool b){
    isDead = b;
}
void Snake::setDirection(SDL_Plotter& g, char k){
        prevKey = key;
        key = k;

        /// Makes sure snake cant go in opposite direction

        if(prevKey == upKey && key == downKey ){
            key = prevKey;
        }
        else if(prevKey == downKey && key == upKey){
            key = prevKey;
        }
        else if(prevKey == leftKey && key == rightKey){
            key = prevKey;
        }
        else if(prevKey == rightKey && key == leftKey){
            key = prevKey;
        }



        switch(key){
            case upKey :
                dir = UP;
                if(prevKey != key){
                    g.playSound("SnakeGoUp.wav");
                }
                break;

            case downKey:
                dir = DOWN;
                if(prevKey != key){
                    g.playSound("SnakeGoDown.wav");
                }
                break;

            case leftKey :
                dir = LEFT;
                if(prevKey != key){
                    g.playSound("SnakeLeftTurn.wav");
                }
                break;

            case rightKey:
                dir = RIGHT;
                if(prevKey != key){
                    g.playSound("SnakeRightTurn.wav");
                }
                break;
        }
}
void Snake::setDirection(Direction d){
    dir = d;
}

/// Methods///
void Snake::checkSelfColision(SDL_Plotter& g){
    for(int i = 1; i < length; i++){
        if(seg[0].getX() == seg[i].getX()
           && seg[0].getY() == seg[i].getY()){
            g.playSound("SnakeDie.wav");
            isDead = true;
        }
    }

}
void Snake::drawSnake(SDL_Plotter& g){
    //Copy Cell Locations
    for(int i = length-1; i > 0; i--){
        seg[i].setPoint(seg[i - 1].getPoint());

    }
     //cout << dir << endl;
    switch(dir){
        case RIGHT: seg[0].setX(seg[0].getX() + SIZE);
                    break;
        case LEFT : seg[0].setX(seg[0].getX() - SIZE);
                    break;
        case UP   : seg[0].setY(seg[0].getY() - SIZE);
                    break;
        case DOWN : seg[0].setY(seg[0].getY() + SIZE);
                    break;

    }


    /// Snake Draw
    for(int i = 0; i < length; i++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                g.plotPixel(seg[i].getPoint().getX() + x,
                            seg[i].getPoint().getY() + y, 79, 121, 66);

            }
        }
    }
}
void Snake::eraseSnake(SDL_Plotter& g){
    /// Snake erase
    for (int i = 0; i < length; i++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                g.plotPixel(seg[i].getPoint().getX() + x,
                            seg[i].getPoint().getY() + y, 255,255,255);

            }
        }
    }
}

void Snake::initSounds(SDL_Plotter& g){
    /// Initializing Sounds
    g.initSound("SnakeMunchSound.wav");
    g.initSound("SnakeLeftTurn.wav");
    g.initSound("SnakeRightTurn.wav");
    g.initSound("SnakeGoUp.wav");
    g.initSound("SnakeGoDown.wav");
    g.initSound("SnakeDie.wav");

}














