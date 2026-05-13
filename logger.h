#pragma once

#include <stdio.h>
#include <stdlib.h>

#define LOG_DEBUG(msg, ...) \
    fprintf(stderr, "\e[1;32m[DEBUG] [%s:%d] \e[0;32m" msg "\e[0;37m\n", \
    __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_INFO(msg, ...) \
    fprintf(stderr, "\e[1;34m[INFO] [%s:%d] \e[0;34m" msg "\e[0;37m\n", \
    __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_WARNING(msg, ...) \
    fprintf(stderr, "\e[1;35m[WARNING] [%s:%d] \e[0;35m" msg "\e[0;37m\n", \
    __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_FATAL(msg, ...)                                    \
    do {                                                       \
        fprintf(stderr, "\e[1;31m[FATAL] [%s:%d] \e[0;31m" msg "\e[0;37m\n",           \
        __FILE__, __LINE__, ##__VA_ARGS__);                    \
        exit(EXIT_FAILURE);                                    \
    } while (0)
