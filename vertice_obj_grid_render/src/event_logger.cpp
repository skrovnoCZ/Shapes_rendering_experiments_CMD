#include "event_logger.h"
#include <time.h>

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

std::string name_log(std::string name)
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
    return log_file_name;
}

//event logger
std::string event_log(std::string event_source, std::string event_type, std::string message)
{
    std::string log_message = "";
    log_message = "[" + time_log() + "]" + " "
        + "[" + event_source + "/" + event_type + "]"
        + ": " + message + "\n";
    return log_message;
}
