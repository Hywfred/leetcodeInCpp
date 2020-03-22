cmake_minimum_required(VERSION 3.15)
project(leetcodeInCpp)

set(CMAKE_CXX_STANDARD 11)
aux_source_directory(./daily daily)
aux_source_directory(./tree/easy easy)
aux_source_directory(./test test)
add_executable(leetcodeInCpp main.cpp ${daily} ${easy} ${test} daily/MinimumIncrementToMakeArrayUnique.h HwInterview.h)