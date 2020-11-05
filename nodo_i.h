#ifndef NODO_I_H
#define NODO_I_H


#include <iostream>
#include "lista.h"
#include "estudiante.h"

using namespace std;

class CnodoI
{
public:
    CnodoI(){
    }

    void InsertarAdelante(Clista *nuevodato)
    {
        CnodoI *Pnuevo = new CnodoI;
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

    CnodoI *Psig;
    CnodoI *Pant;
    Clista *dato;

};



#endif // NODO_I_H
