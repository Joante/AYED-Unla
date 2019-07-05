#include <SDL.h>
#include <SDL_image.h>

#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED


/**
    Definición del tipo Tipo de Dato para el manejo de la Moneda.
    Atributos:
            *posX,
            *posY,
            *tiempoVida
            int anchoCasillero;
            int altoCasillero;
            SDL_Texture *imagen;
            SDL_Rect rectImag;

    Axiomas:
            *posX se definirá mediante un aleatorio.
            *posY se definirá mediante un aleatorio.
            *tiempoVida se determoneda en forma aleatoria al momento de crearla y no podrá superar los VM intervalos.

*/
/** Tipo de estructura de la Estación */

typedef struct
{
    int posX;
    int posY;
    int tiempoVida;
    int anchoCasillero;
    int altoCasillero;
    SDL_Texture *imagen;
    SDL_Rect rectImag;


}Moneda;

/** Definición de Primitivas  */

/* PRE: La moneda no debe haber sido creada.
   POST: La moneda esta creada y lista para ser usada. */

void crearMoneda(Moneda &moneda,int anchoCasillero,int altoCasillero,int maxIntervalo, int maxVida, SDL_Renderer* renderer,int intervaloMoneda,bool &hayMoneda);
/* PRE: La moneda debe haber sido creada.
   POST: La moneda se visualiza por pantalla*/

void dibujarMoneda(Moneda &moneda, SDL_Renderer* renderer, bool hayMoneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: La moneda es elimonedada.

   moneda: Instacia sobre la cual se invoca a la primitiva */

void eliminarMoneda (Moneda &moneda, int &intervalo, bool &hayMoneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: Se devuelve la posición en X de la moneda

   moneda: Instacia sobre la cual se invoca a la primitiva*/

int getPosX (Moneda &moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: Se devuelve la posición en Y de la moneda

   moneda: Instacia sobre la cual se invoca a la primitiva*/

int getPosY (Moneda &moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: Se devuelve el tiempo de vida de la moneda.

   moneda: Instacia sobre la cual se invoca a la primitiva*/

int getTiempoVida (Moneda &moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: El campo tiempoVida de la moneda se modifica por el valor pasado por parametro.

   moneda: Instacia sobre la cual se invoca a la primitiva.
   tiempoVida: Valor pasado por parametro.*/


void setTiempoVida (Moneda &moneda, int tiempoVida);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: El campo posX de la moneda se modifica por el valor pasado por parametro.

   moneda: Instacia sobre la cual se invoca a la primitiva.
   posX: Valor pasado por parametro. Nueva posicion en X. */


void setPosX (Moneda &moneda, int posX);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: El campo posY de la moneda se modifica por el valor pasado por parametro.

   moneda: Instacia sobre la cual se invoca a la primitiva.
   posY: Valor pasado por parametro. Nueva posicion en Y. */

void setPosY (Moneda &moneda, int posY);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: La moneda es generada durante un intervalo de tiempo aleatorio en un lugar aleatorio.

   moneda: Instacia sobre la cual se invoca a la primitiva.
*/

void generarMoneda(Moneda &moneda,int anchoCasillero,int altoCasillero,int maxIntervalo,SDL_Renderer* renderer,int intervaloMoneda);

/**
    Pre: La moneda debe de hacer sido creada mediante crear()
    Post: La moneda es sumada.
*/
void sumarMoneda ();

/**
    PRE: La moneda debe haber sido creada mediante crear().
    POST: Se setea el ancho del casillero de la moneda.

    moneda: Instacia sobre la cual se invoca a la primitiva.
*/
void setAnchoCasilleroMoneda(Moneda &moneda, int anchoCasillero);

/**
    PRE: La moneda debe haber sido creada mediante crear().
    POST: Se devuelve el ancho del casillero de la moneda.

    moneda: Instacia sobre la cual se invoca a la primitiva.
*/
int getAnchoCasilleroMoneda(Moneda &moneda);

/**
    PRE: La moneda debe haber sido creada mediante crear().
    POST: Se setea el alto del casillero de la moneda.

    moneda: Instacia sobre la cual se invoca a la primitiva.
*/
void setAltoCasilleroMoneda(Moneda &moneda, int altoCasillero);

/**
    PRE: La moneda debe haber sido creada mediante crear().
    POST: Se devuelve el alto del casillero de la moneda.

    moneda: Instacia sobre la cual se invoca a la primitiva.
*/
int getAltoCasilleroMoneda(Moneda &moneda);


#endif
