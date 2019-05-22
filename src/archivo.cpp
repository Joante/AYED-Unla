#include "archivo.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void agregarParametro(Parametro &parametro, string clave, string valor){

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

void agregarComanda(Comanda &comanda, string codItem, int cantidad){

}

Comanda readComanda(){
    Comanda lectura;
    string codItem;
    int cantidad;
    ifstream comand;
    comand.open("Comanda.txt");
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

Mina* readMina(){
    Mina* listaMina = new Mina;  //this is fucking wrong
    return listaMina;
}

void crear(ArchivoGral &archivoGral){
    archivoGral.parametro = readParametros();
    archivoGral.comanda = readComanda();
    archivoGral.listaMina = readMina();
}

void eliminar(ArchivoGral &archivoGral){
    //eliminar parametros? comanda? y la lista?
    delete archivoGral;
}

void getListaMina(ArchivoGral &archivoGral, Mina* listaMina){
    listaMina = archivoGral.listaMina;
}


void getIntervaloSegundos(ArchivoGral &archivoGral, float &segundos){
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

