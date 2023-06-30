#ifndef FUNCIONES_AUXILIARES
#define FUNCIONES_AUXILIARES

#include "EmpresaX.h"
#include "../clases/Usuario.h"
#include "../clases/Pelicula.h"
#include <fstream>

void leerPelis(string nombre_archivo, vector <Pelicula> &lista_peliculas);
void limpiar();

#endif