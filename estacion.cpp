#include "estacion.h"
#include <iostream>
#include"SDL.h"
#include"SDL_image.h"

void crear (Estacion &estacion) {}

void eliminar (Estacion &estacion) {}

int getPosXE (Estacion &estacion)
{
    return estacion.posXE;
}

int getPosYE (Estacion &estacion)
{
    return estacion.posYE;
}

void setPosXE (Estacion &estacion, int posXE)
{
    estacion.posXE = posXE;
}

void setPosYE (Estacion &estacion, int posYE)
{
    estacion.posYE = posYE;
}

/* ? */

void agregarVagon (Estacion &estacion, Lista &caravana, SDL_Renderer* renderer)
{
    //hasta que se implemente la cantidad de monedas, le pongo 1;
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */
    Vagon *vagon = new Vagon();
    int y, x, posX, posY, direccion, numero;
    numero=longitud(caravana);
    PtrNodoLista nodo = primero(caravana);
    Locomotora locomotora = *(Locomotora*)nodo->ptrDato;

    if (numero==1)
    {
        y= locomotora.rectImag.y;
        x= locomotora.rectImag.x;
        posX= locomotora.posX;
        posY= locomotora.posY;
        direccion = getDireccion(locomotora);
    }
    else
    {
        Vagon vagon = *(Vagon*)ultimo(caravana)->ptrDato;
        y= vagon.rectImag.y;
        x= vagon.rectImag.x;
        posX= vagon.posX;
        posY=vagon.posY;
        direccion = vagon.direccion;
    }

    if (direccion==0)
    {
        y=y-locomotora.altoCasillero;
        posY--;
    }
    if (direccion==1)
    {
        y=y+locomotora.altoCasillero;
        posY++;
    }
    if (direccion==2)
    {
        x=x-locomotora.anchoCasillero;
        posX++;

    }
    if (direccion==3)
    {
        x=x+locomotora.anchoCasillero;
        posX--;
    }

    crearVagon(*vagon, posX, posY, locomotora.altoCasillero, locomotora.anchoCasillero, renderer, getMonedas(locomotora), x, y, locomotora.direccion);
    std::cout << "Tu vagon nuevo tiene un espacio de: " << vagon->pesoMax << std::endl;
    adicionarFinal(caravana, vagon);
    setMonedas(*(Locomotora*)nodo->ptrDato, 0);

}


void crearEstacion(Estacion &estacion, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer)
{
    estacion.posYE=posY;//coordenada logica y
    estacion.posXE=posX;//coordenada logica x
    estacion.imagen= IMG_LoadTexture(renderer,"img/estacion.png");

    estacion.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    estacion.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    estacion.rectImag.w= anchoCasillero;//ancho
    estacion.rectImag.h= altoCasillero;//alto
}

void dibujarEstacion(Estacion &estacion, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, estacion.imagen,NULL,&(estacion.rectImag));
}


void colisionEstacion (Estacion estacion,Locomotora &locomotora, Lista *caravana, int &direccion, SDL_Renderer* renderer)
{

    int x = getPosX(locomotora);
    int y = getPosY(locomotora);
    int estacionY, estacionX;
    estacionY = getPosYE(estacion);
    estacionX = getPosXE(estacion);

    if (direccion == 0)
    {
        y++;
    }
    else if (direccion == 1)
    {
        y--;

    }
    else if (direccion == 2)
    {
        x++;
    }
    else if (direccion == 3)
    {
        x--;
    }

    if (x==estacionX && y==estacionY)
    {
        agregarVagon(estacion, *caravana, renderer);
        detenerse(locomotora, direccion);
    }

}
