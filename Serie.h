//
// Created by josee on 11/06/2020.
//

#ifndef PROYECTO_SERIE_H
#define PROYECTO_SERIE_H

#include "Episodio.h"
#include "Video.h"

class Serie {
private:
    string id;
    string nombre;
    string genero;
    int temporadas;
    int calificacion;
public:
    Serie(string id, string nombre, string genero, int temporadas, vector <Episodio*> episodios);
    vector <Episodio*> episodios;
    void operator <<(int cero);
};

Serie :: Serie(string id, string nombre, string genero, int temporadas, vector <Episodio*> episodios) {
    this -> id = id;
    this -> nombre = nombre;
    this -> genero = genero;
    this -> temporadas = temporadas;
    for (int i = 0; i < episodios.size(); ++i) {
        if (episodios[i]->getID() == id) {
            this -> episodios = episodios;
        }
    }
    double prom = 0;
    for (int i = 0; i < episodios.size(); ++i) {
        prom += episodios[i]->getCalif();
    }
    calificacion = prom/episodios.size();
}
void Serie :: operator << (int cero) {
    cout << "----------------------------------------" << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Temporadas: " << temporadas << endl;
    cout << "Calificacion: " << calificacion << endl;
}

#endif //PROYECTO_SERIE_H
