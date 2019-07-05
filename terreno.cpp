#include "terreno.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

void crearMatrizTerreno(Terreno &terreno,Terreno matrizTerreno[15][20], int filas, int columnas, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer){
int numero=0;
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {

                if (numero < 6)
                {
                    crearTerreno(terreno,i,j,anchoCasillero,altoCasillero,renderer, numero);
                    matrizTerreno[i][j] = terreno;
                    numero++;
                }
                else
                {
                    numero = 0;
                    crearTerreno(terreno,+i,j,anchoCasillero,altoCasillero,renderer, numero);
                    matrizTerreno[i][j] = terreno;
                    numero++;
                }
            }
        }
}

void crearTerreno(Terreno &terreno,int f,int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer,int numero){

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
        default:;
        }

   terreno.rectImag.y=f* altoCasillero;//coordenada de dibujo y
   terreno.rectImag.x=c* anchoCasillero;//coordenada de dibujo x
    terreno.rectImag.w= anchoCasillero;//ancho
    terreno.rectImag.h= altoCasillero;//alto

}

void dibujarTerreno(Terreno &terreno,Terreno matrizTerreno[15][20],int filas,int columnas, SDL_Renderer* renderer){

                for (int i = 0; i < filas; i++)
                {
                    for (int j = 0; j < columnas; j++)
                    {
                        Terreno terrenos = matrizTerreno[i][j];
                        SDL_RenderCopy(renderer, terrenos.imagen,NULL,&(terrenos.rectImag));
                    }
                }


}

void destruirTerreno(Terreno &terreno){
    SDL_DestroyTexture(terreno.imagen);
}

void setPosX (Terreno &terreno, int posX){
terreno.posX = posX;
}

void setPosY (Terreno &terreno, int posY){
terreno.posX = posY;
}

void setAnchoCasilleroTerreno(Terreno &terreno, int anchoCasillero){
    terreno.anchoCasillero = anchoCasillero;
}

int getAnchoCasilleroTerreno(Terreno &terreno){
    return terreno.anchoCasillero;
}

void setAltoCasilleroTerreno(Terreno &terreno, int altoCasillero){
    terreno.altoCasillero = altoCasillero;
}

int getAltoCasilleroTerreno(Terreno &terreno){
    return terreno.altoCasillero;
}
int getPosX (Terreno &terreno){
    return terreno.posX;
}

int getPosY (Terreno &terreno){
    return terreno.posY;
}

bool getEstado (Terreno &terreno){
    return terreno.estado;
}

void setEstado (Terreno &terreno, bool estado){
    terreno.estado=estado;
}

