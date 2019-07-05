#ifndef ESTACION_H_INCLUDED
#define ESTACION_H_INCLUDED
#include "SDL.h"
#include "Vagon.h"
#include "Lista.h"
#include "Locomotora.h"
/*
Definici�n del tipo Tipo de Dato para el manejo de la Estaci�n.
Atributos:
        *posXE,
        *posYE.

Axiomas:
        *posXE se definir� por el archivo propuesto por el docente.
        *posYE se definir� por el archivo propuesto por el docente.

*/
/* Tipo de estructura de la Estaci�n */

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

/* Definici�n de Primitivas  */

/* PRE: La estaci�n no debe haber sido creada.#endif
   POST: La estaci�n esta creada y lista para ser usada. */

void crear (Estacion &estacion);

/* PRE: La estaci�n debe haber sido creada mediante crear().
   POST: La estaci�n es eliminada.

   estacion: Instacia sobre la cual se invoca a la primitiva */

void eliminar (Estacion &estacion);

/* PRE: La estaci�n debe haber sido creada mediante crear().
   POST: Se devuelve la posici�n en X de la estaci�n

   estacion: Instacia sobre la cual se invoca a la primitiva*/

int getPosXE (Estacion &estacion);

/* PRE: La estaci�n debe haber sido creada mediante crear().
   POST: Se devuelve la posici�n en Y de la estaci�n

   estacion: Instacia sobre la cual se invoca a la primitiva*/

int getPosYE (Estacion &estacion);

/* PRE: La estaci�n debe haber sido creada mediante crear().
   POST: El campo posXE de la estaci�n se modifica por el valor pasado por parametro.

   estacion: Instacia sobre la cual se invoca a la primitiva.
   posXE: Valor pasado por parametro. Nueva posicion en X. */

void setPosXE (Estacion &estacion, int posXE);

/* PRE: La estaci�n debe haber sido creada mediante crear().
   POST: El campo posYE de la estaci�n se modifica por el valor pasado por parametro.

   estacion: Instacia sobre la cual se invoca a la primitiva.
   posYE: Valor pasado por parametro. Nueva posicion en Y. */

void setPosYE (Estacion &estacion, int posYE);

/* ? */

void colisionEstacion (Estacion estacion,Locomotora &locomotora, Lista *caravana, int &direccion, SDL_Renderer* renderer);

void agregarVagon (Estacion &estacion, Lista &caravana, SDL_Renderer* renderer);

void crearEstacion(Estacion &Estacion, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer);

void dibujarEstacion(Estacion &estacion, SDL_Renderer* renderer);

#endif
