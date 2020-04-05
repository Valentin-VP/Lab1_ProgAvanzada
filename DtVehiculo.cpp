#include "DtVehiculo.h"

DtVehiculo::DtVehiculo(){}
DtVehiculo::DtVehiculo(int a,float b ,float c){
	this->nroSerie=a;
	this->porcentajeBateria=b;
	this->precioBase=c;
}
DtVehiculo::~DtVehiculo(){}
int DtVehiculo::getNroSerie(){
	return nroSerie;
}
float DtVehiculo::getPorcentajeBateria(){
	return porcentajeBateria;
}
float DtVehiculo::getPrecioBase(){
	return precioBase;
}

ostream& operator <<(ostream& sal,const DtVehiculo& v){ 
	cout << " - Numero serie: " << v.nroSerie << endl; 
	cout << " - Porcentaje bateria: " << v.porcentajeBateria << "%" << endl;
	cout << " - Precio base: $" << v.precioBase << endl;
    return sal;
}
