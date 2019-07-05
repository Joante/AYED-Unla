#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include"Vagon.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

void crearVagon(Vagon &vagon, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer, int monedas, int x, int y, int direccion)
{
    vagon.id=1;
    vagon.estado=true;
    vagon.posY=posY;//coordenada logica y
    vagon.posX=posX;//coordenada logica x
    vagon.imagen= IMG_LoadTexture(renderer,"img/c2/der/0.png");

    vagon.rectImag.y=y;//coordenada de dibujo y
    vagon.rectImag.x=x;//coordenada de dibujo x
    vagon.rectImag.w= anchoCasillero;//ancho
    vagon.rectImag.h= altoCasillero;//alto
    vagon.estado=true;
    vagon.direccion=direccion;
    vagon.monedas=monedas;
    Pila cajas;
    crearPila(cajas);
    vagon.cajas = cajas;
    vagon.pesoMax= monedas*5;
    vagon.pesoUtilizado=0;
    vagon.item=vacio;

}

void setDireccion(Vagon &vagon, int direccion)
{
    vagon.direccion=direccion;
}

void setPesoUtilizado(Vagon &vagon, int pesoUtilizado)
{
    vagon.pesoUtilizado=pesoUtilizado;
}

void setCajas(Vagon &vagon, Pila cajas)
{
    vagon.cajas=cajas;
}

int getDireccion(Vagon &vagon)
{
    return vagon.direccion;
}

int getPosY(Vagon &vagon)
{
    return vagon.posY;
}

int getPosX(Vagon &vagon)
{
    return vagon.posX;
}

Pila getCajas(Vagon &vagon)
{
    return vagon.cajas;
}

void dibujarVagon(Vagon &vagon, SDL_Renderer* renderer)
{
    //std::cout << "test " << vagon.id << std::endl;
    SDL_RenderCopy(renderer, vagon.imagen,NULL,&(vagon.rectImag));
}

void destruirVagon(Vagon &vagon)
{
    SDL_DestroyTexture(vagon.imagen);
}

void reubicarVagon(Vagon &vagon)
{
//    if (vagon.direccion==0)
//        vagon.posY++;
//
//    if (vagon.direccion==1)
//        vagon.posY--;
//
//    if (vagon.direccion==2)
//        vagon.posX++;
//
//    if(vagon.direccion==3)
//        vagon.posX--;

    vagon.posX=vagon.rectImag.x/40;
    vagon.posY=vagon.rectImag.y/40;

        std::cout << "Vagon: posx:" << vagon.posX << " posy: " << vagon.posY << std::endl;
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
    strcpy (urlImagen,"img/c2/der/0");
    char integer_string[5];
    sprintf(integer_string, "%d", getItem(vagon));
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverVagonALaIzquierda(Vagon &vagon, SDL_Renderer* renderer, int intervalo) //izquierda
{
    vagon.rectImag.x-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/der/0");
    char integer_string[5];
    sprintf(integer_string, "%d", getItem(vagon));
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverVagonAAbajo(Vagon &vagon, SDL_Renderer* renderer, int intervalo)
{
//abajo
    vagon.rectImag.y+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/aba/0");
    char integer_string[5];
    sprintf(integer_string, "%d", getItem(vagon));
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    vagon.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverVagonAArriba(Vagon &vagon, SDL_Renderer* renderer, int intervalo) //arriba
{
    vagon.rectImag.y-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c2/aba/0");
    char integer_string[5];
    sprintf(integer_string, "%d", getItem(vagon));
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

void destellosVagon(Vagon vagon, SDL_Renderer* renderer)
{
    int i=2;

    for (i=2; i<10; i++)

        SDL_RenderClear(renderer);
    if (i%2==0)
    {
        dibujarVagon(vagon, renderer);
    }
    SDL_RenderPresent (renderer);
    SDL_Delay(30);

}
