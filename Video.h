//
// Created by josee on 11/06/2020.
//

#ifndef PROYECTO_VIDEO_H
#define PROYECTO_VIDEO_H

class Video {
protected:
    string id;
    string nombre;
    string duracion;
    string genero;
    int calificacion;
public:
    Video();
    Video(string id, string nombre, string duracion, int calificacion);
    Video(string id, string nombre, string duracion, string genero, int calificacion);
    virtual string getGenero();
    virtual string getID();
    virtual void setGenero(string genero);
    virtual void setCalif(int calificacion);
    virtual int getCalif();
    virtual void operator <<(int cero) = 0;
};

Video :: Video() {
    id = "000000";
    nombre = "Nombre";
    duracion = "00:00";
    genero = "Genero";
    calificacion = 0;
}
Video :: Video(string id, string nombre, string duracion, string genero, int calificacion) {
    this -> id = id;
    this -> nombre = nombre;
    this -> duracion = duracion;
    this -> genero = genero;
    this -> calificacion = calificacion;
}
Video :: Video(string id, string nombre, string duracion, int calificacion) {
    this -> id = id;
    this -> nombre = nombre;
    this -> duracion = duracion;
    this -> calificacion = calificacion;
}
void Video :: setCalif(int calificacion) {
    if (calificacion <= 0 || calificacion >= 10) {
        this -> calificacion = calificacion;
    }
}
string Video :: getGenero() {
    return genero;
}
string Video :: getID() {
    return id;
}
void Video :: setGenero(string genero) {
    this -> genero = genero;
}
int Video :: getCalif() {
    return calificacion;
}

#endif //PROYECTO_VIDEO_H
