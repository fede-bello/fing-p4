
#include "../include/DTHostal.h"


DTHostal::DTHostal(string nombre,string direccion,int telefono){
    this->direccion=direccion;
    this->nombre=nombre;
    this->telefono=telefono;
}

string DTHostal::getNombre(){
    return this->nombre;
}
string DTHostal::getDireccion(){
    return this->direccion;
}
int DTHostal::getTelefono(){
    return this->telefono;
}
DTHostal::~DTHostal(){
    delete this;
}