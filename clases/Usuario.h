#ifndef BLOCKBUSTER_USUARIO_H
#define BLOCKBUSTER_USUARIO_H

#include <iostream>
#include "vector"
#include "Pelicula.h"

using namespace std;

class Usuario{

    //declaracion de atributos
private:
    string dni;
    string nombre_usuario;
    string apellido_usuario;
    int peliculas_alquiladas = 0;

    vector<Usuario> listado_usuarios;
    vector<Pelicula> listado_peliculas;

public:
    //sobrecarga de constructores
    Usuario(){};
    Usuario(string dni, string nombre_usuario, string apellido_usuario){
        this -> dni = dni;
        this -> nombre_usuario = nombre_usuario;
        this -> apellido_usuario = apellido_usuario;
    };

    //Getters
    string getDNI(){
        return dni;
    }
    string getNombre(){
        return nombre_usuario;
    }
    string getApellido(){
        return apellido_usuario;
    }

    void registrarUsuario(Usuario u1){
        listado_usuarios.push_back(u1);
    }

    void getListadoUsuario(){
        for(int i=0; i<listado_usuarios.size();i++){
            cout<<listado_usuarios.at(i).getDNI()<<endl;
            cout<<listado_usuarios.at(i).getNombre()<<endl;
            cout<<listado_usuarios.at(i).getApellido()<<endl;
        }
    }

    void registrarPelicula(Pelicula p1){
        listado_peliculas.push_back(p1);
    }

    void getListadoPelicula(){
        for(int i=0; i<listado_peliculas.size();i++){
            cout<< listado_peliculas.at(i).getNombre_pelicula()<<endl;
            cout<< listado_peliculas.at(i).getRanking()<<endl;
            cout<< listado_peliculas.at(i).getAnio_publicacion()<<endl;
            cout<< listado_peliculas.at(i).getEjemplares_disponibles()<<endl;
        }
    }
};



#endif //BLOCKBUSTER_USUARIO_H
