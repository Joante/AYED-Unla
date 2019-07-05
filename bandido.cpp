#include "bandido.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

void generarBandido(Bandido &bandido, int areaDeAtaque, int anchoCasillero, int altoCasillero, int maxPermitido, int maxIntervalo, int maxVida, SDL_Renderer* renderer, int intervaloBandido)
{
    /**La generación del bandido también determina en forma aleatoria el ítem que va a requerir
    y la cantidad del mismo, pudiendo ser un número entero entre 1 y el máximo permitido (P).*/

    // cantidad
    srand(time(NULL));
    //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    bandido.cantidadSolicitada = 1 + rand() % (maxPermitido);
    bandido.tiempoDeVida = (1 + rand() % (maxVida))+intervaloBandido;
    int y = 0 + rand() % (14 + 1);
    int x = 0 + rand() % (19 + 1);
    bandido.posY= y;//coordenada logica y
    bandido.posX= x;//coordenada logica x
    bandido.imagen= IMG_LoadTexture(renderer,"img/villano.png");
    bandido.rectImag.y=y* altoCasillero;//coordenada de dibujo y
    bandido.rectImag.x=x* anchoCasillero;//coordenada de dibujo x
    bandido.rectImag.w= anchoCasillero;//ancho
    bandido.rectImag.h= altoCasillero;//alto
    bandido.areaDeAtaque=areaDeAtaque;

    //El aleatorio para el item
    int item = 1+ rand() % (6); // porque son 6 items

    std::cout << "bandido: cantidad solicitada " << bandido.cantidadSolicitada << ", tiempo de vida " << bandido.tiempoDeVida <<std::endl;

    bandido.itemSolicitado=plata;
//    switch (item){
//    case 1:
//        bandido.itemSolicitado=oro;
//        std::cout << "El bandido quiere: oro" << std::endl;
//        break;
//    case 2:
//        bandido.itemSolicitado=plata;
//        std::cout << "El bandido quiere: plata" << std::endl;
//        break;
//    case 3:
//        bandido.itemSolicitado=platino;
//        std::cout << "El bandido quiere: platino" << std::endl;
//        break;
//    case 4:
//        bandido.itemSolicitado=roca;
//        std::cout << "El bandido quiere: roca" << std::endl;
//        break;
//    case 5:
//        bandido.itemSolicitado=bronce;
//        std::cout << "El bandido quiere: bronce" << std::endl;
//        break;
//    case 6:
//        bandido.itemSolicitado=carbon;
//        std::cout << "El bandido quiere: carbon" << std::endl;
//        break;
//    }
//    std::cout << "bandido: posicion x" << bandido.posX << ", posY " << bandido.posY << std::endl;
}



void destructor(Bandido &bandido)
{
    SDL_DestroyTexture(bandido.imagen);
}

void setPosX(Bandido &bandido,int posX) {}

int getPosX(Bandido &bandido)
{
    return bandido.posX;
}

void setPosY(Bandido &bandido,int posY) {}

int getPosY(Bandido &bandido)
{
    return bandido.posY;
}

void setAreaDeAtaque(Bandido &bandido,int areaDeAtaque) {}

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

void setItemSolicitado(Bandido &bandido,int itemSolicitado) {}

Item getItemSolicitado(Bandido &bandido)
{
    return bandido.itemSolicitado;
}

//void robaBandido(Bandido &bandido, Locomotora &locomotora ){}

void dibujarBandido(Bandido &bandido, SDL_Renderer* renderer, bool hayBandido)
{
    if (hayBandido)
        SDL_RenderCopy(renderer, bandido.imagen,NULL,&(bandido.rectImag));
}

void crearBandido (Bandido &bandido, int areaDeAtaque, int anchoCasillero, int altoCasillero, int maxPermitido, int maxVida, int maxIntervalo, SDL_Renderer* renderer, bool &hayBandido, int intervaloBandido)
{

    int aleatorio;
    srand(time(NULL));
    //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;

    if (!hayBandido)
    {
        if (intervaloBandido >= maxIntervalo)
        {
            generarBandido(bandido, areaDeAtaque, anchoCasillero, altoCasillero, maxPermitido, maxIntervalo, maxVida, renderer, intervaloBandido);
            hayBandido = true;
        }
        else
        {
            aleatorio = 1 + rand() % (3);
            if (aleatorio % 2 ==0)
            {
                generarBandido(bandido, areaDeAtaque, anchoCasillero, altoCasillero, maxPermitido, maxIntervalo, maxVida, renderer, intervaloBandido);
                hayBandido = true;
            }
        }
    }
}

void matarBandido (Bandido &bandido, int &intervalo, bool &hayBandido)
{
    if (bandido.tiempoDeVida==intervalo)
    {
        hayBandido = false;
        destructor(bandido);
        intervalo =0;
    }

}

void choqueBandido (Bandido &bandido, Lista *caravana, bool &hayBandido, int direccion)
{
    //primero tenemos que ver cual es el rango
    /**
    xxxxx  y aca es -2 +2
    xxxxx
    xxbxx
    xxxxx
    xxxxx  x aca es -2 +2
    entonces, si y esta entre esos numeros e y esta entre esos numeros, esta en el rango.
    recorremos toda la lista y vamos comparanto todos

    Si choca, llamamos a robar
    */
    if (hayBandido)
    {

        int y1, y2, x1, x2, rango;
        rango = bandido.areaDeAtaque;
        y1 = (bandido.posY)- rango;
        y2 = (bandido.posY)+ rango;
        x1 = (bandido.posX)- rango;
        x2 = (bandido.posX)+ rango;
        bool choca = false;

        PtrNodoLista nodo = primero(*caravana);
        Locomotora locomotora = *(Locomotora*) nodo->ptrDato;
        //> <
        int x = getPosX(locomotora);
        int y = getPosY(locomotora);

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

        //se fija si la locomotora va a chocar en el proximo intervalo
        if (x>=x1 && x<=x2 && y>=y1 && y<=y2)
        {
            choca=true;
            std::cout << "Locomotora: " <<getPosX(locomotora)<< " " << getPosY(locomotora) <<std::endl;
            std::cout << x1<< " " << x2 << " y: " << y1<< " " << y2 <<std::endl;
        }

        // se fija si la locomotora ya está en rango
        if (getPosX(locomotora)>=x1 && getPosX(locomotora)<=x2 && getPosY(locomotora)>=y1 && getPosY(locomotora)<=y2)
        {
            choca=true;
            std::cout << "Locomotora: " <<getPosX(locomotora)<< " " << getPosY(locomotora) <<std::endl;
            std::cout << x1<< " " << x2 << " y: " << y1<< " " << y2 <<std::endl;
        }

        // se fija si los vagones estan en rango ya
        if (nodo!=finLista())
        {
            nodo = siguiente(*caravana, nodo);

            while (!choca && nodo!=finLista())
            {
                Vagon vagon = *(Vagon*) nodo ->ptrDato;
                if (getPosX(vagon)>=x1 && getPosX(vagon)<=x2 && getPosY(vagon)>=y1 && getPosY(vagon)<=y2)
                {
                    choca=true;
                    std::cout << "Vagon: " <<getPosX(vagon)<< " " << getPosY(vagon) <<std::endl;
                    std::cout << x1<< " " << x2 << " y: " << y1<< " " << y2 <<std::endl;
                }
                nodo = siguiente(*caravana, nodo);
            }
        }

        if (choca)
            robar(bandido, hayBandido, caravana);
    }
}

void robar(Bandido &bandido, bool &hayBandido, Lista *caravana)
{
    SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_INFORMATION,
        "HOLI, TE ROBO",
        "Veamos si tenes lo que quiero",
        NULL);

    Item itemBandido = getItemSolicitado(bandido);
    PtrNodoLista nodo = primero(*caravana);
    nodo = siguiente(*caravana, nodo);
    bool alcanzo = false;

    //lo primero que hace es ver si te alcanza para pagar
    while (nodo!=finLista())
    {
        if (getItem(*(Vagon*)nodo->ptrDato)==itemBandido)
        {
            robarCajas(bandido, *(Vagon*)nodo->ptrDato, caravana, alcanzo);
        }
        nodo=siguiente(*caravana,nodo);
    }
    if (!alcanzo)
    {
        eliminarVagon(bandido, caravana);
    }
    else
    {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_INFORMATION,
            "HOLI, TE ROBO",
            "Lo tenes, asi que me lo llevo :)",
            NULL);
    }

    destructor(bandido);
    hayBandido=false;
}

void robarCajas (Bandido &bandido, Vagon &vagon, Lista *caravana, bool &alcanzo)
{
    //when will we believ eittt
    /**
    hay que sacar el top, ver si alcanza
    - Si alcanza, se resta lo que quiere el bandido
    Si la caja no queda en 0, se suma de nuevo
    - Si no alcanza, se saca otra caja
    */
    if (!pilaVacia(vagon.cajas))
    {
        PtrDato caja = sacar(vagon.cajas);
        int totalRobar = bandido.cantidadSolicitada;
        int totalCaja = (*(Caja*)caja).capActual;

        if (totalCaja==totalRobar)
        {
            alcanzo=true;
            std::cout << "Primer caso: Me alcanza justito " << std::endl;
            std::cout << "el bandido quiere: " << totalRobar << std::endl;
            std::cout << "esta caja tiene: " << totalCaja << std::endl;
        }
        else if (totalCaja > totalRobar)
        {
            totalCaja=totalCaja-totalRobar;
            setCapActual(*(Caja*)caja,totalCaja);
            std::cout << "Segundo caso: Me alcanza trank" << std::endl;
            std::cout << "el bandido quiere: " << totalRobar << std::endl;
            std::cout << "esta caja tiene: " << totalCaja << std::endl;
            agregar(vagon.cajas, caja);
            alcanzo=true;
        }
        else
        {
            setCantidadSolicitada(bandido, (totalRobar-totalCaja));

            std::cout << "Tercer caso: No me alcanza :( " << std::endl;
            std::cout << "el bandido quiere: " << totalRobar << std::endl;
            std::cout << "esta caja tiene: " << totalCaja << std::endl;

            robarCajas(bandido, vagon, caravana, alcanzo);

        }
    }
}

void eliminarVagon (Bandido &bandido, Lista *caravana)
{
    // para eliminar un vagon
    PtrNodoLista nodo = primero(*caravana);
    if (siguiente(*caravana, nodo)==finLista())
    {
        setEstado(*(Locomotora*)nodo->ptrDato, false);
    }
    nodo= ultimo(*caravana);
    eliminarVagon(*(Vagon*)nodo->ptrDato);
    eliminarNodo(*caravana, ultimo(*caravana));

    SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_INFORMATION,
        "HOLI, TE ROBO",
        "No lo tenes, me llevo un vagon",
        NULL);
}

int getTiempoDeVidaBandido (Bandido &bandido){
    return bandido.tiempoDeVida;
}

void setTiempoDeVidaBandido (Bandido &bandido, int tiempoDeVida){
    bandido.tiempoDeVida = tiempoDeVida;
}

void setAnchoCasilleroBandido (Bandido &bandido, int anchoCasillero){
    bandido.anchoCasillero = anchoCasillero;
}

int getAnchoCasilleroBandido (Bandido &bandido){
    return bandido.anchoCasillero;
}

void setAltoCasilleroBandido (Bandido &bandido, int altoCasillero){
    bandido.altoCasillero = altoCasillero;
}

int getAltoCasilleroBandido (Bandido &bandido){
    return bandido.altoCasillero;
}

//void setImagenBandido (Bandido &bandido, SDL_Texture imagen){
//}

//SDL_Texture getImagenBandido (Bandido &bandido){
//}

void setRectBandido (Bandido &bandido, SDL_Rect rectImagen){
}

SDL_Rect getRectBandido (Bandido &bandido){
    return bandido.rectImag;
}
