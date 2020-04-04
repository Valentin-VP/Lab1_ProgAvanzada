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
        float getPrecioTotal();
        DtVehiculo* getVehiculo();

        friend ostream& operator <<(ostream&,const DtViaje&);
};
#endif