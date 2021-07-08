#include <spdlog/sinks/stdout_color_sinks.h>
#include "Log.h"

namespace logging {

    std::shared_ptr<spdlog::logger> Log::s_appLogger;
    std::shared_ptr<spdlog::logger> Log::s_engineLogger;

    void Log::init()
    {
        Log::s_engineLogger = spdlog::stdout_color_mt("GARMIN_FILES_EDITOR ");
        Log::s_engineLogger->set_level(spdlog::level::trace);
        Log::s_engineLogger->set_pattern("[%H:%M:%S.%f](%^%l%$) %v");
    }

    Log::Log() {
        init();
    }

}