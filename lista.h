#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"
#include "citerador.h"
#include "estudiante.h"

#define CLSID_lista 100

using namespace std;

class Clista: public CObjeto
{
public:
    Clista()
    {
        Inicio.Psig = &Final;
        Final.Pant = &Inicio;
    }
    ~Clista()
    {
        delete &Inicio;
        delete &Final;
    }
    void Busqueda(CObjeto *Ndato);
    virtual int getAtributoI();
    void InsertarInicio(CObjeto *Ndato);
    void InsertarFinal(CObjeto *Ndato);
    void EliminarInicio();
    void EliminarFinal();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void imprimir();
    Cnodo *Begin();
    Cnodo *End();
    Cnodo *rBegin();
    Cnodo *rEnd();
    void Salvar(fstream &out);
    void Cargar(fstream &in);
    int GetCLSID();
private:
    Cnodo Inicio;
    Cnodo Final;
};

void Clista::Busqueda(CObjeto *Ndato)
{
    bool encontrado=false;
    CIterador it;
    for(it = this->Begin(); it!= this->End(); ++it){
        cout<<endl;
        if(it.Pactual->dato->getAtributoI() == Ndato->getAtributoI()){
            it.Pactual->dato->imprimir();
            encontrado=true;
        }
    }
    if(encontrado){

    }else{
        cout<<"No se encontro"<<endl;
    }
}

int Clista::getAtributoI()
{
    this->Begin()->dato->getAtributoI();
}

void Clista::InsertarInicio(CObjeto *Ndato)
{
    if(IsFull()){
        cout<<"Lista llena"<<endl;
    }else
    Inicio.InsertarAdelante(Ndato);
}

void Clista::InsertarFinal(CObjeto *Ndato)
{
    if(IsFull()){
        cout<<"Lista llena"<<endl;
    }else
    Final.Pant->InsertarAdelante(Ndato);
}

void Clista::EliminarInicio()
{
    if(IsEmpty()){
        cout<<"Lista vacia"<<endl;
    }else
    Inicio.EliminarAdelante();
}

void Clista::EliminarFinal()
{
    if(IsEmpty()){
        cout<<"Lista vacia"<<endl;
    }else
    Final.Pant->Pant->EliminarAdelante();
}

int Clista::Size()
{
    int cont = 0;
    Cnodo *temp = Inicio.Psig;
    while(temp != &Final){
        cont++;
        temp = temp->Psig;
    }
    return cont;
}

bool Clista::IsEmpty()
{
    return Size()==0;
}

bool Clista::IsFull()
{
    return false;
}

void Clista::imprimir()
{
    CIterador it;
    for(it = this->Begin(); it!= this->End(); ++it){
        cout<<endl;
        it.Pactual->dato->imprimir();
        cout<<endl;
    }

}

Cnodo *Clista::Begin()
{
    return Inicio.Psig;
}

Cnodo *Clista::End()
{
    return &Final;
}

Cnodo *Clista::rBegin()
{
    return Final.Pant;
}

Cnodo *Clista::rEnd()
{
    return &Inicio;
}

int Clista::GetCLSID()
{
    return CLSID_lista;
}

void Clista::Cargar(fstream &in)
{

    int tamano =0;
    in>>tamano;
    for(int i= 0; i<tamano;i++){
        int CLSID = 0;
        in>>CLSID;
        CObjeto *pobj=0;
        switch(CLSID){
        case CLSID_lista:
            pobj = new Clista();


        case CLSID_persona:

            pobj = new CPersona();


            break;
        case CLSID_estudiante:

        pobj = new CEstudiante();

        break;
        default:
            pobj=0;
            break;
        }
        pobj->Cargar(in);
        InsertarFinal(pobj);
    }
}

void Clista::Salvar(fstream &out)
{
    out<<GetCLSID()<<endl;
    out<<Size()<<endl;
    CIterador it;
    for(it = this->Begin(); it!= this->End(); ++it){
        it.Pactual->dato->Salvar(out);

    }

}
#endif // LISTA_H
