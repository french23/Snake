 /*
 * Author: Peter Whitcomb
 * Assignment Title: Snake Game
 * Assignment Description: Create the game Snake
 * Due Date: 12/7/2022
 * Date Created: 11/26/2022
 * Date Last Modified: 12/7/2022
 */
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

using namespace std;

class Point{
    private:
        int x;
        int y;
    public:
        //Constructors
        Point();
        Point(int, int);

        ///Accessors

        //******************************************************************
        // Description: Gets the X instance variable                       *
        // Return: Integer                                                 *
        // Precondition: The Point object exists                           *
        // Postcondition: The X instance variable is returned.             *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        int getX() const;

        //******************************************************************
        // Description: Gets the Y instance variable                       *
        // Return: Integer                                                 *
        // Precondition: The Point object exists                           *
        // Postcondition: The Y instance variable is returned.             *
        //                The object is unchanged.                         *
        //                                                                 *
        //******************************************************************
        int getY() const;

        /// Mutators
        //******************************************************************
        // Description: Sets the X instance variable                       *
        // Return: Void                                                    *
        // Precondition: The Point object exists                           *
        // Postcondition: The X instance variable is Changes to parameter. *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void setX(const int);

        //******************************************************************
        // Description: Sets the Y instance variable                       *
        // Return: Void                                                    *
        // Precondition: The Point object exists                           *
        // Postcondition: The Y instance variable is Changes to parameter. *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void setY(const int);

        /// Over loaders

        //******************************************************************
        // Description: Overloads the '=' operator                         *
        // Return: Void                                                    *
        // Precondition: Both Point objects exists                         *
        // Postcondition: The instance variables of the second object is   *
        //                  set to the first object.                       *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        void operator=(const Point& other);

        //******************************************************************
        // Description: Overloads the '==' operator                        *
        // Return: Boolean                                                 *
        // Precondition: Both Point objects exists                         *
        // Postcondition: The checks to see if the Point objects equal     *
        //                  each other, returns true if they do false      *
        //                  otherwise.                                     *
        //                The object is changed.                           *
        //                                                                 *
        //******************************************************************
        bool operator==(const Point& other);

};


#endif // POINT_H_INCLUDED
