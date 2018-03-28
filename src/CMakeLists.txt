set(EMULATOR_SOURCES emulator.c emulator.h)
set(MAIN_SOURCES main.c)

add_subdirectory("logger")
add_library(emulator ${EMULATOR_SOURCES})
add_executable(main ${MAIN_SOURCES})

target_link_libraries(main emulator logger)

target_include_directories(emulator PUBLIC ${CMAKE_CURRENT_LIST_DIR})