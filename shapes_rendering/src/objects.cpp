#include "objects.h"



objects::objects()
{
    m_p_grid = nullptr;
    m_count = 0;
}

void objects::configure_grid(grid_screen* p_grid)
{
    m_p_grid = p_grid;
    m_grid_width = m_p_grid->get_width();
    m_grid_height = m_p_grid->get_height();
}

void objects::make_object(float new_x, float new_y)
{
    m_coords_x.push_back(new_x);
    m_coords_y.push_back(new_y);
    m_count++;
}

void objects::set_object_coords(size_t object, float new_x, float new_y)
{
    m_coords_x.at(object) = new_x;
    m_coords_y.at(object) = new_y;
}

objects::~objects()
{
}
