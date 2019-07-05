#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Pila.h"


#ifndef VAGON_H
#define VAGON_H

/**
    Definicion del Tipo de Dato para manejo de Vagones.
    Atributos:
    * id
    * estado
    * pesoMax
    * pesoUtilizado
    * item
    * Caja

    Axiomas:
    *pesoMax > 0
    *pesoUtilizado > 0

*/
/** Tipo de Enumerado Item */


enum Item
{
    oro,
    plata,
    bronce,
    platino,
    roca,
    carbon,
    vacio
};
/** Tipo de Estructura del Vagon */

typedef struct
{
    int id;
    bool estado;
    int pesoMax;
    int pesoUtilizado;
    Item item;
    int posX;
    int posY;
    int monedas;
    int anchoCasillero;
    int altoCasillero;
    int direccion;
    int direccionSiguiente;
    SDL_Texture *imagen;
    SDL_Rect rectImag;
    Pila cajas;
} Vagon;

struct Nodo
{
    Vagon vagon;
    Nodo* siguiente;
};
typedef Nodo* PtrNodoVagon;

/** PRE: El vagon no debe haber sido creado
    POST: El vagon queda creado y preparado para ser utilizado,
    vagon.id=1;
    vagon.estado=true;
*/
void constructorVagon(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El vagon es eliminado
*/
void eliminarVagon(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo radio pasa a tener el dato ingresado
*/
void setId(Vagon &vagon, int id);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  id
*/
int getId(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo estado pasa a tener el dato ingresado
*/
void setEstado(Vagon &vagon, bool estado);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  estado
*/
bool getEstado(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo pesoMax pasa a tener el dato ingresado
*/
void setPesoMax(Vagon &vagon, int pesoMax);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  pesoMax
*/
int getPesoMax(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo PesoUtilizado pasa a tener el dato ingresado
*/
void setPesoUtilizado(Vagon &vagon, int pesoUtilizado);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  PesoUtilizado
*/
int getPesoUtilizado(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo item pasa a tener el dato ingresado
*/
void setItem(Vagon &vagon, Item item);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  item
*/
int getDireccion(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo direccion pasa a tener el dato ingresado
*/
void setDireccion(Vagon &vagon, int direccion);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  direccion
*/
Item getItem(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo cajas pasa a tener el dato ingresado
*/
void setCajas(Vagon &vagon, Pila cajas);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  cajas
*/
Pila getCajas(Vagon &vagon);


/** PRE: La vagon no debe haber sido creada.
   POST: La vagon esta creada y lista para ser usada.
*/

void crearVagon(Vagon &vagon, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer, int monedas, int x, int y, int direccion);


/** PRE: La vagon debe haber sido creada mediante crearVagon().
   POST: Se dibuja en pantalla la vagon

   vagon: Instacia sobre la cual se invoca a la primitiva.
*/
void dibujarVagon(Vagon &vagon, SDL_Renderer* renderer);

/**
    Pre: El vagon debe de haber sido creado.
    Post: Se devuelve la posicion X del vagon
*/
int getPosX(Vagon &vagon);

/**
    Pre: El vagon debe de haber sido creado.
    Post: Se devuelve la posicion Y del vagon
*/
int getPosY(Vagon &vagon);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se mueve la posicion del vagon
*/
void moverVagon(Vagon &vagon,  SDL_Renderer* renderer, int intervalo);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se mueve la posicion del vagon a la derecha
*/
void moverVagonALaDerecha(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se mueve la posicion del vagon a la izquierda
*/
void moverVagonALaIzquierda(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se mueve la posicion del vagon abajo
*/
void moverVagonAAbajo(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se mueve la posicion del vagon arriba
*/
void moverVagonAArriba(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se reubica la posicion del vagon
*/
void reubicarVagon(Vagon &vagon);

/** PRE: La vagon debe haber sido creada mediante crear() y dibujado.
   POST: La vagon es eliminada.

   vagon: Instacia sobre la cual se invoca a la primitiva */
void destruirVagon(Vagon &vagon);

/**
    Pre: El vagon debe de haber sido creado y dibujado.
    Post: Se manejan los moviminetos del vagon
*/
void destellosVagon(Vagon vagon, SDL_Renderer* renderer);

/* PRE: La vagon debe haber sido creada mediante crear().
   POST: El campo posX de la vagon se modifica por el valor pasado por parametro.

   vagon: Instacia sobre la cual se invoca a la primitiva.
   posX: Valor pasado por parametro. Nueva posicion en X. */


void setPosX (Vagon &vagon, int posX);

/* PRE: La vagon debe haber sido creada mediante crear().
   POST: El campo posY de la vagon se modifica por el valor pasado por parametro.

   vagon: Instacia sobre la cual se invoca a la primitiva.
   posY: Valor pasado por parametro. Nueva posicion en Y. */

void setPosY (Vagon &vagon, int posY);

/**
    PRE: La vagon debe haber sido creada mediante crear().
    POST: Se setea el ancho del casillero de la vagon.

    vagon: Instacia sobre la cual se invoca a la primitiva.
*/
void setAnchoCasilleroVagon(Vagon &vagon, int anchoCasillero);

/**
    PRE: La vagon debe haber sido creada mediante crear().
    POST: Se devuelve el ancho del casillero de la vagon.

    vagon: Instacia sobre la cual se invoca a la primitiva.
*/
int getAnchoCasilleroVagon(Vagon &vagon);

/**
    PRE: La vagon debe haber sido creada mediante crear().
    POST: Se setea el alto del casillero de la vagon.

    vagon: Instacia sobre la cual se invoca a la primitiva.
*/
void setAltoCasilleroVagon(Vagon &vagon, int altoCasillero);

/**
    PRE: La vagon debe haber sido creada mediante crear().
    POST: Se devuelve el alto del casillero de la vagon.

    vagon: Instacia sobre la cual se invoca a la primitiva.
*/
int getAltoCasilleroVagon(Vagon &vagon);

/**
    PRE: La vagon debe haber sido creada mediante crear().
    POST: El campo monedas de la vagon se modifica por el valor pasado por parametro.

    vagon: Instacia sobre la cual se invoca a la primitiva.
    monedas: Valor pasado por parametro.
*/

void setMonedas (Vagon &vagon, int monedas);

/**
    PRE: La vagon debe haber sido creada mediante crear().
    POST: Se devuelve las monedas de la vagon.

    vagon: Instacia sobre la cual se invoca a la primitiva
*/
int getMonedas(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  direccion siguiente
*/
int getDireccionSiguiente(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo direccion siguiente pasa a tener el dato ingresado
*/
void setDireccionSiguiente(Vagon &vagon, int direccionSiguiente);
#endif // VAGON_H_INCLUDED
