#ifndef CITERADOR_H
#define CITERADOR_H


#include <iostream>
#include "nodo.h"
#include "estudiante.h"

using namespace std;

class CIterador{
public:
    void operator=( Cnodo *otro){
        Pactual=otro;
    }
    bool operator==( Cnodo *otro)
    {
        return Pactual == otro;
    }
    bool operator!=( Cnodo *otro)
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
    void SetNodo(Cnodo *nuevo);
    Cnodo* GetNodo();
    void Avanzar();
    void Regresar();
    void SetContenido(CObjeto *nc);
    CObjeto *GetContenido();
    void InsertarAdelante(CObjeto *contenido);
    void EliminarSiguiente();

    Cnodo* Pactual;
};

void CIterador::SetNodo(Cnodo *nuevo)
{
    Pactual = nuevo;
}

Cnodo *CIterador::GetNodo()
{
    return Pactual;
}

void CIterador::Avanzar()
{
    Pactual=Pactual->Psig;
}

void CIterador::Regresar()
{
    Pactual=Pactual->Pant;
}

void CIterador::SetContenido(CObjeto *nc)
{
    Pactual->dato=nc;
}

CObjeto *CIterador::GetContenido()
{
    return Pactual->dato;
}

void CIterador::InsertarAdelante(CObjeto *contenido)
{

    Pactual->InsertarAdelante(contenido);
}

void CIterador::EliminarSiguiente()
{
    Pactual->EliminarAdelante();
}

#endif // CITERADOR_H
