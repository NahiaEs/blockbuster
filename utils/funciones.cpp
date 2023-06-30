#include "funciones.h"

// MENU ------------------------------

// REGISTRAR PELICULA ------------------------
Pelicula RegistrarPelicula(){
    string nombre_pelicula;
    string anio_publicacion;
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


// REGISTRAR USUARIO ---------------------------------
Usuario RegistrarUsuario(){
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


// BUSCAR PELICULA






void BuscarPelicula(EmpresaX const &x) {
    int opcion;
    cout << "BUSCAR PELICULA por:" << endl;
    cout << "(1) Nombre"<< endl;
    cout << "(2) Anio" << endl;
    cout << "(3) Ranking" << endl;

    do {
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    } while (opcion > 3 || opcion < 0);

    switch (opcion)
    {
    case 1:
        BuscarNombre(x);
        break;
    
    case 2:
        BuscarAnio(x);
        break;
    case 3:
        BuscarRanking(x);
        break;
    default:
        break;
    }
    
}



// ALQUILAR PELICULA
void AlquilarPelicula(EmpresaX &x) {
    string dni;
    string nombre_pelicula;
    int cantidad_dias;
    int monto_final;

    cout << "Ingrese su DNI: ";
    cin >> dni;

    // Verificar si el usuario está registrado
    bool usuario_registrado = false;

    if (!usuario_registrado) {
        cout << "Usted no está registrado. Derivando al registro de usuario..." << endl;
        RegistrarUsuario();
    }

    cout << "Ingrese el nombre o ID de la película a alquilar: ";
    cin >> nombre_pelicula;

    // Buscar película
    Pelicula pelicula = BuscarPelicula(x, nombre_pelicula);

    if (pelicula.nombre.empty()) {
        cout << "La película no existe." << endl;
        return;
    }

    // Verificar disponibilidad
    if (pelicula.cantidad_ejemplares > 0) {
        cout << "Película disponible: " << pelicula.nombre << endl;

        cout << "Ingrese la cantidad de días de alquiler: ";
        cin >> cantidad_dias;

        // Calcular monto final según estrellas
        if (pelicula.ranking >= 3) {
            monto_final = cantidad_dias * 5.4;
        } else {
            monto_final = cantidad_dias * 4.3;
        }

        // Actualizar cantidad_ejemplares
        pelicula.cantidad_ejemplares -= 1;

        // Agregar película a lista de películas del usuario:
        for (int i = 0; i < x.usuarios.size(); i ++) {
            if (x.usuarios[i].getDni() == dni) {
                x.usuarios[i].peliculas.push_back(pelicula);
            }
        }

        cout << "Monto de alquiler: " << monto_final << endl;
        cout << "¡Alquiler realizado con éxito!" << endl;
    } else {
        cout << "La película no está disponible." << endl;
    }
}

// ------- sobrecarga de BUSCAR PELICULA ----------
Pelicula BuscarPelicula(EmpresaX x, string nombre) {
    for (int i = 0; i < x.listado_peliculas.size(); i++) {
        if (x.listado_peliculas[i].getNombre() == nombre) return x.listado_peliculas[i];
    }
    return Pelicula();
}

// ------------------------------------------------


// DEVOLVER PELICULA
void DevolverPelicula(EmpresaX &x) {

    string nombre_pelicula;
    int ranking_nuevo;

    cout << "Ingrese el nombre o ID de la película a devolver: ";
    cin >> nombre_pelicula;

    // Buscar la película en el listado
    Pelicula pelicula = BuscarPelicula(x, nombre_pelicula);

    if (pelicula.nombre.empty()) {
        cout << "La película no existe o no se ha solicitado un alquiler." << endl;
        return;
    }

    cout << "Ingrese el ranking nuevo de la película: ";
    cin >> ranking_nuevo;

    if(ranking_nuevo < 0 or ranking_nuevo > 5) {
        cout << "Ranking dado no se encuentra entre 1 y 5. "<<endl;
        cout << "Ingrese el ranking nuevo de la película: ";
        cin >> ranking_nuevo;
    }

    // Actualizar el ranking de la película
    pelicula.ranking = ranking_nuevo;

    char respuesta;
    cout << "¿Está de acuerdo con la devolución de la película? (S/N): ";
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's') {
        // Aumentar la cantidad disponible de la película en 1
        pelicula.cantidad_ejemplares += 1;
        cout << "Devolución exitosa." << endl;
    } else {
        cout << "No se realizó la devolución." << endl;
    }
}


// REPORTE PELICULA ES MOSTRAR DATOS:
