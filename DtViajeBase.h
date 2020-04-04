#ifndef DTVIAJEBASE
#define DTVIAJEBASE
#include "DtFecha.h"
#include<iostream>
using namespace std;

class DtViajeBase{
    private:
        int duracion;
        int distancia;
        DtFecha fecha;

    public: 
        DtViajeBase();
        DtViajeBase(int,int,DtFecha);
        ~DtViajeBase();
        int getDuracion();
        int getDistancia();
		DtFecha getFecha();
        
        friend ostream& operator <<(ostream&,const DtViajeBase&);
};
#endif 