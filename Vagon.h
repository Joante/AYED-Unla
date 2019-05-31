#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

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
enum Item{
    oro,
    plata,
    bronce,
    platino,
    roca,
    carbon
};
/** Tipo de Estructura del Vagon */

typedef struct Vagon
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
    SDL_Texture *imagen;
    SDL_Rect rectImag;
//        Pila cajas;
        };

/** PRE: El vagon no debe haber sido creado
    POST: El vagon queda creado y preparado para ser utilizado,
    vagon.id=1;
    vagon.estado=true;
*/
void crearVagon(Vagon &vagon);

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
Item getItem(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo cajas pasa a tener el dato ingresado
*/
//void setCajas(Vagon &vagon, Pila cajas);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  cajas
*/
//Pila getCajas(Vagon &vagon);


/** PRE: La vagon no debe haber sido creada.
   POST: La vagon esta creada y lista para ser usada.
*/
void crearVagon(Vagon &vagon, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer);


/** PRE: La vagon debe haber sido creada mediante crearVagon().
   POST: Se dibuja en pantalla la vagon

   vagon: Instacia sobre la cual se invoca a la primitiva.
*/
void dibujarVagon(Vagon &vagon, SDL_Renderer* renderer);


/** PRE: La vagon debe haber sido creada mediante crear().
   POST: La vagon es eliminada.

   vagon: Instacia sobre la cual se invoca a la primitiva */

void moverVagon(Vagon &vagon,  SDL_Renderer* renderer, int intervalo);

void moverVagonALaDerecha(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

void moverVagonALaIzquierda(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

void moverVagonAAbajo(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

void moverVagonAArriba(Vagon &vagon, SDL_Renderer* renderer, int intervalo);

void reubicarVagon(Vagon &vagon);


#endif // VAGON_H_INCLUDED
