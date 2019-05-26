#include <SDL.h>
#include <SDL_image.h>

#include "moneda.h"
#include <iostream>

using namespace std;

    int main(int argc, char** argv) {

        /*Datros que leo desde un archivo************/
        int filas = 8;int columnas = 10; int anchoCasillero = 50;  int altoCasillero = 50;
        /********************************************/
        int anchoVentana = columnas*anchoCasillero;
        int altoVentana = filas*altoCasillero;

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
        SDL_Window *window;
        SDL_Renderer *renderer;

        window = SDL_CreateWindow("moneda", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, anchoVentana, altoVentana,
        SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

        IMG_Init(IMG_INIT_PNG);

        Moneda moneda;
        crear(moneda,2,3,anchoCasillero,altoCasillero,renderer); //aparece en el cuadrante 2,3

        while(true){
                //aquí según los eventos de teclado podríamos cambiar las coordenadas de persona… tarea para la casa ;)
                SDL_RenderClear(renderer);//borro el renderer
                dibujar(moneda,renderer);
                SDL_RenderPresent(renderer);// dibuja el renderer, aplica todos los cambios que se hicieron en dibujarPersona()
                SDL_Delay(500);//milisegundos
        }
        eliminar(moneda);

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    }

    return 0;
}


