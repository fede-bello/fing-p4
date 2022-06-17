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

IcontroladorReserva* Factory::getIcontroladorReserva(){
    controladorReserva* a_devolver = a_devolver->getInstance();
    IcontroladorReserva * res = a_devolver;
    return res;
}

IcontroladorHostal* Factory::getIcontroladorHostal(){
    controladorHostal* a_devolver = a_devolver->getInstance();
    IcontroladorHostal * res = a_devolver;
    return res;
}

controladorFecha* Factory::getIcontroladorFecha(){
    return controladorFecha::getInstance();
}