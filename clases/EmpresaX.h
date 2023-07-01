#ifndef BLOCKBUSTER_EMPRESAX_H
#define BLOCKBUSTER_EMPRESAX_H
#include <iostream>
#include "Usuario.h"
#include "Pelicula.h"

using namespace std;

class EmpresaX {
private:
    string nombre;
    string direccion;
    string RUC;
    vector <Usuario>listado_usuarios;
    vector <Pelicula>lista_todas_peliculas_empresa;
    vector <int> ids_generados;
    // Ganancias por películas YA DEVUELTAS
    double ganancia_peliculas_devueltas=0;
    double ganancias_totales =0;

    // Cantidad de peliculas que han sido alquiladas
    int cant_peliculas_alquiladas=0;


public:
    //EmpresaX(){};

    EmpresaX(string nombre, string direccion, string RUC){
        this -> nombre = nombre;
        this -> direccion = direccion;
        this -> RUC = RUC;
    }

    void registrarUsuario_Empresa(Usuario u1){
        listado_usuarios.push_back(u1);
    }

    void imprimirListadoUsuario_Empresa(){
        for(int i=0; i<listado_usuarios.size();i++){
            cout<<listado_usuarios.at(i).getDNI()<<endl;
            cout<<listado_usuarios.at(i).getNombre()<<endl;
            cout<<listado_usuarios.at(i).getApellido()<<endl;
        }
    }

    vector<Usuario>getListadoUsuarios(){
        return listado_usuarios;
    }

    vector<Pelicula>getListadoTodasPeliculasEmpresa(){
//        for(int i=0; i<listado_usuarios.size();i++){
//            for(int j=0; j<listado_usuarios.at(i).getListadoPelicula().size();j++){
//                lista_todas_peliculas_empresa.push_back(listado_usuarios.at(i).getListadoPelicula().at(j));
//            }
//        }
        return lista_todas_peliculas_empresa;
    }

    vector <int> getIdsGenerados() {
        return ids_generados;
    }


    int getCantidadUsuarioEmpresa(){
        return listado_usuarios.size();
    }

    void imprimirListaTodasPeliculasEmpresa(){
        cout<<"Lista de peliculas"<<endl;
        for(int i=0; i<lista_todas_peliculas_empresa.size(); i++){
            cout<<"ID : "<<lista_todas_peliculas_empresa.at(i).getId()<<endl;
            cout<<"Nombre pelicula : "<<lista_todas_peliculas_empresa.at(i).getNombre_pelicula()<<endl;
            cout<<"Anio pelicula : "<<lista_todas_peliculas_empresa.at(i).getAnio_publicacion()<<endl;
            cout<<"Ejemplares disponibles : "<<lista_todas_peliculas_empresa.at(i).getEjemplares_disponibles()<<endl;
            cout<<endl;
        }
    }

    // funcion de prueba
    void imprimirVectorUsuarios() {
        cout << "LISTA USUARIOS: " << endl;
        for (int i = 0; i < listado_usuarios.size(); i++ ) {
            cout << endl;
            cout << listado_usuarios[i].getNombre() << " "<< listado_usuarios[i].getDNI() << endl;
        }
    }

    // agregado
    Pelicula BuscarPelicula(const string nombre) {
        for (int i = 0; i < lista_todas_peliculas_empresa.size(); i++) {
            if (lista_todas_peliculas_empresa[i].getNombre_pelicula() == nombre)
                return lista_todas_peliculas_empresa[i];
        }
        return Pelicula();
    }

    // funcion de alquilar de prueba
    void reducirEjemplaresDisponibles (string _nombre) {
        for (int i = 0; i < lista_todas_peliculas_empresa.size(); i ++) {
            if (lista_todas_peliculas_empresa[i].getNombre_pelicula() == _nombre) {
                lista_todas_peliculas_empresa[i].disminucionEjemplares();
            }
        }
    }

    void sumarGananciasPeliculasDevueltas(double _monto) {
        ganancia_peliculas_devueltas += _monto;
    }


    void mostrarDatos() {
        int cantidad_peliculas_disponibles = 0;

        cout << "----- REPORTE ------" << endl;
        cout << "CANTIDAD DE PELICULAS ALQUILADAS: " << cant_peliculas_alquiladas << endl;
//        cout << "CANTIDAD DE PELICULAS DISPONIBLES: " << lista_todas_peliculas_empresa.size() - cant_peliculas_alquiladas << endl;
        cout << "CANTIDAD DE PELICULAS DISPONIBLES: " ;
        for (int i = 0; i < lista_todas_peliculas_empresa.size(); i++) {
            cantidad_peliculas_disponibles += lista_todas_peliculas_empresa[i].getEjemplares_disponibles();
        }
        cout << cantidad_peliculas_disponibles << endl;
        cout << "GANANCIAS POR PELICULAS DEVUELTAS: " << ganancia_peliculas_devueltas<<endl;
        cout << "GANANCIAS POR PELICULAS ALQUILADAS:" << ganancias_totales - ganancia_peliculas_devueltas << endl;
        cout << "GANANCIAS TOTALES: " << ganancias_totales << endl;
    }

    friend Pelicula RegistrarPelicula(EmpresaX *empresa);
    friend void AlquilarPelicula(EmpresaX *empresa);
    friend void DevolverPelicula(EmpresaX *x);
    //friend Pelicula BuscarPelicula(EmpresaX x, string nombre);
   // friend AlquilarPelicula(EmpresaX *empresa);
};


#endif //BLOCKBUSTER_EMPRESAX_H
