#ifndef CONTH
#define CONTH


#include "../../Interfaces/include/IcontroladorHostal.h"



class controladorHostal : public IcontroladorHostal{
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
    //void agregarConsumo(int codigo); //FALTA -------- Dijeron que consumos no van
    DTHabitacion* nuevaHabitacion(int numH, int precioH, int capH);
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
    //Fin Realizar Reserva
    //Consultar top 3 de hostales
    vector<string> mejoresTresHostales();
    vector<DTCalificacion> detallesHostal(string hostal);
    //Fin consulta top 3 de hostales
    //Registrar Estadia
    vector<DTReserva> obtenerReservasHuesped(string email, string hostal);
    //Fin Registrar Estadia
    //Finalizar Estadia
    vector<DTEstadia> estadiasHuespedActivas(string email);
    void finalizarEstadia();
    //Calificar Estadia
    vector<DTEstadia> estadiasHuespedFinalizadas(string email, string hos);
    void estadiaHostalCalificada (int codigo, int calif, string texto, Huesped *hues);
    //Comentar Calificacion
    vector<DTCalificacion> califSinResponderHos(Hostal *hos);
    //Consulta de Usuario
    //Consulta de Hostal
    vector<DTCalificacion> obtenerCalificaciones();
    vector<DTHabitacion> obtenerInfoHabitaciones();
    vector<DTReserva> obtenerReservasHostal();
    void liberarMemoria();
    //Consulta de Reserva
    int habitacionDeReserva(string hostal, DTReserva res);
    vector<DTHuesped> huespedesReserva(string hostal, DTReserva res);
    //Consulta de Estadia
    vector<DTEstadia> obtenerEstadias(string hostal);
    //Baja de Reserva
    void bajaReserva(int codigo);
    void cancelarBajaReserva(int codigo);
};



#endif
