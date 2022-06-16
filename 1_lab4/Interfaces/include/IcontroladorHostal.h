#ifndef IHOSTAL
#define IHOSTAL

#include "../../Controladores/include/controladorHostal.h"
class IcontroladorHostal{
    public:
        //virtual static controladorHostal * getInstance();
        virtual void liberar();
        virtual ~IcontroladorHostal();
        virtual DTHostal *getHostal();
        virtual string getNombre();
        virtual map<string,Hostal*> getMapaHostal();
        //Alta de Usuario
        //Fin alta Usuario
        //Alta Hostal
        virtual DTHostal* nuevoHostal(string nombre,string direccion,string telefono);
        virtual void confirmarAltaHostal(DTHostal *dthostal);
        virtual void cancelarAltaHostal(DTHostal *dthostal);
        //Fin Alta Hostal
        //Alta Habitacion
        virtual vector<DTHostal> obtenerHostales();
        virtual DTHostal *elegirHostal(string nombre);
        virtual void confirmarAltaHabitacion(DTHabitacion *dthabitacion);
        virtual void cancelarAltaHabitacion(DTHabitacion *dthabitacion);   
        //Fin Alta Habitacion
        //Asignar empleado a hostal
        //Realizar Reserva
        virtual float obtenerPromedioCalificaciones();
        virtual vector<DTHabitacion> obtenerHabitaciones(DTFecha checkIn, DTFecha checkOut);
        virtual DTHabitacion elegirHabitacion(int numero);
        virtual void reservaAHostalInd(Huesped *u);
        virtual void reservaAHostalGrup(map<string, Huesped*> huespedes);
        virtual void liberarHos();
        //Consultar top 3 de hostales
        virtual vector<string> mejoresTresHostales();
        virtual vector<DTCalificacion> detallesHostal(string hostal);
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