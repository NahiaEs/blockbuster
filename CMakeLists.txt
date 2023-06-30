cmake_minimum_required(VERSION 3.24.2)
project(blockbuster)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockbuster main.cpp clases/Usuario.cpp clases/Usuario.h clases/Pelicula.cpp clases/Pelicula.h clases/EmpresaX.cpp clases/EmpresaX.h utils/menu.h borrador.h)
