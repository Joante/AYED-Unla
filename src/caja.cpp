#include "caja.h"


void crear(Caja &caja, string contenido, int secuenciaActual){
    caja.contenido = contenido;
    caja.capMax = secuenciaActual;
    caja.capActual = caja.capMax;
}

void eliminar(Caja &caja){
    delete caja;
}

string getContenido(Caja &caja){
    return caja.contenido;
}

int getCapMax(Caja &caja){
    return caja.capMax;
}

int getCapActual(Caja &caja){
    return caja.capActual;
}

int restarContenido(Caja &caja, int menos){
    int aux = caja.capActual;
    if(menos < 0)
        aux+=menos;
    else
        aux-=menos;
    if (aux <= 0)
        caja.capActual = 0;
    else
        caja.capActual = aux;
    return aux;
}
