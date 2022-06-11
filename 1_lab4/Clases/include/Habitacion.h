#ifndef HAB
#define HAB


#include "Reserva.h"
#include "../../DataType/include/DTHabitacion.h"

class Habitacion{
    private:
        int Numero=0, Capacidad=0;
        float Precio=0.0;
        map<int, Reserva> Reservas; //reservas es un map (diccionario) de Reserva, la clave es el codigo de la reserva
    public:
        Habitacion();
        Habitacion(int numero, int capacidad, float precio);
        int getNum();
        int getCap();
        float getPrecio();
        map<int, Reserva> getReservas();
        void setNum(int numero);
        void setCap(int capacidad);
        void setPrecio(float precio);
        void setReserva(Reserva res);

        //Operaciones
        bool habitacionLibre(DTFecha In,DTFecha Out);//hay que modificar cosas, falta implementar coleeciones

        DTHabitacion getDTHabitacion();

        //DTReserva* darReservasHuespedHab(email); //devuelve las reservas asociadas al huesped con email pasado por parámetro
        
        //reservasHabitacion():set(Reservas) creo que es la misma que la de getReserva

        //bool mismoNumero(nr); Esta operacion esta mal desde el diagrama de comunicacion, no tiene sentido

        //DTHuesped* obtenerHuesprResHab(nr);

        bool buscarReserva(int cres);
        void eliminarLinkRes(int cres);

        //Destructora
        ~Habitacion();
};

#endif       