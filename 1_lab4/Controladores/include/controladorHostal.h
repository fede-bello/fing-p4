#ifndef CONTH
#define CONTH

#include"../../Clases/include/Hostal.h"
#include"controladorReserva.h"

class controladorHostal {
private:
    static controladorHostal * instancia;
    controladorHostal();
    map<string,Hostal> MapaHostal;
    DTHostal *HostalGuardado;
public:
    static controladorHostal * getInstance();
    void liberar();
    ~controladorHostal();
    DTHostal *getHostal();
    map<string,Hostal> getMapaHostal();
    //Alta Hostal
    DTHostal* NuevoHostal(string nombre,string direccion,int telefono);
    void confirmarAltaHostal(DTHostal *dthostal);
    void cancelarAltaHostal(DTHostal *dthostal);
    //FIN Alta Hostal
    //ALTA Habitacion
    vector<DTHostal> obtenerHostales();
    DTHostal *elegirHostal(string nombre);
    void confirmarAltaHabitacion(DTHabitacion *dthabitacion);
    void cancelarAltaHabitacion(DTHabitacion *dthabitacion);
};



#endif