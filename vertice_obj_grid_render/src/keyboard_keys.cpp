#include "keyboard_keys.h"
#include "event_logger.h"
#define LOG_KBD "keyboard"



keyboard_keys::keyboard_keys()
{
    m_key_up = false;
    m_key_down = false;
    m_key_left = false;
    m_key_right = false;
    m_key_e = false;
    m_key_alt = false;
    m_key_i = false;
    m_key_control = false;
    m_key_escape = false;
    m_key = 0x00;
    log_output(LOG_TYPE_INFO, "Keyboard initialised");
}



void keyboard_keys::keyboard_key_up()
{
    if ((GetKeyState(VK_UP) < 0) && (!m_key_up))
    {
        m_key = VK_UP;
        m_key_up = true;
    }
    else if (GetKeyState(VK_UP) >= 0 && (m_key_up))
    {
        m_key = 0x00;
        m_key_up = false;
    }
}

void keyboard_keys::keyboard_key_down()
{
    if ((GetKeyState(VK_DOWN) < 0) && (!m_key_down))
    {
        m_key = VK_DOWN;
        m_key_down = true;
    }
    else if (GetKeyState(VK_DOWN) >= 0 && (m_key_down))
    {
        m_key = 0x00;
        m_key_down = false;
    }
}

void keyboard_keys::keyboard_key_left()
{
    if ((GetKeyState(VK_LEFT) < 0) && (!m_key_left))
    {
        m_key = VK_LEFT;
        m_key_left = true;
    }
    else if (GetKeyState(VK_LEFT) >= 0 && (m_key_left))
    {
        m_key = 0x00;
        m_key_left = false;
    }
}

void keyboard_keys::keyboard_key_right()
{
    if ((GetKeyState(VK_RIGHT) < 0) && (!m_key_right))
    {
        m_key = VK_RIGHT;
        m_key_right = true;
    }
    else if (GetKeyState(VK_RIGHT) >= 0 && (m_key_right))
    {
        m_key = 0x00;
        m_key_right = false;
    }
}

void keyboard_keys::keyboard_key_e()
{
    if ((GetKeyState(VK_L_E) < 0) && (!m_key_e))
    {
        m_key = VK_L_E;
        m_key_e = true;
    }
    else if (GetKeyState(VK_L_E) >= 0 && (m_key_e))
    {
        m_key = 0x00;
        m_key_e = false;
    }
}

void keyboard_keys::keyboard_key_alt()
{
    if ((GetKeyState(VK_MENU) < 0) && (!m_key_alt))
    {
        m_key = VK_MENU;
        m_key_alt = true;
    }
    else if (GetKeyState(VK_MENU) >= 0 && (m_key_alt))
    {
        m_key = 0x00;
        m_key_alt = false;
    }
}

void keyboard_keys::keyboard_key_i()
{
    if ((GetKeyState(VK_L_I) < 0) && (!m_key_i))
    {
        m_key = VK_L_I;
        m_key_i = true;
    }
    else if (GetKeyState(VK_L_I) >= 0 && (m_key_i))
    {
        m_key = 0x00;
        m_key_i = false;
    }
}

void keyboard_keys::keyboard_key_ctrl()
{
    if ((GetKeyState(VK_CONTROL) < 0) && (!m_key_control))
    {
        m_key = VK_CONTROL;
        m_key_control = true;
    }
    else if (GetKeyState(VK_CONTROL) >= 0 && (m_key_control))
    {
        m_key = 0x00;
        m_key_control = false;
    }
}

void keyboard_keys::keyboard_key_esc()
{
    if ((GetKeyState(VK_ESCAPE) < 0) && (!m_key_escape))
    {
        m_key = VK_ESCAPE;
        m_key_escape = true;
    }
    else if (GetKeyState(VK_ESCAPE) >= 0 && (m_key_escape))
    {
        m_key = 0x00;
        m_key_escape = false;
    }
}

void keyboard_keys::reset_keys()
{
    m_key = 0x00;
}

int keyboard_keys::get_key()
{
    return m_key;
}


keyboard_keys::~keyboard_keys()
{
}

void keyboard_keys::log_output(std::string new_type, std::string new_message)
{
    logEvent(LOG_KBD, new_type, new_message);
}