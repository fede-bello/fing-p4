#include "Factory.h"

Factory * Factory::instancia = NULL;

Factory * Factory::getInstancia(){
    if(instancia == NULL){
        instancia = new Factory;
    }

    return instancia;
    
}

IcontroladorUsuario* Factory::getIcontroladorUsuario(){
    return controladorUsuario.getInstance();
}

IcontroladorReserva* getIcontroladorReserva(){
    return controladorReserva.getInstance();
}

IcontroladorHostal* getIcontroladorHostal(){
    return controladorHostal.getInstance();

}
IcontroladorFecha* getIcontroladorFecha(){
    return controladorFecha.getInstance();
}