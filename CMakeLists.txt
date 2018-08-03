#########
# CMAKE #
#########

cmake_minimum_required(VERSION 2.6.2)

project(gol)

## set compilation flags
set(CMAKE_C_FLAGS "-W -Wall -pedantic -std=c99 -std=gnu99 -g")

## set the target name and source
add_executable(
    gol
    src/main.c
    src/argument_manager.c
    src/gol_manager.c
)

