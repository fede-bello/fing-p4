#ifndef HAB
#define HAB


#include "Reserva.h"
#include "../../DataType/include/DTHabitacion.h"
#include"../../DataType/include/DTFecha.h" 

class Habitacion{
    private:
        int Numero=0, Capacidad=0;
        float Precio=0.0;
        map<int, Reserva> mapaReservas; //reservas es un map (diccionario) de Reserva, la clave es el codigo de la reserva
    public:
        Habitacion();
        Habitacion(int numero, int capacidad, float precio);
        int getNum();
        int getCap();
        float getPrecio();
        void setNum(int numero);
        void setCap(int capacidad);
        void setPrecio(float precio);
        void setReserva(Reserva res);

        //Operaciones
        map<int, Reserva> getReservas(); //✅
        bool habitacionLibre(DTFecha In,DTFecha Out);//✅
        DTHabitacion getDTHabitacion();//✅
        DTReserva* darReservasHuespedHab(string email);//FALTA
        
        //reservasHabitacion():set(Reservas); Es la misma que getReservas?

        DTReserva darReservasHabitacion();//FALTA
        bool mismoNumero(int nr); //✅
        DTHuesped obtenerHuesprResHab(int nr);//FALTA
        bool buscarReserva(int cres);//✅
        void eliminarLinkRes(int cres);//✅

        //Destructora
        ~Habitacion();
};

#endif       