set(COMPONENTS_SOURCES components.c components.h)

add_library(components ${COMPONENTS_SOURCES})

target_include_directories(components PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(components logger)