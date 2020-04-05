#include <iostream>
#include "DtViajeBase.h"

using namespace std;

DtViajeBase::DtViajeBase(){}
DtViajeBase::DtViajeBase(int d,int n,DtFecha f){
	this->duracion=d;
	this->distancia=n;
	this->fecha=f;
}
DtViajeBase::~DtViajeBase(){}

int DtViajeBase::getDuracion(){
	return this->duracion;
}
int DtViajeBase::getDistancia(){
	return this->distancia;
}
DtFecha DtViajeBase::getFecha(){
	return this->fecha;
}
ostream& operator <<(ostream& salida,const DtViajeBase& dtc){
	cout << "Fecha: " << dtc.fecha <<  endl;
	cout << "Duracion: " << dtc.duracion << endl;
	cout << "Distancia: " << dtc.distancia << endl; 
	return salida;
}
