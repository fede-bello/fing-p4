#include "../include/DTCalificacion.h"
#include "../include/DTFecha.h"

   
DTCalificacion::DTCalificacion(){
    this->Numero:=0;
    this->Comentario:=".";
    this->Respuesta:=".";
    this->Fecha=DTFecha();
    this->Identificador:=0;
    
}

DTCalificacion(int Numero,string Comentario,string Respuesta, DTFecha Fecha,int Identificador){
    this->Numero:=Numero;
    this->Comentario:=Comentario;
    this->Respuesta:=Respuesta;
    this->Fecha=Fecha
    this->Identificador:=Identificador;
    
}
int getNumero(){
    return this->numero;
}
string getComentario(){
    return this->Comentario;
}

string getRespuesta(){
    return this->Respuesta;
}
DTFecha getFecha(){
    return this->Fecha;
}
int getIdentificador(){
    return this->Identificador;
}

~DTCalificacion(){

}