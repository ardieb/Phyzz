//
// Created by Arthur Burke on 3/23/20.
//

#ifndef PHYZZ_PLOGGER_H
#define PHYZZ_PLOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#define LOG_INFO(message)
    #ifndef NDEBUG
    PLogger::getInstance()->info(message)
    #else
    (void)0 // NOP
    #endif

#define LOG_DEBUG(message)
    #ifndef NDEBUG
    PLogger::getInstance()->debug(message)
    #else
    (void)0
    #endif

#define LOG_WARN(message)
    #ifndef NDEBUG
    PLogger::getInstance()->warn(message)
    #else
    (void)0
    #endif

#define LOG_ERROR(message)
    #ifndef NDEBUG
    PLogger::getInstance()->error(message)
    #else
    (void)0
    #endif

#define LOG_CRITICAL(message)
    #ifndef NDEBUG
    PLogger::getInstance()->critical(message)
    #else
    (void)0
    #endif

class PLogger {

    private:
        // ---- Internal Logger ---- //
        static std::shared_ptr<spdlog::logger> mInstance;

        // ---- Private Constructors ---- //
        PLogger() = default;

        PLogger(PLogger const&) = default;             // copy constructor is private

        PLogger& operator=(PLogger const&) = default;  // assignment operator is private

    public:

        static std::shared_ptr<spdlog::logger> getInstance() { return mInstance; }

        static void init();

};


#endif //PHYZZ_PLOGGER_H
