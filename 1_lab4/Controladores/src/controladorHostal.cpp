#include"../include/controladorHostal.h"

ControladorHostal * ControladorHostal::instancia = NULL;

ControladorHostal * ControladorHostal::getInstance() {
    if (instancia == NULL)
        instancia = new ControladorHostal();
    return instancia;
}



ControladorHostal::ControladorHostal(){
} 

