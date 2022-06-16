#ifndef IRESERVA
#define IRESERVA

#include "../../Controladores/include/controladorReserva.h"

class IcontroladorReserva{
    public:
        //virtual static controladorReserva * getInstance();
        virtual void ModificarReservaActual(DTReserva nueva);
        virtual ~IcontroladorReserva();
        virtual void liberar();
        // Alta de Usuario 
        // Alta de Hostal
        // Alta de Habitacion
        // Asignar empleado a hostal

        // Realizar Reserva
        virtual float darPromedio(vector<Reserva> reservas);
        virtual Reserva* getReservaInd(Huesped *u);
        virtual Reserva* getReservaGrup(map<string, Huesped*> huespedes);
        virtual void liberarRes();
        // Consultar top 3 de hostales
        virtual vector<DTCalificacion> darCalificaciones(vector<Reserva> reservas);
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