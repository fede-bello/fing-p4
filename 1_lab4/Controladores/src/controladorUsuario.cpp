#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

controladorUsuario::controladorUsuario (){
}; 

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}

controladorUsuario::~controladorUsuario(){
}

void controladorUsuario::liberar(){
    ArregloEmail.clear();
    this->PasswordGuardado="_";
    this->NombreGuardado="_";
    this->EsFingerGuardado=false;
}

vector<string> controladorUsuario ::getEmail(){
    return ArregloEmail;
}

string controladorUsuario:: getPassword(){
    return this->PasswordGuardado;
}

string controladorUsuario ::getNombre(){
    return this->NombreGuardado;
}

CargoEmp controladorUsuario ::getCargoEmp(){
    return this->CargoEmpGuardado;
}

bool controladorUsuario ::getEsFinger(){
    return this->EsFingerGuardado;
}

void controladorUsuario:: setEmail(string EmailGuardado){
    ArregloEmail.push_back(EmailGuardado);
}

void controladorUsuario:: setPassword(string PasswordGuardado){
    this->PasswordGuardado=PasswordGuardado;
}

void controladorUsuario:: setNombre(string NombreGuardado){
    this->NombreGuardado=NombreGuardado;
}

void controladorUsuario:: setCargoEmp(CargoEmp CargoEmpGuardado){
    this->CargoEmpGuardado=CargoEmpGuardado;
}

void controladorUsuario:: setEsFinger(bool EsFingerGuardado){
    this->EsFingerGuardado=EsFingerGuardado;
}