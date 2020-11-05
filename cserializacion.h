#ifndef CSERIALIZACION_H
#define CSERIALIZACION_H

#include <fstream>
#include <iostream>

using namespace std;

class CSerializacion{
public:
    virtual void Salvar(fstream &out) = 0;
    virtual void Cargar(fstream &in) = 0;
    virtual int GetCLSID() = 0;
};


#endif // CSERIALIZACION_H
