#include "../include/Hostal.h"

Hostal::Hostal(){
    this->Nombre='.';
    this->Direccion='.';
    this->Telefono=0;
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

void Hostal::setNombre(string nombre){
    this->Nombre = nombre;
}

void Hostal::setDireccion(string direccion){
    this->Direccion = direccion;
}

void Hostal::setTelefono(int telefono){
    this->Telefono = telefono;
}

void Hostal::agregarHabitacionAHostal(DTHabitacion dthab){
    Habitacion hab=Habitacion(dthab.getNumero(),dthab.getCapacidad(),dthab.getPrecio());
    this->MapaHabitaciones.insert(pair<int, Habitacion>(dthab.getNumero(), hab));

}

//Operaciones
DTHostal Hostal::getDTHostal(){
    DTHostal res = DTHostal(this->Nombre,this->Direccion,this->Telefono);
    return res;
}



//Destructora
Hostal::~Hostal(){
    for(auto &codigo:MapaHabitaciones){
        Habitacion hab = codigo.second;
        hab.~Habitacion();
    }
}
