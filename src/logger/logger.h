#ifndef EMULATOR_LOGGER_H
#define EMULATOR_LOGGER_H

#include <time.h>

#define BUFFER_SIZE 4096

typedef enum {
    DEBUG_LOG_LEVEL,
    INFO_LOG_LEVEL,
    WARN_LOG_LEVEL,
    ERROR_LOG_LEVEL,
    FATAL_LOG_LEVEL
} LOG_LEVEL;

char *generate_log_message(LOG_LEVEL log_level, const char *message, time_t now);

void log_message(LOG_LEVEL log_level, const char *message);

#endif //EMULATOR_LOGGER_H
