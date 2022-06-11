#include"../include/Empleado.h"

//Constructoras
Empleado::Empleado(){
    this->Nombre = '.';
    this->Password = '.';
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

Hostal* Empleado::getHostal(){
    return this->hos;
}

Calificacion* Empleado::getCalificacion(){
    return this->calif;
}

void Empleado::setCargo(CargoEmp Cargo){
    this->Cargo = Cargo;

}

void Empleado::setHostal(Hostal *hos){
    this->hos = hos;
}

void Empleado::setCalificacion(Calificacion *calif){
    this->calif = calif;
}

//Operaciones 

bool Empleado::empleadoAsignadoAHostal(){
    bool res = true;
    if (this->hos == NULL)
        res = false;
    return res;
}

DTEmpleado Empleado::getDTEmpleado(){
    return DTEmpleado(this->Nombre, this->Password, this->Mail, this->Cargo);
}

bool Empleado::mismoMail(string email){
    return (this->Mail==email);
}

//Destructora
Empleado:: ~Empleado(){

}
