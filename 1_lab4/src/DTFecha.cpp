

#include"../include/DTFecha.h"

//Contructores
DTFecha::DTFecha(int d, int m, int a){
    this->dia=d;       
    this->mes=m;     
    this->anio=a;     
}

DTFecha::DTFecha(){
    this->anio=1900;
    this->dia=1;
    this->mes=1;
}

//Destructora

DTFecha::~DTFecha(){
}

//gets 
int DTFecha::getAnio(){
    return this->anio;
}

int DTFecha::getMes(){
    return this->mes;
}

int DTFecha::getDia(){
    return this->dia;
}

//avanzar y retroceder diferencia fechas
DTFecha DTFecha::avanzarFecha(int i){
    DTFecha nuevo(dia,mes,anio);
    nuevo.dia=nuevo.dia +i;
    if ((nuevo.dia)>31){
        nuevo.mes=nuevo.mes+int(nuevo.dia/31);
        nuevo.dia=(nuevo.dia%31);
        if (nuevo.mes>12){
            nuevo.anio=nuevo.anio+int(nuevo.mes/12);
            nuevo.mes=(nuevo.mes%12);
        }
    }
    return nuevo;
}

DTFecha DTFecha:: retrocederFecha(int i){
    DTFecha nuevo(dia,mes,anio);
    nuevo.dia=nuevo.dia-i;
    while (nuevo.dia<1){
        if (nuevo.mes>=2){
            nuevo.mes=nuevo.mes-1;
            nuevo.dia=nuevo.dia+31;
        }
        else {
            if(nuevo.anio>=1901){
                nuevo.anio=nuevo.anio-1;
                nuevo.mes=nuevo.mes+12;
                nuevo.dia=nuevo.dia+31;
            }
        }
    }
    return nuevo;
}

int DTFecha::diferenciasFechas(DTFecha f){
    long int fecha1 = f.dia + f.mes*31 + f.anio*12*31;
    long int fecha2 = dia + mes*31 + anio*12*31;
    if (fecha1>=fecha2) return fecha1-fecha2;
    else return (fecha2-fecha1);
}

//Operadores
bool DTFecha:: operator==(const DTFecha &f) const{
    return (this->dia==f.dia)&&(this->mes==f.mes)&&(this->anio==f.anio);
}

