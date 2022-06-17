#ifndef IRESERVA
#define IRESERVA

#include "../../Controladores/include/controladorReserva.h"

class IcontroladorReserva{
    public:
        //virtual static controladorReserva * getInstance();
        virtual void ModificarReservaActual(DTReserva nueva)=0;
        virtual ~IcontroladorReserva(){};
        virtual void liberar() = 0;
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
        virtual DTEstadia registrarEstadia(int res) = 0;
        virtual void actualizarEstadoReservaCerrada(int res) = 0;
        // Finalizar Estadia
        virtual vector<DTEstadia> obtenerEstadias(vector<Reserva> resA) = 0;
        virtual DTEstadia elegirEstadia(int codigo) = 0;  
        virtual void actualizarCheckOutEstadia() = 0;
        // Calificar Estadia
        virtual vector<DTEstadia> darEstadiaFinHuespedRes(string email,vector<Reserva> res) = 0;
        virtual void estadiaReservaCalificada(int codigo, int calif, string texto, Huesped *hues) = 0;
        // Comentar Calificacion
        virtual vector<DTCalificacion> califSinResponderRes(vector<Reserva> res) = 0;
        virtual void registrarRespuestaComentario(string respuesta, int codigoCalif) = 0;
        // Consulta de Usuario
        // Consulta de Hostal
        // Consulta de Reserva
        virtual int getNumero(DTReserva res) = 0;
        // Consulta de Estadia
        virtual vector<DTEstadia> estadiasHostal(vector<Reserva> resA) = 0;
        virtual DTHuesped infoHuesped(vector<Reserva> res, int codigo) = 0;
        virtual DTEstadia infoEstadia(vector<Reserva> res, int codigo) = 0;
        virtual int codigoReserva(vector<Reserva> res, int codigo) = 0;
        // Baja de Reserva
        virtual void eliminarLinksHuesEst(int codigo) = 0;
};

#endif