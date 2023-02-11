#include "objects.h"



objects::objects()
{
    m_object_count = 0;
}

void objects::configure_grid(grid_screen* p_grid)
{
    m_p_grid = p_grid;
    m_grid_width = m_p_grid->get_width();
    m_grid_height = m_p_grid->get_height();
}

void objects::make_object_rectangle(float new_x, float new_y, float new_width, float new_height)
{
    m_coords_x.push_back(new_x);
    m_coords_y.push_back(new_y);
    m_width.push_back(new_width);
    m_height.push_back(new_height);
    m_no_collide.push_back(true);
    m_object_count++;
}

void objects::object_collide_rectangle()
{
    bool first_not_tested;

    for (size_t i = 0; i < m_no_collide.size(); i++)
    {
        m_no_collide.at(i) = true;
    }

    for (size_t y = 0; y < m_object_count; y++)
    {
        first_not_tested = true;

        for (size_t x = 0; x < m_object_count; x++)
        {
            if (x != y)
            {
                if (m_coords_x.at(x) + m_width.at(x) / 2 < m_coords_x.at(y) - m_width.at(y) / 2)
                {
                    if (m_no_collide.at(x))
                    {
                        m_no_collide.at(x) = false;
                        m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(x), (size_t)m_coords_x.at(x));

                        if (first_not_tested)
                        {
                            m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(y), (size_t)m_coords_x.at(y));
                            first_not_tested = false;
                        }
                    }
                }
                else if (m_coords_x.at(x) - m_width.at(x) / 2 > m_coords_x.at(y) + m_width.at(y) / 2)
                {
                    if (m_no_collide.at(x))
                    {
                        m_no_collide.at(x) = false;
                        m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(x), (size_t)m_coords_x.at(x));

                        if (first_not_tested)
                        {
                            m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(y), (size_t)m_coords_x.at(y));
                            first_not_tested = false;
                        }
                    }
                }
                else if (m_coords_y.at(x) + m_width.at(x) / 2 < m_coords_y.at(y) - m_width.at(y) / 2)
                {
                    if (m_no_collide.at(x))
                    {
                        m_no_collide.at(x) = false;
                        m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(x), (size_t)m_coords_x.at(x));

                        if (first_not_tested)
                        {
                            m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(y), (size_t)m_coords_x.at(y));
                            first_not_tested = false;
                        }
                    }
                }
                else if (m_coords_y.at(x) - m_width.at(x) / 2 > m_coords_y.at(y) + m_width.at(y) / 2)
                {
                    if (m_no_collide.at(x))
                    {
                        m_no_collide.at(x) = false;
                        m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(x), (size_t)m_coords_x.at(x));

                        if (first_not_tested)
                        {
                            m_p_grid->set_symbol(SYMBOL_NO_COLLIDE, (size_t)m_coords_y.at(y), (size_t)m_coords_x.at(y));
                            first_not_tested = false;
                        }
                    }
                }
                else
                {
                    m_no_collide.at(x) = false;
                    m_p_grid->set_symbol(SYMBOL_COLLIDE, (size_t)m_coords_y.at(x), (size_t)m_coords_x.at(x));

                    if (first_not_tested)
                    {
                        m_p_grid->set_symbol(SYMBOL_COLLIDE, (size_t)m_coords_y.at(y), (size_t)m_coords_x.at(y));
                        first_not_tested = false;
                    }
                }
            }
        }
    }
}

void objects::render_objects()
{
    m_p_grid->refresh_grid();

    for (size_t i = 0; i < m_object_count; i++)
    {
        if (((m_coords_y.at(i) + (m_height.at(i) / 2) * -1) < m_grid_height - 1 && (m_coords_y.at(i) + (m_height.at(i) / 2) * -1) > 0)
            && ((m_coords_x.at(i) + (m_width.at(i) / 2) * -1) < m_grid_width - 1 && (m_coords_x.at(i) + (m_width.at(i) / 2) * -1) > 0))
        {
            for (int y = (int)((m_height.at(i) / 2.0f) * -1.0f); y <= (int)(m_height.at(i) / 2.0f); y++)
            {
                for (int x = (int)((m_width.at(i) / 2.0f) * -1.0f); x <= (int)(m_width.at(i) / 2.0f); x++)
                {
                    if (y == (int)((m_height.at(i) / 2.0f) * -1.0f) || y == (int)(m_height.at(i) / 2.0f) || x == (int)((m_width.at(i) / 2.0f) * -1.0f) || x == (int)(m_width.at(i) / 2.0f))
                    {
                        m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)m_coords_y.at(i) + y, (size_t)m_coords_x.at(i) + x);
                    }
                }
            }
        }
    }
}

void objects::set_object_coords(size_t object, float new_x, float new_y)
{
    m_coords_x.at(object) = new_x;
    m_coords_y.at(object) = new_y;
}

size_t objects::get_object_count()
{
    return m_object_count;
}

objects::~objects()
{
}
