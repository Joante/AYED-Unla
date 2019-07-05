#include "mina.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

void crearMina (Mina &mina, bool estado, int posX, int posY, int intervaloProduccion, int anchoCasillero, int altoCasillero, int secuencia[], Item item, SDL_Renderer* renderer)
{
    mina.posY= posY;//coordenada logica y
    mina.posX= posX;//coordenada logica x
//    mina.imagen = IMG_LoadTexture(renderer,"img/mina.png");
    mina.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    mina.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    mina.rectImag.w= anchoCasillero;//ancho
    mina.rectImag.h= altoCasillero;//alto
    mina.estado=estado;
    mina.intervaloProduccion=intervaloProduccion;
    Lista cajas;
    crearLista(cajas, comparaListaCaja);
    mina.cajas=cajas;
    mina.secuencia=secuencia;
    mina.item=item;

        char urlImagen[50];
        strcpy (urlImagen,"img/mina");
        char integer_string[5];
        sprintf(integer_string, "%d", item);
        strcat (urlImagen,integer_string);
        strcat (urlImagen,".png");
        mina.imagen= IMG_LoadTexture(renderer,urlImagen);

}

ResultadoComparacion comparaListaCaja(PtrDato ptrDato1, PtrDato ptrDato2)
{
           return IGUAL;
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

int * getSecuencia (Mina &mina){
    return mina.secuencia;
}

void setSecuencia (Mina &mina, int* secuencia){
   for(int i=0;i<10;i++){
    mina.secuencia[i]=secuencia[i];
   }
}

void dibujarMinas(Lista *mina, SDL_Renderer* renderer)
{
    PtrNodoLista nodo = primero(*mina);
    while(nodo!=finLista())
    {
        dibujarMina(*(Mina*)nodo->ptrDato, renderer);
        nodo = siguiente(*mina, nodo);
    }
}

void dibujarMina(Mina &mina, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, mina.imagen,NULL,&(mina.rectImag));
}


void generarTodasLasCajas(Lista *mina, int intervalo)
{
    PtrNodoLista nodo = primero(*mina);
    while(nodo!=finLista())
    {
        generarCajas(*(Mina*)nodo->ptrDato, intervalo);
        nodo = siguiente(*mina, nodo);
    }
}

void generarCajas(Mina &mina, int intervalo)
{
    int intervaloProduccion = mina.intervaloProduccion;
    int secuencia;

    if (intervalo % intervaloProduccion == 0)
    {
        secuencia=(intervalo/intervaloProduccion);
        while (secuencia >= 6)
        {
            secuencia = secuencia - 5;
        }

        Caja *caja = new Caja();
        crear(*caja, *(mina.secuencia+secuencia-1));
        adicionarFinal(mina.cajas, caja);

    /** aca descomentarlo */
      std::cout << "Caja creada. Total de lingotes: " << caja ->capMax  << std::endl;

    }
}
