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


    vector<Pelicula>listado_peliculas;
    // PARA CALCULOS FINALES:
    vector <double> pagos;

public:
    //sobrecarga de constructores
    double devolucionPelicula(int _id) {
        double monto_pago=0;
        for (int i = 0; i < listado_peliculas.size(); i++) {
            if (listado_peliculas[i].getId() == _id) {
                monto_pago += pagos[i];
                // cout prueba
                listado_peliculas.erase(listado_peliculas.begin() + i);
                pagos.erase(pagos.begin() + i);
            }
        }
        return monto_pago;
    }
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


    int getCantidadListaPeliculas(){
        return listado_peliculas.size();
    }

    void registrarPelicula(Pelicula p1){
        listado_peliculas.push_back(p1);
    }

    void imprimirListadoPelicula(){
        for(int i=0; i<listado_peliculas.size();i++){
            cout<< listado_peliculas.at(i).getNombre_pelicula()<<endl;
            cout<< listado_peliculas.at(i).getRanking()<<endl;
            cout<< listado_peliculas.at(i).getAnio_publicacion()<<endl;
            cout<< listado_peliculas.at(i).getEjemplares_disponibles()<<endl;
        }
    }


    // Elimina la película de su lista y retorna el valor que pagó (para poder añadirlo a ganancias por películas devueltas)
    double devolucionPelicula(string nombre) {
        double monto_pago=0;

        for (int i = 0; i < listado_peliculas.size(); i++) {
            if (listado_peliculas[i].getNombre_pelicula() == nombre) {
                monto_pago += pagos[i];
                // cout prueba
                listado_peliculas.erase(listado_peliculas.begin() + i);
                pagos.erase(pagos.begin() + i);
            }
        }

        // cout prueba
        return monto_pago;
    }
    void agregarPago(double cantidad) {
        pagos.push_back(cantidad);
    }

    void imprimirPagos() {
        for (int i = 0; i < pagos.size(); i++) {
            cout << pagos[i] << " ";
        }
        cout << endl;
    }

    vector<Pelicula>getListadoPelicula(){
        return listado_peliculas;
    }
    vector <double> getPagos() {
        return this -> pagos;
    };

    bool haAlquilado(Pelicula p) {
        for (int i = 0; i < listado_peliculas.size(); i++) {
            if (listado_peliculas[i].getNombre_pelicula() == p.getNombre_pelicula())
            {
                return true;
            }
        }
        return false;
    }
};



#endif //BLOCKBUSTER_USUARIO_H