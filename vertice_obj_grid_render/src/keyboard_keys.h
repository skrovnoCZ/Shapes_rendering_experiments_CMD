#ifndef __KEYBOARD_KEYS__
#define __KEYBOARD_KEYS__

#include <Windows.h>
#include <string>

#define VK_L_E 0x45 //key E (missing in Windows.h)
#define VK_L_I 0x49 //key I (missing in Windows.h)

class keyboard_keys
{
private:
    bool m_key_up;      //variable to prevent holding keyboard key
    bool m_key_down;    //variable to prevent holding keyboard key
    bool m_key_left;    //variable to prevent holding keyboard key
    bool m_key_right;   //variable to prevent holding keyboard key
    bool m_key_e;       //variable to prevent holding keyboard key
    bool m_key_alt;     //variable to prevent holding keyboard key
    bool m_key_i;       //variable to prevent holding keyboard key
    bool m_key_control; //variable to prevent holding keyboard key
    bool m_key_escape;  //variable to prevent holding keyboard key
    int m_key;          //variable to prevent holding keyboard key
public:
    keyboard_keys();
    void keyboard_key_up();
    void keyboard_key_down();
    void keyboard_key_left();
    void keyboard_key_right();
    void keyboard_key_e();
    void keyboard_key_alt();
    void keyboard_key_i();
    void keyboard_key_ctrl();
    void keyboard_key_esc();
    void reset_keys();
    int get_key();
    ~keyboard_keys();
private:
    void log_output(std::string new_type, std::string new_message);
};

#endif