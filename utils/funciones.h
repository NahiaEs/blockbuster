
#ifndef FUNCIONES_HEADER
#define FUNCIONES_HEADER

#include <vector>
#include <iostream>
#include <fstream>
#include "../clases/EmpresaX.h"
#include "../clases/Usuario.h"
#include "../clases/Pelicula.h"

void leerPelis(string nombre_archivo, EmpresaX &x) {

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
            x.lista_todas_peliculas_empresa.push_back(Pelicula(_titulo, _anio, cant_ejemplares, _ranking));
        }

    }

    // Cerrar el archivo
    archivo.close();
}

void clear() {
    char continuar;
    cout << "Presione C para continuar...";
    cin >> continuar;
    if (continuar == 'C') cout << "\033[2J\033[0;0H";
}

string aMinusculas (string texto) {
    string nuevo_texto = "";
    for (auto i:texto) {
        nuevo_texto += tolower(i);
    }
    return nuevo_texto;
}

void imprimir_empresa(string nombre_empresa, string direccion_empresa, string ruc_empresa)
{
    cout << "-----DATOS DE LA EMPRESA-----" << endl;
    cout << "Nombre : " << nombre_empresa << endl;
    cout << "Direccion : " << direccion_empresa << endl;
    cout << "RUC : " << ruc_empresa << endl;
}

EmpresaX registrar_empresa()
{
    string nombre_empresa;
    string direccion_empresa;
    string ruc_empresa;

    cout << "-----REGISTRAR EMPRESA-----" << endl;
    cout << "Nombre empresa : ";
    //cin.ignore();
    getline(cin, nombre_empresa);
    nombre_empresa = nombre_empresa;

    cout << "Direccion : ";
    //cin.ignore();
    getline(cin, direccion_empresa);

    cout << "RUC : ";
    //cin.ignore();
    getline(cin, ruc_empresa);

    imprimir_empresa(nombre_empresa, direccion_empresa, ruc_empresa);

    return EmpresaX(nombre_empresa, direccion_empresa, ruc_empresa);
}

// Hacer que las funciones sean amigas de empresaX;
// Implementar un mostrarDatos en peliculas;

Pelicula registrarPelicula();
Usuario registrarUsuario();

void BuscarNombre(EmpresaX x)
{
    string nombre;
    cout << "Ingrese nombre a buscar: ";
    cin.ignore();
    getline(cin, nombre);
    nombre = aMinusculas(nombre);

    // x.imprimirListaTodasPeliculasEmpresa();
    for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() == nombre)
        {
            cout << "La pelicula " << nombre << " se encuentra disponible" << endl;
            cout << "los ejemplares que qeudan son: " << x.getListadoTodasPeliculasEmpresa().at(i).getEjemplares_disponibles() << endl;
        }
    }
}

// cambios nuevos

void BuscarAnio(EmpresaX x)
{
    string anio;
    int menor_igual;
    cout << "Ingrese anio de publicacion a buscar: ";
    cin >> anio;
    cout << "(1) Mayor igual\n(2) Menor igual" << endl;
    cout << "Elija una opcion (1/2): ";
    cin >> menor_igual;


    switch (menor_igual)
    {
        case 1:
            cout << setw(7) << "ID";
            cout << setw(20) <<"TITULO";
            cout << setw(7) <<  "AÑO";
            cout << setw(5) << "RANK";
            cout << setw(5) << "DISP";
            cout << endl;
            for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
            {
                if (x.getListadoTodasPeliculasEmpresa().at(i).getAnio_publicacion() >= anio)
                {
                    x.getListadoTodasPeliculasEmpresa().at(i).imprimirDatos();
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << "\t";
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getRanking() << endl;
                }
            }
            break;

        case 2:
            cout << setw(7) << "ID";
            cout << setw(20) <<"TITULO";
            cout << setw(7) <<  "AÑO";
            cout << setw(5) << "RANK";
            cout << setw(5) << "DISP";
            cout << endl;
            for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
            {
                if (x.getListadoTodasPeliculasEmpresa().at(i).getAnio_publicacion() <= anio) {
                    x.getListadoTodasPeliculasEmpresa().at(i).imprimirDatos();
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << "\t";
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getRanking() << endl;
                }
            }
            break;

        default:
            cout << "Opcion no valida. Regresando al menu." << endl;
            break;
    }

    for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x.getListadoTodasPeliculasEmpresa().at(i).getAnio_publicacion() == anio)
        {
            x.getListadoTodasPeliculasEmpresa().at(i).imprimirDatos();
            //cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << endl;
            //cout << x.getListadoTodasPeliculasEmpresa().at(i).getAnio_publicacion() << endl;
        }
    }
}

void BuscarRanking(EmpresaX x)
{

    int ranking, menor_igual;

    cout << "Ingrese ranking a buscar: ";
    cin >> ranking;
    cout << "(1) Mayor igual\n(2) Menor igual" << endl;
    cout << "Elija una opcion (1/2): ";
    cin >> menor_igual;

    cout << setw(7) << "ID";
    cout << setw(20) <<"TITULO";
    cout << setw(7) <<  "AÑO";
    cout << setw(5) << "RANK";
    cout << setw(5) << "DISP";
    cout << endl;

    switch (menor_igual)
    {
        case 1:
            for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
            {
                if (x.getListadoTodasPeliculasEmpresa().at(i).getRanking() >= ranking)
                {
                    x.getListadoTodasPeliculasEmpresa().at(i).imprimirDatos();
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << "\t";
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getRanking() << endl;
                }
            }
            break;

        case 2:
            for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
            {
                if (x.getListadoTodasPeliculasEmpresa().at(i).getRanking() <= ranking) {
                    x.getListadoTodasPeliculasEmpresa().at(i).imprimirDatos();
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << "\t";
                    //cout << x.getListadoTodasPeliculasEmpresa().at(i).getRanking() << endl;
                }
            }
            break;

        default:
            cout << "Opcion no valida. Regresando al menu." << endl;
            break;
    }
}

void AlquilarPelicula(EmpresaX *x)
{
    string dni;
    string nombre_pelicula;
    int cantidad_dias;
    double monto_final;
    bool pelicula_encontrada = false;

    cout << "Ingrese su DNI: ";
    cin >> dni;

    // Verificar si el usuario está registrado
    bool usuario_registrado = false;
    // vector<Usuario>lista_usuarios_empresa = x.getListadoUsuarios();

    for (int j = 0; j < x->getListadoUsuarios().size(); j++)
    {
        if (dni == x->getListadoUsuarios().at(j).getDNI())
        {
            cout << "" << x->getListadoUsuarios().at(j).getDNI() << endl;
            usuario_registrado = true;
            cout << "Usuario encontrado" << endl;
        }
    }

    if (usuario_registrado == false)
    {
        cout << "Usted no está registrado. Derivando al registro de usuario..." << endl;
        registrarUsuario();
    }

    x->imprimirListaTodasPeliculasEmpresa();

    cout << "Ingrese el nombre de la película a alquilar: ";
    cin.ignore();
    getline(cin, nombre_pelicula);
    nombre_pelicula = aMinusculas(nombre_pelicula);
    cout<<"Nombre pelicula alquilada :"<<nombre_pelicula<<endl;

    auto indicePelicula = 0;
    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (nombre_pelicula == x->getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() &&
            x->getListadoTodasPeliculasEmpresa().at(i).getEjemplares_disponibles() > 0)
        { // Verifico disponibilidad
            cout << "Pelicula encontrada/disponible" << endl;
            indicePelicula = i;
            pelicula_encontrada = true;
        }
    }



    if (pelicula_encontrada) {
        Pelicula p(x->getListadoTodasPeliculasEmpresa().at(indicePelicula).getNombre_pelicula(), x->getListadoTodasPeliculasEmpresa().at(indicePelicula).getAnio_publicacion(), x->getListadoTodasPeliculasEmpresa().at(indicePelicula).getEjemplares_disponibles(), x->getListadoTodasPeliculasEmpresa().at(indicePelicula).getRanking());
        cout << "Película disponible: " << x->getListadoTodasPeliculasEmpresa().at(indicePelicula).getNombre_pelicula() << endl;
        cout << "Ingrese la cantidad de días de alquiler: ";
        cin >> cantidad_dias;

        // Calcular monto final según estrellas
        if (x->getListadoTodasPeliculasEmpresa().at(indicePelicula).getRanking() >= 3)
        {
            monto_final = cantidad_dias * 5.4;
        }
        else
        {
            monto_final = cantidad_dias * 4.3;
        }

        cout << x->lista_todas_peliculas_empresa[indicePelicula].getEjemplares_disponibles() << endl;
        // Actualizar cantidad_ejemplares
        x->lista_todas_peliculas_empresa[indicePelicula].disminucionEjemplares();
        //x->reducirEjemplaresDisponibles(nombre_pelicula);

        cout << x->lista_todas_peliculas_empresa[indicePelicula].getEjemplares_disponibles() << endl;
        // Agregar película a lista de películas del usuario:
        for (int k = 0; k < x->getListadoUsuarios().size(); k++)
        {
            if (x->getListadoUsuarios().at(k).getDNI() == dni)
            {
                x->listado_usuarios[k].registrarPelicula(p);
                x->listado_usuarios[k].agregarPago(monto_final);
                // x.listado_usuarios[k].imprimirListadoPelicula();
            }
        }

        cout << "Monto de alquiler: " << monto_final << endl;
        cout << "¡Alquiler realizado con éxito!" << endl;
        x->cant_peliculas_alquiladas++;
        x->ganancias_totales += monto_final;
    }
    else {
        cout << "Pelicula no encontrada!" << endl;
    }


}

int BuscarPelicula(EmpresaX *x, string nombre)
{
    int indicePelicula = 0;
    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x->getListadoTodasPeliculasEmpresa()[i].getNombre_pelicula() == nombre)
        {
            indicePelicula = i;
        }
    }
    return indicePelicula;
}

// Sobrecarga

int BuscarPelicula(EmpresaX *x, int _id)
{
    int indicePelicula = 0;
    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x->getListadoTodasPeliculasEmpresa()[i].getId() == _id)
        {
            indicePelicula = i;
        }
    }
    return indicePelicula;
}

int BuscarUsuario(EmpresaX *x, string _dni)
{
    int indiceUsuario = 0;
    for (int i = 0; i < x->getListadoUsuarios().size(); i++)
    {
        if (x->getListadoUsuarios()[i].getDNI() == _dni)
        {
            indiceUsuario = i;
        }
    }
    return indiceUsuario;
}


// nueva
void DevolverPelicula(EmpresaX *x) {
    int opcion, id, indicePelicula, indiceUsuario, nuevo_ranking;
    string nombre, dni;
    bool ha_alquilado, usuarioRegistrado = false;
    char  proceder_devolucion, solicitar_nuevo_ranking;
    double monto = 0;

    cout << "Ingrese su DNI: "; cin >> dni;

    for (int i = 0; i < x->getListadoUsuarios().size(); i++) {
        if (x->getListadoUsuarios()[i].getDNI() == dni) {
            cout << "Usuario encontrado. Se procede." << endl;
            usuarioRegistrado=true;
            indiceUsuario = i;
        }
    }

    if (!usuarioRegistrado)
    {
        cout << "¡Usuario no encontrado! Derivando al registro de usuario..." << endl;
        registrarUsuario();
    }

    do {
        cout << "¿Usar ID o nombre de la película?" << endl;
        cout << "(1) ID\n(2) Nombre" << endl;
        cout << "Elija una opción (1/2): ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 2);

    switch (opcion)
    {
        case 1:

            cout << "ID: ";
            cin >> id;

            indicePelicula = BuscarPelicula(x, id);

            // Verificar que el usuario haya alquilado dicha pelicula
            ha_alquilado = x->listado_usuarios[indiceUsuario].haAlquilado(x->lista_todas_peliculas_empresa[indicePelicula]);

            if (!ha_alquilado)
            {
                cout << "¡La película no ha sido alquilada por este usuario!" << endl;
                break;
            }


            // AGREGAR NUEVO RANKING
            cout << "¿Desea agregar un nuevo ranking? (S/N) : ";
            cin >> solicitar_nuevo_ranking;
            if (solicitar_nuevo_ranking == 'S') {
                cout << "Ingrese nuevo ranking: ";
                cin >> nuevo_ranking;
                x->lista_todas_peliculas_empresa[indicePelicula].setRanking(nuevo_ranking);
            }

            // PROCEDER CON DEVOLUCIÓN
            cout << "¿Desea proceder con la devolución? (S/N): ";
            cin >> proceder_devolucion;

            if (proceder_devolucion == 'S') break;
            // Aumenta los ejemplares en el vector de la CLASE

            x->lista_todas_peliculas_empresa[indicePelicula].aumentoEjemplares();

            // Elimina película alquilada del vector de películas del USUARIO
            //indiceUsuario = BuscarUsuario(x, dni);
            monto = x->getListadoUsuarios()[indiceUsuario].devolucionPelicula(nombre);

            // Aumenta pago a ganancias por películas devueltas.
            x->sumarGananciasPeliculasDevueltas(monto);




            break;
        case 2:

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);
            nombre = aMinusculas(nombre);

            indicePelicula = BuscarPelicula(x, nombre);

            // Verificar que el usuario haya alquilado dicha pelicula
            ha_alquilado = x->listado_usuarios[indiceUsuario].haAlquilado(x->lista_todas_peliculas_empresa[indicePelicula]);

            if (!ha_alquilado)
            {
                cout << "¡La película no ha sido alquilada por este usuario!" << endl;
                break;
            }

            // AGREGAR NUEVO RANKING
            cout << "¿Desea agregar un nuevo ranking? (S/N) : ";
            cin >> solicitar_nuevo_ranking;
            if (solicitar_nuevo_ranking == 'S') {
                cout << "Ingrese nuevo ranking: ";
                cin >> nuevo_ranking;
                x->lista_todas_peliculas_empresa[indicePelicula].setRanking(nuevo_ranking);
            }

            // PROCEDER CON DEVOLUCIÓN
            cout << "¿Desea proceder con la devolución? (S/N): ";
            cin >> proceder_devolucion;

            if (proceder_devolucion == 'N') break;

            // Aumenta los ejemplares en el vector de la CLASE

            x->lista_todas_peliculas_empresa[indicePelicula].aumentoEjemplares();

            // Elimina película alquilada del vector de películas del USUARIO
            //indiceUsuario = BuscarUsuario(x, dni);
            monto = x->getListadoUsuarios()[indiceUsuario].devolucionPelicula(nombre);

            // Aumenta pago a ganancias por películas devueltas.
            x->sumarGananciasPeliculasDevueltas(monto);
            break;

    }


}








//void DevolverPelicula(EmpresaX *x)
//{
//    string nombre_pelicula;
//    int ranking_nuevo;
//
//    cout << "Ingrese el nombre o ID de la película a devolver: ";
//    cin >> nombre_pelicula;
//
//    // Buscar la película en el listado
//    int indicePelicula = BuscarPelicula(x, nombre_pelicula);
//
//    auto pelicula = x->getListadoTodasPeliculasEmpresa()[indicePelicula];
//    //    Pelicula pelicula("a","a",2,2);
//
//    if (pelicula.getNombre_pelicula().empty())
//    {
//        cout << "La película no existe o no se ha solicitado un alquiler." << endl;
//        return;
//    }
//    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
//    {
//        if (x->getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula().empty())
//        {
//            cout << "La película no existe o no se ha solicitado un alquiler." << endl;
//            return;
//        }
//    }
//    do
//    {
//        cout << "Ingrese el ranking nuevo de la película: ";
//        cin >> ranking_nuevo;
//    } while (ranking_nuevo < 1 || ranking_nuevo > 5);
//
//    //     validacion no optimizada
//    if (ranking_nuevo < 0 or ranking_nuevo > 5)
//    {
//        cout << "Ranking dado no se encuentra entre 1 y 5. " << endl;
//        cout << "Ingrese el ranking nuevo de la película: ";
//        cin >> ranking_nuevo;
//    }
//    //     Actualizar el ranking de la película
//    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
//    {
//        if (x->getListadoTodasPeliculasEmpresa().at(i).getRanking())
//        {
//            cout << "La película no existe o no se ha solicitado un alquiler." << endl;
//            return;
//        }
//    }
//    pelicula.setRanking(ranking_nuevo);
//
//    char respuesta;
//    cout << "¿Está de acuerdo con la devolución de la película? (S/N): ";
//    cin >> respuesta;
//
//    if (respuesta == 'S' || respuesta == 's')
//    {
//        //Aumentar la cantidad disponible de la película en 1
//        pelicula.aumentoEjemplares();
//        cout << "Devolución exitosa." << endl;
//    }
//    else
//    {
//        cout << "No se realizó la devolución." << endl;
//    }
//}


/*
void BuscarAnio(EmpresaX const &x);
void BuscarRanking(EmpresaX const &x);
void BuscarPelicula(EmpresaX const &x);
void AlquilarPelicula(EmpresaX &x);
void DevolverPelicula(EmpresaX &x);
*/
#endif