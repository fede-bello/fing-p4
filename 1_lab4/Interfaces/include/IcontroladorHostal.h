#ifndef IHOSTAL
#define IHOSTAL

#include"../../Clases/include/Hostal.h"
#include"../../Controladores/include/controladorReserva.h"

class IcontroladorHostal{
    public:
        virtual ~IcontroladorHostal(){};
        virtual void liberar() = 0;
        virtual DTHostal *getHostal() = 0;
        virtual string getNombre() = 0;
        virtual map<string,Hostal*> getMapaHostal() = 0;
        //Alta de Usuario
        //Fin alta Usuario
        //Alta Hostal
        virtual DTHostal* nuevoHostal(string nombre,string direccion,string telefono) = 0;
        virtual void confirmarAltaHostal(DTHostal *dthostal) = 0;
        virtual void cancelarAltaHostal(DTHostal *dthostal) = 0;
        //Fin Alta Hostal
        //Alta Habitacion
        virtual vector<DTHostal> obtenerHostales() = 0;
        virtual DTHostal *elegirHostal(string nombre) = 0;
        // virtual void agregarConsumo(int codigo) = 0; --------- Dijeron que consumos no van
        virtual DTHabitacion* nuevaHabitacion(int numH, int precioH, int capH) = 0;
        virtual void confirmarAltaHabitacion(DTHabitacion *dthabitacion) = 0;
        virtual void cancelarAltaHabitacion(DTHabitacion *dthabitacion) = 0;   
        //Fin Alta Habitacion
        //Asignar empleado a hostal
        //Realizar Reserva
        virtual float obtenerPromedioCalificaciones() = 0;
        virtual vector<DTHabitacion> obtenerHabitaciones(DTFecha checkIn, DTFecha checkOut) = 0;
        virtual DTHabitacion elegirHabitacion(int numero) = 0;
        virtual void reservaAHostalInd(Huesped *u) = 0;
        virtual void reservaAHostalGrup(map<string, Huesped*> huespedes) = 0;
        virtual void liberarHos() = 0;
        //Consultar top 3 de hostales
        virtual vector<string> mejoresTresHostales() = 0;
        virtual vector<DTCalificacion> detallesHostal(string hostal) = 0;
        //Registrar Estadia
        virtual vector<DTReserva> obtenerReservasHuesped(string email, string hostal) = 0;
        //Finalizar Estadia
        virtual vector<DTEstadia> estadiasHuespedActivas(string email) = 0;
        virtual void finalizarEstadia() = 0;
        //Calificar Estadia
        virtual vector<DTEstadia> estadiasHuespedFinalizadas(string email, string hos) = 0;
        virtual void estadiaHostalCalificada (int codigo, int calif, string texto, Huesped *hues) = 0;
        //Comentar Calificacion
        virtual vector<DTCalificacion> califSinResponderHos(Hostal *hos) = 0;
        //Consulta de Usuario
        //Consulta de Hostal
        virtual vector<DTCalificacion> obtenerCalificaciones() = 0;
        virtual vector<DTHabitacion> obtenerInfoHabitaciones() = 0;
        virtual vector<DTReserva> obtenerReservasHostal() = 0;
        virtual void liberarMemoria() = 0;
        //Consulta de Reserva
        virtual int habitacionDeReserva(string hostal, DTReserva res)=0;
        virtual vector<DTHuesped> huespedesReserva(string hostal, DTReserva res) = 0;
        //Consulta de Estadia
        virtual vector<DTEstadia> obtenerEstadias(string hostal)=0;
        //Baja de Reserva
};

#endif
