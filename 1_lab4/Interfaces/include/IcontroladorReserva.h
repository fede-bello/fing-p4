#ifndef IRESERVA
#define IRESERVA

#include "../../Controladores/include/controladorReserva.h"

class IcontroladorReserva{
    public:
        //virtual static controladorReserva * getInstance();
        virtual void ModificarReservaActual(DTReserva nueva)=0;
        virtual ~IcontroladorReserva()=0;
        virtual void liberar();
        // Alta de Usuario 
        // Alta de Hostal
        // Alta de Habitacion
        // Asignar empleado a hostal

        // Realizar Reserva
        virtual float darPromedio(vector<Reserva> reservas)=0;
        virtual Reserva* getReservaInd(Huesped *u)=0;
        virtual Reserva* getReservaGrup(map<string, Huesped*> huespedes)=0;
        virtual void liberarRes()=0;
        // Consultar top 3 de hostales
        virtual vector<DTCalificacion> darCalificaciones(vector<Reserva> reservas)=0;
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