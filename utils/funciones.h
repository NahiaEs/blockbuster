
#ifndef FUNCIONES_HEADER
#define FUNCIONES_HEADER

#include <vector>
#include <iostream>
#include <fstream>
#include "../clases/EmpresaX.h"
#include "../clases/Usuario.h"
#include "../clases/Pelicula.h"

using namespace std;
void imprimir_empresa(string nombre_empresa, string direccion_empresa, string ruc_empresa)
{
    cout << "-----DATOS DE LA EMPRESA-----" << endl;
    cout << "Nombre : " << nombre_empresa << endl;
    cout << "Direccion : " << direccion_empresa << endl;
    cout << "RUC : " << ruc_empresa << endl;
}

EmpresaX *registrar_empresa()
{
    string nombre_empresa;
    string direccion_empresa;
    string ruc_empresa;

    cout << "-----REGISTRAR EMPRESA-----" << endl;
    cout << "Nombre empresa : ";
    cin.ignore();
    getline(cin, nombre_empresa);

    cout << "Direccion : ";
    cin.ignore();
    getline(cin, direccion_empresa);

    cout << "RUC : ";
    cin.ignore();
    getline(cin, ruc_empresa);

    imprimir_empresa(nombre_empresa, direccion_empresa, ruc_empresa);

    return new EmpresaX(nombre_empresa, direccion_empresa, ruc_empresa);
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
    cout << "Ingrese anio de publicacion a buscar: ";
    cin >> anio;

    for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x.getListadoTodasPeliculasEmpresa().at(i).getAnio_publicacion() == anio)
        {
            cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << endl;
            cout << x.getListadoTodasPeliculasEmpresa().at(i).getAnio_publicacion() << endl;
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

    switch (menor_igual)
    {
    case 1:
        for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
        {
            if (x.getListadoTodasPeliculasEmpresa().at(i).getRanking() >= ranking)
            {
                cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << endl;
                cout << x.getListadoTodasPeliculasEmpresa().at(i).getRanking();
            }
        }
        break;

    case 2:
        for (int i = 0; i < x.getListadoTodasPeliculasEmpresa().size(); i++)
        {
            if (x.getListadoTodasPeliculasEmpresa().at(i).getRanking() >= ranking)
                cout << x.getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() << endl;
            cout << x.getListadoTodasPeliculasEmpresa().at(i).getRanking();
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

    cout << "Ingrese el nombre de la película a alquilar: ";
    cin.ignore();
    getline(cin, nombre_pelicula);

    auto indicePelicula = 0;
    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (nombre_pelicula == x->getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula() &&
            x->getListadoTodasPeliculasEmpresa().at(i).getEjemplares_disponibles() > 0)
        { // Verifico disponibilidad
            cout << "Pelicula encontrada/disponible" << endl;
            indicePelicula = i;
        }
    }

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

    cout << x->lista_todas_peliculas_empresa[indicePelicula].getEjemplares_disponibles() << endl;
    // Agregar película a lista de películas del usuario:
    for (int k = 0; k < x->getListadoUsuarios().size(); k++)
    {
        if (x->getListadoUsuarios().at(k).getDNI() == dni)
        {
            x->listado_usuarios[k].registrarPelicula(p);
            // x->listado_usuarios[k].agregarPago(monto_final);
            //  x.listado_usuarios[k].imprimirListadoPelicula();
        }
    }

    cout << "Monto de alquiler: " << monto_final << endl;
    cout << "¡Alquiler realizado con éxito!" << endl;
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
    };
}
// nueva

void DevolverPelicula(EmpresaX *x)
{
    string nombre_pelicula;
    int ranking_nuevo;

    cout << "Ingrese el nombre o ID de la película a devolver: ";
    cin >> nombre_pelicula;

    // Buscar la película en el listado
    int indicePelicula = BuscarPelicula(x, nombre_pelicula);

    auto pelicula = x->getListadoTodasPeliculasEmpresa()[indicePelicula];
    //    Pelicula pelicula("a","a",2,2);

    if (pelicula.getNombre_pelicula().empty())
    {
        cout << "La película no existe o no se ha solicitado un alquiler." << endl;
        return;
    }
    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x->getListadoTodasPeliculasEmpresa().at(i).getNombre_pelicula().empty())
        {
            cout << "La película no existe o no se ha solicitado un alquiler." << endl;
            return;
        }
    }
    do
    {
        cout << "Ingrese el ranking nuevo de la película: ";
        cin.ignore();
        cin >> ranking_nuevo;
    } while (ranking_nuevo < 1 || ranking_nuevo > 5);

    //     validacion no optimizada
    if (ranking_nuevo < 0 or ranking_nuevo > 5)
    {
        cout << "Ranking dado no se encuentra entre 1 y 5. " << endl;
        cout << "Ingrese el ranking nuevo de la película: ";
        cin.ignore();
        cin >> ranking_nuevo;
    }
    //     Actualizar el ranking de la película
    for (int i = 0; i < x->getListadoTodasPeliculasEmpresa().size(); i++)
    {
        if (x->getListadoTodasPeliculasEmpresa().at(i).getRanking())
        {
            cout << "La película no existe o no se ha solicitado un alquiler." << endl;
            return;
        }
    }
    pelicula.setRanking(ranking_nuevo);

    char respuesta;
    cout << "¿Está de acuerdo con la devolución de la película? (S/N): ";
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's')
    {
        //         Aumentar la cantidad disponible de la película en 1
        pelicula.aumentoEjemplares();
        cout << "Devolución exitosa." << endl;
    }
    else
    {
        cout << "No se realizó la devolución." << endl;
    }
}

/*
void BuscarAnio(EmpresaX const &x);
void BuscarRanking(EmpresaX const &x);
void BuscarPelicula(EmpresaX const &x);
void AlquilarPelicula(EmpresaX &x);
void DevolverPelicula(EmpresaX &x);
*/
#endif