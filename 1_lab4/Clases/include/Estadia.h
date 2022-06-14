#ifndef EST
#define EST


#include"Calificacion.h"
#include "Huesped.h"
#include"../../DataType/include/DTEstadia.h"
#include"../../Controladores/include/controladorFecha.h"



class Estadia{
    private:
        int identificador;
        DTFecha CheckIn;
        DTFecha CheckOut;
        Calificacion *calif;
        Huesped *hues;
        //promo y costo ya no son necesarios
    public:
        Estadia();
        Estadia(int identificador,DTFecha CheckIn,DTFecha CheckOut);
        int getIdentificador(); //hecha
        DTFecha getCheckIn();//hecha
        DTFecha getCheckOut();//hecha
        Calificacion* getCalificacion();//hecha
        DTEstadia getDTEstadia();//hecha
        Huesped* getHuesped();//hecha
        void setIdentificador(int identificador);//hecha
        void setCheckIn(DTFecha checkIn);//hecha
        void setCheckOut(DTFecha checkOut);//hecha
        void setCalificacion(Calificacion *calif);//hecha
        void setHuesped(Huesped *huesped);//hecha
        float calcularPuntajeEstadia();
        bool estadiaActiva();//hecha, revisar
        bool mismoCodigo(int codigo);//hecha
        bool estaFinalizadaEstadia();//hecha, revisar
        void registrarRespuesta(string respuesta, int codigoCalif); //hecha, revisar
        bool mismaEstadia(int identificador);//hecha
        DTHuesped huesEs();//hecha - Devuelve el DTHuesped del Huesped asociado a la estadia
        DTCalificacion calificacionEstadia(); //hecho
        DTCalificacion darCalificacionesEstadia();
        void calificarEst(Huesped* hues, int calif, string texto);
        ~Estadia();

};


     

#endif