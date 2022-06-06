#include "../include/Hostal.h"

Hostal::Hostal(string nombre,string direccion,int telefono){
    this->direccion=direccion;
    this->nombre=nombre;
    this->telefono=telefono;
}

string Hostal::getNombre(){
    return this->nombre;
}
string Hostal::getDireccion(){
    return this->direccion;
}
int Hostal::getTelefono(){
    return this->telefono;
}
DTHostal Hostal::getDTHostal(){
    DTHostal res=DTHostal(this->nombre,this->direccion,this->telefono);
    return res;
}
Hostal::~Hostal(){
    delete this;
}