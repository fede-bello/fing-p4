#ifndef CONTH
#define CONTH

#include"../../Clases/include/Hostal.h"
#include"controladorReserva.h"

class controladorHostal {
private:
    static controladorHostal * instancia;
    controladorHostal();
    map<string,Hostal> MapaHostal;
    
public:
    static controladorHostal * getInstance();
    void operacion();
    ~controladorHostal();
    //Alta Hostal
    DTHostal* NuevoHostal(string nombre,string direccion,int telefono);
    void confirarAltaHostal(DTHostal *dthostal);
    void cancelarAltaHostal(DTHostal *dthostal);
    //Alta Hostal
    //falta hacer obtenerHostales();
    DTHostal elegirHostal(string nombre);
};



#endif