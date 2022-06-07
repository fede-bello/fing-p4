#ifndef CAL
#define CAL

#include<iostream>
#include<string>
#include"../../DataType/include/DTFecha.h"

class Calificacion{
    private:
        int Numero;
        string Comentario;
        string Respuesta;
        DTFecha Fecha;
        //no inclui identificador, 
        //no me parecio necesario por que esta linkeada a una unica reserva
    public:
        Calificacion(int cod,string Comentario,DTFecha realizada);
        //no se si se precisa esto
        int getNumero();
        string getComentario();
        string getRespuesta();
        DTFecha getFecha();
        void setNumero(int numero);
        void setComentario(string Comentario);
        void setRespuesta(string respuesta);
        void setFecha(DTFecha fecha);
        ~Calificacion();
};


#endif
