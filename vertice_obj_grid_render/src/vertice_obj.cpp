#include "vertice_obj.h"
#include <string>
#include "event_logger.h"

#define LOG_VERT_OBJ "Vertice Object"

vertice_obj::vertice_obj(std::fstream &new_log_file) : m_log_file(new_log_file)
{
    m_pos_x = 0.000000;
    m_pos_y = 0.000000;
    m_pos_z = 0.000000;
    m_axis_x = 0.000000;
    m_mtl_source = "_!NOINIT!_";
    m_mtl_group = "_!NOINIT!_";
    m_mtl_specific = "_!NOINIT!_";
    m_obj_ok = true;
    log_output(LOG_TYPE_INFO, "Object created");
}

void vertice_obj::set_obj_coord(double new_x, double new_y, double new_z)
{
    for (size_t i = 0; i < m_vertice_x.size(); i++)
    {
        m_vertice_x[i] += new_x - m_pos_x;
        m_vertice_y[i] += new_y - m_pos_y;
        m_vertice_z[i] += new_z - m_pos_z;
    }

    m_pos_x = new_x;
    m_pos_y = new_y;
    m_pos_z = new_z;
}

void vertice_obj::set_obj_coord_x(double new_x)
{
    m_pos_x = new_x;
}

void vertice_obj::set_obj_coord_y(double new_y)
{
    m_pos_y = new_y;
}

void vertice_obj::set_obj_coord_z(double new_z)
{
    m_pos_z = new_z;
}

void vertice_obj::set_obj_axis_x(double new_axis_x)
{
    m_axis_x = new_axis_x;
}

void vertice_obj::increment_obj_axis_x(double new_axis_x)
{
    if (m_axis_x + new_axis_x < 360.000000)
    {
        m_axis_x += new_axis_x;
    }
    else
    {
        m_axis_x = 0.000000 + new_axis_x;
    }
}

void vertice_obj::move_obj(double new_x, double new_y, double new_z)
{
    m_pos_x += new_x;
    m_pos_y += new_y;
    m_pos_z += new_z;

    for (size_t i = 0; i < m_vertice_x.size(); i++)
    {
        m_vertice_x[i] += new_x;
        m_vertice_y[i] += new_y;
        m_vertice_z[i] += new_z;
    }
}
//TODO: calculate maybe the vertices using diagonal distance, the angle (angle from x, y and z) and then calculate x, y, and z vertice distances from center later

void vertice_obj::add_vertice(double new_x, double new_y, double new_z)
{
    m_vertice_x.push_back(new_x);
    m_vertice_y.push_back(new_y);
    m_vertice_z.push_back(new_z);
    m_vertice_x_cache.push_back(new_x);
    m_vertice_y_cache.push_back(new_y);
    m_vertice_z_cache.push_back(new_z);
}

void vertice_obj::set_vertice(size_t new_vertice, double new_x, double new_y, double new_z)
{
    m_vertice_x[new_vertice] = new_x;
    m_vertice_y[new_vertice] = new_y;
    m_vertice_z[new_vertice] = new_z;
}

void vertice_obj::set_vertice_cache(size_t new_vertice, double new_x, double new_y, double new_z)
{
    m_vertice_x_cache[new_vertice] = new_x;
    m_vertice_y_cache[new_vertice] = new_y;
    m_vertice_z_cache[new_vertice] = new_z;
}

void vertice_obj::add_vertice_x(double new_x)
{
    m_vertice_x.push_back(new_x);
    m_vertice_x_cache.push_back(new_x);
}

void vertice_obj::add_vertice_y(double new_y)
{
    m_vertice_y.push_back(new_y);
    m_vertice_y_cache.push_back(new_y);
}

void vertice_obj::add_vertice_z(double new_z)
{
    m_vertice_z.push_back(new_z);
    m_vertice_z_cache.push_back(new_z);
}

void vertice_obj::set_face(std::vector<int> new_face)
{
    for (size_t i = 0; i < new_face.size(); i++)    //TODO: fix faces IDs to begin from 1 (1 means first face so 1 should be 0 in vector)
    {
        new_face.at(i) -= 1;
    }

    m_face.push_back(new_face);
}

void vertice_obj::set_mtl_source(std::string new_source)
{
    m_mtl_source = new_source;
}

void vertice_obj::set_mtl_group(std::string new_group)
{
    m_mtl_group = new_group;
}

void vertice_obj::set_mtl_specific(std::string new_specific)
{
    m_mtl_specific = new_specific;
}

void vertice_obj::set_obj_ok(bool new_status)
{
    m_obj_ok = new_status;
}

double vertice_obj::get_obj_coord_x()
{
    return m_pos_x;
}

double vertice_obj::get_obj_coord_y()
{
    return m_pos_y;
}

double vertice_obj::get_obj_coord_z()
{
    return m_pos_z;
}

double vertice_obj::get_obj_axis_x()
{
    return m_axis_x;
}

double vertice_obj::get_vertice_x(size_t vertice_x)
{
    return m_vertice_x.at(vertice_x);
}

double vertice_obj::get_vertice_y(size_t vertice_y)
{
    return m_vertice_y.at(vertice_y);
}

double vertice_obj::get_vertice_z(size_t vertice_z)
{
    return m_vertice_z.at(vertice_z);
}

double vertice_obj::get_vertice_x_cache(size_t vertice_x)
{
    return m_vertice_x_cache.at(vertice_x);
}

double vertice_obj::get_vertice_y_cache(size_t vertice_y)
{
    return m_vertice_y_cache.at(vertice_y);
}

double vertice_obj::get_vertice_z_cache(size_t vertice_z)
{
    return m_vertice_z_cache.at(vertice_z);
}

std::vector<int> vertice_obj::get_face(size_t face)
{
    return m_face.at(face);
}

std::string vertice_obj::get_mtl_source()
{
    return m_mtl_source;
}

std::string vertice_obj::get_mtl_group()
{
    return m_mtl_group;
}

std::string vertice_obj::get_mtl_specific()
{
    return m_mtl_specific;
}

bool vertice_obj::get_obj_ok() //info: if obj corrupt then do not render object but print to console object "name" error
{
    return m_obj_ok;
}

size_t vertice_obj::get_vertice_count()
{
    return m_vertice_x.size();
}

size_t vertice_obj::get_face_count()
{
    return m_face.size();
}

void vertice_obj::obj_prepare()
{
    std::string id_mapped_temp = "";

    for (size_t y = 0; y < m_face.size(); y++)
    {
        for (size_t x = 0; x < m_face.at(y).size(); x++)
        {
            if (x + 1 < m_face.at(y).size())
            {
                if (m_face.at(y).at(x) < m_face.at(y).at(x + 1))
                {
                    id_mapped_temp = std::to_string(m_face.at(y).at(x)) + " " + std::to_string(m_face.at(y).at(x + 1));

                    if (m_vert_mapped.count(id_mapped_temp) < 1)
                    {
                        m_vert_mapped[id_mapped_temp] = { m_face.at(y).at(x), m_face.at(y).at(x + 1) };
                    }
                }
                else
                {
                    id_mapped_temp = std::to_string(m_face.at(y).at(x + 1)) + " " + std::to_string(m_face.at(y).at(x));

                    if (m_vert_mapped.count(id_mapped_temp) < 1)
                    {
                        m_vert_mapped[id_mapped_temp] = { m_face.at(y).at(x + 1), m_face.at(y).at(x) };
                    }
                }
            }
            else if (x == m_face.at(y).size() - 1)   //connect last to first in one face
            {
                if (m_face.at(y).at(0) < m_face.at(y).at(x))
                {
                    id_mapped_temp = std::to_string(m_face.at(y).at(0)) + " " + std::to_string(m_face.at(y).at(x));

                    if (m_vert_mapped.count(id_mapped_temp) < 1)
                    {
                        m_vert_mapped[id_mapped_temp] = { m_face.at(y).at(0), m_face.at(y).at(x) };
                    }
                }
                else
                {
                    id_mapped_temp = std::to_string(m_face.at(y).at(x)) + " " + std::to_string(m_face.at(y).at(0));

                    if (m_vert_mapped.count(id_mapped_temp) < 1)
                    {
                        m_vert_mapped[id_mapped_temp] = { m_face.at(y).at(x), m_face.at(y).at(0) };
                    }
                }
            }
        }
    }

    for (const auto& elem : m_vert_mapped)
    {
        m_vert_connected.push_back(elem.first);  //remember which points to connect
    }
}

std::map<std::string, std::vector<int>> vertice_obj::get_mapped_verts()
{
    return m_vert_mapped;
}

std::vector<std::string> vertice_obj::get_known_vert_connections()
{
    return m_vert_connected;
}

std::vector<double> vertice_obj::get_vertices_x()
{
    return m_vertice_x;
}

std::vector<double> vertice_obj::get_vertices_y()
{
    return m_vertice_y;
}

std::vector<double> vertice_obj::get_vertices_z()
{
    return m_vertice_z;
}

void vertice_obj::log_output(std::string new_type, std::string new_message)
{
    if (m_log_file.is_open())
    {
        m_log_file << logEvent(LOG_VERT_OBJ, new_type, new_message);
    }
}