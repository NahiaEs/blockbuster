//
// Created by Giancarlos on 29/06/23.
//

#ifndef BLOCKBUSTER_MENU_H
#define BLOCKBUSTER_MENU_H

#include <iostream>

using namespace std;

int menu(){
    int opcion;
    do{
        cout << " -------MENU-------\n";
        cout << "1. Registrar película\n";
        cout << "2. Registrar usuario\n";
        cout << "3. Buscar Película\n";
        cout << "      3.1 Por nombre\n";
        cout << "      3.2 Por año de publicación\n";
        cout << "      3.3 Por ranking\n";
        cout << "4. Alquilar película\n";
        cout << "5. Devolver película\n";
        cout << "6. Reporte película\n";
        cout << "7. Salir\n";

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout<<endl;

    } while(opcion>7 || opcion<0);
    return opcion;
}

#endif //BLOCKBUSTER_MENU_H
