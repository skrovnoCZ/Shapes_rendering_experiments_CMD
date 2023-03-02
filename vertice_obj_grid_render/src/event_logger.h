#ifndef __EVENT_LOGGER__
#define __EVENT_LOGGER__

#include <string>

#define LOG_TYPE_INFO "INFO"
#define LOG_TYPE_WARNING "WARN"
#define LOG_TYPE_ERROR "ERROR"
#define LOG_EV_SRC "default"

#ifndef EVENTAPI
#define EVENTAPI extern  //external (all functions using this are defined in event_logger.cpp)
#endif

//open log file
EVENTAPI void open_log(std::string name);
#define logOpen open_log
//close log file
EVENTAPI void close_log();
#define logClose close_log
//event logger
EVENTAPI void event_log(std::string event_source, std::string event_type, std::string message);
#define logEvent event_log

#endif