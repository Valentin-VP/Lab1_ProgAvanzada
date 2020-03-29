#include "Viaje.h"

Viaje::Viaje(){}
Viaje::Viaje(int d,int n,DtFecha f, Vehiculo* v){
	this->duracion=d;
	this->distancia=n;
	this->fecha=f;
	this->vehiculo=v;
}
Viaje::~Viaje(){}

void Viaje::setDuracion(int d){
	this->duracion=d;
}
int Viaje::getDuracion(){
	return this->duracion;
}
void Viaje::setDistancia(int n){
	this->distancia=n;
}
int Viaje::getDistancia(){
	return this->distancia;
}
void Viaje::setFecha(DtFecha f){
	this->fecha=f;
}
DtFecha Viaje::getFecha(){
	return this->fecha;
}

Vehiculo* Viaje::getVehiculo(){
	return this->vehiculo;
}