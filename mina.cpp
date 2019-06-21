#include "mina.h"
#include <iostream>

void crearMina (Mina &mina, bool estado, int posX, int posY, int intervaloProduccion, int anchoCasillero, int altoCasillero, int secuencia[],SDL_Renderer* renderer){
    mina.posY= posY;//coordenada logica y
    mina.posX= posX;//coordenada logica x
    mina.imagen = IMG_LoadTexture(renderer,"img/mina.png");

    mina.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    mina.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    mina.rectImag.w= anchoCasillero;//ancho
    mina.rectImag.h= altoCasillero;//alto
}

void eliminarMina (Mina &mina){
    SDL_DestroyTexture(mina.imagen);
}


bool getEstado (Mina &mina){
    return mina.estado;
}

void setEstado (Mina &mina, bool estado){
    mina.estado=estado;
}

int  getPosX (Mina &mina){
    return mina.posX;
}

void setPosX (Mina &mina, int posX){
    mina.posX = posX;
}

int getPosY (Mina &mina){
    return mina.posY;
}

void setPosY (Mina &mina, int posY){
    mina.posY = posY;
}

int getIntervaloProduccion (Mina &mina){
    return mina.intervaloProduccion;
}

void setIntervaloProduccion (Mina &mina, int intervaloProduccion){
    mina.intervaloProduccion = intervaloProduccion;
}

ListaCajas getListaCajas (Mina &mina){
    return mina.cajas;
}

void setListaCajas (Mina &mina, ListaCajas cajas){
    mina.cajas = cajas;
}

int * getSecuencia (Mina &mina){
    return mina.secuencia;
}

void setSecuencia (Mina &mina, int* secuencia){
   for(int i=0;i<10;i++){
    mina.secuencia[i]=secuencia[i];
   }
}

void dibujarMina(Mina &mina, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, mina.imagen,NULL,&(mina.rectImag));
}
