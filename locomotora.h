#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Lista.h"
#include "Vagon.h"
#include "mina.h"
#include "Pila.h"
#include "moneda.h"
#include "estacion.h"
#ifndef LOCOMOTORA_H_INCLUDED
#define LOCOMOTORA_H_INCLUDED


/**
    Definición del tipo Tipo de Dato para el manejo de la Locomotora.
    Atributos:
        bool estado;
        int posX;
        int posY;
        int monedas;
        int anchoCasillero;
        int altoCasillero;
        int direccion;

    Axiomas:
        posX debe tener un valor entre 0 y 600
        posY debe tener un valor entre 0 y 600

*/
/** Tipo de estructura de la Locomotora */

typedef struct
{
    bool estado;
    int posX;
    int posY;
    int monedas;
    int anchoCasillero;
    int altoCasillero;
    int direccion;
    SDL_Texture *imagen;
    SDL_Rect rectImag;
} Locomotora;


/** Definición de Primitivas  */

/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: La locomotora es eliminada.

   locomotora: Instacia sobre la cual se invoca a la primitiva */

//void eliminar (Locomotora &locomotora);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve la posición en X de la locomotora

    Locomotora: Instacia sobre la cual se invoca a la primitiva
*/

int getPosX (Locomotora &locomotora);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve la posición en Y de la locomotora

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/

int getPosY (Locomotora &locomotora);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve la cantidad de monedas que posee la locomotora

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/

//int getMonedas (Locomotora &locomotora);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve la direccion de la locomotora.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
int getDireccion (Locomotora &locomotora);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve la imagen de la locomotora.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
SDL_Rect getRectImag (Locomotora &locomotora);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve el estado de la locomotora.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
bool getEstado (Locomotora &locomotora);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se setea la direccion de la locomotora.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void setDireccion (Locomotora &locomotora, int direccion);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se setea la imagen de la locomotora.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void setRectImag (Locomotora &locomotora, SDL_Rect imagen);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se reubica la locomotora en la pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void reubicarLocomotora(Locomotora &locomotora);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: El campo monedas de la locomotora se modifica por el valor pasado por parametro.

    locomotora: Instacia sobre la cual se invoca a la primitiva.
    monedas: Valor pasado por parametro.
*/

void setMonedas (Locomotora &locomotora, int monedas);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: El campo posX de la locomotora se modifica por el valor pasado por parametro.

    locomotora: Instacia sobre la cual se invoca a la primitiva.
    posX: Valor pasado por parametro. Nueva posicion en X.
*/

void setPosX (Locomotora &locomotora, int posX);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: El campo posY de la locomotora se modifica por el valor pasado por parametro.

    locomotora: Instacia sobre la cual se invoca a la primitiva.
    posY: Valor pasado por parametro. Nueva posicion en Y.
*/

void setPosY (Locomotora &locomotora, int posY);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: El edtado de la locomotora se modifica por el valor pasado por parametro.

    locomotora: Instacia sobre la cual se invoca a la primitiva.
    posX: Valor pasado por parametro.
*/

void setEstado (Locomotora &locomotora, bool estado);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se devuelve las monedas de la locomotora.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
int getMonedas(Locomotora &locomotora);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se cambia el estado de la locomotora y se pierde el juego.

    locomotora: Instacia sobre la cual se invoca a la primitiva.
*/
void colisionLimites (Locomotora &locomotora);


/**
    PRE: La locomotora no debe haber sido creada.
    POST: La locomotora esta creada y lista para ser usada.
*/
void crearLocomotora(Locomotora &locomotora, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer);


/**
    PRE: La locomotora debe haber sido creada mediante crearLocomotora().
    POST: Se dibuja en pantalla la locomotora

    locomotora: Instacia sobre la cual se invoca a la primitiva.
*/
void dibujarLocomotora(Locomotora &locomotora, SDL_Renderer* renderer);


/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: La locomotora es eliminada.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void destruirLocomotora(Locomotora &locomotora);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: La se efectua el movimiento sobre la locomotora en pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/

void moverLocomotora(Locomotora &locomotora, SDL_Renderer* renderer,  int intervalo);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se direcciona la locomotora en la pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/

int direccionarLocomotora(Locomotora &locomotora, SDL_Event evento);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se mueve la locomotora a la derecha en pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void moverLocomotoraALaDerecha(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se mueve la locomotora a la izquierda en pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void moverLocomotoraALaIzquierda(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se mueve la locomotora hacia abajo en pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void moverLocomotoraAAbajo(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se mueve la locomotora hacia arriba en pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void moverLocomotoraAArriba(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo);


void chocarVagones (Locomotora &locomotora, Lista *caravana);

/**
    PRE: La locomotora debe haber sido creada mediante crear().
    POST: Se suma monedas a la locomotra.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void sumarMoneda (Locomotora &locomotora, bool &hayMoneda);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se maneja la colision de los vagones.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
int colisionVagones(SDL_Rect H, SDL_Rect M, int dir);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se maneja la colision de la locomotora con los bordes.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void chocarBordes (Locomotora &locomotora, int direccion);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se maneja la colision de la locomotora con la mina.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void colisionMina (Locomotora &locomotora, Mina &mina, Lista *caravana, int &direccion);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se detiene el movimiento de la locomotora en pantalla.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void detenerse(Locomotora &locomotora, int &direccion1);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se suma una caja al vagon designado.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void sumarCaja(Locomotora &locomotora, Lista *caravana, Mina &mina);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se maneja la colision de la locomotora con la mina.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void colisionMinas (Locomotora &locomotora, Lista *minas, Lista *caravana, int &direccion);

/**
    PRE: La locomotora debe haber sido creada mediante crear() y se debe de haber dibujado.
    POST: Se maneja la colision de la locomotora con la moneda.

    locomotora: Instacia sobre la cual se invoca a la primitiva
*/
void colisionMoneda(Locomotora &locomotora, Moneda &moneda, bool &hayMoneda, int &monedas);

#endif
