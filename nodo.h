#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "estudiante.h"

using namespace std;

class Cnodo
{
public:
    Cnodo(){
    }

    void InsertarAdelante(CObjeto *nuevodato)
    {
        Cnodo *Pnuevo = new Cnodo;
        Pnuevo->Pant=this;
        Pnuevo->Psig=this->Psig;
        this->Psig=Pnuevo;
        Pnuevo->Psig->Pant=Pnuevo;
        Pnuevo->dato=nuevodato;
    }
    void EliminarAdelante()
    {

        this->Psig = this->Psig->Psig;
        delete this->Psig->Pant;
        this->Psig->Pant = this;

    }

    Cnodo *Psig;
    Cnodo *Pant;
    CObjeto *dato;

};



#endif // NODO_H
