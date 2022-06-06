#include"../include/DTEmpleado.h"

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

//Setters y getters

CargoEmp getCargo(){
    return this->Cargo;
}

/*Hostal getHostal(){
    return this->hos;
} */



//Destructora
DTEmpleado:: ~DTEmpleado(){

}