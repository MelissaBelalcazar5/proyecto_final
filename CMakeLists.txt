cmake_minimum_required(VERSION 3.23)
project(proyecto_final)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(proyecto_final
        Entidad.cpp
        Entidad.h
        Jugador.cpp
        Jugador.h
        main.cpp)
