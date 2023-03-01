//use exact coordinates
//or use one coordinate and then distance from center and degree

#ifndef VERTICE_OBJ
#define VERTICE_OBJ

#include<vector>
#include <map>

class vertice_obj
{
private:
    double m_pos_x; //TODO: if vector map (different header) then before setting position, check if position input is in map range and if so then set position of object
    double m_pos_y;
    double m_pos_z;
    double m_axis_x;
    std::vector<double> m_vertice_x;    //object vertice x coords
    std::vector<double> m_vertice_y;    //object vertice y coords
    std::vector<double> m_vertice_z;    //object vertice z coords
    std::map<std::string, std::vector<int>>m_vert_mapped;
    std::vector<std::string> m_vert_connected;
    //maybe always calculate movement from begining
    std::vector<double> m_vertice_x_cache;    //object vertice x coords
    std::vector<double> m_vertice_y_cache;    //object vertice y coords
    std::vector<double> m_vertice_z_cache;    //object vertice z coords
    std::vector<std::vector<int>> m_face;   //object faces
    std::string m_mtl_source;
    std::string m_mtl_group;
    std::string m_mtl_specific;
    bool m_obj_ok;
    std::fstream &m_log_file;
public:
    vertice_obj(std::fstream &new_log_file);
    void set_obj_coord(double new_x, double new_y, double new_z);
    void set_obj_coord_x(double new_x);
    void set_obj_coord_y(double new_y);
    void set_obj_coord_z(double new_z);
    void set_obj_axis_x(double new_axis_x);
    void increment_obj_axis_x(double new_axis_x);
    void move_obj(double new_x, double new_y, double new_z);
    void add_vertice(double new_x, double new_y, double new_z);
    void set_vertice(size_t new_vertice, double new_x, double new_y, double new_z);
    void set_vertice_cache(size_t new_vertice, double new_x, double new_y, double new_z);
    void add_vertice_x(double new_x);
    void add_vertice_y(double new_y);
    void add_vertice_z(double new_z);
    void set_face(std::vector<int> new_face);
    void set_mtl_source(std::string new_source);
    void set_mtl_group(std::string new_groutp);
    void set_mtl_specific(std::string new_specific);
    void set_obj_ok(bool new_status);
    double get_obj_coord_x();
    double get_obj_coord_y();
    double get_obj_coord_z();
    double get_obj_axis_x();
    double get_vertice_x(size_t vertice_x);
    double get_vertice_y(size_t vertice_y);
    double get_vertice_z(size_t vertice_z);
    double get_vertice_x_cache(size_t vertice_x);
    double get_vertice_y_cache(size_t vertice_y);
    double get_vertice_z_cache(size_t vertice_z);
    std::vector<int> get_face(size_t face);
    std::string get_mtl_source();
    std::string get_mtl_group();
    std::string get_mtl_specific();
    bool get_obj_ok();
    size_t get_vertice_count();
    size_t get_face_count();

    void obj_prepare();
    std::map<std::string, std::vector<int>> get_mapped_verts();
    std::vector<std::string> get_known_vert_connections();
    std::vector<double> get_vertices_x();
    std::vector<double> get_vertices_y();
    std::vector<double> get_vertices_z();
private:
    void log_output(std::string new_type, std::string new_message);
};

#endif

//TODO: when moving object, vertices must move the same direction so new coordinates will be set
//      when rotating object, use vertices location from cache (non-cache is the default position)