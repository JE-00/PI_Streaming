#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

class Serie;

/*
 * Diseñar un modelo de clases que de solución a la situación problema. Verificar que el modelo emplee los mecanismos
 * de Herencia y Polimorfismo.
 * Elaborar el Diagrama UML que represente el diseño de la solución.
 * Construir diseño de clases propuesto en el lenguaje de programación. Asegurar que el sistema de clases construido
 * funciona correctamente haciendo un programa de aplicación para ese fin.
 * Diseñar y elaborar una aplicación que emplee el sistema de clases construido para dar solución a la situación problema.
 * La aplicación debe mostrar el siguiente menu ciclado:
     * 1. Cargar archivos de datos (Peliculas, Series, Episodios)
     * 2. Mostrar los videos en general con un cierto rango de calificación de un cierto género
     * 3. Mostrar los videos en general de un cierto género
     * 4. Mostrar los episodios de una determinada serie con un rango de calificación determinada
     * 5. Mostrar las películas con cierto rango de calificación
     * 6. Calificar un video:
        * pedir titulo a calificar
        * pedir valor otorgado
     * 0. Salir
 * El sistema debe validar todas las entradas dadas por el usuario.
 * El trabajo debe ser desarrollado de manera individual a partir del momento de presentación de la situación problema
 * y hasta el momento de entregar el proyecto.
 */


int Menu() {
    int menu;
    cout << endl << "Menu" << endl;
    cout << "1. Cargar archivos de datos." << endl;
    cout << "2. Mostrar los videos en general con un cierto rango de calificacion de un cierto genero." << endl;
    cout << "3. Mostrar los videos en general de un cierto genero." << endl;
    cout << "4. Mostrar los episodios de una determinada serie con un rango de calificacion determinada." << endl;
    cout << "5. Mostrar las películas con cierto rango de calificacion." << endl;
    cout << "6. Calificar un video." << endl;
    cout << "0. Salir." << endl;
    cout << "Selecciona una opcion del menu" << endl;
    cin >> menu;
    return menu;
}
string leerArchivos(vector <Video*> &videos, vector <Serie*> &series, vector <Episodio*> &episodios, vector<Pelicula*> &peliculas) {
    string error = "";
    ifstream archPeliculas("C:\\Users\\josee\\CLionProjects\\Proyecto_Integrador\\ProyectoIntegrador-Peliculas.csv");
    ifstream archSeries("C:\\Users\\josee\\CLionProjects\\Proyecto_Integrador\\ProyectoIntegrador-Series.csv");
    ifstream archEpisodios("C:\\Users\\josee\\CLionProjects\\Proyecto_Integrador\\ProyectoIntegrador-Episodios.csv");
    string line, valor;
    char delim = ',';
    int calificacion;
    int col, temporadas, temporada;
    string id, idE, nombre, genero, duracion, idA;

    if (archPeliculas.is_open() && archPeliculas.good()) {
        getline(archPeliculas,line);
        while (getline(archPeliculas,line)) {
            stringstream ss(line);
            col = 0;
            while (getline(ss,valor,delim)) {
                switch (col) {
                    case 0:
                        id = valor;
                        break;
                    case 1:
                        nombre = valor;
                        break;
                    case 2:
                        duracion = valor;
                        break;
                    case 3:
                        genero = valor;
                        break;
                    case 4:
                        calificacion = stoi(valor);
                        break;
                } col++;
            } videos.push_back(new Pelicula(id, nombre, duracion, genero, calificacion));
            peliculas.push_back(new Pelicula(id, nombre, duracion, genero, calificacion));
        } archPeliculas.close();
    } else {
        error += "Error al leer el archivo de Peliculas\n";
    }

    if (archEpisodios.is_open() && archEpisodios.good()) {
        getline(archEpisodios,line);
        while (getline(archEpisodios,line)) {
            stringstream ss(line);
            col = 0;
            while (getline(ss, valor, delim)) {
                switch (col) {
                    case 0:
                        id = valor;
                        break;
                    case 1:
                        idE = valor;
                        break;
                    case 2:
                        nombre = valor;
                        break;
                    case 3:
                        duracion = valor;
                        break;
                    case 4:
                        calificacion = stoi(valor);
                        break;
                    case 5:
                        temporada = stoi(valor);
                        break;
                } col++;
            } videos.push_back(new Episodio(id, idE, nombre, duracion, calificacion, temporada));
            episodios.push_back(new Episodio(id, idE, nombre, duracion, calificacion, temporada));
        } archEpisodios.close();
    } else {
        error += "Error al leer el archivo de Episodios\n";
    }

    if (archSeries.is_open() && archSeries.good()) {
        getline(archSeries,line);
        while (getline(archSeries,line)) {
            stringstream ss(line);
            col = 0;
            while (getline(ss,valor,delim)) {
                switch (col) {
                    case 0:
                        id = valor;
                        break;
                    case 1:
                        nombre = valor;
                        break;
                    case 2:
                        genero = valor;
                        break;
                    case 3:
                        temporadas = stoi(valor);
                        break;
                } col++;
            }series.push_back(new Serie(id, nombre, genero, temporadas, episodios));
        } archSeries.close();
    } else {
        error += "Error al leer el archivo de Series\n";
    }

    return error;
}

int main() {
    vector<Video*> videos;
    vector<Pelicula*> peliculas;
    vector<Serie*> series;
    vector<Episodio*> episodios;
    int menu;
    int inf = 0, sup = 10;
    int opc, calificacion;
    string carga = "";
    bool error = true;

    menu = Menu();

    while (menu != 0) {
        while (menu < 0 || menu > 6) {
            menu = Menu();
        }

        switch (menu) {
            case 0:
                cout << "Adios";
                break;
            case 1:
                try {
                    //cout << leerArchivos(videos, series);
                    if (leerArchivos(videos, series, episodios, peliculas) == "") {
                        error = false;
                        cout << "Archivos cargados exitosamente" << endl;
                        menu = Menu();
                    } else {
                        throw invalid_argument("Error al cargar el archivo");
                    }
                } catch (invalid_argument& e) {
                    error = true;
                    menu = 0;
                    cout << e.what() <<endl;
                }
                break;
            case 2:
                if (!error) {
                    cout << "Rangos de calificación a buscar: " << endl;
                    cout << "Mínimo: " << endl;
                    cin >> inf;
                    cout << "Máximo: " << endl;
                    cin >> sup;
                    for (int i = 0; i < videos.size(); ++i) {
                        if (videos[i]->getCalif() >= inf && videos[i]->getCalif() <= sup) {
                            videos[i]->operator<<(0);
                        }
                    }
                    menu = Menu();
                } else {
                    cout << "No hay archivos disponible, asegurese de cargarlos primero";
                    menu = Menu();
                }
                break;
            case 3:
                if (!error) {
                    int gen;
                    string genero;
                    cout << "Menu de generos" << endl;
                    cout << "1. Drama" << endl;
                    cout << "2. Acción" << endl;
                    cout << "3. Msiterio" << endl;
                    cin >> gen;
                    if (gen == 1) {
                        genero = "Drama";
                    } else if(gen == 2) {
                        genero = "Accion";
                    } else if (gen == 3) {
                        genero = "Misterio";
                    }
                    for (int i = 0; i < videos.size(); ++i) {
                        if (videos[i]->getGenero() == genero) {
                            videos[i]->operator<<(0);
                        }
                    }
                    menu = Menu();
                } else {
                    cout << "No hay archivos disponible, asegurese de cargarlos primero";
                    menu = Menu();
                }
                break;
            case 4:
                if (!error) {
                    for (int i = 0; i < series.size(); ++i) {
                        cout << i << ". ";
                        series[i]->operator<<(0);
                    }
                    cout << "Elige una serie: " << endl;
                    cin >> opc;
                    cout << "Rangos de calificación a buscar: " << endl;
                    cout << "Mínimo: " << endl;
                    cin >> inf;
                    cout << "Máximo: " << endl;
                    cin >> sup;
                    for (int i = 0; i < series[opc]->episodios.size(); ++i) {
                        if (series[opc]->episodios[i]->getCalif() >= inf && series[opc]->episodios[i]->getCalif() <= sup) {
                            series[opc]->episodios[i]->operator<<(0);
                        }
                    }
                    menu = Menu();
                } else {
                    cout << "No hay archivos disponible, asegurese de cargarlos primero";
                    menu = Menu();
                }
                break;
            case 5:
                if (!error) {
                    cout << "Rangos de calificación a buscar: " << endl;
                    cout << "Mínimo: " << endl;
                    cin >> inf;
                    cout << "Máximo: " << endl;
                    cin >> sup;
                    for (int i = 0; i < peliculas.size(); ++i) {
                        if (peliculas[i]->getCalif() >= inf && peliculas[i]->getCalif() <= sup) {
                            peliculas[i]->operator<<(0);
                        }
                    }
                    menu = Menu();
                } else {
                    cout << "No hay archivos disponible, asegurese de cargarlos primero";
                    menu = Menu();
                }
                break;
            case 6:
                if (!error) {
                    for (int i = 0; i < videos.size(); ++i) {
                        cout << i << ". ";
                        videos[i]->operator<<(0);;
                    }
                    cout << "Digite el numero del video a calificar: " << endl;
                    cin >> opc;
                    cout << "Del 1 al 10 elige que calificación le darías al video" << endl;
                    cin >> calificacion;
                    videos[opc]->setCalif(calificacion);
                    menu = Menu();
                } else {
                    cout << "No hay archivos disponible, asegurese de cargarlos primero";
                    menu = Menu();
                }
                break;
            default:
                cout << "Introduzca un numero del menu" << endl;
                menu = Menu();
                break;
        }
    }
    return 0;
}
