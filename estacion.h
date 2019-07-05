#ifndef ESTACION_H_INCLUDED
#define ESTACION_H_INCLUDED
#include "SDL.h"
#include "Vagon.h"
#include "Lista.h"
#include "Locomotora.h"
/**
Definici�n del tipo Tipo de Dato para el manejo de la Estaci�n.
Atributos:
        *posXE,
        *posYE.

Axiomas:
        *posXE se definir� por el archivo propuesto por el docente.
        *posYE se definir� por el archivo propuesto por el docente.

*/
/** Tipo de estructura de la Estaci�n */

typedef struct
{
    int posXE;
    int posYE;
    int anchoCasillero;
    int altoCasillero;
    int direccion;
    SDL_Texture *imagen;
    SDL_Rect rectImag;

} Estacion;

/** Definici�n de Primitivas  */

/**
    PRE: La estaci�n no debe haber sido creada.
    POST: La estaci�n esta creada y lista para ser usada.
*/

void crear (Estacion &estacion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: La estaci�n es eliminada.

    estacion: Instacia sobre la cual se invoca a la primitiva
*/

void eliminar (Estacion &estacion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se devuelve la posici�n en X de la estaci�n

    estacion: Instacia sobre la cual se invoca a la primitiva
*/

int getPosXE (Estacion &estacion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se devuelve la posici�n en Y de la estaci�n

    estacion: Instacia sobre la cual se invoca a la primitiva
*/

int getPosYE (Estacion &estacion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: El campo posXE de la estaci�n se modifica por el valor pasado por parametro.

    estacion: Instacia sobre la cual se invoca a la primitiva.
    posXE: Valor pasado por parametro. Nueva posicion en X.
*/

void setPosXE (Estacion &estacion, int posXE);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: El campo posYE de la estaci�n se modifica por el valor pasado por parametro.

    estacion: Instacia sobre la cual se invoca a la primitiva.
    posYE: Valor pasado por parametro. Nueva posicion en Y.
*/

void setPosYE (Estacion &estacion, int posYE);

/**
    PRE: La estaci�n debe haber sido creada mediante crear() y se debe de haber dibujado mediante dibujar().
    POST: Se maneja la colision de la caravana con la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/

void colisionEstacion (Estacion estacion,Locomotora &locomotora, Lista *caravana, int &direccion, SDL_Renderer* renderer);

/**
    PRE: La estaci�n debe haber sido creada mediante crear() y se debe de haber dibujado mediante dibujar().
    POST: Se crea un vagon en la caravana en base a las monedas.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
void agregarVagon (Estacion &estacion, Lista &caravana, SDL_Renderer* renderer);

/**
    PRE: La estaci�n no debe haber sido creada
    POST: Se construye la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
void crearEstacion(Estacion &Estacion, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se dibuja la estacion en la pantalla.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
void dibujarEstacion(Estacion &estacion, SDL_Renderer* renderer);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se setea el ancho del casillero de la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
void setAnchoCasilleroEstacion(Estacion &estacion, int anchoCasillero);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se devuelve el ancho del casillero de la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
int getAnchoCasilleroEstacion(Estacion &estacion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se setea el alto del casillero de la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
void setAltoCasilleroEstacion(Estacion &estacion, int altoCasillero);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se devuelve el alto del casillero de la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
int getAltoCasilleroEstacion(Estacion &estacion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se setea la dirreccion de la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
void setDireccionEstacion(Estacion &estacion, int dirreccion);

/**
    PRE: La estaci�n debe haber sido creada mediante crear().
    POST: Se devuelve la dirreccion de la estacion.

    estacion: Instacia sobre la cual se invoca a la primitiva.
*/
int getDirreccionEstacion(Estacion &estacion);

#endif
