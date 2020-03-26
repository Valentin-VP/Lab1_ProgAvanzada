#include "DtViajeBase.h"

DtViajeBase::DtViajeBase(){}
DtViajeBase::DtViajeBase(int d,int n,DtFecha f){
	this->duracion=d;
	this->distancia=n;
	this->fecha=f;
}
DtViajeBase::~DtViajeBase(){}

void DtViajeBase::setDuracion(int d){
	this->duracion=d;
}
int DtViajeBase::getDuracion(){
	return this->duracion;
}
void DtViajeBase::setDistancia(int n){
	this->distancia=n;
}
int DtViajeBase::getDistancia(){
	return this->distancia;
}
void DtViajeBase::setFecha(DtFecha f){
	this->fecha=f;
}
DtFecha DtViajeBase::getFecha(){
	return this->fecha;
}