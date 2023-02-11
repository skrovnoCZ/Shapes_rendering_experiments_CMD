#include "rectangles.h"



rectangles::rectangles()
{
}

void rectangles::set_parameters(float new_width, float new_height)
{
    m_width.push_back(new_width);
    m_height.push_back(new_height);
}

void rectangles::render_objects()
{
    for (size_t i = 0; i < m_count; i++)
    {
        if (((m_coords_y.at(i) + (m_height.at(i) / 2) * -1) < m_grid_height - 1 && (m_coords_y.at(i) + (m_height.at(i) / 2) * -1) > 0)
            && ((m_coords_x.at(i) + (m_width.at(i) / 2) * -1) < m_grid_width - 1 && (m_coords_x.at(i) + (m_width.at(i) / 2) * -1) > 0))
        {
            for (int y = (m_height.at(i) / 2) * -1; y <= m_height.at(i) / 2; y++)
            {
                for (int x = (m_width.at(i) / 2) * -1; x <= m_width.at(i) / 2; x++)
                {
                    if (y == (int)(m_height.at(i) / 2) * -1 || y == (int)(m_height.at(i) / 2) || x == (int)(m_width.at(i) / 2) * -1 || x == (int)(m_width.at(i) / 2))   //int fixes float render but cannot be used when rendering to float grid
                    {
                        m_p_grid->set_symbol(SYMBOL_TEXTURE, m_coords_y.at(i) + y, m_coords_x.at(i) + x);
                    }
                }
            }
        }
    }
}

rectangles::~rectangles()
{
}
