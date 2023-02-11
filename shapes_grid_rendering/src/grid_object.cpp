#include <cmath>
#include "grid_object.h"

using namespace std;

grid_object::grid_object()
{
}

void grid_object::configure_grid(grid_screen* p_grid)
{
    m_p_grid = p_grid;
    m_grid_width = m_p_grid->get_width();
    m_grid_height = m_p_grid->get_height();
}

void grid_object::add_coord(float new_x, float new_y)
{
    bool id_found = true;
    size_t id = 1;

    if (m_ids_assigned.size() == 0)
    {
        m_coord_x[id] = new_x;
        m_coord_y[id] = new_y;
        m_ids_assigned[id] = { 0 };
    }
    else
    {
        while (id_found)
        {
            id_found = false;

            for (const auto& elem : m_ids_assigned)
            {
                if (elem.first == id)
                {
                    id_found = true;
                }
            }

            if (!id_found)  //if ID was not found, use this ID
            {
                m_coord_x[id] = new_x;
                m_coord_y[id] = new_y;
                m_ids_assigned[id] = { 0 };
            }

            id++;
        }
    }
}

void grid_object::set_coord(size_t new_id, float new_x, float new_y)
{
    m_coord_x.at(new_id) = new_x;
    m_coord_y.at(new_id) = new_y;
}

float grid_object::get_coord_x(size_t new_id)
{
    return m_coord_x.at(new_id);
}

float grid_object::get_coord_y(size_t new_id)
{
    return m_coord_y.at(new_id);
}

size_t grid_object::get_coord_count()
{
    return m_coord_x.size();
}

void grid_object::render_object()
{
    vector<size_t> elem_i_used;
    bool id_not_used = true;
    for (const auto& elem_i : m_ids_assigned)
    {
        elem_i_used.push_back(elem_i.first);

        if (elem_i.second.size() > 0)   //if at least one connection with selected point
        {
            for (size_t j = 0; j < elem_i.second.size(); j++)
            {
                id_not_used = true;

                if (elem_i.first != elem_i.second.at(j))    //if two selected points are not single poind (if not same ID)
                {
                    for (size_t i = 0; i < elem_i_used.size(); i++)
                    {
                        if (elem_i.second.at(j) == elem_i_used.at(i))  //test if selected coord was already connected
                        {
                            id_not_used = false;
                        }
                    }

                    if (id_not_used)
                    {
                        float x_source_0 = m_coord_x.find(elem_i.first)->second;
                        float y_source_0 = m_coord_y.find(elem_i.first)->second;

                        float x_source_1 = m_coord_x.find(elem_i.second.at(j))->second;
                        float y_source_1 = m_coord_y.find(elem_i.second.at(j))->second;

                        float x_dist = x_source_1 - x_source_0;
                        float y_dist = y_source_1 - y_source_0;

                        calculate_line(x_source_0, y_source_0, x_dist, y_dist);
                    }
                }
            }
        }
        else
        {
            m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)m_coord_y.find(elem_i.first)->second, (size_t)m_coord_x.find(elem_i.first)->second); //single point (no connection)
        }


    }
}

void grid_object::calculate_line(float new_x_source_0, float new_y_source_0, float new_x_dist, float new_y_dist)
{
    if (abs(new_x_dist) > abs(new_y_dist))
    {
        if (new_x_dist < 0.0f)
        {
            for (int i = (int)new_x_dist; i <= 0; i++)
            {
                m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)(new_y_source_0 + ((new_y_dist / new_x_dist) * i)), (size_t)new_x_source_0 + i); //calculating line without degrees
            }
        }
        else if (new_x_dist > 0.0f)
        {
            for (int i = 0; i <= (int)new_x_dist; i++)
            {
                m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)(new_y_source_0 + ((new_y_dist / new_x_dist) * i)), (size_t)new_x_source_0 + i); //calculating line without degrees
            }
        }
        else
        {
            m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)new_y_source_0, (size_t)new_x_source_0); //single point (distance 0)
        }
    }
    else
    {
        if (new_y_dist < 0.0f)
        {
            for (int i = (int)new_y_dist; i <= 0; i++)
            {
                m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)new_y_source_0 + i, (size_t)(new_x_source_0 + ((new_x_dist / new_y_dist) * i))); //calculating line without degrees
            }
        }
        else if (new_y_dist > 0.0f)
        {
            for (int i = 0; i <= (int)new_y_dist; i++)
            {
                m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)new_y_source_0 + i, (size_t)(new_x_source_0 + ((new_x_dist / new_y_dist) * i))); //calculating line without degrees
            }
        }
        else
        {
            m_p_grid->set_symbol(SYMBOL_TEXTURE, (size_t)new_y_source_0, (size_t)new_x_source_0); //single point (distance 0)
        }
    }
}

void grid_object::list_ids()
{
    for (const auto& elem : m_coord_x)
    {
        cout << "ID: " << elem.first;
        cout << ", X: " << elem.second << endl;
    }

    cout << endl;

    for (const auto& elem : m_coord_y)
    {
        cout << "ID: " << elem.first;
        cout << ", Y: " << elem.second << endl;
    }
}

void grid_object::list_assigned_ids()
{
    for (const auto& elem : m_ids_assigned)
    {
        cout << "ID: " << elem.first;
        cout << ", Assigned IDs: ";

        for (size_t i = 0; i < elem.second.size(); i++)
        {
            cout << elem.second.at(i) << " ";
        }

        cout << endl;
    }
}

void grid_object::assign_coord(size_t id_first, size_t id_second)
{
    if (m_ids_assigned.count(id_first) > 0)
    {
        if (m_ids_assigned.find(id_first)->second.at(0) == 0)
        {
            m_ids_assigned.find(id_first)->second.at(0) = id_second;
        }
        else
        {
            m_ids_assigned.find(id_first)->second.push_back(id_second);
        }
    }
    else
    {
        cerr << "No coord with ID " << id_first << " was found!" << endl;
    }
}

grid_object::~grid_object()
{
}
