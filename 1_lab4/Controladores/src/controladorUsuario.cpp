#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

controladorUsuario::controladorUsuario (){};

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}