#ifndef BLOCKBUSTER_PELICULA_H
#define BLOCKBUSTER_PELICULA_H

#include <iostream>
#include "vector"
using namespace std;

class Pelicula {

    //declaracion de atributos
private:
    string nombre_pelicula;
    int anio_publicacion;
    int ejemplares_disponibles;
    int ranking = 5;
    int ID;

public:
    //sobrecarga de constructores
    //Cuando el usuario no coloca el ranking, por defecto ranking=5
    Pelicula(string nombre_pelicula, int anio_publicacion, int ejemplares_disponibles){
        this -> nombre_pelicula = nombre_pelicula;
        this -> anio_publicacion= anio_publicacion;
        this -> ejemplares_disponibles = ejemplares_disponibles;
    };
    //Cuando coloca el ranking
    Pelicula(string nombre_pelicula, int anio_publicacion, int ejemplares_disponibles, int ranking){
        this -> nombre_pelicula = nombre_pelicula;
        this -> anio_publicacion= anio_publicacion;
        this -> ejemplares_disponibles = ejemplares_disponibles;
        this -> ranking = ranking;
    };

    //Metodo para generar ID aleatorio
    int generarID(vector<int> idsGenerados) {
        int nuevoID;
        bool repetido;
        do {
            nuevoID = rand();  // Generar un ID aleatorio
            repetido = false;
            for (int id : idsGenerados) {
                if (id == nuevoID) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);  // Verifica si el ID ya existe en el vector
        ID= nuevoID;
        return ID;
    };

    //GETTERS
    string getNombre_pelicula(){
        return nombre_pelicula;
    }
    int getAnio_publicacion(){
        return anio_publicacion;
    }
    int getEjemplares_disponibles(){
        return ejemplares_disponibles;
    }
    int getRanking(){
        return ranking;
    }

    // SETTERS
};

#endif //BLOCKBUSTER_PELICULA_H
