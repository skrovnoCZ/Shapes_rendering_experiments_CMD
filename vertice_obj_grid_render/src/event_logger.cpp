#include "event_logger.h"
#include <time.h>
#include <fstream>

#define LOG_LOG "log"

std::fstream file_log;

tm *local_time()
{
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    return ltm;
}

std::string time_log()
{
    std::string log_time = "";
    log_time = std::to_string(local_time()->tm_hour)
        + ":" + std::to_string(local_time()->tm_min)
        + ":" + std::to_string(local_time()->tm_sec);
    return log_time;
}

void open_log(std::string name)
{
    if (!file_log.is_open())
    {
    #ifdef __linux__ 
        system("mkdir logs");
    #elif _WIN32
        system("md logs");
    #else
    #endif

        std::string log_file_name = "";
        log_file_name = "logs/" + name + "_" + std::to_string(1900 + local_time()->tm_year)
            + "" + std::to_string(1 + local_time()->tm_mon)
            + "" + std::to_string(local_time()->tm_mday)
            + "" + std::to_string(local_time()->tm_hour)
            + "" + std::to_string(local_time()->tm_min)
            + "" + std::to_string(local_time()->tm_sec) + ".log";
        file_log.open(log_file_name, std::fstream::out);
    }
    else
    {
        event_log(LOG_LOG, LOG_TYPE_WARNING, "Attempting to open already opened log file");
    }
}

void close_log()
{
    if (file_log.is_open())
    {
        file_log.close();
    }
}

//event logger
void event_log(std::string event_source, std::string event_type, std::string message)
{
    if (file_log.is_open())
    {
        std::string log_message = "";
        log_message = "[" + time_log() + "]" + " "
            + "[" + event_source + "/" + event_type + "]"
            + ": " + message + "\n";
        file_log << log_message;
    }
}
