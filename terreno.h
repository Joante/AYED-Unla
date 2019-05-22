#ifndef TERRENO_H_INCLUDED
#define TERRENO_H_INCLUDED
/**
    Definición del tipo Tipo de Dato para el manejo de el terreno.
    Atributos:
        bool estado;
        Locomotora locomotora;
        ListaMinas listaMinas;
        ListaMonedas listaMonedas;
        ListaBandidos listaBandidos;
        Estacion estacion;

    Axiomas:

*/

/* Tipo de estructura de el terreno */

typedef struct Terreno{
    bool estado;
    Locomotora locomotora;
    ListaMinas listaMinas;
    ListaMonedas listaMonedas;
    ListaBandidos listaBandidos;
    Estacion estacion;
} Terreno;

/* Definición de Primitivas  */

/**
    PRE: El terreno no debe haber sido creado.
    POST: El terreno esta creado y listo para ser usado.
*/

void crear (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: El terreno es eliminado.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

void eliminar (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado el Estado mediante setEstado().
    POST: Se devuelve el estado del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int getEstado (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea el estado del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int setEstado (Terreno &terreno, bool estado);

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la Locomotora mediante setLocomotora().
    POST: Se devuelve la instancia de Locomotora.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int getLocomotora (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la Locomotora del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int setLocomotora (Terreno &terreno, Locomotora locomotora);

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la ListaMinas mediante setListaMinas().
    POST: Se devuelve la lista de minas del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int getListaMinas (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la ListaMinas del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int setListaMinas (Terreno &terreno, ListaMinas listaMinas);

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la ListaMonedas mediante setListaMonedas().
    POST: Se devuelve la ListaMinas del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int getListaMonedas (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la ListaMonedas del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int setListaMonedas (Terreno &terreno, ListaMonedas listaMonedas);

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la ListaBandidos mediante setListaBandidos().
    POST: Se devuelve la ListaBandidos del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int getListaBandidos (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la ListaBandidos del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int setListaBandidos (Terreno &terreno, ListaBandidos listaBandidos);

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado la Estacion mediante setEstacion().
    POST: Se devuelve la Estacion del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int getEstacion (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea la Estacion del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

int setEstacion (Terreno &terreno, Estacion estacion);





#endif // TERRENO_H_INCLUDED
