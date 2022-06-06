#include"../include/DTEmpleado.h"

//Constructoras
DTEmpleado::DTEmpleado(){
    this->Nombre:='.';
    this->Password:='.';
    this->Mail:='.';
    this->Cargo=Limpieza;
    
}

DTEmpleado::DTEmpleado(string Nombre, string Password, string Mail, CargoEmp Cargo){
    this->Nombre:=Nombre;
    this->Password:=Password;
    this->Mail:=Mail;
    this->Cargo:=Cargo;
}

//Getters

CargoEmp getCargo(){
    return this->Cargo;
}

Hostal getHostal(){
    return this->hos;
}

//Destructora
Empleado:: ~Empleado(){

}