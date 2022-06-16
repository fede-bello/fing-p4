#include"../include/DTEmpleado.h"


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

void DTEmpleado::imprimir(){
    CargoEmp cargo=this->getCargo();
    string cargost;
    if (cargo==Limpieza) cargost="Limpieza";
    else if (cargo==Recepcion) cargost= "Recepcion";
    else if (cargo==Administracion) cargost="Administracion";
    else cargost="Infrasetructura";

    cout<<"Nombre: "<<this->getNombre()<<endl<<"Email: "<<this->getMail()<<endl<<cargost<<endl;
}


//Destructora
DTEmpleado:: ~DTEmpleado(){

}