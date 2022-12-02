cmake_minimum_required(VERSION 3.23)
project(Aula_12_Lista_estatica C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Aula_12_Lista_estatica
        lista.c
        lista.h
        main.c)
