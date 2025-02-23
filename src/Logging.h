/*
Copyright (c) 2024 i-am-shodan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once
#include <stdint.h>

// Define the logging macro
#ifdef DUCKY_CUSTOM_LOG
    extern void DuckyInterpreterLog(uint8_t level, const char *format, ...);
    #define LOG(...) DuckyInterpreterLog(__VA_ARGS__)
#elif DUCKY_LOG_INTERNAL
    #define LOG(...) Log::Write(__VA_ARGS__)
#else
    #define LOG(...) ((void)0) // Define as void if LOGGING is not present
#endif

#if DUCKY_LOG_INTERNAL
    #include <cstdarg>
#endif

namespace Ducky
{
    class Log
    {
    public:
        enum LogLevel : uint8_t
        {
            LOG_DEBUG = 0,
            LOG_INFO = 1,
            LOG_WARNING = 2,
            LOG_ERROR = 3
        };

#if DUCKY_LOG_INTERNAL
        static void Write(LogLevel level, const char *format, ...)
        {
            if ((uint8_t)level >= (uint8_t)Log::LOG_WARNING)
            {
                va_list args;
                va_start(args, format);
                vprintf(format, args);
                va_end(args);
            }
        }
#endif
    };
}