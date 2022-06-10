#ifndef HAB
#define HAB


#include "Reserva.h"
#include "../../DataType/include/DTHabitacion.h"

class Habitacion{
    private:
        int Numero=0, Capacidad=0;
        float Precio=0.0;
        Reserva* res;
    public:
        Habitacion();
        Habitacion(int numero, int capacidad, float precio);
        int getNum();
        int getCap();
        float getPrecio();
        Reserva* getReserva();
        void setNum(int numero);
        void setCap(int capacidad);
        void setPrecio(float precio);
        void setReserva(Reserva *res);

        //Operaciones
        bool habitacionLibre(In,Out);//hay que modificar cosas, falta implementar coleeciones

        DTHabitacion getDTHabitacion();

        //DTReserva* darReservasHuespedHab(email);
        
        //reservasHabitacion():set(Reservas) creo que es la misma que la de getReserva

        //bool mismoNumero(nr); Esta operacion esta mal desde el diagrama de comunicacion, no tiene sentido

        //DTHuesped* obtenerHuesprResHab(nr);

        bool buscarReserva(cres);
        void eliminarLinkRes();

        //Destructora
        ~Habitacion();
};

#endif       