#ifndef DTCAL
#define DTCAL


#include "DTHuesped.h"//
#include "DTFecha.h"



class DTCalificacion{
    private:
        //Falta pseudo atributo para DTHuesped
        int Numero;
        string Comentario;
        string Respuesta;
        DTFecha Fecha;
        int Identificador;
        /*suscriptores?*/
    public:
        DTCalificacion();
        DTCalificacion(int Numero,string Comentario,string Respuesta, DTFecha Fecha,int Identificador);        
        int getNumero();
        string getComentario();
        string getRespuesta();
        DTFecha getFecha();
        int getIdentificador();
        ~DTCalificacion();
};

#endif
