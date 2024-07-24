cmake_minimum_required(VERSION 3.15.0)
project(radicalp)

include_directories(include)
aux_source_directory(src SRC_DIR)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic-errors")

set(RADICALP_SRC ${SRC_DIR})

add_library(${PROJECT_NAME} ${RADICALP_SRC})

add_subdirectory(examples)


