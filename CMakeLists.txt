cmake_minimum_required(VERSION 3.5)
project(logc)

option(LOG_USE_COLOR "Color Output" ON)
option(LOG_BUILD_EXAMPLE "Color Output" ON)
option(LOG_SUBSECOND_NANO "Nanosecond" OFF)
option(LOG_SUBSECOND_MILLI "Millisecond" ON)
    
add_library(${PROJECT_NAME} STATIC src/logc/log.c)
target_include_directories(${PROJECT_NAME} PUBLIC src)

if(LOG_SUBSECOND_NANO)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SUBSECOND_NANO)
elseif(LOG_SUBSECOND_MILLI)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SUBSECOND_MILLI)
endif()

if(LOG_USE_COLOR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_USE_COLOR)    
endif()

if(LOG_BUILD_EXAMPLE)
    add_executable(demo demo/demo.cpp)
    target_link_libraries(demo PRIVATE ${PROJECT_NAME})

    add_executable(democ demo/demo.c)
    target_link_libraries(democ PRIVATE ${PROJECT_NAME})

    add_executable(demo-2-threads demo/demo-2-threads.c)
    target_link_libraries(demo-2-threads PRIVATE ${PROJECT_NAME})

    add_executable(file demo/file.c)
    target_link_libraries(file PRIVATE ${PROJECT_NAME})
endif()