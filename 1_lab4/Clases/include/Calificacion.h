#ifndef CAL
#define CAL


#include "Huesped.h"
#include"../../DataType/include/DTFecha.h"
#include"../../DataType/include/DTCalificacion.h"


class Calificacion{
    private:
        int Numero;
        string Comentario;
        string Respuesta;
        DTFecha Fecha;
        int Identificador;
        Huesped *hues;
        
    public:
        Calificacion();
        Calificacion(int Numero,string Comentario,string Respuesta, DTFecha Fecha,int Identificador);
        //getters y setters
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
        //operaciones
        DTCalificacion getDTCalificacion();
        bool esCalificacion(int codigoCalif);
        void asociarHuesped(Huesped *hues);
        //suscribir,desuscribir y notificar nos encargamos despues cuando encaremos el observer
        //destructora
        ~Calificacion();
};


#endif
