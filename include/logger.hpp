//
// Description: Logger class for logging
//
// Usage:
// Logger logger("AMUSE");
// logger.info("Hello, World!");
// logger.warn("Hello, World!");
// logger.error("Hello, World!");
// logger.panic("Hello, World!");
//
// Output:
// [AMUSE][INFO] Hello, World!
// [AMUSE][WARN] Hello, World!
// [AMUSE][ERROR] Hello, World!
// [AMUSE][PANIC] Hello, World!
//
// Note: This is a simple logger class for logging
//
// If LOGGER_NO_INFO is defined, the info method will not be compiled
// #define LOGGER_NO_INFO
//

#pragma once

#include <string>
#include <iostream>

#include "format.hpp"
#include "dll.hpp"

class Logger
{
public:
    std::string name;

    AMUSE_API Logger();
    AMUSE_API Logger(const std::string &name);

#ifdef LOGGER_NO_INFO
    template <typename... Args>
    void info(const std::string &fmt, Args &&...args) {}
#else
    template <typename... Args>
    void info(const std::string &_fmt, Args &&...args)
    {
        std::cout << fmt("[{}][INFO] {}", name, fmt(_fmt, args...)) << std::endl;
    }
#endif

    template <typename... Args>
    void warn(const std::string &_fmt, Args &&...args)
    {
        std::cout << fmt("[{}][WARN] {}", name, fmt(_fmt, args...)) << std::endl;
    }

    template <typename... Args>
    void error(const std::string &_fmt, Args &&...args)
    {
        std::cerr << fmt("[{}][ERROR] {}", name, fmt(_fmt, args...)) << std::endl;
    }

    template <typename... Args>
    void panic(const std::string &_fmt, Args &&...args)
    {
        std::cerr << fmt("[{}][PANIC] {}", name, fmt(_fmt, args...)) << std::endl;
        std::exit(1);
    }
};

extern AMUSE_API Logger logger;