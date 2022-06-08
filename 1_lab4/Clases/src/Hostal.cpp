#include "../include/Hostal.h"

Hostal::Hostal(){
    this->nombre='.';
    this->nireccion='.';
    this->telefono=0;
}

Hostal::Hostal(string Nombre,string Direccion,int Telefono){
    this->Direccion=Direccion;
    this->Nombre=Nombre;
    this->Telefono=Telefono;
}

string Hostal::getNombre(){
    return this->Nombre;
}

string Hostal::getDireccion(){
    return this->Direccion;
}

int Hostal::getTelefono(){
    return this->Telefono;
}

DTHostal Hostal::getDTHostal(){
    DTHostal res=DTHostal(this->Nombre,this->Direccion,this->Telefono);
    return res;
}

Habitacion* Hostal::getHabitacion(){
    return this->hab;
}

void Hostal::setNombre(string nombre){
    this->Nombre = nombre;
}

void Hostal::setDireccion(string direccion){
    this->Direccion = direccion;
}

void Hostal::setTelefono(int telefono){
    this->Telefono = telefono;
}

void Hostal::setHabitacion(Habitacion *hab){
    this->hab = hab; 
}

Hostal::~Hostal(){

}
