cmake_minimum_required(VERSION 3.15)
project(leetcodeInCpp)

set(CMAKE_CXX_STANDARD 11)
# add header files
include_directories(./daily)
# add source files
aux_source_directory(./daily daily)
aux_source_directory(./tree/easy easy)
aux_source_directory(./test test)
aux_source_directory(./hard hard)
add_executable(${PROJECT_NAME} main.cpp ${daily} ${easy} ${test} ${hard})