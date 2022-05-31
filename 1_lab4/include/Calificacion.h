#ifndef C
#define C

#include<iostream>
#include<string>
#include"DTFecha.h"

class Calificacion{
    private:
        int num;
        string texto;
        string respuesta;
        DTFecha realizada;
        //no inclui identificador, 
        //no me parecio necesario por que esta linkeada a una unica reserva
    public:
        Calificacion(int cod,string texto,DTFecha realizada);
        //no se si se precisa esto
        int getNum();
        string getTexto();
        DTFecha getFecha();
        string getRespuesta();
        void setRespuesta(string respuesta);
        ~Calificacion();
};


#endif
