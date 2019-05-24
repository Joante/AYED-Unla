#include "archivo.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>


using namespace std;

/*
recibe la clave y el valor a agregar en parametro, compara la clave
con una lista de claves y dependiendo cual agrega ese valor a cierta variable
en parametro
*/


int stringToInt(string valor){
    int aux;
    istringstream iss (valor);
    iss >> aux;
    return aux;
}


void agregarParametro(Parametro &parametro, string clave, string valor){
 /*   int aux;
    istringstream iss (valor);
    iss >> aux; */
    if (clave == "s" || clave == "S")
        parametro.segundosIntervalo = stringToInt(valor);
    else if (clave == "p" || clave == "P")
        parametro.pillageMax = stringToInt(valor);
    else if (clave == "a" || clave == "A")
        parametro.AreaDeBandido = stringToInt(valor);
    else if (clave == "posXE")
        parametro.posXEstacion = stringToInt(valor);
    else if (clave == "posYE")
        parametro.posYEstacion = stringToInt(valor);
    else if (clave == "im" || clave == "iM" || clave == "Im" || clave == "IM")
        parametro.intervaloMoneda = stringToInt(valor);
    else if (clave == "vm" || clave == "vM" || clave == "Vm" || clave == "VM")
        parametro.vidaMoneda = stringToInt(valor);
    else if (clave == "ib" || clave == "iB" || clave == "Ib" || clave == "IB")
        parametro.intervaloBandido = stringToInt(valor);
    else if (clave == "vb" || clave == "vB" || clave == "Vb" || clave == "VB")
        parametro.vidaBandido = stringToInt(valor);

    }

Parametro readParametros(){
    Parametro lectura;
    string clave,valor;
    ifstream parametros;
    parametros.open("Parametros.txt");
    if(parametros.fail()){
        cerr << "File Parametros.txt failed to open";
        exit(EXIT_FAILURE);
    }
    while(!parametros.eof()){
        getline(parametros,clave,'=');
        getline(parametros,valor);
        agregarParametro(lectura,clave,valor);
    }
    parametros.close();
    return lectura;
}

void agregarComanda(Comanda &comanda, string codItem, string cantidad){
 /*   int aux;
    istringstream iss (cantidad);
    iss >> aux;*/
    if (codItem == "oro")
        comanda.oro = stringToInt(cantidad);
    else if (codItem == "plata")
        comanda.plata = stringToInt(cantidad);
    else if (codItem == "bronce")
        comanda.bronce = stringToInt(cantidad);
    else if (codItem == "carbon")
        comanda.carbon = stringToInt(cantidad);
    else if (codItem == "platino")
        comanda.platino = stringToInt(cantidad);
    else if (codItem == "roca")
        comanda.roca = stringToInt(cantidad);
}

Comanda readComanda(){
    Comanda lectura;
    string codItem;
    string cantidad;
    ifstream comand;
    comand.open("comanda.txt");
    if(comand.fail()){
        cerr << "File 'Comanda.txt' failed to open";
        exit(EXIT_FAILURE);
    }
    while(!comand.eof()){
        getline(comand,codItem,';');
        getline(comand,cantidad);
        agregarComanda(lectura,codItem,cantidad);
    }
    comand.close();
    return lectura;
}

void addNodo(Nodo* &lista, Mina datos){     //F in the chat for me
    Nodo* nuevo = new Nodo();
    nuevo->dato = datos;    //es lo mismo que *nuevo.dato = datos;
    Nodo* aux1 = lista.siguiente;
    Nodo* aux2;
    while (aux1!= null){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    nuevo->siguiente=aux1;

}



Nodo* readMina(){       //implementar listas
    Nodo* listaMina = new Nodo();
    listaMina.siguiente = null;
    ifstream mina;
    string aux;
    Mina auxiliar;
    mina.open("mina.txt");
    if(mina.fail()){
        cerr<< "File 'mina.txt' failed to open";
        exit(EXIT_FAILURE);
    }
    while(!mina.eof()){
        getline(mina,aux,';');
        auxiliar.posX = stringToInt(aux);
        getline(mina,aux,';');
        auxiliar.posY = stringToInt(aux);
        getline(mina,aux,';');
        auxiliar.codItem = aux;
        getline(mina,aux,';');
        auxiliar.intervaloProduccion = stringToInt(aux);
        getline(mina,aux,';');
        auxiliar.listaSecuencia[0] = stringToInt(aux);
        getline(mina,aux,';');
        auxiliar.listaSecuencia[1] = stringToInt(aux);
        getline(mina,aux,';');
        auxiliar.listaSecuencia[2] = stringToInt(aux);
        getline(mina,aux,';');
        auxiliar.listaSecuencia[3] = stringToInt(aux);
        getline(mina,aux);
        auxiliar.listaSecuencia[4] = stringToInt(aux);
        addNodo(listaMina,auxiliar);                        //THIS DOESN'T FUCKING WORK GG
    }
    return listaMina;
}

void crear(ArchivoGral &archivoGral){
    archivoGral.parametro = readParametros();
    archivoGral.comanda = readComanda();
    archivoGral.listaMina = readMina();
}

void eliminar(ArchivoGral &archivoGral){
    //eliminar parametros? comanda? y la lista?
}

void getListaMina(ArchivoGral &archivoGral, Mina* listaMina){
    listaMina = archivoGral.listaMina;
}


void getIntervaloSegundos(ArchivoGral &archivoGral, int &segundos){
    segundos = archivoGral.parametro.segundosIntervalo;
}


void getPosicionEstacion(ArchivoGral &archivoGral,int& posX, int& posY){
    posX = archivoGral.parametro.posXEstacion;
    posY = archivoGral.parametro.posYEstacion;
}


void getAreaBandido(ArchivoGral &archivoGral,int& area){
    area = archivoGral.parametro.AreaDeBandido;
}


void getIntervaloBandido(ArchivoGral &archivoGral,int& intervalo){
    intervalo = archivoGral.parametro.intervaloBandido;
}


void getVidaBandido(ArchivoGral &archivoGral,int& vida){
    vida = archivoGral.parametro.vidaBandido;
}


void getPillageBandido(ArchivoGral &archivoGral,int& pillage){
    pillage = archivoGral.parametro.pillageMax;
}


void getIntervaloMoneda(ArchivoGral &archivoGral,int& intervalo){
    intervalo = archivoGral.parametro.intervaloMoneda;
}


void getVidaMoneda(ArchivoGral &archivoGral,int& vida){
    vida =  archivoGral.parametro.vidaMoneda;
}

void getComandaDe(ArchivoGral &archivoGral, int& com, string nombre){
    if (nombre == "oro")
        com = archivoGral.comanda.oro;
    else if (nombre == "plata")
        com = archivoGral.comanda.plata;
    else if (nombre == "bronce")
        com = archivoGral.comanda.bronce;
    else if (nombre == "carbon")
        com = archivoGral.comanda.carbon;
    else if (nombre == "platino")
        com = archivoGral.comanda.platino;
    else if (nombre == "roca")
        com = archivoGral.comanda.roca;
}
