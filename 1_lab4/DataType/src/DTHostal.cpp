
#include "../include/DTHostal.h"


DTHostal::DTHostal(){
    this->Nombre='.';
    this->Direccion='.';
    this->Telefono="0";
}

DTHostal::DTHostal(string Nombre,string Direccion,string Telefono){
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

string DTHostal::getTelefono(){
    return this->Telefono;
}
void DTHostal::imprimir(){
    cout<<"Nombre: "<<this->getNombre()<<endl<<"Dirección: "<<this->getDireccion()<<endl<<"Tel: "<<this->getTelefono()<<endl;
}


DTHostal::~DTHostal(){

}