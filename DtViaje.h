#ifndef DTVIAJE
#define DTVIAJE
#include "DtVehiculo.h"
#include "DtViajeBase.h"

class DtViaje: public DtViajeBase{
    private:
        float precioTotal;
        DtVehiculo* vehiculo;
    public:
        DtViaje();
        DtViaje(int, int, DtFecha, float ,DtVehiculo*);
        ~DtViaje();

        void setPrecioTotal(float);
        float getPrecioTotal();
        void setVehiculo(DtVehiculo*);
        DtVehiculo* getVehiculo();

        //Falta implementar sobrecarga de impresion con el operador <<
};
#endif