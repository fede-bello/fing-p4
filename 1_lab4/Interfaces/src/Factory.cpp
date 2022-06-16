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
    controladorHostal* a_devolver = a_devolver->getInstance();
    IcontroladorHostal * res = a_devolver;
    return res;
}

controladorFecha* Factory::getIcontroladorFecha(){
    return controladorFecha::getInstance();
}