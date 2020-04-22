# source files
aux_source_directory(. SRCS)
# add shared library
add_library(daily SHARED ${SRCS})
