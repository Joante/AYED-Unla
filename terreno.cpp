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


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: El terreno es eliminado.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

void eliminar (Terreno &terreno){
}


/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado el Estado mediante setEstado().
    POST: Se devuelve el estado del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

bool getEstado (Terreno &terreno){
    return terreno.estado;
}


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea el estado del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

void setEstado (Terreno &terreno, bool estado){
    terreno.estado = estado;
}

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la Locomotora mediante setLocomotora().
    POST: Se devuelve la instancia de Locomotora.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

Locomotora getLocomotora (Terreno &terreno){
    return terreno.locomotora;
}


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la Locomotora del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

void setLocomotora (Terreno &terreno, Locomotora locomotora){
    terreno.locomotora=locomotora;
}

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la ListaMinas mediante setListaMinas().
    POST: Se devuelve la lista de minas del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

ListaMinas getListaMinas (Terreno &terreno){
    return terreno.listaMinas;
}


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la ListaMinas del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

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
