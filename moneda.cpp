#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "moneda.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>


/* Implemanetación de las Primitivas */

void generarMoneda(Moneda &moneda,int anchoCasillero,int altoCasillero,int maxVida,SDL_Renderer* renderer,int intervaloMoneda){

    srand(time(NULL));
    moneda.tiempoVida = (10 + rand() % (maxVida))+intervaloMoneda;
    int y = 0 + rand() % (14 + 1);
    int x = 0 + rand() % (19 + 1);
    moneda.posY= y;//coordenada logica y
    moneda.posX= x;//coordenada logica x
    moneda.imagen= IMG_LoadTexture(renderer,"img/moneda.png");
    moneda.rectImag.y=y* altoCasillero;//coordenada de dibujo y
    moneda.rectImag.x=x* anchoCasillero;//coordenada de dibujo x
    moneda.rectImag.w= anchoCasillero;//ancho
    moneda.rectImag.h= altoCasillero;//alto

}


void crearMoneda(Moneda &moneda,int anchoCasillero,int altoCasillero,int maxIntervalo, int maxVida, SDL_Renderer* renderer,int intervaloMoneda,bool &hayMoneda){

 int aleatorio;
 srand(time(NULL));

    if (!hayMoneda)
    {
        if (intervaloMoneda >= maxIntervalo)
        {
            generarMoneda(moneda,anchoCasillero, altoCasillero, maxVida,renderer,intervaloMoneda);
            hayMoneda = true;
        }
        else
        {
            aleatorio = 1 + rand() % (3);
            if (aleatorio % 2 ==0)
            {
                generarMoneda(moneda,anchoCasillero, altoCasillero, maxIntervalo,renderer,intervaloMoneda);
                hayMoneda = true;
            }
        }
    }

}


void dibujarMoneda(Moneda &moneda, SDL_Renderer* renderer, bool hayMoneda){
    if (hayMoneda)
    SDL_RenderCopy(renderer, moneda.imagen,NULL,&(moneda.rectImag));
}


void eliminarMoneda (Moneda &moneda, int &intervalo, bool &hayMoneda){
    if (moneda.tiempoVida==intervalo)
    {
    hayMoneda = false;
    SDL_DestroyTexture(moneda.imagen);
    intervalo =0;
    }
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


