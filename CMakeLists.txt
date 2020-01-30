cmake_minimum_required(VERSION 3.15)
project(LonelyCells C)

set(CMAKE_C_STANDARD 99)

add_executable(LonelyCells LonelyCells.c map_read.c map_read.h map_save.c map_save.h map_build.c map_build.h map_print.c map_print.h cell_data_read.c cell_data_read.h cell_creat_list.c cell_creat_list.h cell_rand_name.c cell_rand_name.h cell_move.c cell_move.h cell_split.c cell_split.h cell_split_spawn.c cell_split_spawn.h cell_increase_energy.c cell_increase_energy.h cell_save.c cell_save.h)