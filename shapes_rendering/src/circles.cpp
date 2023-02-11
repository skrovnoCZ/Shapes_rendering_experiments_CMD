#include "circles.h"
#include <cmath>


circles::circles()
{
}

void circles::set_parameters(float new_radius)
{
    m_radius.push_back(new_radius);
}

void circles::render_objects()
{
    for (size_t i = 0; i < m_count; i++)
    {
        for (int y = m_coords_y.at(i) - m_radius.at(i); y <= m_coords_y.at(i) + m_radius.at(i); y++)
        {
            for (int x = m_coords_x.at(i) - m_radius.at(i); x <= m_coords_x.at(i) + m_radius.at(i); x++)
            {
                //std::cout << "Distance measured is " << (int)sqrt(((m_coords_y.at(i) - y) * (m_coords_y.at(i) - y)) + ((m_coords_x.at(i) - x) * (m_coords_x.at(i) - x))) << " and radius is " << (int)m_radius.at(i) << "." << std::endl;

                if ((int)sqrt(((m_coords_y.at(i) - y) * (m_coords_y.at(i) - y)) + ((m_coords_x.at(i) - x) * (m_coords_x.at(i) - x))) == (int)m_radius.at(i))
                {
                    if (y > 0 && y < m_grid_height - 1 && x > 0 && x < m_grid_width - 1)
                    {
                        m_p_grid->set_symbol(SYMBOL_TEXTURE, y, x);
                    }
                }
            }
        }
    }
}

circles::~circles()
{
}
