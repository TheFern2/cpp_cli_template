#pragma once

#include <memory>
#include "spdlog/spdlog.h"

class Log {

public:
    static void Init(const std::string& app_name, bool only_console);
    static void SetPattern(const std::string& pattern);
    static void SetLevel(spdlog::level::level_enum level);
    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_logger; }

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};

// ordered by level of severity
#define LOG_TRACE(...)    ::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)    ::Log::GetLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)     ::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Log::GetLogger()->critical(__VA_ARGS__)