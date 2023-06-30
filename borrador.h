//
// Created by Nahia Escalante on 29/06/23.
//

#ifndef BLOCKBUSTER_BORRADOR_H
#define BLOCKBUSTER_BORRADOR_H

#endif //BLOCKBUSTER_BORRADOR_H
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
break;

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

case 3:

}
break;
}

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
while (opcion != 4); //7
