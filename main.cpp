#include <iostream>
#include <vector>
#include "clases/Pelicula.h"
#include "clases/EmpresaX.h"
#include "utils/funciones.h"
#include "clases/Usuario.h"
#include "utils/menu.h"
using namespace std;




Usuario registrarUsuario(){
    string dni;
    string nombre_usuario;
    string apellido_usuario;

    cout<<"-----REGISTRAR USUARIO-----"<<endl;
    cout<<"DNI: ";
    cin>>dni;
    cout<<"Nombre: ";
    cin.ignore();
    getline(cin, nombre_usuario);
    cout<<"Apellido : ";
    cin.ignore();
    getline(cin, apellido_usuario);

    Usuario* usuario = new Usuario(dni, nombre_usuario, apellido_usuario);
    return *usuario;
}


Pelicula registrarPelicula(){
    string nombre_pelicula;
    int anio_publicacion;
    int ejemplares_disponibles;
    int ranking;
    int opcion;

    cout<<"-----REGISTRAR PELICULA-----"<<endl;
    cout<<"Nombre pelicula : ";
    cin.ignore();
    getline(cin, nombre_pelicula);

    cout<<"Anio : ";
    cin >> anio_publicacion;

    cout<<"Ejemplares : ";
    cin >> ejemplares_disponibles;

    do{
        cout<<"Agregar ranking 1- Si   2- No : ";
        cin >> opcion;
    }while(opcion<1 or opcion>2);

    if(opcion==1){
        do{
            cout << "Ranking : ";
            cin>>ranking;
        }while(ranking<0 || ranking >5);

        //hacer validacion
        Pelicula pelicula(nombre_pelicula, anio_publicacion, ejemplares_disponibles, ranking);
        return pelicula;

    }
    Pelicula pelicula(nombre_pelicula, anio_publicacion, ejemplares_disponibles);
    return pelicula;
}







int main() {
    EmpresaX *empresa1 = registrar_empresa();
    vector<int> listaids;
    vector<int> listausuarios;
    int opcionsubmenu;
    cout << endl;
    Usuario *usuario = new Usuario();
    int nro_peliculas_registradas;
    int opcion;
    int index;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                if (empresa1->getCantidadUsuarioEmpresa() != 0) {
                    cout << "Nro de peliculas por registrar : ";
                    cin >> nro_peliculas_registradas;

                    for (int j = 0; j < nro_peliculas_registradas; j++) {
                        Pelicula *p = new Pelicula(registrarPelicula());
                        cout << endl;
                        cout << "Imprimiendo pelicula registrada : " << endl;
                        cout << "Nombre de pelicula : " << p->getNombre_pelicula() << endl;
                        cout << "Ejemplares disponibles : " << p->getEjemplares_disponibles() << endl;
                        cout << "Anio de publicacion : " << p->getAnio_publicacion() << endl;
                        cout << "Ranking : " << p->getRanking() << endl;
                        usuario->registrarPelicula(*p);
                    }
                } else {
                    cout << "Por favor, registrar un usuario " << endl;
                }
                break;

            case 2:
                Usuario usuarioRegistrado = registrarUsuario();
                empresa1->registrarUsuario_Empresa(usuarioRegistrado);
                cout << "Imprimiendo usuario registrado : " << endl;
                empresa1->getListadoUsuario_Empresa();
                break;

            case 3:
                cout << "1. Por nombre" << endl;
                cout << "2. Por anio de publicacion" << endl;
                cout << "3. Por ranking" << endl;
                cin >> opcionsubmenu;

                switch (opcionsubmenu) {
                    case 1:
                        void BuscarNombre(EmpresaX const &x) {
                            string nombre;
                            cout << "Ingrese nombre a buscar: ";
                            getline(cin, nombre);

                            for (int i = 0; i < x.listado_peliculas.size(); i++) {
                                Pelicula pelicula = x.listado_peliculas[i];
                                if (pelicula.getNombre() == nombre) {
                                    pelicula.mostrarDatos();
                                }
                            }
                        }
                        break;
                    case 2:
                        void BuscarAnio(EmpresaX const &x) {
                            string anio;
                            cout << "Ingrese anio de publicacion a buscar: ";
                            cin >> anio;

                            for (int i = 0; i < x.listado_peliculas.size(); i++) {
                                Pelicula pelicula = x.listado_peliculas[i];
                                if (pelicula.getAnio_publicacion() == anio) {
                                    pelicula.mostrarDatos();
                                }
                            }
                        }
                        break;

                        //case 3:


                        //index = buscarPelicula(versiones);
                        //if (index != -1)
                        //   cout << versiones.at(index)<<" "<< anios.at(index)<<endl;
                        //(versiones, anios);
                        //break;

                        //case 4:
                        //alquilarPelicula();
                        // case 5:
                        //devolverPelicula();
                        // case 6:
                        // reportePelicula();


                }

        }
        while (opcion != 4); //7
        return 0;
    }
}