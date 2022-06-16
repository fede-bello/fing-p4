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

IcontroladorHostal* Factory::getIcontroladorHostal(){
    IcontroladorHostal * res = res->getInstance();
    return res;
}

controladorFecha* Factory::getIcontroladorFecha(){
    return controladorFecha::getInstance();
}