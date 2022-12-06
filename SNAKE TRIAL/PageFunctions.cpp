#include "PageFunctions.h"

string mainPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT)
{
    string return_comand = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox title(Point(250,50),15,"SNAKE!");
    textBox play(Point(450,200),10,"PLAY");
    textBox loadSaved(Point(220,320),10,"LOAD SAVED");
    textBox exit(Point(450,600),10,"EXIT");
    ///NEW STUFF
    textBox controls(Point(900,750),4,"CONTROLS");


    fill_screen_with_color(g,background_color, WIDTH, HEIGHT);

    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    title.draw(g);
    play.draw(g,border_color,background_color);
    loadSaved.draw(g,border_color,background_color);
    exit.draw(g,border_color,background_color);
    ///NEW STUFF
    controls.draw(g,border_color,background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();

        // check the exit button
        if(exit.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_comand = "exit";
        }
        // check the play button
        else if(play.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_comand = "start game";
        }
         else if(loadSaved.isClicked(Point(temp.x,temp.y))){
            return_comand = "load saved";
            g.playSound("uibuttonclick2.mp3");
        }
        ///NEW STUFF
        else if(controls.isClicked(Point(temp.x,temp.y))){
            return_comand = "controls";
            g.playSound("uibuttonclick2.mp3");
        }

    }

    return return_comand;
}

string gameOverPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT)
{
    string return_comand = "null";color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    color background_color;
    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    textBox gameOver(Point(100,200),13,"GAME OVER!");
    textBox play_again(Point(300,320),8,"PLAY AGAIN");
    textBox main_page(Point(340,440),8,"MAIN PAGE");

    gameOver.draw(g);
    play_again.draw(g, border_color, background_color);
    main_page.draw(g, border_color, background_color);

    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(play_again.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_comand = "play again";
        }
        else if(main_page.isClicked(Point(temp.x,temp.y)))
        {
               g.playSound("uibuttonclick2.mp3");
               return_comand = "main page";
        }
    }

    return return_comand;
}

void fill_screen_with_color(SDL_Plotter& g, color background_color,const int& WIDTH, const int& HEIGHT)
{
    for(int x = 0; x < HEIGHT; x++)
    {
        for(int y = 0; y < WIDTH; y++)
        {
            g.plotPixel(x,y,background_color);
        }
    }
}

string pauseGamePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    color background_color;
    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    textBox pauseGame(Point(100, 75),13,"PAUSE GAME");
    textBox resumeGame(Point(250,220),8,"RESUME GAME");
    textBox resetGame(Point(275,340),8,"RESET GAME");
    textBox saveGame(Point(300,460),8,"SAVE GAME");
    textBox mainPage(Point(300,580),8,"MAIN PAGE");


    pauseGame.draw(g);
    resumeGame.draw(g, border_color, background_color);
    resetGame.draw(g, border_color, background_color);
    saveGame.draw(g, border_color, background_color);
    mainPage.draw(g, border_color, background_color);

    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(resumeGame.isClicked(Point(temp.x,temp.y)))
        {
            g.Sleep(100);
            g.playSound("uibuttonclick2.mp3");
            return_command = "resume game";
        }
        else if(resetGame.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "reset game";
        }
        else if(saveGame.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "save game";

        }
        else if(mainPage.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "main page";
        }
    }

    return return_command;
}

string saveGamePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox saveGame(Point(175, 300),10, "GAME SAVED!");
    textBox okay(Point(450,500),8,"OKAY");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
    saveGame.draw(g);
    okay.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(okay.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "clicked";
        }
    }

    return return_command;

}

string successLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox loadedGame(Point(175, 300),10, "LOADED GAME!");
    textBox play(Point(450,500),8,"PLAY");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
    loadedGame.draw(g);
    play.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(play.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "clicked";
        }
    }

    return return_command;
}

string failedLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox loadedGame(Point(75, 300),10, "NO SAVED DATA!");
    textBox mainPage(Point(300,500),8,"MAIN PAGE");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
    loadedGame.draw(g);
    mainPage.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(mainPage.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "clicked";
        }
    }

    return return_command;
}

///NEW STUFF
string controlsPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    //use WASD
    textBox use(Point(125, 150),8, "USE");
    textBox W(Point(450, 80), 8, "W");
    textBox A(Point(370, 160), 8, "A");
    textBox S(Point(450, 160), 8, "S");
    textBox D(Point(530, 160), 8, "D");
    textBox toMove(Point(650, 150),8, "TO MOVE");

    //press pause
    textBox press(Point(125, 450),8, "PRESS");
    textBox P(Point(475, 450), 8, "P");
    textBox toPause(Point(600, 450),8, "TO PAUSE");

    //main button
    textBox mainPage(Point(300,700),8,"MAIN PAGE");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);

    //use WASD
    use.draw(g);
    W.draw(g, border_color);
    S.draw(g, border_color);
    A.draw(g, border_color);
    D.draw(g, border_color);
    toMove.draw(g);

    //press Pause
    press.draw(g);
    P.draw(g, border_color);
    toPause.draw(g);

    //main page
    mainPage.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(mainPage.isClicked(Point(temp.x,temp.y)))
        {
            g.playSound("uibuttonclick2.mp3");
            return_command = "clicked";
        }
    }

    return return_command;

}



