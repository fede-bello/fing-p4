#ifndef DTUS
#define DTUS


#include<iostream>
#include<string>
using namespace std;
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