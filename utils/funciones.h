
#ifndef FUNCIONES_HEADER
#define FUNCIONES_HEADER

#include <vector>
#include <iostream>
#include <fstream>
#include "../clases/EmpresaX.h"
#include "../clases/Usuario.h"
#include "../clases/Pelicula.h"

using namespace std;
void imprimir_empresa(string nombre_empresa, string direccion_empresa, string ruc_empresa){
    cout<<"-----DATOS DE LA EMPRESA-----"<<endl;
    cout<<"Nombre : "<< nombre_empresa <<endl;
    cout<<"Direccion : "<< direccion_empresa <<endl;
    cout<<"RUC : "<< ruc_empresa <<endl;
}

EmpresaX* registrar_empresa(){
    string nombre_empresa;
    string direccion_empresa;
    string ruc_empresa;

    cout<<"-----REGISTRAR EMPRESA-----"<<endl;
    cout<<"Nombre empresa : ";
    cin.ignore();
    getline(cin, nombre_empresa);

    cout<<"Direccion : ";
    cin.ignore();
    getline(cin, direccion_empresa);

    cout<<"RUC : ";
    cin.ignore();
    getline(cin, ruc_empresa);

    imprimir_empresa(nombre_empresa, direccion_empresa, ruc_empresa);

    return new EmpresaX(nombre_empresa, direccion_empresa, ruc_empresa);
}







// Hacer que las funciones sean amigas de empresaX;
// Implementar un mostrarDatos en peliculas;

Pelicula registrarPelicula();
Usuario registrarUsuario();
void BuscarNombre(EmpresaX const &x);
void BuscarAnio(EmpresaX const &x);
void BuscarRanking(EmpresaX const &x);
void BuscarPelicula(EmpresaX const &x);
void AlquilarPelicula(EmpresaX &x);
void DevolverPelicula(EmpresaX &x);
#endif