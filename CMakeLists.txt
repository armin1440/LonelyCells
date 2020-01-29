cmake_minimum_required(VERSION 3.15)
project(LonelyCells C)

set(CMAKE_C_STANDARD 99)

add_executable(LonelyCells LonelyCells.c map_read.c map_read.h map_save.c map_save.h map_build.c map_build.h map_print.c map_print.h cell_data_read.c cell_data_read.h cell_creat_list.c cell_creat_list.h cell_rand_name.c cell_rand_name.h)