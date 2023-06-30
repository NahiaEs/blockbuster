# BlockBuster
Proyecto de Programación II

El proyecto consiste en elaborar un gestor pel ́ıculas para una empresa X. Se debe definir el nombre de la empresa, direcci ́on y RUC. Los datos b ́asicos de la empresa se deben solicitar por  ́unica vez al inicio del programa o se pueden definir por defecto.

## Clases
Pelicula
Usuario

## Funcionalidades principales
Menu
1. RegistrarPelicula
2. RegistrarUsuario
3. BuscarPelicula por
   Nombre
   Año
   Ranking
4. AlquilarPelicula
5. DevolverPelicula
6. Reporte
7. Salir

### Pelicula
**Atributos:**
- Nombre
- Año de publicacion
- Ejemplares disponibles
- Ranking (5 por defecto)
- ID (es unico y aleatorio)
  **Metodos:**
- serAlquilada(): reduce ejemplares disponibles
- setter y getters

### Usuario
**Atributos:**
- Nombre
- Apellido
- DNI
- Cantidad de peliculas alquiladas (0 por defecto)
  **Metodos**
- alquilarPelicula
- devolverPelicula
- setters y getters


### 1. RegistroPelicula
**Input:** nombre de pelicula, año de publicacion, ejemplares disponibles
Especificaciones: almacenar peliculas en un vector o arreglo dinámico

### 2. RegistroUsuario
**Input:** dni, nombre, apellido
Especificaciones: almacenar usuarios en un vector o arreglo dinamico

### 3. BusquedaPelicula
**Output:** submenu con:
(1) Nombre
(2) Año: busca peliculas con año mayor o igual o menor o igual, segun el usuario
(3) Ranking: busca peliculas con ranking mayor o igual o menor o igual, segun el usuario

### 4. AlquilerPelicula
**Input:** DNI
Si usuario no esta registrado, se procede con funcionalidad **2. RegistrarUsuario**
Si usuario esta registrado:
Mostrar lista enumerada de peliculas disponibles (ID, nombre, año, cantidad disponible, cantidad de ejemplares)
Usuario selecciona una pelicula segun su enumeracion + dias de alquiler
Si ( ranking >= 3 ) 5.40 soles
Si no, 4.30 soles
Mostrar mensaje
Disminuir cantidad de peliculas disponibles

### 5. DevolucionPelicula
**Input:** ID *o* nombre de pelicula a devolver, nuevo ranking, preguntar proceder con devolucion
Si se procede, mostrar mensaje de exito
Si no, se regresa al menu principal

### 6. ReportePeliculas
**Output:**
- Cantidad de peliculas alquiladas
- Cantidad de peliculas disponibles
- Ganancias por peliculas alquiladas
- Ganancias por peliculas devueltas
- Ganancias totales


## Funciones adicionales

LimpiarConsola()
LeerVector() ¿?







