cmake_minimum_required(VERSION 3.8)

project(Snake)

aux_source_directory(. src)

add_executable(Snake ${src})