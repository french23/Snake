#include "Game.h"

using namespace std;

///Constructors///
Game::Game(){
    s = Snake();
    a = Apple();
    score = 0;
    gameOver = false;
    isPaused = false;
    isReset = false;

}
Game::Game(Snake snk, Apple app){
    s = snk;
    a = app;

    score = 0;
    gameOver = false;
    isPaused = false;
    isReset = false;
}

///Accessors ///
Snake Game::getSnake() const{
    return s;
}
Apple Game::getApple()const{
    return a;
}
int   Game::getScore() const{
    return score;
}
bool  Game::getGameCond()const{
    return s.isSnakeDead();
}
bool  Game::getIsPaused(){
    return isPaused;
}
char  Game::getKey(){
    return key;
}

///Mutators///
void Game::setSnake(const Snake snk){
    s = snk;
}
void Game::setApple(const Apple app){
    a = app;
}
void Game::setScore(const int s){
    score = s;
}
void Game::incrementScore(){
    score++;
}
void Game::setPause(const bool b){
    isPaused = b;
}
void Game::setKey(const char c){
    key = c;
}

///Methods///
void Game::checkBoarderCollision(SDL_Plotter& g){

    if(s.getDirection() == UP ){
        if(s.getSegment(0).getY() == 0){
            g.playSound("death.mp3");
            s.setSnakeDeath(true); /// End Game
        }
    }
    else if(s.getDirection() == DOWN ){
        if(s.getSegment(0).getY() + SIZE == g.getRow()){
            g.playSound("death.mp3");
            s.setSnakeDeath(true); /// End Game
        }
    }
    else if(s.getDirection() == LEFT ){
        if(s.getSegment(0).getX() == 0){
            g.playSound("death.mp3");
            s.setSnakeDeath(true); /// End Game
        }
    }
    else if(s.getDirection() == RIGHT ){
        if(s.getSegment(0).getX() + SIZE == g.getCol()){
            g.playSound("death.mp3");
            s.setSnakeDeath(true); /// End Game
        }
    }

}
void Game::playClassicSnake(SDL_Plotter& g){
    ///Resets game
    if(isReset){
        resetGame(g);
    }
    ///Keyboard detection
    if(g.kbhit()){
        key = g.getKey();
        s.setDirection(g, key);
        switch(key){
            case 'p': isPaused = !isPaused; /// 'p' pauses game
                    break;
            case 'r': isReset = true;
                    break;
        }
    }
    if(!s.isSnakeDead() && !isPaused){
        ///Apple Collision
        if(a.checkAppleCollision(s)){
            a.eraseApple(g);
            a.setPoint(a.createPoint(s));

            s.incrementLength();
            g.playSound("appleappleeateat.mp3");
            score++;

        }

        /// Self and wall collision
        s.checkSelfColision(g);
        checkBoarderCollision(g);

        /// Draw snake and apple
        a.drawApple(g);
        if(!s.isSnakeDead()){
            s.eraseSnake(g);
            s.drawSnake(g);
        }



        /// Update
        g.Sleep(100);
        g.update();
    }
}
void Game::resetGame(SDL_Plotter& g){
    g.clear();

    //Reset length
    s.setLength(2);

    //Reset snake and apple points
    s.setSegment( Segment(25, Point((650 / 2), (900 / 2))) , 0);
    s.setSegment( Segment(25, Point((650 / 2 + 25), (900 / 2 + 25))) , 1);
    a.setPoint(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25)));

    //Reset Conditionals
    isReset = false;
    s.setSnakeDeath(false);
    score = 0;
    s.setDirection(RIGHT);
    key = rightKey;



}
void Game::initSounds(SDL_Plotter& g){
    /// Initializing Sounds
    g.initSound("appleappleeateat.mp3");
    g.initSound("left.mp3");
    g.initSound("right.mp3");
    g.initSound("up.mp3");
    g.initSound("down.mp3");
    g.initSound("death.mp3");
}

///Methods regarding save/load game
void Game::saveGame(string fName){
    filePush.open(fName);

    //Score and length
    filePush << "Score: " << endl
             << score << endl << endl
             << "Length: " << endl
             << s.getLength() << endl << endl
             << "Direction: " << endl
             << s.getDirection() << endl << endl;

    //Snake Reference Points
    filePush << "SnakePoints: " << endl;
    for(int i = 0; i < s.getLength(); i++){
        filePush << s.getSegment(i).getX() << " "
                 << s.getSegment(i).getY() << endl;
    }
    filePush << endl;

    //Apple Point
    filePush << "ApplePoint: " << endl
             << a.getSegment().getX() << " "
             << a.getSegment().getY() << endl;




    filePush.close();



}
void Game::loadGame(string fName){
    fileRead.open(fName);
    string junk;
    int num, x, y;
    Direction d;
    //Set Score
    fileRead >> junk;
    fileRead >> num;
    score = num;

    //Set Snake's Length
    fileRead >> junk;
    fileRead >> num;
    s.setLength(num);

    //Set Snakes Direction
    fileRead >> junk;
    fileRead >> num;

    switch(num){
        case 0:  d = UP;
                 break;
        case 1:  d = DOWN;
                 break;
        case 2:  d = LEFT;
                 break;
        case 3:  d = RIGHT;
                 break;
    }
    s.setDirection(d);

    //Set Snake ref Points
    fileRead >> junk;
    for(int i = 0; i < s.getLength(); i++){
        fileRead >> x >> y;
        s.setRefPoint(i, Point(x,y));
    }

    //Set apple ref Points
    fileRead >> junk;
    fileRead >> x >> y;
    a.setPoint(Point(x,y));


    fileRead.close();
}

///Methods regarding HighScore
void Game::readHighScores(string fName){
    fileRead.open(fName);
    string name;
    int fileScore;

    for(int i = 0; i < 10; i++){
        fileRead >>  name >> fileScore;
        highScoreNames[i] = name;
        highScores[i] = fileScore;
    }

    fileRead.close();
}
void Game::setHighScores(string fName, string username){
    readHighScores(fName);
    filePush.open(fName);
    highScoreNames[10] = username;
    highScores[10] = score;

    //Sort data
    for(int pass = 0; pass < 10; pass++){
        for(int j = 0; j < 10 - pass; j++){
            if(highScores[j] < highScores[j+1]){
                swap(highScores[j], highScores[j+1]);
                swap(highScoreNames[j], highScoreNames[j+1]);
            }
        }
    }

    for(int i = 0; i < 10; i++){
        filePush << highScoreNames[i] << " "
                 <<highScores[i] << endl;
    }

    filePush.close();

}
