#include <iostream>
#include <Windows.h>
#include "event_logger.h"
#include "object_renderer.h"
//#define MATH_FUNCT_REQUEST
#include "custom_functions.h"
#include "keyboard_keys.h"

#define LOG_MAIN "main"

using namespace std;

int main()
{
    logOpen("proccess");
    logEvent(LOG_MAIN, LOG_TYPE_INFO, "Inintialising program...");

    keyboard_keys keyboard;
    grid_screen* p_screen = new grid_screen(75, 75);
    object_renderer* p_renderer = new object_renderer(p_screen);
    map<string, vertice_obj*>m_vert_mapped;
    vector<string> object_names = { "square", "rectangle", "polygon", "shape" };

    //object angle speeds
    vector<double> object_angle = { 0.5, -15.0, 5.0, 2.0 };    //this will increment to rotation

    m_vert_mapped[object_names.at(0)] = new vertice_obj();
    m_vert_mapped[object_names.at(1)] = new vertice_obj();
    m_vert_mapped[object_names.at(2)] = new vertice_obj();
    m_vert_mapped[object_names.at(3)] = new vertice_obj();
    
    m_vert_mapped.find("square")->second->set_obj_coord(25.0, 25.0, 0.0);
    m_vert_mapped.find("square")->second->add_vertice(15.0, 15.0, 0.0);
    m_vert_mapped.find("square")->second->add_vertice(35.0, 15.0, 0.0);
    m_vert_mapped.find("square")->second->add_vertice(35.0, 35.0, 0.0);
    m_vert_mapped.find("square")->second->add_vertice(15.0, 35.0, 0.0);
    m_vert_mapped.find("square")->second->set_face({ 1, 2, 3, 4 });
    m_vert_mapped.find("square")->second->obj_prepare();

    m_vert_mapped.find("rectangle")->second->set_obj_coord(45.0, 45.0, 0.0);
    m_vert_mapped.find("rectangle")->second->add_vertice(40.0, 28.0, 0.0);
    m_vert_mapped.find("rectangle")->second->add_vertice(68.0, 28.0, 0.0);
    m_vert_mapped.find("rectangle")->second->add_vertice(68.0, 65.0, 0.0);
    m_vert_mapped.find("rectangle")->second->add_vertice(40.0, 65.0, 0.0);
    m_vert_mapped.find("rectangle")->second->set_face({ 1, 2, 3, 4 });
    m_vert_mapped.find("rectangle")->second->obj_prepare();

    m_vert_mapped.find("polygon")->second->set_obj_coord(37.0, 37.0, 0.0);
    m_vert_mapped.find("polygon")->second->add_vertice(30.0, 27.0, 0.0);
    m_vert_mapped.find("polygon")->second->add_vertice(44.0, 27.0, 0.0);
    m_vert_mapped.find("polygon")->second->add_vertice(50.0, 40.0, 0.0);
    m_vert_mapped.find("polygon")->second->add_vertice(37.0, 53.0, 0.0);
    m_vert_mapped.find("polygon")->second->add_vertice(24.0, 40.0, 0.0);
    m_vert_mapped.find("polygon")->second->set_face({ 1, 2, 3, 4, 5 });
    m_vert_mapped.find("polygon")->second->obj_prepare();

    m_vert_mapped.find("shape")->second->set_obj_coord(37.0, 37.0, 0.0);
    m_vert_mapped.find("shape")->second->add_vertice(3.0, 3.0, 0.0);
    m_vert_mapped.find("shape")->second->add_vertice(57.0, 17.0, 0.0);
    m_vert_mapped.find("shape")->second->add_vertice(57.0, 57.0, 0.0);
    m_vert_mapped.find("shape")->second->add_vertice(17.0, 57.0, 0.0);
    m_vert_mapped.find("shape")->second->set_face({ 1, 2, 3 });
    m_vert_mapped.find("shape")->second->set_face({ 4, 3, 1 });
    m_vert_mapped.find("shape")->second->set_face({ 2, 4 });
    m_vert_mapped.find("shape")->second->obj_prepare();

    for (size_t i = 0; i < object_names.size(); i++)
    {
        p_renderer->render_object(*m_vert_mapped.find(object_names.at(i))->second);
    }

    p_screen->print_grid();

    logEvent(LOG_MAIN, LOG_TYPE_INFO, "Loaded neccessary requirements");

    string start = "";
    getline(cin, start);

    logEvent(LOG_MAIN, LOG_TYPE_INFO, "Proccess continue after user input: " + start);

    //main loop
    while (!(GetKeyState(VK_ESCAPE) < 0))
    {
        keyboard.keyboard_key_up();
        keyboard.keyboard_key_down();
        keyboard.keyboard_key_left();
        keyboard.keyboard_key_right();

        switch (keyboard.get_key())
        {
        case VK_UP:
            p_screen->shift_y(1);
            break;
        case VK_DOWN:
            p_screen->shift_y(-1);
            break;
        case VK_LEFT:
            p_screen->shift_x(-1);
            break;
        case VK_RIGHT:
            p_screen->shift_x(1);
            break;
        default:
            break;
        }

        keyboard.reset_keys();

        if (real_timer(15625000.0))
        {
            p_screen->refresh_grid();

            double vertice_x = 0.0;
            double vertice_y = 0.0;

            for (size_t i = 0; i < object_names.size(); i++)
            {
                for (size_t j = 0; j < m_vert_mapped.find(object_names.at(i))->second->get_vertice_count(); j++)
                {
                    vertice_x = m_vert_mapped.find(object_names.at(i))->second->get_vertice_x(j);
                    vertice_y = m_vert_mapped.find(object_names.at(i))->second->get_vertice_y(j);
                    vertice_center_rotate(m_vert_mapped.find(object_names.at(i))->second->get_obj_coord_x(), m_vert_mapped.find(object_names.at(i))->second->get_obj_coord_y(), vertice_x, vertice_y, object_angle.at(i));

                    //TODO: find a better way to remember axis tilt (reason is because this needs to be inicialised evry time after vertice_center_rotate)
                    m_vert_mapped.find(object_names.at(i))->second->increment_obj_axis_x(object_angle.at(i));
                    m_vert_mapped.find(object_names.at(i))->second->set_vertice(j, vertice_x, vertice_y, 0.0);
                }

                p_renderer->render_object(*m_vert_mapped.find(object_names.at(i))->second);
            }

            p_screen->print_grid();
        }
    }

    logEvent(LOG_MAIN, LOG_TYPE_INFO, "Ending proccess...");

    size_t i = 0;

    for (const auto& elem_i : m_vert_mapped)
    {
        if (elem_i.second != nullptr)
        {
            delete elem_i.second;
            m_vert_mapped[object_names.at(i)] = nullptr;
        }

        i++;
    }

    delete p_renderer;
    p_renderer = nullptr;
    delete p_screen;
    p_screen = nullptr;
    logClose();

    return 0;
}

//TODO: solve square glitch when horizontal