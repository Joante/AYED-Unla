#include "mina.h"
#include "caja.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

void crearMina (Mina &mina){
}

void construirMina(Mina &mina, bool estado, int posX, int posY, int intervaloProduccion, int anchoCasillero, int altoCasillero, int secuencia[2], std::string material, SDL_Renderer* renderer){
    mina.posY= posY;//coordenada logica y
    mina.posX= posX;//coordenada logica x
    mina.imagen = IMG_LoadTexture(renderer,"img/mina.png");

    mina.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    mina.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    mina.rectImag.w= anchoCasillero;//ancho
    mina.rectImag.h= altoCasillero;//alto)
    setSecuencia(mina, secuencia);
    mina.intervaloProduccion = intervaloProduccion;
    mina.material = material;
    mina.contadorSecuencia = 0;
    mina.estado=estado;
}

void dibujarMina(Mina &mina, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, mina.imagen,NULL,&(mina.rectImag));
}

void eliminarMina (Mina &mina){
    SDL_DestroyTexture(mina.imagen);
}


bool getEstadoMina(Mina &mina){
    return mina.estado;
}

void setEstadoMina (Mina &mina, bool estado){
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

Caja getPilaCajas (Mina &mina){
    return mina.cajas;
}

void setPilaCajas (Mina &mina, Caja cajas){
    mina.cajas = cajas;
}

int * getSecuencia (Mina &mina){
    return mina.secuencia;
}

void setSecuencia (Mina &mina, int* secuencia){
   for(int i=0;i<2;i++){
    mina.secuencia[i]=secuencia[i];
   }
}

void setMaterialMina (Mina &mina, std::string material){
    mina.material = material;
}

std::string getMaterialMina(Mina &mina){
    return mina.material;
}

void producirCaja (Mina &mina){
    Caja* caja = new Caja;
    construirCaja(*caja,getMaterialMina(mina), mina.secuencia[mina.contadorSecuencia]);
    //push(mina.cajas, caja);
    if(mina.contadorSecuencia < 2){
        mina.contadorSecuencia++;
    }else {
        mina.contadorSecuencia=0;
    }
    mina.cajas = *caja;
}

