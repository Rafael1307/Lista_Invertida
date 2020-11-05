#ifndef LISTA_INVERTIDA_H
#define LISTA_INVERTIDA_H

#include <iostream>
#include "nodo_i.h"
#include "iteradori.h"
#include "lista.h"
#include "estudiante.h"

#define CLSID_listaI 110

using namespace std;

class Clista_I: public CObjeto
{
public:
    Clista_I()
    {
        Inicio.Psig = &Final;
        Final.Pant = &Inicio;
    }
    ~Clista_I()
    {
        delete &Inicio;
        delete &Final;
    }
    void NuevaL(CObjeto *Ndato);
    void Busqueda(int dato);
    void InsertarInicio(Clista *Ndato);
    void InsertarFinal(Clista *Ndato);
    void EliminarInicio();
    void EliminarFinal();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void imprimir();
    CnodoI *Begin();
    CnodoI *End();
    CnodoI *rBegin();
    CnodoI *rEnd();
    void Salvar(fstream &out);
    void Cargar(fstream &in);
    int GetCLSID();
    int getAtributoI();
private:
    CnodoI Inicio;
    CnodoI Final;
};

void Clista_I::NuevaL(CObjeto *Ndato)
{
    bool encontrado=false;
    CIteradorI it;
    for(it = this->Begin(); it!= this->End(); ++it){
        cout<<endl;
        if(it.Pactual->dato->getAtributoI() == Ndato->getAtributoI()){
            it.Pactual->dato->InsertarFinal(Ndato);
            encontrado=true;
        }
    }
    if(encontrado){

    }else{
        Clista *lista = new Clista;
        lista->InsertarFinal(Ndato);
        InsertarFinal(lista);
    }
}

void Clista_I::Busqueda(int dato)
{
    bool encontrado=false;
    CIteradorI it;
    for(it = this->Begin(); it!= this->End(); ++it){
        cout<<endl;
        if(it.Pactual->dato->getAtributoI() == dato){
            it.Pactual->dato->imprimir();
            encontrado=true;
        }
    }
    if(encontrado){

    }else{
        cout<<"No se encontro"<<endl;
    }
}

void Clista_I::InsertarInicio(Clista *Ndato)
{
    if(IsFull()){
        cout<<"Lista llena"<<endl;
    }else
    Inicio.InsertarAdelante(Ndato);
}

void Clista_I::InsertarFinal(Clista *Ndato)
{
    if(IsFull()){
        cout<<"Lista llena"<<endl;
    }else
    Final.Pant->InsertarAdelante(Ndato);
}

void Clista_I::EliminarInicio()
{
    if(IsEmpty()){
        cout<<"Lista vacia"<<endl;
    }else
    Inicio.EliminarAdelante();
}

void Clista_I::EliminarFinal()
{
    if(IsEmpty()){
        cout<<"Lista vacia"<<endl;
    }else
    Final.Pant->Pant->EliminarAdelante();
}

int Clista_I::Size()
{
    int cont = 0;
    CnodoI *temp = Inicio.Psig;
    while(temp != &Final){
        cont++;
        temp = temp->Psig;
    }
    return cont;
}

bool Clista_I::IsEmpty()
{
    return Size()==0;
}

bool Clista_I::IsFull()
{
    return false;
}

void Clista_I::imprimir()
{
    CIteradorI it;
    for(it = this->Begin(); it!= this->End(); ++it){
        cout<<endl;
        it.Pactual->dato->imprimir();
        cout<<endl;
    }

}

CnodoI *Clista_I::Begin()
{
    return Inicio.Psig;
}

CnodoI *Clista_I::End()
{
    return &Final;
}

CnodoI *Clista_I::rBegin()
{
    return Final.Pant;
}

CnodoI *Clista_I::rEnd()
{
    return &Inicio;
}

int Clista_I::GetCLSID()
{
    return CLSID_listaI;
}

int Clista_I::getAtributoI()
{

}

void Clista_I::Cargar(fstream &in)
{

    int tamano =0;
    in>>tamano;
    for(int i= 0; i<tamano;i++){
        int CLSID = 0;
        in>>CLSID;
        Clista *pobj;
        switch(CLSID){
        case CLSID_lista:
            pobj = new Clista();
            break;
        default:
            pobj=0;
            break;
        }
        pobj->Cargar(in);
        InsertarFinal(pobj);
    }
}

void Clista_I::Salvar(fstream &out)
{
    out<<GetCLSID()<<endl;
    out<<Size()<<endl;
    CIteradorI it;
    for(it = this->Begin(); it!= this->End(); ++it){
        it.Pactual->dato->Salvar(out);

    }

}

#endif // LISTA_INVERTIDA_H
