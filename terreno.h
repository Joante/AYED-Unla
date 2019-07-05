#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
typedef struct
{
    bool estado;
    int posX;
    int posY;
    int anchoCasillero;
    int altoCasillero;
    SDL_Texture *imagen;
    SDL_Rect rectImag;

//falta la implementacion de lista para la lista de vagones
}Terreno;

/* PRE: La matriz de Terreno no debe haber sido creada.
   POST: La matriz Terreno esta creada y lista para ser usada.
*/

void crearMatrizTerreno(Terreno &terreno,Terreno matrizTerreno[15][20], int filas, int columnas, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer);

/* PRE: El Terreno no debe haber sido creada.
   POST: El Terreno esta creada y lista para ser usada.
*/
void crearTerreno(Terreno &terreno, int f, int c,int anchoCasillero, int altoCasillero, SDL_Renderer* renderer,int numero);


/* PRE: El Terreno debe haber sido creado mediante crearTerreno().
   POST: Se dibuja en pantalla la Terreno

   Terreno: Instacia sobre la cual se invoca a la primitiva.
*/


void dibujarTerreno(Terreno &terreno,Terreno matrizTerreno[15][20],int filas,int columnas, SDL_Renderer* renderer);


/* PRE: El Terreno debe haber sido creado mediante crear().
   POST: El Terreno es eliminada.

   Terreno: Instacia sobre la cual se invoca a la primitiva */

void destruirTerreno(Terreno &terreno);

/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea el ancho del casillero de la terreno.

    terreno: Instacia sobre la cual se invoca a la primitiva.
*/
void setAnchoCasilleroTerreno(Terreno &terreno, int anchoCasillero);

/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se devuelve el ancho del casillero de la terreno.

    terreno: Instacia sobre la cual se invoca a la primitiva.
*/
int getAnchoCasilleroTerreno(Terreno &terreno);

/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea el alto del casillero de la terreno.

    terreno: Instacia sobre la cual se invoca a la primitiva.
*/
void setAltoCasilleroTerreno(Terreno &terreno, int altoCasillero);

/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se devuelve el alto del casillero de la terreno.

    terreno: Instacia sobre la cual se invoca a la primitiva.
*/
int getAltoCasilleroTerreno(Terreno &terreno);

/* PRE: El terreno debe haber sido creado mediante crear().
   POST: El campo posX de la terreno se modifica por el valor pasado por parametro.

   terreno: Instacia sobre la cual se invoca a la primitiva.
   posX: Valor pasado por parametro. Nueva posicion en X. */


void setPosX (Terreno &terreno, int posX);

/* PRE: El terreno debe haber sido creado mediante crear().
   POST: El campo posY de la terreno se modifica por el valor pasado por parametro.

   terreno: Instacia sobre la cual se invoca a la primitiva.
   posY: Valor pasado por parametro. Nueva posicion en Y. */

void setPosY (Terreno &terreno, int posY);

/* PRE: El terreno debe haber sido creado mediante crear().
   POST: Se devuelve la posición en X de la terreno

   terreno: Instacia sobre la cual se invoca a la primitiva*/

int getPosX (Terreno &terreno);

/* PRE: El terreno debe haber sido creado mediante crear().
   POST: Se devuelve la posición en Y de la terreno

   terreno: Instacia sobre la cual se invoca a la primitiva*/

int getPosY (Terreno &terreno);

/**
    PRE: El terreno debe haber sido creado mediante crear(), y se debe de haber seteado el Estado mediante setEstado().
    POST: Se devuelve el estado del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

bool getEstado (Terreno &terreno);


/**
    PRE: El terreno debe haber sido creado mediante crear().
    POST: Se setea el estado del terreno.
    Terreno: Instacia sobre el cual se invoca a la primitiva
*/

void setEstado (Terreno &terreno, bool estado);
