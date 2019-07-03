#include "locomotora.h"
#include "bandido.h"
#include "vagon.h"
#include "terreno.h"
#include "moneda.h"
#include "estacion.h"
#include "pantalla.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdio>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include<string.h>
#include<SDL_ttf.h>

using namespace std;

void cambiarDireccionVagones (PtrNodoLista ptrNodo, int direccion);
void cambiarDireccion(Lista caravana, int direccion);
ResultadoComparacion comparaListaVagonVagones(PtrDato ptrDato1, PtrDato ptrDato2)
{
    int dato1 = ((Vagon*) ptrDato1)->id;
    int dato2 = ((Vagon*) ptrDato2)->id;

    if (dato1 < dato2)
    {
        return MENOR;
    }
    else if (dato1 > dato2)
    {
        return MAYOR;
    }
    else
    {
        return IGUAL;
    }
}

int colision(SDL_Rect H, SDL_Rect M, int dir)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */
    if (dir==0)
    {
        H.h++;
    }
    else if (dir==1)
    {
        H.y--;

    }
    else if (dir==2)
    {
        H.w++;

    }
    else if (dir==3)
    {
        H.x--;
    }


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

void manejoDelTeclado (int &direccion, Locomotora &locomotora, bool &moverse)
{
    int typeEvent;
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        typeEvent = event.type;
        if (typeEvent == SDL_QUIT)
        {
            setEstado(locomotora, false);
        }
        else if (typeEvent == SDL_KEYDOWN)
        {
            direccion=direccionarLocomotora(locomotora,event);
            moverse=true;
        }
    }
}

void detenerse(Locomotora &locomotora, Lista caravana, int &direccion1)

{
    int typeEvent;
    SDL_Event event;
    int direccionAnterior = direccion1;

    //Si la direccion que me tiraste es la misma que la que venias, no vamos a andar
    while (direccionAnterior==direccion1)
    {
        if(SDL_PollEvent(&event))
        {
            typeEvent = event.type;
            if (typeEvent == SDL_KEYDOWN)
            {
                direccion1=direccionarLocomotora(locomotora,event);


            }
        }
    }
}
void getTextoRectang(SDL_Renderer *renderer, int x, int y, char *texto,
                     TTF_Font *fuente, SDL_Texture **textura, SDL_Rect *rectangulo)
{
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};
    surface = TTF_RenderText_Solid(fuente, texto, textColor);
    *textura = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rectangulo->x = x;
    rectangulo->y = y;
    rectangulo->w = text_width;
    rectangulo->h = text_height;
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

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {

        /** Variables de SDL */

        SDL_Window *window;
        SDL_Renderer *renderer;
        window = SDL_CreateWindow("Clash of UNLa", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, anchoVentana, altoVentana,
                                  SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        IMG_Init(IMG_INIT_PNG);
//IMPLEMENTACION DE TEXTO PRUEBA 1
        
	TTF_Init();
        
	TTF_Font *Fuente= TTF_OpenFont("fuente.ttf",20);
	SDL_Texture *textura;
       
	SDL_Rect rectangulo;
        /** Inicializacion de TDA */

        Locomotora locomotora;
        Locomotora* ptroLocomotora = &locomotora;
        Terreno terreno;
        Estacion estacion;
        Moneda moneda;
        Bandido bandido;
        Vagon vagon;
        Lista caravana;
        PtrNodoLista nodo;
        Pantalla pantalla;
//        crearVagon(vagon,4,4,anchoCasillero,altoCasillero,renderer, 5, 1, 1);
        //crearListaVagon(vagones);
        adicionarPrincipio(caravana, ptroLocomotora);
        crearPantalla(pantalla,&caravana,&moneda, filas, columnas, anchoCasillero,altoCasillero);
        setMatrizTerreno(pantalla, renderer);
        crearBandido(bandido,5,5,anchoCasillero,altoCasillero,renderer);
        crearLocomotora(locomotora,0,0,anchoCasillero,altoCasillero,renderer);
        crearEstacion(estacion,5,5,anchoCasillero,altoCasillero,renderer);
        crearMoneda(moneda,6,6,anchoCasillero,altoCasillero,altoVentana,anchoVentana,renderer);

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

        /** Variables de manejo de intervalo y movimiento */

        int direccion1=2;
        int subIntervalo=0;
        bool moverse = true;
        char titulo[255];
        char texto[100]="WE ARE THE CHAMPIONS";

        /**While del juego*/

        while(getEstado(locomotora))
        {

            /** Manejo de teclado */
            /*Puede cerrar la pantalla haciendo click en la x
            Puede tomar un valor de las flechas, guardarlo, y despues cambiamos direccion
            */
            manejoDelTeclado (direccion1, locomotora, moverse);
            sprintf(titulo,"Clash of UNLa -- Monedas: %d",locomotora.monedas);

            if (moverse==true)
            {

                if (subIntervalo==10 || subIntervalo==0)
                {
                    subIntervalo=0;
                    cambiarDireccion(caravana,direccion1);
                    reubicarLocomotora(locomotora);
                    //reubicarVagon(vagon);
                }

                //Dibuja la locomotora en el espacio que corresponde, con el sprite correspondiente al subintervalo
                moverLocomotora(locomotora, renderer, subIntervalo);
                nodo=primero(caravana);
                while(siguiente(caravana, nodo)!=finLista())
                {
                    nodo=siguiente(caravana,nodo);
                    moverVagon(*(Vagon*)nodo->ptrDato, renderer, subIntervalo);
                }

                if (subIntervalo==9)
                {
                    if(colision(locomotora.rectImag,estacion.rectImag,direccion1)==1)
                    {
                        SDL_ShowSimpleMessageBox(
                            SDL_MESSAGEBOX_INFORMATION,
                            "DESEA COMPRAR UN VAGON?",
                            "AUNQUE YA TENGA UNO XD",
                            NULL);
                        agregarVagon(estacion, caravana, 4, renderer);
                        detenerse(locomotora, caravana, direccion1);
                    }
                }


                //el tema de la colision es la siguiente: le sumamos/restamos 1 dependiendo de la direccion.

                if(colision(locomotora.rectImag,moneda.rectImag, getDireccion(locomotora))==1)
                {
                    sumarMoneda(locomotora);
                    eliminarMoneda(moneda);
                    puntos++;
                }

                /** Dibujo de pantalla */

                SDL_RenderClear(renderer);

                /**Dibujo de TDA*/
                //dibujarTerrenos(pantalla, renderer);

                for (int i = 0; i < filas; i++)
                {
                    for (int j = 0; j < columnas; j++)
                    {
                        dibujarTerreno(matrizTerreno[i][j],renderer);
                    }
                }

                dibujarEstacion(estacion,renderer);
                /**dibujamos locomotora+vagones*/
                dibujarLocomotora(locomotora,renderer);
                nodo=primero(caravana);
                while(siguiente(caravana, nodo)!=finLista())
                {
                    nodo=siguiente(caravana,nodo);
                    dibujarVagon(*(Vagon*)nodo->ptrDato, renderer);
                }

                dibujar(moneda, renderer);
                SDL_RenderPresent(renderer);


                /** Cuando es subintervalo 1, ya se considera en el siguiente casillero
                Por esto, cambiamos los valores de x e y de los tda */

//                if (subIntervalo==1)
//                {
//                    reubicarLocomotora(locomotora, vagon);
//                    reubicarVagon(vagon);
//                }


                /**Cambia la direccion de la locomotora*/
                subIntervalo++;
                char* puntos=(char*)puntos;
                strcat(texto,puntos);
                getTextoRectang(renderer, 0, 0, texto, Fuente, &textura, &rectangulo);
                SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
                SDL_RenderPresent(renderer);
                SDL_Delay(50);
            }

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


void cambiarDireccion(Lista caravana, int direccion)
{
    PtrNodoLista nodo = primero(caravana);
    int direccionAnterior = getDireccion(*(Locomotora*)nodo->ptrDato);
    setDireccion(*(Locomotora*)nodo->ptrDato,direccion);
    nodo = siguiente(caravana,nodo);
    cout << "La direccion de la Locomotora es: " << direccion << endl << "Estamos pasando la direccion: " << direccionAnterior << endl;
    cambiarDireccionVagones(nodo,direccionAnterior);
}


void cambiarDireccionVagones (PtrNodoLista ptrNodo, int direccion)
{
    if(ptrNodo!=NULL)
    {
        //validar la direccion;
        int dirAnterior = getDireccion(*(Vagon*)ptrNodo->ptrDato);

        cout << "La direccion de este vagon sera: " << direccion << " y la del vagon siguiente:" << dirAnterior << endl;
        if(dirAnterior!=direccion)
            setDireccion(*(Vagon*)ptrNodo->ptrDato,direccion);//cargo la nueva dirección
        cambiarDireccionVagones(ptrNodo->sgte,dirAnterior);
    }
}
