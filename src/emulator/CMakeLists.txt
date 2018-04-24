set(EMULATOR_SOURCES emulator.c emulator.h)

add_library(emulator ${EMULATOR_SOURCES})

target_include_directories(emulator PUBLIC ${CMAKE_CURRENT_LIST_DIR})