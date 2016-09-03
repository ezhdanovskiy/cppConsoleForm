#ifndef CPPCONSOLEFORM_LOGGER_H
#define CPPCONSOLEFORM_LOGGER_H


#include <iostream>
#include <unistd.h>
#include <thread>

#define LOG_BEGIN std::cout
#define LOG_END "\t\t\t[" << __FILE__ << ":" << __LINE__ << "]" << std::endl;

#define LOG(chain) LOG_BEGIN << chain << LOG_END
#define LOG1(el) LOG_BEGIN << #el << "=" << (el) << LOG_END

#define CONSOLE_COLOR_OFF "\033[0m"
#define CONSOLE_COLOR_BOLD "\033[1m"
#define CONSOLE_COLOR_RED "\033[1;31m"
#define CONSOLE_COLOR_GREEN "\033[0;32m"
#define CONSOLE_COLOR_YELLOW "\033[0;33m"
#define CONSOLE_COLOR_BLUE "\033[1;34m"
#define CONSOLE_COLOR_MAGENTA "\033[0;35m"
#define CONSOLE_COLOR_CYAN "\033[1;36m"
#define CONSOLE_COLOR_GREY "\033[1;30m"
#define CONSOLE_COLOR_WHITE "\033[37m"
// полу яркий цвет (тёмно-серый, независимо от цвета)
#define CONSOLE_COLOR_DBOLD "\033[2m"
// установить нормальную интенсивность
#define CONSOLE_COLOR_NBOLD "\033[22m"
// подчеркивание
#define CONSOLE_COLOR_UNDERLINE "\033[4m"
// отменить подчеркивание
#define CONSOLE_COLOR_NUNDERLINE "\033[4m"
// реверсия (знаки приобретают цвет фона, а фон -- цвет знаков)
#define CONSOLE_COLOR_INVERSE "\033[7m"
// отменить реверсию
#define CONSOLE_COLOR_NINVERSE "\033[7m"
// все атрибуты по умолчанию
#define CONSOLE_COLOR_BREAK "\033[m"
// все атрибуты по умолчанию
#define CONSOLE_COLOR_NORMAL "\033[0m"

#endif //CPPCONSOLEFORM_LOGGER_H
