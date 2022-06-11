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
}

vector<string> controladorUsuario ::getEmail(){
    return ArregloEmail;
}


void controladorUsuario:: setEmail(string EmailGuardado){
    ArregloEmail.push_back(EmailGuardado);
}
