#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#define CLSID_persona 10
#define CLSID_estudiante 11

#include "cserializacion.h"
#include <iostream>

using namespace std;
//*********************************************************************************************
class CObjeto: public CSerializacion
{
public:
    CObjeto(){
    }

    virtual void imprimir()=0;
    virtual int getAtributoI()=0;

protected:

};
//*********************************************************************************************
class CPersona: public CObjeto
{
public:
    CPersona(){};
    CPersona(string nombrec):CObjeto(){

        nombre = nombrec;
    }

    void imprimir();
    virtual void Salvar(fstream &out);
    virtual void Cargar(fstream &in);
    virtual int getAtributoI();
    virtual int GetCLSID();
protected:
    string nombre;

};

void CPersona::imprimir()
{
    cout<<"Persona"<<endl;
    cout<<"Nombre: "<<nombre<<endl;
}

void CPersona::Salvar(fstream &out)
{
    out<<GetCLSID()<<endl;
    out<<nombre<<endl;
}

void CPersona::Cargar(fstream &in)
{
    in>>nombre;
}

int CPersona::getAtributoI()
{

}

int CPersona::GetCLSID()
{
    return CLSID_persona;
}

//*********************************************************************************************
class CEstudiante: public CPersona
{
public:
    CEstudiante(){};
    CEstudiante(string nombrec, int codigoc, int edadc, string carrerac, string lugarNacc):CPersona(nombrec){
        codigo = codigoc;
        edad = edadc;
        carrera = carrerac;
        LugarNac = lugarNacc;
    }

    void imprimir();
    virtual void Salvar(fstream &out);
    virtual void Cargar(fstream &in);
    virtual int getAtributoI();
    virtual int GetCLSID();
protected:
    int codigo;
    int edad;
    string carrera;
    string LugarNac;
};

void CEstudiante::imprimir()
{
    cout<<"Estudiante"<<endl;
    cout<<"Nombre: "<<nombre<<endl
       <<"Codigo: "<<codigo<<endl
      <<"Edad: "<<edad<<endl
     <<"Carrera: "<<carrera<<endl
    <<"Lugar de nacimiento"<<LugarNac<<endl;
}

void CEstudiante::Salvar(fstream &out)
{
    out<<GetCLSID()<<endl;
    out<<nombre<<endl;
    out<<codigo<<endl;
    out<<edad<<endl;
    out<<carrera<<endl;
    out<<LugarNac<<endl;

}

void CEstudiante::Cargar(fstream &in)
{
    in>>nombre;
    in>>codigo;
    in>>edad;
    in>>carrera;
    in>>LugarNac;
}

int CEstudiante::getAtributoI()
{
    return edad;
}

int CEstudiante::GetCLSID()
{
    return CLSID_estudiante;
}

#endif // ESTUDIANTE_H
