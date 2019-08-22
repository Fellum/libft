cmake_minimum_required(VERSION 3.14)
project(libft C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

aux_source_directory(src/string srcs)
aux_source_directory(src/list srcl)
aux_source_directory(src/io srci)
aux_source_directory(src/printf srcp)

add_library(libft ${srcs} ${srcl} ${srci} ${srcp})