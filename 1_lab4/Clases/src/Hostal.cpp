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

void Hostal::setHabitacion(Habitacion *hab){
    this->hab = hab; 
}

//Operaciones
DTHostal Hostal::getDTHostal(){
    DTHostal res = DTHostal(this->Nombre,this->Direccion,this->Telefono);
    return res;
}



//Asumo que es una coleccion de habitaciones
DTHabitacion Hostal::infHab(int cres){
    bool encontre = false;
    int i = 0;
    DTHabitacion res;
    while(!encontre){
        if(this->hab[i].getNum() == cres){
            res = DTHabitacion(this->hab[i].getNum(), this->hab[i].getCap(), this->hab[i].getPrecio());
            encontre = true;
        } else{
            i++;
        }
    }
    return res;
}




//Destructora
Hostal::~Hostal(){

}
