#include "Log.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"


std::shared_ptr<spdlog::logger> Log::s_logger;

void Log::Init(const std::string& app_name, bool only_console) {
    std::vector<spdlog::sink_ptr> log_sinks;
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    log_sinks.emplace_back(console_sink);

    if(!only_console)
    {
        auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                "./logs/log.txt",
                1024 * 1024 * 5,
                3);
        log_sinks.emplace_back(file_sink);
    }

    s_logger = std::make_shared<spdlog::logger>(app_name, begin(log_sinks), end(log_sinks));
    spdlog::register_logger(s_logger);
    spdlog::flush_every(std::chrono::seconds(3)); // can expose this
    s_logger->set_level(spdlog::level::trace);
}

void Log::SetPattern(const std::string& pattern) {
    s_logger->set_pattern(pattern);
}

void Log::SetLevel(spdlog::level::level_enum level) {
    s_logger->set_level(level);
}
