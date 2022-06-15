#ifndef HOS
#define HOS


#include "Habitacion.h"
#include "../../DataType/include/DTHostal.h"
#include "../../DataType/include/DTHabitacion.h"



class Hostal{
    private:
        string Nombre;
        string Direccion;
        string Telefono;
        map<int, Habitacion*> mapaHabitaciones; //mapaHabitaciones es un map (diccionario) de Habitacion
    public:
        Hostal();
        Hostal(string Nombre,string Direccion,string Telefono);
        string getNombre();
        string getDireccion();
        string getTelefono();
        void setNombre(string nombre);
        void setDireccion(string direccion);
        void setTelefono(string telefono);
        void agregarHabitacionAHostal(DTHabitacion hab);
        //Operaciones
        DTHostal getDTHostal();//✅
        vector<DTReserva> darReservasHuespedHos(string email);//✅ agregue el mail del huesped como parametro
        vector<Reserva> getReservasHostal();//✅
        vector<DTHabitacion> darInfoHabs();//✅
        vector<DTReserva> darReservasHostal();//✅
        vector<Reserva> reservasAsociadas(); //✅
        int darNumHab(int nr);//✅
        vector<DTHuesped> huespedes(int nr);//✅
        DTHabitacion infoHab(int cres);//✅
        void eliminarLinkReserva(int cres);//✅agregue a que reserva hace referencia
        void AsociarReservaHostal(Reserva r,int habitacion);//✅
        vector<DTHabitacion> habitacionesDisponibles(DTFecha in, DTFecha out);//✅
     
        //Destructoras
        ~Hostal();
};

#endif   

