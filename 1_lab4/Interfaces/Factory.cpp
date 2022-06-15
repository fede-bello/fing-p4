#include "Factory.h"

IcontroladorUsuario Factory::getIcontroladorUsuario(){
    return controladorUsuario.getInstance();
}

IcontroladorReserva getIcontroladorReserva(){
    return controladorReserva.getInstance();
}

IcontroladorHostal getIcontroladorHostal(){
    return controladorHostal.getInstance();

}
IcontroladorFecha getIcontroladorFecha(){
    return controladorFecha.getInstance();
}