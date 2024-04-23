cmake_minimum_required(VERSION 3.5)
project(logc)

option(LOG_USE_COLOR "Color Output" ON)

if(LOG_USE_COLOR)
    add_compile_definitions(LOG_USE_COLOR)    
endif()
    
add_library(${PROJECT_NAME} STATIC src/logc/log.c)
target_include_directories(${PROJECT_NAME} PUBLIC src)


add_executable(demo demo/demo.cpp)
target_link_libraries(demo PRIVATE ${PROJECT_NAME})

add_executable(democ demo/demo.c)
target_link_libraries(democ PRIVATE ${PROJECT_NAME})

add_executable(demo-2-threads demo/demo-2-threads.c)
target_link_libraries(demo-2-threads PRIVATE ${PROJECT_NAME})