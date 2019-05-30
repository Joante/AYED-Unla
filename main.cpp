#include "locomotora.h"
#include "terreno.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>

using namespace std;

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

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        int typeEvent;

        window = SDL_CreateWindow("Ejemplo Juego Locomotora", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, anchoVentana, altoVentana,
        SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

        IMG_Init(IMG_INIT_PNG);

        Locomotora locomotora;
        Terreno terreno;
        crearTerreno(terreno,0,0,anchoVentana,altoVentana,renderer);
        crearLocomotora(locomotora,0,0,anchoCasillero,altoCasillero,renderer); //aparece en el cuadrante 2,3

        int subIntervalo=0;

        while(getEstado(locomotora))
        {
            if(SDL_PollEvent(&event))
            {
                typeEvent = event.type;
                if (typeEvent == SDL_QUIT)
                {
                    setEstado(locomotora, false);
                }
                else if (typeEvent == SDL_KEYDOWN)
                {
                    direccionarLocomotora(locomotora,event);
                }
            }

            if(subIntervalo == 10)
            {
                subIntervalo = 0;
                /*
                abajo 0
                arriba 1
                derecha 2
                izquierda 3
                */
            }

            SDL_RenderClear(renderer);
               //borro el renderer
        moverLocomotora(locomotora, renderer, subIntervalo);
        dibujarTerreno(terreno,renderer);
        dibujarLocomotora(locomotora,renderer);

                    SDL_RenderPresent(renderer);
//                       }
        subIntervalo++;
        SDL_Delay(50);//milisegundos
        std::cout <<"\n( DIBUJADO X:" << locomotora.rectImag.x << " DIBUJADO Y:" << locomotora.rectImag.y <<")  \n";
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
//    getch();
    return 0;
}
