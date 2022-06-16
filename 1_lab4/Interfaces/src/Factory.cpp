#include "../include/Factory.h"

Factory * Factory::instancia = NULL;

Factory::Factory(){}
Factory * Factory::getInstancia(){
    if(instancia == NULL){
        instancia = new Factory;
    }
    return instancia;
}

controladorUsuario* Factory::getIcontroladorUsuario(){
    return controladorUsuario::getInstance();
}

controladorReserva* Factory::getIcontroladorReserva(){
    return controladorReserva::getInstance();
}

controladorHostal* Factory::getIcontroladorHostal(){
    return controladorHostal::getInstance();
}

controladorFecha* Factory::getIcontroladorFecha(){
    return controladorFecha::getInstance();
}