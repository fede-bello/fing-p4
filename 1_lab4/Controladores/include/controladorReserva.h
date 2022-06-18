#ifndef CONTR
#define CONTR

#include "../../Clases/include/Reserva.h"
#include "../../Clases/include/ReservaIndividual.h"
#include "../../Clases/include/ReservaGrupal.h"
#include "../../DataType/include/DTReserva.h"
#include "controladorFecha.h"
#include "../../Interfaces/include/IcontroladorReserva.h"

class controladorReserva : public IcontroladorReserva{
private:
    static controladorReserva * instancia;
    controladorReserva();
    map<int,Reserva*> MapaReserva;
    DTReserva *ReservaGuardada;
    
public:
    int codigoRes=1000, codigoEst=1000,codigoCalificacion=1000;
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
    DTEstadia registrarEstadia(int res);
    void actualizarEstadoReservaCerrada(int res);
    // Finalizar Estadia
    vector<DTEstadia> obtenerEstadias(vector<Reserva> resA);
    DTEstadia elegirEstadia(int codigo);  
    void actualizarCheckOutEstadia();
    // Calificar Estadia
    vector<DTEstadia> darEstadiaFinHuespedRes(string email,vector<Reserva> res);
    void estadiaReservaCalificada(int codigo, int calif, string texto, Huesped *hues);
    // Comentar Calificacion
    vector<DTCalificacion> califSinResponderRes(vector<Reserva> res);
    void registrarRespuestaComentario(string respuesta, int codigoCalif);
    // Consulta de Usuario
    // Consulta de Hostal
    // Consulta de Reserva
    int getNumero(DTReserva res);
    // Consulta de Estadia
    vector<DTEstadia> estadiasHostal(vector<Reserva> resA);
    DTHuesped infoHuesped(vector<Reserva> res, int codigo);//falta
    DTEstadia infoEstadia(vector<Reserva> res, int codigo);//falta
    int codigoReserva(vector<Reserva> res, int codigo);//falta
    // Baja de Reserva
    void eliminarLinksHuesEst(int codigo);

};


#endif