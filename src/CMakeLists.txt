set(MAIN_SOURCES main.c)

add_subdirectory("emulator")
add_subdirectory("components")
add_subdirectory("logger")
add_executable(main ${MAIN_SOURCES})

target_link_libraries(main emulator logger components)