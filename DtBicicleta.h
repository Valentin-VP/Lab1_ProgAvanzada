#ifndef DTBICICLETA
#define DTBICICLETA
#include "DtVehiculo.h"
#include "TipoBici.h"
using namespace std;

class DtBicicleta: public DtVehiculo{
    private:
        TipoBici tipo;
        int cantCambios;
    public:
        DtBicicleta();
        DtBicicleta(TipoBici,int);
        
        TipoBici getTipoBici();
        void setTipoBici(TipoBici);
        int getCantCambios();
        void setCantCambios(int);

        ~DtBicicleta();
        float darPrecioViaje(int,int);
};
#endif