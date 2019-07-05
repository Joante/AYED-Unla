#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "Lista.h"
#include "caja.h"
#include "Vagon.h"
/**
    Definición del tipo de Dato para el manejo de la mina.
    Atributos:
        enum item
        int posX
        int posY
        int intervaloProduccion
        lista<Caja> cajas
        array secuencia

    Axiomas:
        int intervalo produccion > 0;

*/

/* Tipo de estructura de el mina */

typedef struct Mina{
    bool estado;
    int posX;
    int posY;
    int intervaloProduccion;
    Lista cajas;
    int *secuencia;
    int anchoCasillero;
    int altoCasillero;
    SDL_Texture *imagen;
    SDL_Rect rectImag;
    Item item;
} Mina;


ResultadoComparacion comparaListaCaja(PtrDato ptrDato1, PtrDato ptrDato2);
/* Definición de Primitivas  */

/**
    PRE: La mina no debe haber sido creada.
    POST: La mina esta creada y listo para ser usada.
*/

void crearMina (Mina &mina, bool estado, int posX, int posY, int intervaloProduccion, int anchoCasillero, int altoCasillero, int secuencia[], Item item, SDL_Renderer* renderer);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: La mina es eliminada.
    Mina: Instacia sobre la cual se invoca a la primitiva
*/

void eliminarMina (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado el Estado mediante setEstado().
    POST: Se devuelve el estado de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

bool getEstado (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea el estado de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setEstado (Mina &mina, bool estado);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la posX mediante setPosX().
    POST: Se devuelve la posicionX seteada.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int  getPosX (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la posicionX de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setPosX (Mina &mina, int posX);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la posY mediante setPosY().
    POST: Se devuelve la posicion Y de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int getPosY (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la posicion Y de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setPosY (Mina &mina, int posY);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado el intervaloProduccion mediante setIntervaloProduccion().
    POST: Se devuelve el intervalo de produccion de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int getIntervaloProduccion (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea intervalo de produccion de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setIntervaloProduccion (Mina &mina, int intervaloProduccion);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la ListaCajas mediante setListaCajas().
    POST: Se devuelve la ListaCajas de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

Lista getListaCajas (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la ListaCajas de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setListaCajas (Mina &mina, Lista cajas);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la secuencia mediante setSecuencia().
    POST: Se devuelve la secuencia de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int* getSecuencia (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la secuencia de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setSecuencia (Mina &mina, int* secuencia);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se dibuja la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/
void dibujarMina(Mina &mina, SDL_Renderer* renderer);

/**
    PRE: Las minas debe haber sido creadas mediante crear().
    POST: Se dibujan las minas.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/
void dibujarMinas(Lista *mina, SDL_Renderer* renderer);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se genera la caja de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/
void generarCajas(Mina &mina, int intervalo);

/**
    PRE: Las minas debe haber sido creadas mediante crear().
    POST: Se generan las cajas de todas las minas.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/
void generarTodasLasCajas(Lista *mina, int intervalo);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea el ancho del casillero de la mina.

    mina: Instacia sobre la cual se invoca a la primitiva.
*/
void setAnchoCasilleroMina(Mina &mina, int anchoCasillero);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se devuelve el ancho del casillero de la mina.

    mina: Instacia sobre la cual se invoca a la primitiva.
*/
int getAnchoCasilleroMina(Mina &mina);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea el alto del casillero de la mina.

    mina: Instacia sobre la cual se invoca a la primitiva.
*/
void setAltoCasilleroMina(Mina &mina, int altoCasillero);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se devuelve el alto del casillero de la mina.

    mina: Instacia sobre la cual se invoca a la primitiva.
*/
int getAltoCasilleroMina(Mina &mina);

#endif // MINA_H_INCLUDED
