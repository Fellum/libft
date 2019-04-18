aux_source_directory("srcs" libft_C)
include_directories("includes")
add_library(libft ${libft_C} ${libft_H})