#include "terreno.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


void crearTerreno(Terreno &terreno, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer){
    terreno.posY=f;//coordenada logica y
    terreno.posX=c;//coordenada logica x
    terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_3.png");

    terreno.rectImag.y=f* altoCasillero;//coordenada de dibujo y
    terreno.rectImag.x=c* anchoCasillero;//coordenada de dibujo x
    terreno.rectImag.w= anchoCasillero;//ancho
    terreno.rectImag.h= altoCasillero;//alto

}

void dibujarTerreno(Terreno &terreno, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, terreno.imagen,NULL,&(terreno.rectImag));
}

void destruirTerreno(Terreno &terreno){
    SDL_DestroyTexture(terreno.imagen);
}

