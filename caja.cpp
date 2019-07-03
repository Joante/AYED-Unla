#include <iostream>
#include "caja.h"
#include <string>
#include <iostream>
 #include <cstdlib>

using namespace std;


void crearCaja(Caja &caja){
    caja.material = ' ';
    caja.capMax = 0;
    caja.capActual = 0;
}
void construirCaja (Caja &caja, std::string material, int capMax){
    caja.material = material;
    caja.capMax = capMax;
    caja.capActual = capMax;
}
void eliminarCaja(Caja caja){
//    delete caja;
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
        eliminarCaja(caja);
    }
    else
        caja.capActual = aux;
}
