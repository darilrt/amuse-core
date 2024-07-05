#include <iostream>

#include <string>
#include <sstream>
#include <cstdint>
#include <vector>

template <typename T>
struct Formatter
{
    static std::string parse(T value)
    {
        std::string type_name = typeid(T).name();
        return "[Formatter not implemented for this type" + type_name + "]";
    }
};

template <>
struct Formatter<std::string>
{
    static std::string parse(std::string val)
    {
        return val;
    }
};

template <>
struct Formatter<char *>
{
    static std::string parse(char *val)
    {
        return val;
    }
};

template <>
struct Formatter<const char *>
{
    static std::string parse(const char *val)
    {
        return val;
    }
};

template <>
struct Formatter<int>
{
    static std::string parse(int val)
    {
        return std::to_string(val);
    }
};

template <>
struct Formatter<float>
{
    static std::string parse(float val)
    {
        return std::to_string(val);
    }
};

template <>
struct Formatter<double>
{
    static std::string parse(double val)
    {
        return std::to_string(val);
    }
};

template <>
struct Formatter<bool>
{
    static std::string parse(bool val)
    {
        return val ? "true" : "false";
    }
};

template <>
struct Formatter<char>
{
    static std::string parse(char val)
    {
        return std::string(1, val);
    }
};

template <>
struct Formatter<const char>
{
    static std::string parse(const char val)
    {
        return std::string(1, val);
    }
};

template <>
struct Formatter<std::string &>
{
    static std::string parse(std::string &val)
    {
        return val;
    }
};

template <>
struct Formatter<const std::string &>
{
    static std::string parse(const std::string &val)
    {
        return val;
    }
};

template <>
struct Formatter<const char *&>
{
    static std::string parse(const char *&val)
    {
        return val;
    }
};

template <>
struct Formatter<char *&>
{
    static std::string parse(char *&val)
    {
        return val;
    }
};

template <>
struct Formatter<int32_t &>
{
    static std::string parse(int32_t val)
    {
        return std::to_string(val);
    }
};

template <>
struct Formatter<uint32_t>
{
    static std::string parse(uint32_t val)
    {
        return std::to_string(val);
    }
};

template <>
struct Formatter<uint64_t>
{
    static std::string parse(uint64_t val)
    {
        return std::to_string(val);
    }
};

template <typename... Args>
std::string fmt(const std::string &fmt, Args... args)
{
    std::stringstream ss;

    std::vector<std::string> s_args = {
        (Formatter<Args>::parse(args))...};

    uint32_t arg = 0;
    for (uint32_t i = 0; i < fmt.size();)
    {
        const char c = fmt[i++];

        if (c == '{')
        {
            if (arg >= s_args.size())
            {
                throw std::runtime_error("Invalid argument count");
            }

            if (i >= fmt.size())
            {
                throw std::runtime_error("Invalid format string");
            }

            const char next = fmt[i++];

            if (next == '}')
            {
                ss << s_args[arg];
                arg++;
            }
        }
        else
        {
            ss << c;
        }
    }

    return ss.str();
}
