//
// Created by Arthur Burke on 3/23/20.
//

#include "PLogger.h"

void PLogger::init() {
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(spdlog::level::warn);
    consoleSink->set_pattern("[Phyzz] [%^%l%$] %v");

    auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/PhyzzLogs.txt", true);
    fileSink->set_level(spdlog::level::trace);

    std::vector<spdlog::sink_ptr> sinks {consoleSink, fileSink};
    auto logger = std::make_shared<spdlog::logger>("PhyzzLog", sinks.begin(), sinks.end());
    PLogger::mInstance = logger;
}