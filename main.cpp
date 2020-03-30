#include <stdio.h>
#include <iostream>
#include <stdexcept> //funcion invaid_argument
#include <stdlib.h> //funcion system
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
#define MAX_VEHICULOS 100

struct{
	Usuario* usuarios[MAX_USER];
	int tope;
} coleccionUsuarios;

struct{
	Vehiculo* vehiculos[MAX_VEHICULOS];
	int tope;
} coleccionVehiculos;

Usuario* obtenerUsuario (string);
void ingresarViaje();
void ingresarViaje(string ci,int nroSerie,DtViajeBase& viajeB);
void verViajesAntesDeFecha();
DtViaje** verViajesAntesDeFecha(DtFecha&,string,int&);
void agregarVehiculo();
void agregarVehiculo(DtVehiculo&);
void existeVehiculo(int);
void porcentajeValido(float);
void precioBaseValido(float);


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

void existeUsuario(string ci){
    int i=0;
    bool existe=false;
    while((!existe)&&(i<coleccionUsuarios.tope)){
        if(ci==coleccionUsuarios.usuarios[i]->getCedula())
            existe=true;
        else
            i++;
        }
        if(existe)
            throw invalid_argument("ERROR: YA EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

void registrarUsuario(){ //funcionando ***FALTA MANEJO DE EXCEPCION USANDO TRY CATCH***
    string ci, nombre;
	int d, m, y;
    cout << "Cedula: ";
    cin >> ci;
    try{
        existeUsuario(ci);
        cout << "Nombre: ";
        cin >> nombre;
		cout << "Fecha de registro" << endl << "Dia: ";
		cin >> d;
		cout << "Mes: ";
		cin >> m;
		cout << "Anio: ";
		cin >> y; 
        DtFecha* fecha = new DtFecha(d,m,y);
        Usuario* u=new Usuario(ci,nombre,*fecha);
        coleccionUsuarios.usuarios[coleccionUsuarios.tope] = u;
        coleccionUsuarios.tope++;
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}
 
void agregarVehiculo(){
    system("clear");
    //Interfaz con el usuario
    	int nroSerie;
		float porcentajeBateria;
		float precioBase;
        DtVehiculo vehiculo; //REVISAR
        //Controles requeridos: 1-No existe un vehiculo con el mismo numero de serie
    try{
        existeVehiculo(nroSerie);
        // 2 - Porcentaje en valor entre 0 y 100
        porcentajeValido(porcentajeBateria);
        // 3 - Precio base positivo
        precioBaseValido(precioBase);
        // Se agrega vehiculo a coleccionVehiculos
        
    }catch (invalid_argument& e){
        //YA EXISTE EL VEHICULO, PORCENTAJE INVALIDO O 
        cout << e.what() << endl;
    }
}

void precioBaseValido(float pb){
    if(pb<=0)
        throw invalid_argument("Precio base inválido; debe ser mayor a 0\n");
}
void porcentajeValido(float pb){
    if((pb<0)||(pb>100))
        throw invalid_argument("Valor de batería inválido\n");
}
void existeVehiculo(int nroSerie){
    int i=0;
    // bool existe=true;
    while(i<coleccionVehiculos.tope){//&&(existe)){
        if(nroSerie==coleccionVehiculos.vehiculos[i]->getNroSerie())
            throw invalid_argument("Ya existe ese vehículo\n");
        i++;
    }
}


// Operacion ingresarViaje

void ingresarViaje(){
	string ci;
	int nroSerie;
	DtViajeBase viajeB;
	DtFecha fecha;
	int dia, mes, anio, duracion, distancia;
	cout << "Ingrese su cedula: ";
	cin >> ci;
	cout << "Ingrese numero de serie del vehiculo" << endl;
	cin >> nroSerie;
	try{
		existeUsuario(ci);
		existeVehiculo(nroSerie);
		cout <<  "Ingrese dia: ";
		cin >> dia;
		cout << "Ingrese mes: ";
		cin >> mes;
		cout << "Ingrese anio: ";
		cin >> anio;
		fecha=DtFecha(dia,mes,anio);
		cout << "Ingrese la duracion del viaje: ";
		cin >> duracion;
		cout << "Ingrese la distancia del viaje: ";
		cin >> distancia;
		if(duracion > 0 && distancia > 0){
			darPrecioViaje();
			viajeB=DtViajeBase(duracion,distancia,fecha);
			ingresarViaje(ci,nroSerie,viajeB);
		}else{
			cout << "La distancia y duracion deben ser mayor a 0";
		}

	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}

void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viajeB){
	try{
		Usuario* usuario = obtenerUsuario(ci);
		Vehiculo* vehiculo = obtenerVehiculo(nroSerie);
		//usuario->ingresarViaje()
		DtViaje* dtv = new DtViaje(darPrecioViaje(viajeB.getDuracion(),viajeB.getDistancia()),vehiculo);
		Viaje v = new Viaje(dtv.getDuracion(),dtv.getDistancia(),viajeB.getFecha());


	}catch(){

	}

}


//Fin Operacion ingresarViaje


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
            if(viajes[i]->getFecha()<fecha){

            }
        }



}

 
int main(){
    /*
    int opcion;

	system("clear");
	cout << "Bienvenido. Elija la opción." << endl;
	cout << "1) Registrar usuario" << endl;
	cout << "2) Agregar vehículo" << endl;
	cout << "3) Ingresar viaje" << endl;
	cout << "4) Ver viajes antes de.." << endl;
	cout << "5) Eliminar viajes" << endl;
	cout << "6) Cambiar bateria vehículo" << endl;
	cout << "7) Obtener vehículos" << endl;
	cout << "0) Salir" << endl;
	cout << "Opción:";
	cin >> opcion;
		switch(opcion){
			case 1: //registrarUsuario(ci,nombre);
				break;
			case 2: //agregarVehiculo(vehiculo);
				break;
			case 3: //ingresarViaje();
				break;
			case 4: //verViajesAntesDeFecha(fecha,ci,cantViajes);
				break;
			case 5: //eliminarViajes(ci,fecha);
				break;
			case 6: //cambiarBateriaVehiculo(nroSerieVehiculo,cargaVehiculo);
				break;
			case 7: //obtenerVehiculos(cantVehiculos);
				break;
			case 0: system("exit");
				break;
			default:
				cout << "Opción incorrecta" << endl;
		}
        */

    //Llamada a operacion D desde el main.
    verViajesAntesDeFecha();
    //Llamada a operacion B desde el main.
    agregarVehiculo();

    return 0;
}
