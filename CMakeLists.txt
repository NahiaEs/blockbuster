cmake_minimum_required(VERSION 3.25)
project(blockbuster)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockbuster main.cpp clases/Usuario.cpp clases/Usuario.h clases/Pelicula.cpp clases/Pelicula.h clases/Empresa.cpp clases/Empresa.h utils/menu.h)
