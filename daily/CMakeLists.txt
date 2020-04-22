# source files
aux_source_directory(. SRCS)

include_directories(${CMAKE_SOURCE_DIR}/util)

# add shared library
add_library(daily SHARED ${SRCS})

target_include_directories(daily PUBLIC ${CMAKE_SOURCE_DIR}/util)

target_link_directories(daily PUBLIC libutil)
