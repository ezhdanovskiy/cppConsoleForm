#ifndef CPPCONSOLEFORM_LOGGER_H
#define CPPCONSOLEFORM_LOGGER_H


#include <iostream>
#include <unistd.h>
#include <thread>

#define LOG_BEGIN std::cout
#define LOG_END "\t\t\t[" << __FILE__ << ":" << __LINE__ << "]" << std::endl;

#define LOG(chain) LOG_BEGIN << chain << LOG_END
#define LOG1(el) LOG_BEGIN << #el << "=" << (el) << LOG_END


#endif //CPPCONSOLEFORM_LOGGER_H
