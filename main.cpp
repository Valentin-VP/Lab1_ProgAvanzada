#include <stdio.h>
#include <iostream>
#include <ctime>
#include "Bicicleta.h"
#include "DtBicicleta.h"
#include "DtFecha.h"
#include "DtMonopatin.h"
#include "DtVehiculo.h"
#include "DtViajeBase.h"
#include "Monopatin.h"
#include "TipoBici.h"
#include "Usuario.h"
#include "Vehiculo.h"
#include "Viaje.h"
#include "DtViaje.h"

using namespace std;
#define MAX_USER 30

struct{
	Usuario* usuarios[MAX_USER];
	int tope;
} coleccionUsuarios;

Usuario* obtenerUsuario (string);
void verViajesAntesDeFecha();
DtViaje** verViajesAntesDeFecha(DtFecha&,string,int&);

Usuario* obtenerUsuario(string ci){ //falta probar
    Usuario* user;
	bool existe=false;
	int i=0;
	while((i<coleccionUsuarios.tope)&&(!existe)){
		if(ci==coleccionUsuarios.usuarios[i]->getCedula()){
			user=coleccionUsuarios.usuarios[i];
			existe=true;
		}
		i++;
	}
	return user;
}


void registrarUsuario(){ //funcionando
    string ci, nombre;
    cout << "Cedula: ";
    cin >> ci;
    bool existe=false;
    int i=0;
    while((!existe)&&(i<coleccionUsuarios.tope)){
        if(ci==coleccionUsuarios.usuarios[i]->getCedula())
            existe=true;
        else
            i++;
    }
    if(existe){
        cout << "Usuario ya registrado" << endl;
    }else{    
        cout << "Nombre: ";
        cin >> nombre;
        DtFecha* fecha = new DtFecha(27,3,2020);
        Usuario* u=new Usuario(ci,nombre,*fecha);
        coleccionUsuarios.usuarios[coleccionUsuarios.tope] = u;
        coleccionUsuarios.tope++;
    }
}
 
 
// DtViaje ---> Rodrigo -en proceso-
// Bloque de codigo cuando se solicita imprimir Viajes -- OPERACION verViajesAntesDe
void verViajesAntesDeFecha(){
    system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"V I A J E S   D E L   U S U A R I O"<< endl;
	string ci;
	int dia,mes,anio,cantViajes=0;
    DtFecha dtFecha;
    cout << "CI: ";
	cin >> ci;
    cout << "Visualizar viajes antes de la fecha: "<<endl;
    cout << "Dia: ";
	cin >> dia;
    cout << "Mes: ";
	cin >> mes;
    cout << "Año: ";
	cin >> anio;
    dtFecha = DtFecha(dia,mes,anio);
    DtViaje** viajes= verViajesAntesDeFecha(dtFecha, ci, cantViajes);
    for (int i=0; i<cantViajes; i++)
        cout << "\n" << *(viajes[i]);
}

DtViaje** verViajesAntesDeFecha (DtFecha& fecha, string ci, int& cantViajes){
    // Devuelve un arreglo con información detallada de los viajes realizados por el usuario antes de cierta fecha. Para poder implementar esta operación
    // se deberá sobrecargar el operador < del tipo de datos DtFecha.
    // cantViajes es un parámetro de salida donde se devuleve la cantidad de viajes encontrados (correspobnde a la cantidad de valores DtViajes que se devuelven)
    // Se espera una salida con el formato:

    // Viajes encontrados antes de @fecha: @cantViajes

    // Fecha: 25/1/19  10 minutos  3.5 Km

    Usuario* user = obtenerUsuario(ci); //considerar que puede devolver un objeto nulo
        if(cantViajes>user->getTopeViajes())
            cantViajes=user->getTopeViajes();
        Viaje** viajes=user->obtenerViaje(); //copia todos los viajes del usuario en el arreglo de punteros Viaje viajes
        DtViaje** dtViajes = new DtViaje*[MAX_VIAJES];
        DtViaje* dtViaje;
        DtVehiculo* dtVehiculo;
        int i=0;
        cout << "Viajes Realizados: " << endl;
        while (i<user->getTopeViajes()){
            if(viajes[i]->getFecha()<fecha){
                dtVehiculo= new DtVehiculo (viajes[i]->getVehiculo()->getNroSerie(),viajes[i]->getVehiculo()->getPorcentajeBateria(),viajes[i]->getVehiculo()->getPrecioBase());
                dtViaje= new DtViaje(viajes[i]->getDuracion(),viajes[i]->getDistancia(),viajes[i]->getFecha(),(viajes[i]->getVehiculo())->getPrecioBase(),dtVehiculo); //falta solucionar
                cantViajes++;
            }
        }
        for(int i=0; i<user->getTopeViajes;i++){
            if(viajes[i]->getFecha()<fecha)

        }



}

 
int main(){
    //Llamada a operacion D desde el main.
    verViajesAntesDeFecha();
}
