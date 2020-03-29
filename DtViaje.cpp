#include "DtViaje.h"
#include "DtVehiculo.h"

    DtViaje::DtViaje(){}
    DtViaje::DtViaje(int d,int n,DtFecha f, float precioTotal,DtVehiculo* vehiculo):DtViajeBase(d,n,f){
        this->precioTotal=precioTotal;
        this->vehiculo=vehiculo;
    }
    DtViaje::~DtViaje(){}

    void DtViaje::setPrecioTotal(float precioTotal){
        this->precioTotal=precioTotal;
    } 
    float DtViaje::getPrecioTotal(){
        return this->precioTotal;
    }
    void DtViaje::setVehiculo(DtVehiculo* vehiculo){
        this->vehiculo=vehiculo;
    }
    DtVehiculo* DtViaje::getVehiculo(){
        return this->vehiculo;
    }