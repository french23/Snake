#include "pixel_square.h"


pixel_square::pixel_square(Point_T sqr_origin, int input_size)
{
    m_sqr_origin = sqr_origin;
    m_size = input_size;
}

pixel_square::pixel_square()
{
    m_sqr_origin = (Point_T(0,0));
    m_size = 10;
}

int pixel_square::get_size()
{
    return m_size;
}

void pixel_square::fill_with_color(color fill_color, SDL_Plotter& g)
{
    //cout << "inside of the fill_with_color function " << endl;
    for(int x = 0; x < m_size; x++)
    {
        for(int y = 0; y < m_size; y++)
        {
            g.plotPixel(m_sqr_origin.getX()+x, m_sqr_origin.getY()+y ,fill_color);
        }
    }
}
