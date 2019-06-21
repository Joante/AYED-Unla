#include <SDL.h>
#include <SDL_image.h>

#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED


/*
Definición del tipo Tipo de Dato para el manejo de la Moneda.
Atributos:
        *posX,
        *posY,
        *tiempoVida

Axiomas:
        *posX se definirá mediante un aleatorio.
        *posY se definirá mediante un aleatorio.
        *tiempoVida se determina en forma aleatoria al momento de crearla y no podrá superar los VM intervalos.

*/
/* Tipo de estructura de la Estación */

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

/* Definición de Primitivas  */

/* PRE: La moneda no debe haber sido creada.
   POST: La moneda esta creada y lista para ser usada. */

void crearMoneda(Moneda &moneda,int posX, int posY, int altoCasillero, int anchoCasillero,int altoVentana, int anchoVentana, SDL_Renderer* renderer);

/* PRE: La moneda debe haber sido creada.
   POST: La moneda se visualiza por pantalla*/

void dibujar(Moneda &moneda, SDL_Renderer* renderer);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: La moneda es eliminada.

   moneda: Instacia sobre la cual se invoca a la primitiva */

void eliminarMoneda (Moneda &moneda);

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

void generarMoneda (Moneda &moneda, int tiempoVida);



#endif
