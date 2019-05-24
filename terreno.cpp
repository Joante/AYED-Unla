#include "terreno.h"

/************************************************/

void crear (Terreno &terreno){
    terreno.estado = true;
    terreno.locomotora = 0;
    terreno.listaMonedas=0;
    terreno.listaMinas=0;
    terreno.listaBandidos=0;
    terreno.estacion=0;
}


void eliminar (Terreno &terreno){
}

void dibujarTerreno(ListaTerreno &ListaTerrenos, SDL_Renderer* renderer);


bool getEstado (Terreno &terreno){
    return terreno.estado;
}



void setEstado (Terreno &terreno, bool estado){
    terreno.estado = estado;
}


Locomotora getLocomotora (Terreno &terreno){
    return terreno.locomotora;
}


void setLocomotora (Terreno &terreno, Locomotora locomotora){
    terreno.locomotora=locomotora;
}


ListaMinas getListaMinas (Terreno &terreno){
    return terreno.listaMinas;
}


void setListaMinas (Terreno &terreno, ListaMinas listaMinas){
    terreno.listaMinas=listaMinas;
}


ListaMonedas getListaMonedas (Terreno &terreno){
    return terreno.listaMonedas;
}

void setListaMonedas (Terreno &terreno, ListaMonedas listaMonedas){
    terreno.listaMonedas=listaMonedas;
}

ListaBandidos getListaBandidos (Terreno &terreno){
    return terreno.listaBandidos;
}

void setListaBandidos (Terreno &terreno, ListaBandidos listaBandidos){
    terreno.listaBandidos = listaBandidos;
}

Estacion getEstacion (Terreno &terreno){
    return terreno.estacion;
}


void setEstacion (Terreno &terreno, Estacion estacion){
    terreno.estacion = estacion;
}
