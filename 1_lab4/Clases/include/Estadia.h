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
        //Operaciones 
        float calcularPuntajeEstadia();//✅
        DTCalificacion darCalificacionesEstadia();//✅
        bool estadiaActiva();//✅
        bool mismoCodigo(int codigo);//✅
        bool estaFinalizadaEstadia();//✅
        void registrarRespuesta(string respuesta, int codigoCalif);//✅
        bool mismaEstadia(int identificador);//✅
        DTHuesped huesEs();//✅
        DTCalificacion calificacionEstadia();//✅
        void calificarEst(Huesped* hues, int calif, string texto);//✅
        DTEstadia EstadiaResFin(string mail);//FALTA
        DTCalificacion CalifSinRes();//FALTA
        //DEstructora
        ~Estadia();//No estoy seguro de si asi esta bien al final

};


     

#endif