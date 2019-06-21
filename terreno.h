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

/* PRE: La Terreno no debe haber sido creada.
   POST: La Terreno esta creada y lista para ser usada.
*/
void crearTerreno(Terreno &terreno, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer,int numero);


/* PRE: La Terreno debe haber sido creada mediante crearTerreno().
   POST: Se dibuja en pantalla la Terreno

   Terreno: Instacia sobre la cual se invoca a la primitiva.
*/
void dibujarTerreno(Terreno &terreno, SDL_Renderer* renderer);


/* PRE: La Terreno debe haber sido creada mediante crear().
   POST: La Terreno es eliminada.

   Terreno: Instacia sobre la cual se invoca a la primitiva */

void destruirTerreno(Terreno &terreno);
