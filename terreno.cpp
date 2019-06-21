#include "terreno.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

void crearTerreno(Terreno &terreno, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer,int numero){

    terreno.posY=f;//coordenada logica y
    terreno.posX=c;//coordenada logica x
    //terreno.imagen= IMG_LoadTexture(renderer,imagenTerreno);
       switch (numero){
        case 0:  terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_0.png");
        break;
        case 1:  terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_1.png");
        break;
        case 2:  terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_2.png");
        break;
        case 3:  terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_3.png");
        break;
        case 4:  terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_4.png");
        break;
        case 5:  terreno.imagen= IMG_LoadTexture(renderer,"img/suelo_5.png");
        break;
        default:;}

    terreno.rectImag.y=f* altoCasillero;//coordenada de dibujo y
    terreno.rectImag.x=c* anchoCasillero;//coordenada de dibujo x
    terreno.rectImag.w= anchoCasillero;//ancho
    terreno.rectImag.h= altoCasillero;//alto

}

void dibujarTerreno(Terreno &terreno, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, terreno.imagen,NULL,&(terreno.rectImag));
}

void destruirTerreno(Terreno &terreno){
    SDL_DestroyTexture(terreno.imagen);
}

