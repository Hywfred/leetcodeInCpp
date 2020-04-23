# source files
aux_source_directory(. SRCS)

# add shared library
add_library(daily STATIC ${SRCS})

target_link_libraries(daily libutil)