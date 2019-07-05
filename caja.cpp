#include "caja.h"
#include <string>

void crear(Caja &caja, int secuenciaActual){
    caja.capMax = secuenciaActual;
    caja.capActual = caja.capMax;
}

void crear(Caja &caja, std::string contenido, int secuenciaActual){
    caja.contenido = contenido;
    caja.capMax = secuenciaActual;
    caja.capActual = caja.capMax;
}

void eliminar(Caja &caja){
    //???;
}

std::string getContenido(Caja &caja){
    return caja.contenido;
}

int getCapMax(Caja &caja){
    return caja.capMax;
}

int getCapActual(Caja &caja){
    return caja.capActual;
}

void setCapActual(Caja &caja, int capActual){
caja.capActual=capActual;
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

void setContenido (Caja &caja, std::string material){
    caja.contenido = material;
}

void setCapMax (Caja &caja, int capMax){
    caja.capMax = capMax;
}
