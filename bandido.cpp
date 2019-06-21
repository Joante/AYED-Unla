#include "bandido.h"
#include"SDL.h"
#include "SDL_image.h"
void constructor(Bandido &bandido)
{
    bandido.areaDeAtaque=0;
    bandido.cantidadSolicitada=0;
    bandido.itemSolicitado=0;
    bandido.posX=0;
    bandido.posY=0;



}

void destructor(Bandido &bandido) { }


void setPosX(Bandido &bandido,int posX)
{

    bandido.posX=posX;
}

int getPosX(Bandido &bandido)
{
    return bandido.posX;
}


void setPosY(Bandido &bandido,int posY)
{

    bandido.posY=posY;
}

int getPosY(Bandido &bandido)
{
    return bandido.posY;

}

void setAreaDeAtaque(Bandido &bandido,int areaDeAtaque)
{
    bandido.areaDeAtaque=areaDeAtaque;


}

int getAreaDeAtaque(Bandido &bandido)
{
    return bandido.areaDeAtaque;
}

void setCantidadSolicitada(Bandido &bandido,int cantidadSolicitada)
{
    bandido.cantidadSolicitada=cantidadSolicitada;

}

int getCantidadSolicitada(Bandido &bandido)
{
    return bandido.cantidadSolicitada;
}

void setItemSolicitado(Bandido &bandido,int itemSolicitado)
{

    bandido.itemSolicitado=itemSolicitado;
}

int getItemSolicitado(Bandido &bandido)
{

    return bandido.itemSolicitado;

}
Bandido& generarBandido(Bandido &Bandido) {}

void CrearBandido(Bandido &bandido, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer){
    bandido.f=f;//coordenada logica y
    bandido.c=c;//coordenada logica x
    bandido.imagen=IMG_LoadTexture(renderer,"villano.png");

    bandido.rectImag.y=f* altoCasillero;//coordenada de dibujo y
    bandido.rectImag.x= c* anchoCasillero;//coordenada de dibujo x
    bandido.rectImag.w= anchoCasillero;//ancho
    bandido.rectImag.h= altoCasillero;//alto
}
void DibujarBandido(Bandido &bandido, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, bandido.imagen,NULL,&(bandido.rectImag));
}

void DestruirBandida(Bandido &bandido){
    SDL_DestroyTexture(bandido.imagen);
}


//void robaBandido(Bandido &bandido, Locomotora &locomotora ){} // cocmentado falta implementacion de locomotora.


