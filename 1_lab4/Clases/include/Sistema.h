#ifndef SISTEMA
#define SISTEMA

#include "ReservaIndividual.h"
#include "ReservaGrupal.h"

class Sistema{
    public:
        Habitacion** ArrHabitacion;
        Huesped** ArrHuesped;
        Reserva** ArrReserva;
    
        int indHuesped=0 ,indHabitacion=0,indReserva=0;
        Sistema();
        ~Sistema();
        void agregarHuesped(string nombre, string email, bool esFinger);
        void agregarHabitacion(int numero, int capacidad,float precio);
        DTHuesped** obtenerHuespedes(int& cantHuespedes);
        DTHabitacion** obtenerHabitaciones(int& cantHabitaciones);
        DTReserva** obtenerReservas(DTFecha fecha, int& cantReservas);
        void registrarReserva(string email, DTReserva* reserva);

};

#endif