#include"../include/DTEmpleado.h"
#include "DTUsuario.cpp"

//Constructoras
DTEmpleado::DTEmpleado():DTUsuario(){
        this->Cargo=Limpieza;
    
}

DTEmpleado::DTEmpleado(string Nombre, string Password, string Mail, CargoEmp Cargo):DTUsuario(Nombre, Password, Mail){
    this->Cargo=Cargo;
}

//Getters

CargoEmp DTEmpleado::getCargo(){
    return this->Cargo;
}

/*Hostal getHostal(){
    return this->hos;
} */

//Destructora
DTEmpleado:: ~DTEmpleado(){

}