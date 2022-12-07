/*
* Author: Peter Whitcomb
* Assignment Title: Snake Game
* Assignment Description: Create the game Snake
* Due Date: 12/7/2022
* Date Created: 11/26/2022
* Date Last Modified: 12/7/2022
*/
#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED

#include "Point.h"
#include "SDL_Plotter.h"
using namespace std;
class Segment
{
private:
    int segS;
    Point p;

public:
    //Constructors
    Segment();
    Segment(int, Point);

    /// Accessors
    //******************************************************************
    // Description: Gets the size of the Segment.                      *
    // Return: Integer                                                 *
    // Precondition: The Segment object exists                         *
    // Postcondition: The segments size is returned.                   *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    int getSize() const;

    //******************************************************************
    // Description: Gets the Point of the Segment.                     *
    // Return: Point                                                   *
    // Precondition: The Segment object exists                         *
    // Postcondition: The segments point is returned.                  *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    Point getPoint() const;

    //******************************************************************
    // Description: Gets the X instance variable of the Point p.       *
    // Return: Integer                                                 *
    // Precondition: The Segment object exists                         *
    // Postcondition: The X instance variable of p is returned.        *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    int getX();

    //******************************************************************
    // Description: Gets the Y instance variable of the Point p.       *
    // Return: Integer                                                 *
    // Precondition: The Segment object exists                         *
    // Postcondition: The Y instance variable of p is returned.        *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    int getY();

    ///Mutators

    //******************************************************************
    // Description: Sets the size of the Segment.                      *
    // Return: Void                                                    *
    // Precondition: The Segment object exists                         *
    // Postcondition: The segments size is set to parameter value.     *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setSize(const int);

    //******************************************************************
    // Description: Sets the Point of the Segment.                     *
    // Return: Void                                                    *
    // Precondition: The Segment object exists                         *
    // Postcondition: The segments point is set to parameter point.    *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setPoint(const Point);

    //******************************************************************
    // Description: Sets the X instance variable of the Point p.       *
    // Return: Void                                                    *
    // Precondition: The Segment object exists                         *
    // Postcondition: The X instance variable of p is set to parameter *
    //                  value.                                         *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setX(int);

    //******************************************************************
    // Description: Sets the Y instance variable of the Point p.       *
    // Return: Void                                                    *
    // Precondition: The Segment object exists                         *
    // Postcondition: The Y instance variable of p is set to parameter *
    //                  value.                                         *
    //                The object is changed.                           *
    //                                                                 *
    //******************************************************************
    void setY(int);

    /// Methods

    //******************************************************************
    // Description: Draws the square making p the reference point.     *
    //              Takes in R G B color parameters.                   *
    // Return: Void                                                    *
    // Precondition: The Segment object exists                         *
    // Postcondition: The segment is drawn to the screen               *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    void draw(SDL_Plotter&, int r = 0, int g = 0, int b = 0);

    //******************************************************************
    // Description: Draws the square making p the reference point.     *
    //              Takes in Color Object as parameters.               *
    // Return: Void                                                    *
    // Precondition: The Segment object exists                         *
    // Postcondition: The segment is drawn to the screen               *
    //                The object is unchanged.                         *
    //                                                                 *
    //******************************************************************
    void draw(SDL_Plotter&, color input_color);




};
#endif // SEGMENT_H_INCLUDED
