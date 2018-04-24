//
// Created by Christian Lugo on 3/17/18.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "logger.h"

char *generate_log_message(const LOG_LEVEL log_level, const char *message, time_t now, int buffer)
{
    char str[buffer];
    char *out;

    switch (log_level)
    {
        case DEBUG_LOG_LEVEL:
            sprintf(str, "%s [%s]: %s", ctime(&now), "DEBUG", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case INFO_LOG_LEVEL:
            sprintf(str, "%s [%s]: %s", ctime(&now), "INFO", message);
            int wat = strlen(str);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case WARN_LOG_LEVEL:
            sprintf(str, "%s [%s]: %s", ctime(&now), "WARN", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case ERROR_LOG_LEVEL:
            sprintf(str, "%s [%s]: %s", ctime(&now), "ERROR", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case FATAL_LOG_LEVEL:
        default:
            sprintf(str, "%s [%s]: %s", ctime(&now), "FATAL", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
    }

    return out;
}

void log_message(const LOG_LEVEL log_level, const char *message)
{
    time_t now;
    time(&now);

    char *log_message = generate_log_message(log_level, message, now, 1024);
    puts(log_message);

    free(log_message);
}



