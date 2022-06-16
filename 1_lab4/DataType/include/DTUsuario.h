#ifndef DTUS
#define DTUS


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
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
        //set
        void setMail(string Mail); //PUEDE QUE ESTE MAL

        //Destructora
        virtual ~DTUsuario();
};






#endif