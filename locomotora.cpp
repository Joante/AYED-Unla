#include "locomotora.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

void crearLocomotora(Locomotora &locomotora, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer)
{
    locomotora.posY=posY;//coordenada logica y
    locomotora.posX=posX;//coordenada logica x
    locomotora.imagen= IMG_LoadTexture(renderer,"img/c1/der/0.png");

    locomotora.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    locomotora.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    locomotora.rectImag.w= anchoCasillero;//ancho
    locomotora.rectImag.h= altoCasillero;//alto
    locomotora.estado=true;
    locomotora.monedas=0;
    locomotora.direccion=2;

}

void dibujarLocomotora(Locomotora &locomotora, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, locomotora.imagen,NULL,&(locomotora.rectImag));
}

void destruirLocomotora(Locomotora &locomotora)
{
    SDL_DestroyTexture(locomotora.imagen);
}

void setPosY (Locomotora &locomotora, int posY)
{
    locomotora.posY=posY;
}

void setPosX (Locomotora &locomotora, int posX)
{
    locomotora.posX=posX;
}

int getPosY (Locomotora &locomotora)
{
    return locomotora.posY;
}

int getPosX (Locomotora &locomotora)
{
    return locomotora.posX;
}

void setEstado (Locomotora &locomotora, bool estado)
{
    locomotora.estado=estado;
}

bool getEstado(Locomotora &locomotora)
{
    return locomotora.estado;
}

int getDireccion (Locomotora &locomotora){
return locomotora.direccion;}

SDL_Rect getRectImag (Locomotora &locomotora){
return locomotora.rectImag;}

void setDireccion (Locomotora &locomotora, int direccion){
    locomotora.direccion=direccion;
}

void setRectImag (Locomotora &locomotora, SDL_Rect imagen){
}

void reubicarLocomotora(Locomotora &locomotora, Vagon &vagon){

    vagon.posX=locomotora.posX;
    vagon.posY=locomotora.posY;
    vagon.rectImag.x= vagon.posX*40;
    vagon.rectImag.y= vagon.posY*40;

        if (locomotora.direccion==0)
            locomotora.posY++;

        if (locomotora.direccion==1)
            locomotora.posY--;

        if (locomotora.direccion==2)
            locomotora.posX++;

        if(locomotora.direccion==3)
           locomotora.posX--;

        colisionLimites(locomotora);
}

int direccionarLocomotora(Locomotora &locomotora, SDL_Event evento)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */

    int direccion1=0;

    const unsigned char *keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_UP]&& locomotora.direccion!=0)
    {
        direccion1=1;
    }
    else if (keys[SDL_SCANCODE_DOWN] && locomotora.direccion!=1)
    {
        direccion1=0;
    }
    else if (keys[SDL_SCANCODE_RIGHT]&& locomotora.direccion!=3)
    {
        direccion1=2;
    }
    else if (keys[SDL_SCANCODE_LEFT]&& locomotora.direccion!=2)
    {
        direccion1=3;
    }
    std::cout << "direccion 1: " << direccion1 << "\n";
    return direccion1;
}

void moverLocomotora(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */

    int direccion = locomotora.direccion;

    if (direccion == 0)
    {
        moverLocomotoraAAbajo(locomotora, renderer, intervalo);
    }
    else if (direccion == 1)
    {
        moverLocomotoraAArriba(locomotora, renderer, intervalo);

    }
    else if (direccion == 2)
    {
        moverLocomotoraALaDerecha(locomotora, renderer, intervalo);
    }

    else if (direccion == 3)
    {
        moverLocomotoraALaIzquierda(locomotora,  renderer,  intervalo);
    }
    std::cout <<"\n( X:" << locomotora.posX << " Y:" << locomotora.posY <<")  \n";


}

void moverLocomotoraALaDerecha(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo) //derecha
{
    locomotora.rectImag.x+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/der/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverLocomotoraALaIzquierda(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo) //izquierda
{
    locomotora.rectImag.x-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/izq/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverLocomotoraAAbajo(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo)
{
//abajo
    locomotora.rectImag.y+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/aba/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverLocomotoraAArriba(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo) //arriba
{
    locomotora.rectImag.y-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/arr/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void colisionLimites (Locomotora &locomotora)
{

    if (locomotora.posY <0)
    {
        locomotora.estado=false;
    }
    else if (locomotora.posX <0)
    {
        locomotora.estado=false;
    }
    else if (locomotora.posY >14)
    {
        locomotora.estado=false;
    }
    else if (locomotora.posX >19)
    {
        locomotora.estado=false;
    }

}

 void sumarMoneda (Locomotora &locomotora){
    locomotora.monedas = locomotora.monedas + 1;
 }
