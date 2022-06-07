#include"../include/Empleado.h"

//Constructoras
Empleado::Empleado(){
    this->Nombre = '.';
    this->Passwor = '.';
    this->Mail = '.';
    this->Cargo = Limpieza;
    
}

Empleado::Empleado(string Nombre, string Password, string Mail, CargoEmp Cargo){
    this->Nombre = Nombre;
    this->Password = Password;
    this->Mail = Mail;
    this->Cargo = Cargo;
}

//Setters y getters

CargoEmp Empleado::getCargo(){
    return this->Cargo;
}

Hostal *Empleado::getHostal(){
    return this->hos;
}

void setCargo(CargoEmp Cargo){
    this->Cargo = Cargo;

}

Hostal setHostal(Hostal *hos){
    this->hos = hos;
}

//Operaciones 

bool empleadoAsignadoAHostal(){
    bool res = true;
    if (this->hos = NULL)
        res = false;
    return res;
}



//Destructora
Empleado:: ~Empleado(){

}