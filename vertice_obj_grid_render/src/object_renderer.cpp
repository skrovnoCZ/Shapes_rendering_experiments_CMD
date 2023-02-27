#include "object_renderer.h"
#include <map>

using namespace std;

object_renderer::object_renderer(grid_screen* new_p_screen)
{
    m_p_screen = new_p_screen;
}

void object_renderer::render_object(vertice_obj &new_object)
{
    std::vector<double> vertice_x = new_object.get_vertices_x();
    std::vector<double> vertice_y = new_object.get_vertices_y();
    std::vector<double> vertice_z = new_object.get_vertices_z();
    std::map<std::string, std::vector<int>> vert_mapped_temp = new_object.get_mapped_verts();
    std::vector<std::string> vert_knowon_connection_temp = new_object.get_known_vert_connections();
    size_t i = 0;

    for (const auto& elem_i : vert_mapped_temp)
    {
        if (elem_i.second.size() > 1)   //if at least one connection with selected point
        {
            int debug = vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(0);
            float x_source_0 = vertice_x.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(0));
            float y_source_0 = vertice_y.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(0));
            //float z_source_0 = vertice_z.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(j))->second.at(0));

            float x_source_1 = vertice_x.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(1));
            float y_source_1 = vertice_y.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(1));
            //float z_source_1 = vertice_z.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(j))->second.at(1));

            float x_dist = x_source_1 - x_source_0;
            float y_dist = y_source_1 - y_source_0;

            calculate_line(x_source_0, y_source_0, x_dist, y_dist);
        }
        else if (elem_i.second.size() == 1)
        {
            m_p_screen->set_point( (size_t)vertice_x.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(0)),
                                   (size_t)vertice_y.at(vert_mapped_temp.find(vert_knowon_connection_temp.at(i))->second.at(0)),
                                   SYMBOL_DET); //single point (no connection)
        }

        i++;
    }
}

//line between vertices calculator
void object_renderer::calculate_line(float new_x_source_0, float new_y_source_0, float new_x_dist, float new_y_dist)
{
    
    if (abs(new_x_dist) > abs(new_y_dist))
    {
        if (new_x_dist < 0.0f)
        {
            for (int i = (int)new_x_dist; i <= 0; i++)
            {
                m_p_screen->set_point((size_t)new_x_source_0 + i, (size_t)(new_y_source_0 + ((new_y_dist / new_x_dist) * i)), SYMBOL_DET); //calculating line without degrees
            }
        }
        else if (new_x_dist > 0.0f)
        {
            for (int i = 0; i <= (int)new_x_dist; i++)
            {
                m_p_screen->set_point((size_t)new_x_source_0 + i, (size_t)(new_y_source_0 + ((new_y_dist / new_x_dist) * i)), SYMBOL_DET); //calculating line without degrees
            }
        }
        else
        {
            m_p_screen->set_point((size_t)new_x_source_0, (size_t)new_y_source_0, SYMBOL_DET); //single point (distance 0)
        }
    }
    else
    {
        if (new_y_dist < 0.0f)
        {
            for (int i = (int)new_y_dist; i <= 0; i++)
            {
                m_p_screen->set_point((size_t)(new_x_source_0 + ((new_x_dist / new_y_dist) * i)), (size_t)new_y_source_0 + i, SYMBOL_DET); //calculating line without degrees
            }
        }
        else if (new_y_dist > 0.0f)
        {
            for (int i = 0; i <= (int)new_y_dist; i++)
            {
                m_p_screen->set_point((size_t)(new_x_source_0 + ((new_x_dist / new_y_dist) * i)), (size_t)new_y_source_0 + i, SYMBOL_DET); //calculating line without degrees
            }
        }
        else
        {
            m_p_screen->set_point((size_t)new_x_source_0, (size_t)new_y_source_0, SYMBOL_DET); //single point (distance 0)
        }
    }
    
}

object_renderer::~object_renderer()
{
}
