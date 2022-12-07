 /*
 * Author: Peter Whitcomb
 * Assignment Title: Snake Game
 * Assignment Description: Create the game Snake
 * Due Date: 12/7/2022
 * Date Created: 11/26/2022
 * Date Last Modified: 12/7/2022
 */
#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED
#include "Snake.h"
#include "ctime"

using namespace std;

class Apple{
    private:
        Segment appSeg;
        bool beenHit;
        int R, G, B;
        int appleSize = 25;
    public:
        /// Constructors ///
        Apple();
        Apple(int size, Point p, int r = 255, int g = 215, int b = 0);

        /// Accessors ///
        //******************************************************************
        // Description: Gets the segment of the apple.                     *
        // Return: Segment                                                 *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's segment is returned.                 *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        Segment getSegment();

        //******************************************************************
        // Description: Gets the beenHit boolean.                          *
        // Return: Boolean                                                 *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's beenHit boolean is returned.         *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        bool hasBeenHit();

        //******************************************************************
        // Description: Gets the apple's size.                             *
        // Return: Integer                                                 *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's size is returned.                    *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        int getAppleSize();

        /// Mutators ///

        //******************************************************************
        // Description: Sets the segment of the apple.                     *
        // Return: Void                                                    *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's segment is set to parameter value.   *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void setSegment(const Segment);

        //******************************************************************
        // Description: Sets the Point of the apple.                       *
        // Return: Void                                                    *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's point is set to parameter value.     *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void setPoint(const Point);

        //******************************************************************
        // Description: Sets the Color of the apple.                       *
        // Return: Void                                                    *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's color is set to parameter value.     *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void setColor(int, int, int);

        //******************************************************************
        // Description: Sets the collision of the apple.                   *
        // Return: Void                                                    *
        // Precondition: The Apple object exists                           *
        // Postcondition: The apple's collision is set to parameter value. *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void setAppleColision(const bool);


        /// Methods ///

        //******************************************************************
        // Description: Checks to see if the snake hit the apple.          *
        // Return: Boolean                                                 *
        // Precondition: The Apple object exists                           *
        // Postcondition: Returns true if the snake hit the apple, false   *
        //                  otherwise.                                     *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        bool checkAppleCollision(Snake);

        //******************************************************************
        // Description: Draws the apple to a SDL Plotter                   *
        // Return: Void                                                    *
        // Precondition: The Apple object exists                           *
        // Postcondition: Apple is drawn to screen                         *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        void drawApple(SDL_Plotter&);

        //******************************************************************
        // Description: Erases the apple from a SDL Plotter                *
        // Return: Void                                                    *
        // Precondition: The Apple object exists                           *
        // Postcondition: Apple is erased from the screen.                 *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        void eraseApple(SDL_Plotter&);

        //******************************************************************
        // Description: Creates an available point the apple can be drawn  *
        // Return: Point                                                   *
        // Precondition: The Apple object exists                           *
        // Postcondition: An available point that apple can be drawn on    *
        //                  is returned                                    *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        Point createPoint(Snake);
};

#endif // APPLE_H_INCLUDED
