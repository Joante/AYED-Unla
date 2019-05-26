#include <SDL.h>
#include <SDL_image.h>

#include "moneda.h"
#include <iostream>

/* Implemanetación de las Primitivas */

void crear(Moneda &moneda, int posX, int posY, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer){
    moneda.posY= posY;//coordenada logica y
    moneda.posX=posX;//coordenada logica x
    moneda.imagen=IMG_LoadTexture(renderer,"img/moneda.png");

    moneda.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    moneda.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    moneda.rectImag.w= anchoCasillero;//ancho
    moneda.rectImag.h= altoCasillero;//alto
}

void dibujar(Moneda &moneda, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, moneda.imagen,NULL,&(moneda.rectImag));
}

void eliminar (Moneda &moneda){
SDL_DestroyTexture(moneda.imagen);
}

int getPosX (Moneda &moneda){
    return moneda.posX;
}

int getPosY (Moneda &moneda){
    return moneda.posY;
}

int getTiempoVida (Moneda &moneda){
    return moneda.tiempoVida;
}

void setTiempoVida (Moneda &moneda, int tiempoVida){
moneda.tiempoVida = tiempoVida;
}

void setPosX (Moneda &moneda, int posX){
moneda.posX = posX;
}

void setPosY (Moneda &moneda, int posY){
moneda.posX = posY;
}

void generarMoneda (Moneda &moneda){}

/* ? */

void sumarMoneda (){}
