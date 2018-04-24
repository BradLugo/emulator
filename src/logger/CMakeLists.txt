set(LOGGER_SOURCES logger.c logger.h)

add_library(logger ${LOGGER_SOURCES})

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_LIST_DIR})