#include "auxiliares.h"

void leerPelis(string nombre_archivo, vector <Pelicula> &lista_peliculas) {

    // crear objeto fstream
    fstream archivo(nombre_archivo, ios::in);

    if (!archivo.is_open()) { // verificar que esté abierto
        cout << "Error al abrir el archivo." << endl;
    }

    else {

        string linea;

        while(getline(archivo, linea)) {

            cout << linea << endl;
            vector <int> indices; 

            // guardar los índices donde están las comas para usarlos con el método substr()
            for (int i = 0; i < linea.length(); i++) {
                if (linea[i]==',') {
                    indices.push_back(i);
                }
            }

            // Variables para inicializar un objeto pelicula
            string _titulo = linea.substr(0, indices[0]);
            string _anio = linea.substr(indices[0]+1, indices[1]-indices[0]-1);
            int cant_ejemplares = stoi(linea.substr(indices[1]+1, indices[2]-indices[1]-1));
            int _ranking = stoi(linea.substr(indices[2]+1, indices[3]-indices[2]-1));

            // Agregar las peliculas al vector
            lista_peliculas.push_back(Pelicula(_titulo, _anio, cant_ejemplares, _ranking));
        }

    }

    // Cerrar el archivo
    archivo.close();
}

void clear() {
    cout << "\033[2J\033[0;0H";
}