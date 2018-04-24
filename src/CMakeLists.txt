set(EMULATOR_SOURCES emulator.c emulator.h components.c components.h)
set(MULTIPLEXER_SOURCES multiplexer.c multiplexer.h)
set(MAIN_SOURCES main.c)

add_subdirectory("logger")
add_library(emulator ${EMULATOR_SOURCES})
add_library(multiplexer ${MULTIPLEXER_SOURCES})
add_executable(main ${MAIN_SOURCES})

target_link_libraries(main emulator logger multiplexer)

target_include_directories(emulator PUBLIC ${CMAKE_CURRENT_LIST_DIR})