#include "grid_square.h"

grid_square::grid_square()
{
    m_grid_size = 10;
    m_sqr_size = 10;
    m_point.setX(0);
    m_point.setY(0);

    create_grid();
}

grid_square::grid_square(int grid_size, int sqr_size, Point location)
{
    m_grid_size = grid_size;
    m_sqr_size = sqr_size;
    m_point = location;

    create_grid();
}

/*
* description: colors a square
* return: none
* precondition: the location and color of the sqr
* postcondition: colors the sqr to the correct color
*
*/
void grid_square::color_sqr(Point location, color fill_color, SDL_Plotter& g)
{
    m_grid[location.getX()][location.getY()].draw(g, fill_color);
    //m_grid[3][3].get_size();
}

/*
   * description: fills the vecor with pixel squares
   * return: none
   * precondition: fills the vecor with pixel squares
   * postcondition: vector is full
   *
   */
void grid_square::create_grid()
{
    for(int x = 0; x < m_grid_size; x++)
    {
        vector<Segment> temp_vec;
        for(int y = 0; y < m_grid_size; y++)
        {
            Point temp_point(m_point.getX() + (x * m_sqr_size), m_point.getY() + (y* m_sqr_size));

            Segment temp_pixel_sqr(m_sqr_size, temp_point);

            temp_vec.push_back(temp_pixel_sqr);
        }

        m_grid.push_back(temp_vec);
    }
}
