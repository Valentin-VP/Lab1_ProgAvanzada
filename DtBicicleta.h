#ifndef DTBICICLETA
#define DTBICICLETA
#include "DtVehiculo.h"
#include "TipoBici.h"
#include <iostream>
using namespace std;

class DtBicicleta: public DtVehiculo{
    private:
        TipoBici tipo;
        int cantCambios;
    public:
        DtBicicleta();
        DtBicicleta(int, float, float, TipoBici,int);
        
        TipoBici getTipoBici();
        void setTipoBici(TipoBici);
        int getCantCambios();
        void setCantCambios(int);

        ~DtBicicleta();
        float darPrecioViaje(int,int);
        friend ostream& operator <<(ostream& sal, const DtBicicleta& b); //imprime datos de b
};
#endif