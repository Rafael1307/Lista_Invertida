#ifndef ITERADORI_H
#define ITERADORI_H

#include <iostream>
#include "nodo_i.h"
#include "estudiante.h"

using namespace std;

class CIteradorI{
public:
    void operator=( CnodoI *otro){
        Pactual=otro;
    }
    bool operator==( CnodoI *otro)
    {
        return Pactual == otro;
    }
    bool operator!=( CnodoI *otro)
    {
        return Pactual != otro;
    }
    void operator++(){
        Pactual=Pactual->Psig;
    }

    void operator--(){
        Pactual=Pactual->Pant;
    }
    CObjeto &operator*(){
        return *Pactual->dato;
    }
    void SetNodo(CnodoI *nuevo);
    CnodoI* GetNodo();
    void Avanzar();
    void Regresar();
    void SetContenido(Clista *nc);
    Clista *GetContenido();
    void InsertarAdelante(Clista *contenido);
    void EliminarSiguiente();

    CnodoI* Pactual;
};

void CIteradorI::SetNodo(CnodoI *nuevo)
{
    Pactual = nuevo;
}

CnodoI *CIteradorI::GetNodo()
{
    return Pactual;
}

void CIteradorI::Avanzar()
{
    Pactual=Pactual->Psig;
}

void CIteradorI::Regresar()
{
    Pactual=Pactual->Pant;
}

void CIteradorI::SetContenido(Clista *nc)
{
    Pactual->dato=nc;
}

Clista *CIteradorI::GetContenido()
{
    return Pactual->dato;
}

void CIteradorI::InsertarAdelante(Clista *contenido)
{

    Pactual->InsertarAdelante(contenido);
}

void CIteradorI::EliminarSiguiente()
{
    Pactual->EliminarAdelante();
}

#endif // ITERADORI_H
