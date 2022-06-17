#include "../include/Factory.h"

Factory * Factory::instancia = NULL;

Factory::Factory(){}
Factory * Factory::getInstancia(){
    if(instancia == NULL){
        instancia = new Factory;
    }
    return instancia;
}

IcontroladorUsuario* Factory::getIcontroladorUsuario(){
    controladorUsuario* a_devolver = a_devolver->getInstance();
    IcontroladorUsuario * res = a_devolver;
    return res;
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
 IcontroladorFecha* Factory::getIcontroladorFecha(){
    controladorFecha* a_devolver = a_devolver->getInstance();
    IcontroladorFecha * res = a_devolver;
    return res;
}