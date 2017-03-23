cmake_minimum_required(VERSION 3.6)

project(fdf2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES main.c fdf2.h usage.c sub.c image.c update_coord.c hook.c)

add_executable(fdf2 ${SOURCE_FILES})

target_link_libraries(fdf2 ${CMAKE_SOURCE_DIR}/libft/libft.a)

#target_link_libraries(fdf2 ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

#include_directories(includes libft includes minilibx) # headers

#link_directories(/Users/alex/ClionProjects/fdf2/libft /Users/alex/ClionProjects/fdf2/minilibx_macos) # libraries

#set(SOURCE_FILES main.c fdf2.h image.c sub.c usage.c) # sources

#add_executable(fdf2 ${SOURCE_FILES}) # compilation

#target_link_libraries(fdf2 libft.a libmlx.a) # linkage