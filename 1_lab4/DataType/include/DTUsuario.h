#ifndef DTUS
#define DTUS


#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


enum CargoEmp{
    Limpieza, Administracion, Infrasetructura, Recepcion
};


class DTUsuario{
    protected:
        string Nombre, Password, Mail;

    public:
        //Constructoras 
        DTUsuario();
        DTUsuario(string Nombre, string Password, string Mail);

        //Getters
        string getNombre();
        string getPassword();
        string getMail();


        //Destructora
        virtual ~DTUsuario();
};






#endif