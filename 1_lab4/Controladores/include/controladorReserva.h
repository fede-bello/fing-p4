#ifndef CONTR
#define CONTR

#include "../../Clases/include/Reserva.h"
#include "controladorFecha.h"
class controladorReserva {
private:
    static controladorReserva * instancia;
    controladorReserva();
    map<int,Reserva*> MapaReserva;
    DTReserva *ReservaGuardada;
public:
    static controladorReserva * getInstance();
    void ModificarReservaActual(DTReserva nueva);
    ~controladorReserva();
    void liberar();
    //Alta de Usuario 
    //Alta de Hostal
    //Alta de Habitacion
    //Asignar empleado a hostal
   
    //Realizar Reserva
    float darPromedio(vector<Reserva> reservas);
    //Consultar top 3 de hostales
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