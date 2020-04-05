#include "Usuario.h"
#include<iostream>
using namespace std;

Usuario::Usuario(){}
Usuario::Usuario(string c,string n,DtFecha f){
	this->cedula=c;
	this->nombre=n;
	this->fechaIngreso=f;
	this->topeViajes=0;
}
Usuario::~Usuario(){}
void Usuario::setCedula(string c){
	this->cedula=c;
}
string Usuario::getCedula(){
	return this->cedula;
}
void Usuario::setNombre(string n){
	this->nombre=n;
}
string Usuario::getNombre(){
	return this->nombre;
}
void Usuario::setFechaIngreso(DtFecha f){
	this->fechaIngreso=f;
}
DtFecha Usuario::getFechaIngreso(){
	return this->fechaIngreso;
}

int Usuario::getTopeViajes(){
	return this->topeViajes;
}

void Usuario::setTopeViajes(int a){
	this->topeViajes=a;
}

void Usuario::agregarViaje(Viaje* v){
	this->viajes[this->topeViajes]=v;
	this->topeViajes++;
}

Viaje** Usuario::obtenerViaje(){
	Viaje** todos_viajes = new Viaje*[this->topeViajes];
	for(int i=0; i<this->topeViajes;i++)
		todos_viajes[i]=this->viajes[i];
	return todos_viajes;
}


ostream& operator <<(ostream& sal,const Usuario& u){
	cout << "Cedula: " << u.cedula << endl << "Nombre: " << u.nombre << endl << "Fecha: " << u.fechaIngreso;
}
