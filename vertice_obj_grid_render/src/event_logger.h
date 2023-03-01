#ifndef __EVENT_LOGGER__
#define __EVENT_LOGGER__

#include <string>
#include <fstream>

#define LOG_TYPE_INFO "INFO"
#define LOG_TYPE_WARNING "WARN"
#define LOG_TYPE_ERROR "ERROR"
#define LOG_EV_SRC "default"

#ifndef EVENTAPI
#define EVENTAPI extern  //external (all functions using this are defined in obj_translator.cpp)
#endif

//name of log file
EVENTAPI std::string name_log(std::string name);
#define logName name_log
//event logger
EVENTAPI std::string event_log(std::string event_source, std::string event_type, std::string message);
#define logEvent event_log

#endif