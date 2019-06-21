#include "moneda.h"
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <iomanip>

/* Implemanetación de las Primitivas */

void crearMoneda(Moneda &moneda,int posX, int posY, int altoCasillero, int anchoCasillero,int altoVentana, int anchoVentana, SDL_Renderer* renderer){
    moneda.posX=posX;
    moneda.posY=posY;
    moneda.imagen= IMG_LoadTexture(renderer,"img/moneda.png");
    moneda.rectImag.w= anchoCasillero;//ancho
    moneda.rectImag.h= altoCasillero;//alto
    moneda.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    moneda.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    //Posicionamos aleatoriamente la moneda en la pantalla.
   // moneda.rectImag.x = ((rand() % ((altoVentana-moneda.rectImag.w)/moneda.rectImag.w))*moneda.rectImag.w);
   // moneda.rectImag.y = ((rand() % ((anchoVentana-moneda.rectImag.h)/moneda.rectImag.h))*moneda.rectImag.h);
    moneda.tiempoVida=0;

}

void dibujar(Moneda &moneda, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, moneda.imagen,NULL,&(moneda.rectImag));
}

void eliminarMoneda (Moneda &moneda){
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

void generarMoneda (Moneda &moneda, int tiempoVida){

    srand(time(NULL));
    int a = rand()%tiempoVida;

}


