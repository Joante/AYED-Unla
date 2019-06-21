#include "estacion.h"
#include <iostream>
#include"SDL.h"
#include"SDL_image.h"

void crear (Estacion &estacion) {}

void eliminar (Estacion &estacion) {}

int getPosXE (Estacion &estacion)
{
    return estacion.posXE;
}

int getPosYE (Estacion &estacion)
{
    return estacion.posYE;
}

void setPosXE (Estacion &estacion, int posXE)
{
    estacion.posXE = posXE;
}

void setPosYE (Estacion &estacion, int posYE)
{
    estacion.posYE = posYE;
}

/* ? */

void agregarVagon () {}
void crearEstacion(Estacion &estacion, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer)
{
    estacion.posYE=posY;//coordenada logica y
    estacion.posXE=posX;//coordenada logica x
    estacion.imagen= IMG_LoadTexture(renderer,"img/estacion.png");

    estacion.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    estacion.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    estacion.rectImag.w= anchoCasillero;//ancho
    estacion.rectImag.h= altoCasillero;//alto
}
void dibujarEstacion(Estacion &estacion, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, estacion.imagen,NULL,&(estacion.rectImag));
}
