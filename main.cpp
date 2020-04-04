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

void existeUsuario(string ci);
Usuario* obtenerUsuario (string);
void ingresarViaje();
void ingresarViaje(string ci,int nroSerie,DtViajeBase& viajeB);
void verViajesAntesDeFecha();
DtViaje** verViajesAntesDeFecha(DtFecha&,string,int&);
void agregarVehiculo();
void agregarVehiculo(DtVehiculo& Vehiculo);
void existeVehiculo(int);
void porcentajeValido(float);
void precioBaseValido(float);
void valorPositivo(int);
void fechaValida(DtFecha,string);

Usuario* obtenerUsuario(string ci){  //esta bien?
	try{
		existeUsuario(ci);
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
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
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
	cout <<"______________________________________________" <<endl;
	cout <<"____R E G I S T R O__D E__V E H I C U L O_____"<< endl;
    int nroSerie;
	float porcentajeBateria;
	float precioBase;
	DtVehiculo* dtvehiculo;	
           
	
    try{
		
		cout << "Nro de Serie: " << endl;
		cin >> nroSerie;		
		existeVehiculo(nroSerie);// 1 -Vehiculo ya registrado
        

		cout <<"\nPorcentaje Batería: " << endl;
		cin >> porcentajeBateria;
        porcentajeValido(porcentajeBateria);// 2 - Porcentaje en valor entre 0 y 100


        cout <<"\nPrecio Base: " << endl;
		cin >> precioBase;
        precioBaseValido(precioBase);// 3 - Precio base positivo
       
		dtvehiculo = new DtVehiculo(nroSerie,porcentajeBateria,precioBase);		
			

		agregarVehiculo(dtvehiculo);
		
        
    }catch (invalid_argument& e){
        //YA EXISTE EL VEHICULO, PORCENTAJE INVALIDO O 
        cout << e.what() << endl;
    }
}

void agregarVehiculo(DtVehiculo& Vehiculo){

	if(Bicicleta* bici=dynamic_cast<Bicicleta*>(dtvehiculo)){

		DtBicicleta* dtbici=new Bicicleta(bici->getNroSerie(),bici->getPorcentajeBateria(),bici->getPrecioBase(),bici->getTipo(),bici->getCantCambios());
		dtvehiculo = dtbici;

	}else if(Monopatin* mono=dynamic_cast<Monopatin*>(dtvehiculo)){
		
		DtMonopatin* dtmono=new Monopatin(mono->getNroSerie(),mono->getPorcentajeBateria(),mono->getPrecioBase(),mono->getTipo(),mono->getTieneLuces());
		dtvehiculo = dtmono;

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
	cout << "Ingrese numero de serie del vehiculo ";
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
		valorPositivo(duracion);
		valorPositivo(distancia);
		fechaValida(fecha, ci);
		viajeB=DtViajeBase(duracion,distancia,fecha);
		// ingresarViaje(ci,nroSerie,viajeB); //Llamada a ingresarViaje con los parametros listos

	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
void valorPositivo(int d){
	if(d<=0)
		throw invalid_argument("El valor debe ser positivo\n");
}

void fechaValida(DtFecha f, string ci){
	Usuario* user = obtenerUsuario(ci);
	if(f < user->getFechaIngreso())
		throw invalid_argument("La fecha del viaje debe ser posterior o igual a la fecha de ingreso del usuario\n");
}

// void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viajeB){
// 	try{
// 		Usuario* usuario = obtenerUsuario(ci);
// 		Vehiculo* vehiculo = obtenerVehiculo(nroSerie);
// 		//usuario->ingresarViaje()
// 		DtViaje* dtv = new DtViaje(darPrecioViaje(viajeB.getDuracion(),viajeB.getDistancia()),vehiculo);
// 		Viaje v = new Viaje(dtv.getDuracion(),dtv.getDistancia(),viajeB.getFecha());


// 	}catch(){

// 	}

// }


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
    cout << "Anio: ";
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

bool igualFecha(DtFecha f1,DtFecha f2){ //ve si una fecha es igual a la otra
	if(f1.getDia()==f2.getDia()){
		if(f1.getMes()==f2.getMes()){
			if(f1.getAnio()==f2.getAnio())
				return true;
			else
				return false;
		}else
			return false;
	}else
		return false;
}

bool existeViaje(string ci,DtFecha& fecha){ //ve si el usuario ci tiene un viaje en esa fecha
	Usuario* user = obtenerUsuario(ci);
	bool encontro;
	int i=0;
	while((!encontro)&&(i < user->getTopeViajes())){
		if(igualFecha(user->obtenerViaje[i]->getFecha(), fecha))
			encontro=true;
		else
			i++;
	}
	if(encontro)
		return true;
	else 
		return false;
}

void eliminarViajes(string ci, DtFecha& fecha){   //ejercicio e sin comprobar si funciona
	try{
		existeUsuario(ci);
		int i=0,f=0;
		bool encontroUser=false,encontroFecha=false;
		while((!encontroUser)||(i<coleccionUsuarios.tope)){
        	if(ci!=coleccionUsuarios.usuarios[i]->getCedula())
				i++;
			else{
				encontroUser=true;
				while(existeViaje(ci,fecha)){	
					while((!encontroFecha)||(i<coleccionUsuarios.usuarios[i]->getTopeViajes())){
						if(!igualFecha(fecha,coleccionUsuarios.usuarios[i]->obtenerViaje[f]))//PUEDEN SER IGUALES LAS FECHAS? O SON OBJETOS CON IDENTIDAD PROPIA
							f++;
						else{
							while(coleccionUsuarios.usuarios[i]->getTopeViajes > f+1){
								coleccionUsuarios.usuarios[i]->obtenerViaje[f]=coleccionUsuarios.usuarios[i]->obtenerViaje[f+1];
								f++;
							}	
						}
					}
				}
			}
		}
	}catch (invalid_argument& e){
		cout << e.what() << endl;
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
			case 1: //registrarUsuario();
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
        

    //Llamada a operacion D desde el main.
    verViajesAntesDeFecha();
    //Llamada a operacion B desde el main.
    agregarVehiculo();
*/
int a=0,i=0;
	while(a==0){
		registrarUsuario();
		cout << endl;
		cin >> a;
		cout << *coleccionUsuarios.usuarios[i] << endl;
	}
    return 0;
}
