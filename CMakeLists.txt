# Basic Skeleton CMake file

## Common

cmake_minimum_required(VERSION 3.27)

set(PROJ skeleton)
project(${PROJ})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Requirements

### Use Boost

find_package(Boost 1.84 REQUIRED COMPONENTS chrono filesystem system)

#### Include directories for Boost
include_directories(${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

### Include Catch2 as a submodule
#add_subdirectory(external/Catch2 ${CMAKE_BINARY_DIR}/catch2_build)
add_subdirectory(external/Catch2)#// ${CMAKE_BINARY_DIR}/catch2_build)

## Use nlohmann/json 
add_subdirectory(external/json)

## Assuming your header files are located in the "include" directory
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

## Filter out system header files
foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(FILE_NAME ${HEADER_FILE} NAME)
    if(NOT "${FILE_NAME}" MATCHES "^(assert|windows|other_system_header).h$")
        list(APPEND FILTERED_HEADER_FILES ${HEADER_FILE})
    endif()
endforeach()

## Create a filter named "Header Files" in Visual Studio
source_group("Header Files" FILES ${FILTERED_HEADER_FILES})

source_group("include" FILE ${HEADER_FILES})

## Add your executable target and specify source files
add_executable(${PROJ} source/main.cpp)

## Link the nlohmann/json library to your executable target
target_link_libraries(${PROJ} PRIVATE nlohmann_json::nlohmann_json)

