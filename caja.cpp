#include "caja.h"
#include <string>



void crearCaja(Caja &caja, std::string material, int secuenciaActual){
    caja.material = material;
    caja.capMax = secuenciaActual;
    caja.capActual = caja.capMax;
}

void eliminarCaja(Caja *caja){
    delete caja;
}

void setMaterialCaja (Caja &caja, std::string material){
    caja.material = material;
}

std::string getMaterialCaja(Caja &caja){
    return caja.material;
}

void setCapMaxCaja(Caja &caja, int capMax){
    caja.capMax = capMax;
}

int getCapMaxCaja(Caja &caja){
    return caja.capMax;
}

void setCapActualCaja(Caja &caja, int capActual){
    caja.capActual = capActual;
}

int getCapActualCaja(Caja &caja){
    return caja.capActual;
}

void restarMaterialCaja(Caja &caja, int cantMenos){
    int aux = caja.capActual;
    if(cantMenos < 0){
        aux+=cantMenos;
    }
    else{
        aux-=cantMenos;
    }
    if (aux <= 0){
        eliminarCaja(*caja);
    }
    else
        caja.capActual = aux;
}
