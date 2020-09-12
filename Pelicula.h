//
// Created by josee on 11/06/2020.
//

#ifndef PROYECTO_PELICULA_H
#define PROYECTO_PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(string id, string titulo, string duracion, string genero, int calificacion);
    void operator <<(int cero);
};

Pelicula :: Pelicula(string id, string titulo, string duracion, string genero, int calificacion) : Video(id, titulo, duracion, genero, calificacion){
}
void Pelicula :: operator <<(int cero) {
    cout << "----------------------------------------" << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Genero: " << genero << endl;
    cout << "Calificacion: " << calificacion << endl;
}

#endif //PROYECTO_PELICULA_H
