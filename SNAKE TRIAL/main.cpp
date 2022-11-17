#include <iostream>
#include "SDL_Plotter.h"
#include "Point_T.h"

using namespace std;

int main(int argc, char **argv)
{
    Point_T origin(5,10);

    cout << "(" << origin.getX() << "," << origin.getY() << ")" << endl;
    origin.setX(13);
    origin.setY(4);
    cout << "(" << origin.getX() << "," << origin.getY() << ")" << endl;

    return 0;
}
