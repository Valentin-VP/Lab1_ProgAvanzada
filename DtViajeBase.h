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

        void setDuracion(int);
        int getDuracion();

        void setDistancia(int);
        int getDistancia();

        void setFecha(DtFecha);
		DtFecha getFecha();
        
        friend ostream& operator <<(ostream&,DtViajeBase&);
};
#endif 