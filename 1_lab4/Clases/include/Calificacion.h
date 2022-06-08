#ifndef CAL
#define CAL

#include<iostream>
#include<string>
#include "Huesped.h"
#include"../../DataType/include/DTFecha.h"
#include"../../DataType/include/DTCalificacion.h"

class Calificacion{
    private:
        int Numero;
        string Comentario;
        string Respuesta;
        DTFecha Fecha;
        int identificador;
        Huesped *hues;
        
    public:
        Calificacion(int cod,string Comentario,DTFecha realizada);
        //no se si se precisa esto
        int getNumero();
        string getComentario();
        string getRespuesta();
        DTFecha getFecha();
        int getIdentificador();
        Huesped* getHuesped();        
        void setNumero(int numero);
        void setComentario(string Comentario);
        void setRespuesta(string respuesta);
        void setFecha(DTFecha fecha);
        void setIdentificador(int identificador);
        void setHuesped(Huesped *huesped);
        ~Calificacion();
};


#endif
