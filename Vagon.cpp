#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include"Vagon.h"
#include"Vagon.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

void crearVagon(Vagon &vagon, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer)
{
    vagon.id=1;
    vagon.estado=true;
    vagon.posY=posY;//coordenada logica y
    vagon.posX=posX;//coordenada logica x
    vagon.imagen= IMG_LoadTexture(renderer,"img/c2/der/0.png");

    vagon.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    vagon.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    vagon.rectImag.w= anchoCasillero;//ancho
    vagon.rectImag.h= altoCasillero;//alto
    vagon.estado=true;
    vagon.direccion=2;

}

void dibujarVagon(Vagon &vagon, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, vagon.imagen,NULL,&(vagon.rectImag));
}

void destruirVagon(Vagon &vagon)
{
    SDL_DestroyTexture(vagon.imagen);
}

void reubicarVagon(Vagon &vagon){
        if (vagon.direccion==0)
            vagon.posY++;

        if (vagon.direccion==1)
            vagon.posY--;

        if (vagon.direccion==2)
            vagon.posX++;

        if(vagon.direccion==3)
           vagon.posX--;
}

void moverVagon(Vagon &vagon, SDL_Renderer* renderer, int intervalo)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */

    int direccion = vagon.direccion;
//
//    if((vagon.direccion==0) && vagon.posY>getPosY(locomotora))
//        vagon.direccion=getDireccion(locomotora);
//
//    if((vagon.direccion==1) && vagon.posY<getPosY(locomotora))
//        vagon.direccion=getDireccion(locomotora);
//
//    if((vagon.direccion==3) && vagon.posX<getPosX(locomotora))
//        vagon.direccion=getDireccion(locomotora);
//
//    if((vagon.direccion==2) && vagon.posX>getPosX(locomotora))
//        vagon.direccion=getDireccion(locomotora);

    if (direccion == 0)
    {
        moverVagonAAbajo(vagon, renderer, intervalo);
    }
    else if (direccion == 1)
    {
        moverVagonAArriba(vagon, renderer, intervalo);

    }
    else if (direccion == 2)
    {
        moverVagonALaDerecha(vagon, renderer, intervalo);
    }

    else if (direccion == 3)
    {
        moverVagonALaIzquierda(vagon,  renderer,  intervalo);
    }
}

void moverVagonALaDerecha(Vagon &vagon, SDL_Renderer* renderer, int intervalo) //derecha
{
    vagon.rectImag.x+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/der/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverVagonALaIzquierda(Vagon &vagon, SDL_Renderer* renderer, int intervalo) //izquierda
{
    vagon.rectImag.x-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/izq/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverVagonAAbajo(Vagon &vagon, SDL_Renderer* renderer, int intervalo)
{
//abajo
    vagon.rectImag.y+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/aba/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverVagonAArriba(Vagon &vagon, SDL_Renderer* renderer, int intervalo) //arriba
{
    vagon.rectImag.y-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/arr/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}










void eliminarVagon(Vagon &vagon)
{

}

void setId(Vagon &vagon, int id)
{
    vagon.id=id;
}

int getId(Vagon &vagon)
{
    return vagon.id;
}
void setEstado(Vagon &vagon, bool estado)
{
    vagon.estado=estado;
}
bool getEstado(Vagon &vagon)
{
    return vagon.estado;
}
void setPesoMax(Vagon &vagon, int pesoMax)
{
    vagon.pesoMax=pesoMax;
}
int getPesoMax(Vagon &vagon)
{
    return vagon.pesoMax;
}
void setPesoUtilizado(Vagon &vagon, int pesoUtilizado)
{
    vagon.pesoUtilizado;
}
int getPesoUtilizado(Vagon &vagon)
{
    return vagon.pesoUtilizado;
}
void setItem(Vagon &vagon, Item item)
{
    vagon.item=item;
}

Item getItem(Vagon &vagon)
{
    return vagon.item;
}
