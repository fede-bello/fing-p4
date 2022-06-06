#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

controladorUsuario::controladorUsuario (){
    //Aca creo que deberia ir algo, no se muy bien que
}; 

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}