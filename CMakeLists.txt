# cmake_minimum_required(VERSION 2.8.9)
project(chicony-ir-toggle)

add_executable(${PROJECT_NAME} main.c)

install(TARGETS ${PROJECT_NAME})