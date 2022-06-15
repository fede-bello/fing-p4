#ifndef CONTH
#define CONTH

#include"../../Clases/include/Hostal.h"
#include"controladorReserva.h"

class controladorHostal {
private:
    static controladorHostal * instancia;
    controladorHostal();
    map<string,Hostal*> MapaHostal;
    DTHostal *HostalGuardado;
    string nombreGuardado;
    int numHabGuardado;
    DTFecha inGuardado, outGuardado;
public:
    static controladorHostal * getInstance();
    void liberar();
    ~controladorHostal();
    DTHostal *getHostal();
    string getNombre();
    map<string,Hostal*> getMapaHostal();
    //Alta de Usuario
    //Fin alta Usuario
    //Alta Hostal
    DTHostal* nuevoHostal(string nombre,string direccion,string telefono);
    void confirmarAltaHostal(DTHostal *dthostal);
    void cancelarAltaHostal(DTHostal *dthostal);
    //Fin Alta Hostal
    //Alta Habitacion
    vector<DTHostal> obtenerHostales();
    DTHostal *elegirHostal(string nombre);
    void confirmarAltaHabitacion(DTHabitacion *dthabitacion);
    void cancelarAltaHabitacion(DTHabitacion *dthabitacion);   
    //Fin Alta Habitacion
    //Asignar empleado a hostal
    //Realizar Reserva
    float obtenerPromedioCalificaciones();
    vector<DTHabitacion> obtenerHabitaciones(DTFecha checkIn, DTFecha checkOut);
    DTHabitacion elegirHabitacion(int numero);
    void reservaAHostalInd(Huesped *u);
    void reservaAHostalGrup(map<string, Huesped*> huespedes);
    void liberarHos();
    //Consultar top 3 de hostales
    vector<string> mejoresTresHostales();
    vector<DTCalificacion> detallesHostal(string hostal);
    //Registrar Estadia
    //Finalizar Estadia
    //Calificar Estadia
    //Comentar Calificacion
    //Consulta de Usuario
    //Consulta de Hostal
    //Consulta de Reserva
    //Consulta de Estadia
    //Baja de Reserva
};



#endif