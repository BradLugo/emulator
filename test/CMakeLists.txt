add_executable(unit_tests tests.c)

target_link_libraries(unit_tests unity emulator logger components)
target_include_directories(unit_tests PUBLIC src unity)

add_test(tests unit_tests)