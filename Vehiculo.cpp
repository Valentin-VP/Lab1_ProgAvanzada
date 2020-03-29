#include "Vehiculo.h"

Vehiculo::Vehiculo(){}
Vehiculo::Vehiculo(int nroSerie,float porcentajeBateria,float precioBase){
	this->nroSerie=nroSerie;
	this->porcentajeBateria=porcentajeBateria;

}
Vehiculo::~Vehiculo(){}
void Vehiculo::setNroSerie(int nroSerie){
	this->nroSerie=nroSerie;
}
int Vehiculo::getNroSerie(){
	return this->nroSerie;
}
void Vehiculo::setPorcentajeBateria(float porcentajeBateria){
	this->porcentajeBateria=porcentajeBateria;
}
float Vehiculo::getPorcentajeBateria(){
	return this->porcentajeBateria;
}
void Vehiculo::setPrecioBase(float precioBase){
	this->precioBase=precioBase;
}
float Vehiculo::getPrecioBase(){
	return this->precioBase;
}
float Vehiculo::darPrecioViaje(int,int){
	
}
//falta darPrecio



