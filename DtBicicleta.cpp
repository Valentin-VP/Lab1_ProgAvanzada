#include "DtBicicleta.h"
#include "TipoBici.h"
#include "DtVehiculo.h"

DtBicicleta::DtBicicleta(){}

DtBicicleta::DtBicicleta(int a, float b, float c, TipoBici tipoB, int cambios):DtVehiculo(a,b,c){
    this->tipo = tipoB;
    this->cantCambios = cambios;
}


DtBicicleta::~DtBicicleta(){}

TipoBici DtBicicleta::getTipoBici(){
    return this->tipo;
}


int DtBicicleta::getCantCambios(){
    return this->cantCambios;
}


ostream& operator <<(ostream& sal, const DtBicicleta& b){ //imprime los datos de m
    string tipo[2]={"Paseo","Montaña"};
	cout << (DtVehiculo) b << "\n" 
	"Tipo de Bicicleta: " << tipo[b.tipo] << "\n" 
    "Cantidad de Cambios: " << b.cantCambios << endl;
  	return sal;
}