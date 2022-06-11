#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

controladorUsuario::controladorUsuario (){
    this->ArregloEmail=new string[MAX_HUESPEDES];
    this->ArregloUsuario=new Usuario*[MAX_HUESPEDES]; 
    for(int i=0;i<MAX_HUESPEDES;i++){
        ArregloEmail[i]="_";
        ArregloUsuario[i]=NULL;
    }
}; 

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}

controladorUsuario::~controladorUsuario(){
    for(int i=0;i<indUsuario;i++)
        delete this->ArregloUsuario[i];
    delete[] ArregloEmail;
    delete[] ArregloUsuario;
}

string* controladorUsuario ::getEmail(){
    string *ArregloResultado=new string[MAX_HUESPEDES];
    int i=0;
    while(i<MAX_HUESPEDES && this->ArregloEmail[i]!="_"){
        ArregloResultado[i]=this->ArregloEmail[i];
        i++;
    }
    return ArregloResultado;
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
    this->EmailGuardado=EmailGuardado;
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