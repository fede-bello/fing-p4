#ifndef RES
#define RES

#include "Estadia.h"
#include "Huesped.h"
#include "../../DataType/include/DTReserva.h"
#include"../../DataType/include/DTFecha.h"

class Reserva{
    protected:
        int codigo;
        DTFecha checkIn,checkOut;
        EstadoReserva estado;
        float costo;
        Huesped *hues;
        map<int, Estadia> mapaEstadias; //estadias asociadas a Reserva
    public:
        //constructores
        Reserva();
        Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado);
    
        //gettes y setters
        //virtual float calcularCosto();
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstado();
        float getCosto();     
        map<int,Estadia> getEstadias();
        Huesped* getHuesped();
        void setCodigo(int codigo);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setEstado(EstadoReserva estado);
        void setEstadia(map<int,Estadia> mapaEstadias);
        void setHuesped(Huesped *huesped);        
         //destructor
        ~Reserva();
        //operaciones 
        bool reservaDisponibleEntre(DTFecha In, DTFecha Out);
        float calcularPromedioReserva(); //FALTA
        //set(DTCalificacion) darCalificacionesReserva(); (no me acuerdo el set como funcionaba despues investigo)
        bool mismoHuesped(string email);
        DTReserva getDTReserva();
        DTEstadia crearEstadiaNueva(DTFecha f);
        void cerrarEstadoReserva();
        //set(DTEstadia) estadiasActivas();
        DTEstadia mismaEstadia(int codigo); //devuelve la estadia de reserva que tenga codigo, ta raro
        void actualizarCheckOut(DTFecha co); //es solamente setCheckOut
        //set(DTEstadia) getEstadias();
        //set(DTCalificacion) getCalifSinResReserva()
        void buscarCalificacion(string respuesta, int codigoCalif);
        bool esGrupalReserva();
        //set(DTHuesped) obtenerHuespedesReserva();
        //set(DTEstadia) estadiasReserva() Hace lo mismo que getEstadias();
        DTHuesped esHuesped(); 
        int esReserva();
        bool mismaReserva(int cres);
        DTCalificacion calificacionBuscada();
        DTReserva reservaBuscada();
        //void eliminarLinksHuesEst();
        void calificarEstadiaReserva(Huesped hues);

};



#endif