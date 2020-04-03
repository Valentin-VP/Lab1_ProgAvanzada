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
ostream& operator <<(ostream& sal,DtVehiculo& v){ //imprime los datos de v
	cout << "Número serie: " << v.nroSerie << "\n" 
	"Porcentaje bateria: " << v.porcentajeBateria << "\n"
	"Precio base: $: " << v.precioBase << endl;
    return sal;
}