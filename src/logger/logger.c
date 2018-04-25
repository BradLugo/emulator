#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "logger.h"

char *generate_log_message(const LOG_LEVEL log_level, const char *message, time_t now) {
    char str[BUFFER_SIZE];
    char timestr[64];
    char *out;

    switch (log_level) {
        case DEBUG_LOG_LEVEL:
            strftime(timestr, 64, "%c", localtime(&now));
            sprintf(str, "%s [%s]: %s", timestr, "DEBUG", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case INFO_LOG_LEVEL:
            strftime(timestr, 64, "%c", localtime(&now));
            sprintf(str, "%s [%s]: %s", timestr, "INFO", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case WARN_LOG_LEVEL:
            strftime(timestr, 64, "%c", localtime(&now));
            sprintf(str, "%s [%s]: %s", timestr, "WARN", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case ERROR_LOG_LEVEL:
            strftime(timestr, 64, "%c", localtime(&now));
            sprintf(str, "%s [%s]: %s", timestr, "ERROR", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
            break;
        case FATAL_LOG_LEVEL:
        default:
            strftime(timestr, 64, "%c", localtime(&now));
            sprintf(str, "%s [%s]: %s", timestr, "FATAL", message);
            out = (char *) malloc(strlen(str) + 1);
            strcpy(out, str);
    }

    return out;
}

void log_message(const LOG_LEVEL log_level, const char *message) {
    time_t now;
    time(&now);

    char *log_message = generate_log_message(log_level, message, now);
    puts(log_message);

    free(log_message);
}



