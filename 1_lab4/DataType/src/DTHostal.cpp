
#include "../include/DTHostal.h"


DTHostal::DTHostal(){
    this->Nombre='.';
    this->Direccion='.';
    this->Telefono=0;
}
DTHostal::DTHostal(string Nombre,string Direccion,int Telefono){
    this->Nombre=Nombre;
    this->Direccion=Direccion;
    this->Telefono=Telefono;
}

string DTHostal::getNombre(){
    return this->Nombre;
}
string DTHostal::getDireccion(){
    return this->Direccion;
}
int DTHostal::getTelefono(){
    return this->Telefono;
}
DTHostal::~DTHostal(){

}