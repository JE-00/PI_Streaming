//
// Created by josee on 11/06/2020.
//

#ifndef PROYECTO_EPISODIO_H
#define PROYECTO_EPISODIO_H

#include "Video.h"

class Episodio : public Video {
private:
    int temporada;
    string idE;
    string genero;
public:
    Episodio(string id, string idE, string titulo, string duracion, int calificacion, int temporada);
    void operator << (int cero);
    void setGenero(string genero);
};

Episodio :: Episodio(string id, string idE, string nombre, string duracion, int calificacion, int temporada) : Video(id, nombre, duracion, calificacion){
    this -> idE = idE;
    this -> temporada = temporada;
}
void Episodio :: operator<<(int cero) {
    cout << "----------------------------------------" << endl;
    cout << "ID: " << idE << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "Temporada: " << temporada << endl;
}
void Episodio :: setGenero(string genero) {
    this -> genero = genero;
}
#endif //PROYECTO_EPISODIO_H
