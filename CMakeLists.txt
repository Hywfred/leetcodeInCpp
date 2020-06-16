cmake_minimum_required(VERSION 3.10)
project(leetcodeInCpp)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

# add header dir
include_directories(includes daily util)

# add sub dir
add_subdirectory(daily)
add_subdirectory(util)
add_subdirectory(mytest)

add_executable(main main.cpp)
