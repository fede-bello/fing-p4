#ifndef CONTR
#define CONTR

#include "../../Clases/include/Reserva.h"
#include "../../Clases/include/ReservaIndividual.h"
#include "../../Clases/include/ReservaGrupal.h"
#include "controladorFecha.h"
#include "../../Interfaces/include/IcontroladorReserva.h"

class controladorReserva /*: public IcontroladorReserva*/ {
private:
    static controladorReserva * instancia;
    controladorReserva();
    map<int,Reserva*> MapaReserva;
    DTReserva *ReservaGuardada;
    int codigo;
public:
    static controladorReserva * getInstance();
    void ModificarReservaActual(DTReserva nueva);
    ~controladorReserva();
    void liberar();
    // Alta de Usuario 
    // Alta de Hostal
    // Alta de Habitacion
    // Asignar empleado a hostal

    // Realizar Reserva
    float darPromedio(vector<Reserva> reservas);
    Reserva* getReservaInd(Huesped *u);
    Reserva* getReservaGrup(map<string, Huesped*> huespedes);
    void liberarRes();
    // Consultar top 3 de hostales
    vector<DTCalificacion> darCalificaciones(vector<Reserva> reservas);
    // Registrar Estadia
    // Finalizar Estadia
    // Calificar Estadia
    // Comentar Calificacion
    // Consulta de Usuario
    // Consulta de Hostal
    // Consulta de Reserva
    // Consulta de Estadia
    // Baja de Reserva
};


#endif