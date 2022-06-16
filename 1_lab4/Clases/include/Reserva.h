#ifndef RES
#define RES


#include "Estadia.h"
#include "Huesped.h"
#include "../../DataType/include/DTUsuario.h"
#include "../../DataType/include/DTReserva.h"
#include"../../DataType/include/DTFecha.h"
#include"../../DataType/include/DTCalificacion.h"



class Reserva{
    protected:
        int codigo;
        DTFecha checkIn,checkOut;
        EstadoReserva estado;
        float costo;
        Huesped *hues;
        map<int, Estadia*> mapaEstadias; //estadias asociadas a Reserva, deberia ser map<int, *Estadia>???
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
        map<int,Estadia*> getEstadias();
        Huesped* getHuesped();
        void setCodigo(int codigo);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setEstado(EstadoReserva estado);
        void setEstadia(map<int,Estadia*> mapaEstadias);
        void setHuesped(Huesped *huesped);        
         //destructor
        ~Reserva();//✅
        //operaciones 
        bool reservaDisponibleEntre(DTFecha In, DTFecha Out);//✅
        float calcularPromedioReserva();//✅
        vector<DTCalificacion> darCalificacionesReserva();//✅ 
        bool mismoHuesped(string email);//✅
        DTReserva getDTReserva();//✅
        DTEstadia crearEstadiaNueva(DTFecha f);//✅
        void cerrarEstadoReserva();//✅
        vector<DTEstadia> estadiasActivas();//✅ 
        DTEstadia mismaEstadia(int codigo);//✅
        void actualizarCheckOut(DTFecha co,int codigo);//✅
        vector<DTEstadia> EstadiasFin(string mail);// FALTAAAAA //Devuelve las DTEstadias que esten finalizadas y estan asociadas al mail
        vector<DTCalificacion> getCalifSinResReserva(); //FALTA
        void buscarCalificacion(string respuesta, int codigoCalif); //FALTA
        bool esGrupalReserva(); //FALTA
        vector<DTHuesped> obtenerHuespedesReserva(); //FALTA
        vector<DTEstadia> estadiasReserva(); //FALTA  //Hace lo mismo que getEstadias();
        DTHuesped esHuesped();//✅
        int esReserva();//✅
        bool mismaReserva(int cres);//✅
        DTCalificacion calificacionBuscada(int codigo); //FALTA, agregue el codigo como parametro si no imposible encontrar la calificacion (hecha por danilo, funciona si se saca el puntero a estadia)
        DTReserva reservaBuscada(int codigo); //FALTA, agregue el codigo como parametro si no imposible encontrar la calificacion
        void eliminarLinksHuesEst(); //FALTA
        void calificarEstadiaReserva(int codigo, int calif, string texto,Huesped *hues); //FALTA

};



#endif