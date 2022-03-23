#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>
#include "Config.h"
#include "Log.h"

int main()
{    
    config::load_config("conf.json");

    Log::Init("APP", false);
    Log::SetPattern("[%D %H:%M:%S.%e] [%n] [%^%l%$] %v");
    Log::SetLevel(spdlog::level::debug);

    LOG_INFO("{} {} started", config::app_name, config::version);
    LOG_DEBUG("Debug log");
    LOG_TRACE("Trace log");
    LOG_WARN("Warn log");
    LOG_ERROR("Error log");
    LOG_CRITICAL("Critical log");

    return 0;
}

#if defined(_WIN32)
#include <windows.h>
int APIENTRY WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
  return main();
}
#endif