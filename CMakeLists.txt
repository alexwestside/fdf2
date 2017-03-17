cmake_minimum_required(VERSION 3.6)

project(fdf2)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES main.c fdf2.h)

add_executable(fdf2 ${SOURCE_FILES})

target_link_libraries(fdf2 ${CMAKE_SOURCE_DIR}/libft/libft.a)