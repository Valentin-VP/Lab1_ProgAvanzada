#include "DtFecha.h"
#include<iostream>
using namespace std;

DtFecha::DtFecha(){}
DtFecha::DtFecha(int dia,int mes,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}
DtFecha::~DtFecha(){}

void DtFecha::setDia(int dia){
    this->dia=dia;
}
int DtFecha::getDia(){
    return this->dia;
}

void DtFecha::setMes(int mes){
    this->mes=mes;
}
int DtFecha::getMes(){
    return this->mes;
}

void DtFecha::setAnio(int anio){
    this->anio=anio;
}
int DtFecha::getAnio(){
    return this->anio;
}

ostream& operator <<(ostream& sal,DtFecha& f){ //impime fecha el cout
    cout << f.dia << "/" << f.mes << "/" << f.anio;
    return sal;
}

// pendiente de revisión -Rodrigo-
bool operator <(const DtFecha& f1,const DtFecha& f2){
	//Compara si f1 es anterior a f2
	bool ret;
	if (f1.anio < f2.anio){
		ret=true;
	}else if(f1.anio == f2.anio){
		if (f1.mes < f2.mes){
			ret=true;
		}else if(f1.mes == f2.mes){
			if (f1.dia < f2.dia){
				ret=true;
			}else{ 
				ret=false;
			}
		}
	}
	return ret;
}