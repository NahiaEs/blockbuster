#ifndef BLOCKBUSTER_PELICULA_H
#define BLOCKBUSTER_PELICULA_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Pelicula {

    //declaracion de atributos
private:
    string nombre_pelicula;
    string anio_publicacion;
    int ejemplares_disponibles;
    int ranking = 5;
    int ID;

public:
    //sobrecarga de constructores

    // Constructor vacio
    Pelicula();

    //Cuando el usuario no coloca el ranking, por defecto ranking=5
    Pelicula(string nombre_pelicula, string anio_publicacion, int ejemplares_disponibles){
        this -> nombre_pelicula = nombre_pelicula;
        this -> anio_publicacion= anio_publicacion;
        this -> ejemplares_disponibles = ejemplares_disponibles;
        this -> ID = rand()%1000 + 1000;
    };
    //Cuando coloca el ranking
    Pelicula(string _nombre_pelicula, string _anio_publicacion, int _ejemplares_disponibles, int _ranking){
        this -> nombre_pelicula = _nombre_pelicula;
        this -> anio_publicacion= _anio_publicacion;
        this -> ejemplares_disponibles = _ejemplares_disponibles;
        this -> ranking = _ranking;
        this -> ID = rand()%1000 + 1000;
    };

    //Metodo para generar ID aleatorio
    // void generarID(vector<int> idsGenerados) {
    //     int nuevoID;
    //     bool repetido;
    //     do {
    //         cout << "EN EJECUCION" << endl;
    //         nuevoID = rand()%1000 + 1000;  // Generar un ID aleatorio
    //         repetido = false;
    //         for (int id : idsGenerados) {
    //             if (id == nuevoID) {
    //                 repetido = true;
    //                 break;
    //             }
    //         }
    //     } while (repetido);  // Verifica si el ID ya existe en el vector
    //     this -> ID= nuevoID;

    // };

    //GETTERS
    string getNombre_pelicula(){
        return nombre_pelicula;
    }
    string getAnio_publicacion(){
        return anio_publicacion;
    }
    int getEjemplares_disponibles(){
        return ejemplares_disponibles;
    }
    int getRanking(){
        return ranking;
    }
    int getId() {
        return ID;
    }
    // SETTERS
    void disminucionEjemplares() {
        ejemplares_disponibles--;
    }

    void aumentoEjemplares() {
        ejemplares_disponibles++;
    }

    void setRanking(int _ranking) {
        this -> ranking = _ranking;
    }

    void imprimirDatos() {
        cout << setw(7) << this -> ID;
        cout << setw(20) << this -> nombre_pelicula;
        cout << setw(7) << this -> anio_publicacion;
        cout << setw(5) << this -> ranking;
        cout << setw(5) << this -> ejemplares_disponibles;
        cout << endl;
    }



};

#endif //BLOCKBUSTER_PELICULA_H