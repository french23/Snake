/*
* Author: Peter Whitcomb
* Assignment Title: Snake Game
* Assignment Description: Create the game Snake
* Due Date: 12/7/2022
* Date Created: 11/26/2022
* Date Last Modified: 12/7/2022
*/
#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "Segment.h"
using namespace std;

const char upKey    = 'w';
const char downKey  = 's';
const char leftKey  = 'a';
const char rightKey = 'd';

const int MAX_SIZE = 100;
const int SIZE = 25;


enum Direction {UP, DOWN, LEFT, RIGHT};
class Snake
{
private:
    int length;
    Segment seg[MAX_SIZE];
    bool isDead;
    Direction dir;
    int R,G,B;
    char key, prevKey;


public:
    /// Constructors ///
    Snake();
    Snake(int size, int red = 0, int green = 0, int blue = 0);

    /// Accessors ///

    //******************************************************************
    // Description: Gets the length of the Snake                       *
    // Return: Integer                                                 *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's length is returned.                  *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    int getLength() const;

    //******************************************************************
    // Description: Gets the segment of the Snake                      *
    // Return: Segment                                                 *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's Segment is returned.                 *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    Segment getSegment(int i);

    //******************************************************************
    // Description: Gets the bool value isDead.                        *
    // Return: Boolean                                                 *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's bool val isDead is returned.         *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    bool isSnakeDead() const;

    //******************************************************************
    // Description: Gets the Direction of the Snake                    *
    // Return: Direction                                               *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's direction is returned.               *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    Direction getDirection() const;

    /// Mutators ///

    //******************************************************************
    // Description: Sets the length of the Snake                       *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's length is set to parameter value.    *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setLength(const int);

    //******************************************************************
    // Description: increments snake's length by one.                  *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's length is incremented by one.        *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void incrementLength();

    //******************************************************************
    // Description: Sets the snake's Segment at parameter value        *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's segment at given index value to      *
    //                  to parameter value.                            *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setSegment(const Segment, const int);

    //******************************************************************
    // Description: Sets the snake's death.                            *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's isDead is set to parameter value.    *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setSnakeDeath(const bool);

    //******************************************************************
    // Description: Sets the snake's Direction.                        *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's direction is set to parameter value. *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setDirection(const Direction);

    //******************************************************************
    // Description: Sets the snake's Direction based off of key. If    *
    //                  the key is 'w', 'a', 's', or 'd' it sets it    *
    //                  up, left, down, and right. Additionally it     *
    //                  makes sure it cannot go in the opposite        *
    //                  direction (i.e. if they are going up you       *
    //                  cannot go down)                                *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's direction is based of keyboard input.*
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setDirection(SDL_Plotter& g, char k);

    //******************************************************************
    // Description: Sets the snake's reference point and index i.      *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: The snake's reference point is set to index i.   *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setRefPoint(int i, Point p);

    //******************************************************************
    // Description: Sets the snake's key character                     *
    // Return: Void                                                    *
    // Precondition: The Snake object exists.                          *
    // Postcondition: The snake's key char is set to parameter value.  *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setKey(const char k);



    /// Methods ///

    //******************************************************************
    // Description: Checks to see if the snake hits itself.            *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: Will turn snakes death to true if hit, false     *
    //                  otherwise                                      *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void checkSelfColision(SDL_Plotter& g);

    //******************************************************************
    // Description: Draws the whole snake object.                      *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: Snake is drawn to the SDL plotter.               *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void drawSnake(SDL_Plotter&);

    //******************************************************************
    // Description: Erases the whole snake                             *
    // Return: Void                                                    *
    // Precondition: The Snake object exists                           *
    // Postcondition: Snake is erased from  the SDL plotter.           *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    void eraseSnake(SDL_Plotter&);






};

#endif // SNAKE_H_INCLUDED
