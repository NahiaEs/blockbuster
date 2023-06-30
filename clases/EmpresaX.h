#ifndef BLOCKBUSTER_EMPRESAX_H
#define BLOCKBUSTER_EMPRESAX_H
#include <iostream>
#include "Usuario.h"

using namespace std;

class EmpresaX {
private:
    string nombre;
    string direccion;
    string RUC;
    vector <Usuario>listado_usuarios;
public:
    EmpresaX(){};
    EmpresaX(string nombre, string direccion, string RUC){
        this -> nombre = nombre;
        this -> direccion = direccion;
        this -> RUC = RUC;
    }

    void registrarUsuario_Empresa(Usuario u1){
        listado_usuarios.push_back(u1);
    }

    void getListadoUsuario_Empresa(){
        for(int i=0; i<listado_usuarios.size();i++){
            cout<<listado_usuarios.at(i).getDNI()<<endl;
            cout<<listado_usuarios.at(i).getNombre()<<endl;
            cout<<listado_usuarios.at(i).getApellido()<<endl;
        }
    }

    int getCantidadUsuarioEmpresa(){
        return listado_usuarios.size();
    }
};


#endif //BLOCKBUSTER_EMPRESAX_H
