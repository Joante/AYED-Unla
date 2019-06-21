#include "locomotora.h"
#include "bandido.h"
#include "vagon.h"
#include "terreno.h"
#include "moneda.h"
#include "estacion.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include<cstdio>

using namespace std;
int colision(SDL_Rect H,SDL_Rect M)
{
    if (((H.x + H.w) > M.x) && ((H.y + H.h) > M.y) &&
            ((M.x + M.w) > H.x) && ((M.y + M.h) > H.y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char** argv)
{

    /*Datros que leo desde un archivo************/
    int filas = 15;
    int columnas = 20;
    int anchoCasillero = 40;
    int altoCasillero = 40;
    /********************************************/
    int anchoVentana = columnas*anchoCasillero;
    int altoVentana = filas*altoCasillero;
    int puntos=0;
    char titulo[255];
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        int typeEvent;

        window = SDL_CreateWindow("Clash of UNLa", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, anchoVentana, altoVentana,
                                  SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

        IMG_Init(IMG_INIT_PNG);


        Locomotora locomotora;
        Terreno terreno;
        Vagon vagon;
        Estacion estacion;
        Moneda moneda;
        Bandido bandido;
        CrearBandido(bandido,5,5,anchoCasillero,altoCasillero,renderer);
        crearLocomotora(locomotora,3,4,anchoCasillero,altoCasillero,renderer);
        crearVagon(vagon,3,3,anchoCasillero,altoCasillero,renderer); //aparece en el cuadrante 2,3
        crearEstacion(estacion,1,1,anchoCasillero,altoCasillero,renderer);
        crearMoneda(moneda,6,6,anchoCasillero,altoCasillero,altoVentana,anchoVentana,renderer);
        int direccion1=2;
        int subIntervalo=0;

        //TERRENO

        Terreno matrizTerreno[filas][columnas];
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



        while(getEstado(locomotora))
        {

            sprintf(titulo,"Clash of UNLa -- Puntos: %d",puntos);
            sprintf(titulo,"Clash of UNLa -- Monedas: %d",locomotora.monedas);
            if(colision(locomotora.rectImag,estacion.rectImag)==1)
            {
                SDL_ShowSimpleMessageBox(
                    SDL_MESSAGEBOX_INFORMATION,
                    "DESEA COMPRAR UN VAGON?",
                    "AUNQUE YA TENGA UNO XD",
                    NULL);
            }

            if(colision(locomotora.rectImag,moneda.rectImag)==1)
            {
                sumarMoneda(locomotora);
                eliminarMoneda(moneda);
            }

            if (subIntervalo==10)
            {
                subIntervalo=0;
            }

            SDL_RenderClear(renderer);
            cout << " dibujo \n";
            moverLocomotora(locomotora, renderer, subIntervalo);
            moverVagon(vagon,renderer,subIntervalo);
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    dibujarTerreno(matrizTerreno[i][j],renderer);
                }
            }
            DibujarBandido(bandido,renderer);
            dibujarEstacion(estacion,renderer);
            dibujarLocomotora(locomotora,renderer);
            dibujarVagon(vagon, renderer);
            dibujar(moneda, renderer);

            SDL_RenderPresent(renderer);

            if(SDL_PollEvent(&event))
            {
                typeEvent = event.type;
                if (typeEvent == SDL_QUIT)
                {
                    setEstado(locomotora, false);
                }
                else if (typeEvent == SDL_KEYDOWN)
                {
                    direccion1=direccionarLocomotora(locomotora,event);
                }
            }

            if (subIntervalo==1)
            {
                reubicarLocomotora(locomotora, vagon);
                reubicarVagon(vagon);
            }

            if(subIntervalo == 0)
            {
                setDireccion(locomotora, direccion1);
            }

//                       }
            cout << subIntervalo;
            subIntervalo++;
            SDL_Delay(300);
            puntos++;
            SDL_SetWindowTitle ( window ,titulo);

        }

        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_INFORMATION,
            "Fin del juego",
            "perdiste :(",
            NULL);


        destruirLocomotora(locomotora);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    }

    return 0;
}


