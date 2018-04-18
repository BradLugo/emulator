set(EMULATOR_SOURCES emulator.c emulator.h)
set(DEMULTIPLEXER_SOURCES demultiplexer.c demultiplexer.h)
set(MAIN_SOURCES main.c)

add_library(emulator ${EMULATOR_SOURCES})
add_library(demultiplexer ${DEMULTIPLEXER_SOURCES})
add_executable(main ${MAIN_SOURCES})

target_link_libraries(main emulator demultiplexer)

target_include_directories(emulator PUBLIC ${CMAKE_CURRENT_LIST_DIR})