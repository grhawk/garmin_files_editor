#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>

namespace logging {
    class Log
    {
    public:
        Log();
        void init();
        inline static std::shared_ptr<spdlog::logger>& getEngineLogger() { return s_engineLogger; };
        inline static std::shared_ptr<spdlog::logger>& getAppLogger() { return s_appLogger; };

    private:
        static std::shared_ptr<spdlog::logger> s_engineLogger;
        static std::shared_ptr<spdlog::logger> s_appLogger;
    };
}

#define _LOG_DEBUG(...) logging::Log::getEngineLogger()->debug(__VA_ARGS__)
#define _LOG_TRACE(...) logging::Log::getEngineLogger()->trace(__VA_ARGS__)
#define _LOG_INFO(...) logging::Log::getEngineLogger()->info(__VA_ARGS__)
#define _LOG_WARN(...) logging::Log::getEngineLogger()->warning(__VA_ARGS__)
#define _LOG_ERRROR(...) logging::Log::getEngineLogger()->error(__VA_ARGS__)
#define _LOG_CRITICAL(...) logging::Log::getEngineLogger()->critical(__VA_ARGS__)

#endif //LOG_H

#pragma clang diagnostic pop