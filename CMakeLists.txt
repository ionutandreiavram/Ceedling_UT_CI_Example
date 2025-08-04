cmake_minimum_required(VERSION 3.13)
project(Silly_C)

# include_path
include_directories(include)

# find all sources (.c files)
file(GLOB SOURCES "src/*.c")

# make executable
add_executable(Silly_C ${SOURCES})
