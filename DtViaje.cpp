#include "DtViaje.h"
#include "DtVehiculo.h"

    DtViaje::DtViaje(){}
    DtViaje::DtViaje(int d,int n,DtFecha f, float precioTotal,DtVehiculo* vehiculo):DtViajeBase(d,n,f){
        this->precioTotal=precioTotal;
        this->vehiculo=vehiculo;
    }
    DtViaje::~DtViaje(){}

    float DtViaje::getPrecioTotal(){
        return this->precioTotal;
    }
    DtVehiculo* DtViaje::getVehiculo(){
        return this->vehiculo;
    }

    ostream& operator <<(ostream& salida,const DtViaje& dtf){ 
        cout << (DtViajeBase) dtf <<
        "Precio viaje: " << 
        dtf.precioTotal << "/" <<
        dtf.vehiculo <<endl;
        return salida;
    }