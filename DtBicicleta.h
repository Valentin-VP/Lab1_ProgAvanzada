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
        void setTipoBici(TipoBici);	//No seria necesario
        int getCantCambios();
        void setCantCambios(int);	//No seria necesario

        ~DtBicicleta();
        float darPrecioViaje(int,int);		//No seria necesario
        
        friend ostream& operator <<(ostream& sal, const DtBicicleta& b); //imprime datos de b
};
#endif