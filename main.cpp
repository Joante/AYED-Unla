#include "locomotora.h"
#include "bandido.h"
#include "vagon.h"
#include "terreno.h"
#include "moneda.h"
#include "estacion.h"
#include "pantalla.h"
#include "mina.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdio>
#include <iostream>
#include<string.h>
#include<SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include "caravana.h"

using namespace std;

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


void ganar (int orosT, int platasT, int broncesT, int platinosT, int rocasT, int carbonesT)
{
    if (orosT<=0 && platasT<=0 && broncesT<=0 && platasT<=0 && rocasT<=0 && carbonesT<=0){

        SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_INFORMATION,
                "GANASTE",
                "INSERTE MUSICA DE FELIZ DOMINGO",
                NULL);
    }

}

void actualizarItemComanda(Lista *carvana,int &oros, int &platas, int &bronces, int &platinos, int &rocas, int &carbones,int orosT, int platasT, int broncesT, int platinosT, int rocasT, int carbonesT)
{
    int contadorOro=0;
    int contadorPlata=0;
    int contadorRoca=0;
    int contadorCarbon=0;
    int contadorPlatino=0;
    int contadorBronce=0;

    PtrNodoLista ptrLocomotora= primero(*carvana);
    PtrNodoLista ptrVagon=siguiente(*carvana,ptrLocomotora);
    while(ptrVagon!=finLista())
    {
        Vagon vagon= *(Vagon*)ptrVagon;
        Item itemVagon =getItem((*(Vagon*)ptrVagon->ptrDato));
        int pesoUtilizado= getPesoUtilizado((*(Vagon*)ptrVagon->ptrDato));

        if(itemVagon==oro)
        {
            contadorOro=contadorOro+pesoUtilizado;
        }
        if(itemVagon==plata)
        {
            contadorPlata=contadorPlata+pesoUtilizado;
        }
        if(itemVagon==bronce)
        {
            contadorBronce=contadorBronce+pesoUtilizado;
        }
        if(itemVagon==platino)
        {
            contadorPlatino=contadorPlatino+pesoUtilizado;
        }
        if(itemVagon==roca)

        {
            contadorRoca=contadorRoca+pesoUtilizado;
        }
        if(itemVagon==carbon)
        {
            contadorCarbon=contadorCarbon+pesoUtilizado;
        }

        ptrVagon=siguiente(*carvana,ptrVagon);
    }

    if (orosT>contadorOro)
        oros=orosT-contadorOro;
    else
        oros=0;
    if (platasT>contadorPlata)
        platas=platasT-contadorPlata;
    else
        platas=0;
    if (contadorBronce<bronces)
        bronces=broncesT-contadorBronce;
    else
        bronces=0;
    if (platinosT > contadorPlatino)
        platinos=platinosT-contadorPlatino;
    else
        platinos=0;
    if (rocasT>contadorRoca)
        rocas=rocasT-contadorRoca;
    else
        rocas=0;
    if(carbonesT > contadorCarbon)
        carbones=carbonesT-contadorCarbon;
    else
        carbones=0;

        ganar (oros, platas, bronces, platinos, rocas,  carbones);

}




//void actualizarItemComanda(Lista *carvana,int &oros, int &platas, int &bronces, int &platinos, int &rocas, int &carbones,int orosT, int platasT, int broncesT, int platinosT, int rocasT, int carbonesT)
//{
//    PtrNodoLista ptrLocomotora= primero(*carvana);
//    PtrNodoLista ptrVagon=siguiente(*carvana,ptrLocomotora);
//    while(ptrVagon!=finLista())
//    {
//        Vagon vagon= *(Vagon*)ptrVagon;
//        Item itemVagon =getItem((*(Vagon*)ptrVagon->ptrDato));
//        int pesoUtilizado= getPesoUtilizado((*(Vagon*)ptrVagon->ptrDato));
////        cout << "Hola: " << pesoUtilizado << endl;
//        if(itemVagon==oro && orosT!=oros-pesoUtilizado)
//        {
//            cout << "Hola: " << pesoUtilizado << endl;
//            oros= oros - pesoUtilizado;
//        }
//        if(itemVagon==plata && platasT!=platas-pesoUtilizado)
//        {
//            cout << "Hola: " << pesoUtilizado << endl;
//            platas= platas-pesoUtilizado;
//        }
//        if(itemVagon==bronce && broncesT!=bronces-pesoUtilizado)
//        {
//            cout << "Hola: " << pesoUtilizado << endl;
//            bronces= bronces-pesoUtilizado;
//        }
//        if(itemVagon==platino && platinosT!=platinos-pesoUtilizado)
//        {
//            cout << "Hola: " << pesoUtilizado << endl;
//            platinos= platinos -pesoUtilizado;
//        }
//        if(itemVagon==roca && rocasT!=rocas-pesoUtilizado)
//        {
//            cout << "Hola: " << pesoUtilizado << endl;
//            rocas= rocas -pesoUtilizado;
//        }
//        if(itemVagon==carbon && carbonesT!=carbones-pesoUtilizado)
//        {
//            cout << "Hola: " << pesoUtilizado << endl;
//            carbones= carbones - pesoUtilizado;
//        }
//
//        ptrVagon=siguiente(*carvana,ptrVagon);
//    }
//}


void actualizarComanda( char texto[100],int monedas,int oro,int plata,int bronce,int platino,int roca,int carbon,char comanda_monedas[2],char comanda_oro[2],char comanda_plata[2],char comanda_bronce[2],char comanda_platino[2],char comanda_roca[2],char comanda_carbon[2])
{

    sprintf(comanda_monedas,"%d",monedas);
    //Asignamos texto al marcador....
    strcpy(texto,"MONEDAS:");
    //concatenamos la puntuacion de la vida
    strcat(texto, comanda_monedas);
    //concatenamos más texto informativo
    strcat(texto,"  ORO:");
    // Pasamos los puntos a la cadena de numeros, por aquello de reciclar variables
    sprintf(comanda_oro,"%d",oro);
    // volvemos a concatenar...
    strcat(texto,comanda_oro);

    //concatenamos más texto informativo
    strcat(texto,"  PLATA:");
    // Pasamos los puntos a la cadena de numeros, por aquello de reciclar variables
    sprintf(comanda_plata,"%d",plata);
    // volvemos a concatenar...
    strcat(texto,comanda_plata);

    //concatenamos más texto informativo
    strcat(texto,"  PLATINO:");
    // Pasamos los puntos a la cadena de numeros, por aquello de reciclar variables
    sprintf(comanda_platino,"%d",platino);
    // volvemos a concatenar...
    strcat(texto,comanda_platino);

    //concatenamos más texto informativo
    strcat(texto,"  BRONCE:");
    // Pasamos los puntos a la cadena de numeros, por aquello de reciclar variables
    sprintf(comanda_bronce,"%d",bronce);
    // volvemos a concatenar...
    strcat(texto,comanda_bronce);

    //concatenamos más texto informativo
    strcat(texto,"  ROCA:");
    // Pasamos los puntos a la cadena de numeros, por aquello de reciclar variables
    sprintf(comanda_roca,"%d",roca);
    // volvemos a concatenar...
    strcat(texto,comanda_roca);

    //concatenamos más texto informativo
    strcat(texto,"  CARBON:");
    // Pasamos los puntos a la cadena de numeros, por aquello de reciclar variables
    sprintf(comanda_carbon,"%d",carbon);
    // volvemos a concatenar...
    strcat(texto,comanda_roca);
}

int main(int argc, char** argv)
{

    int filas = 15;
    int columnas = 20;
    int anchoCasillero = 40;
    int altoCasillero = 40;
    int anchoVentana = columnas*anchoCasillero;
    int altoVentana = filas*altoCasillero;

/**Datos desde archivo */
/*
	S: Segundos que dura un intervalo.
	P: cantidad máxima que puede pedir un bandido.
	A: posiciones para definir el área de Ataque de un bandido.
	posXE: posición x de la estación.
	posYE: posición y de la estación.
	IM: intervalo máximo para generación de monedas.
	VM: intervalos máximos de vida de una moneda.
	IB: máxima cantidad de intervalos para la aparición de bandidos.
	VB: tiempo máximo de vida de un bandido.
	IP: intervalos entre producciones de las minas.
*/

 int s = 20;
 int p = 4;
 int a = 1;
 int posXE = 6;
 int posYE = 7;
 int im = 5; //pending
 int vm = 50; //pending
 int ib = 2;
 int vb = 50;
 int ip = 10; //pending


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
        /** Vriables TTF */
        SDL_Texture *textura;
        SDL_Rect rectangulo;
        TTF_Init();
        TTF_Font *Fuente= TTF_OpenFont("fuente.ttf",20);
        char texto[100];
        int monedas=0;
        //oro, plata, bronce, platino, roca, carbón.
        int oros=1;
        int platas=1;
        int bronces=1;
        int platinos=1;
        int rocas=1;
        int carbones=1;
        int orosTotal=oros;
        int platasTotal=platas;
        int broncesTotal=bronces;
        int platinosTotal=platinos;
        int rocasTotal=rocas;
        int carbonesTotal=carbones;
        char comanda_monedas[2];
        char comanda_oro[2];
        char comanda_plata[2];
        char comanda_bronce[2];
        char comanda_platino[2];
        char comanda_roca[2];
        char comanda_carbon[2];
        actualizarComanda(texto,monedas,oros,platas,bronces,platinos,rocas,carbones,comanda_monedas,comanda_oro,comanda_plata,comanda_bronce,comanda_platino,comanda_roca,
                          comanda_carbon);
        getTextoRectang(renderer, 0, 0, texto, Fuente, &textura, &rectangulo);
        /** Inicializacion de TDA */

        /** Inicializacion de TDA */

        Locomotora locomotora;
        Locomotora* ptroLocomotora = &locomotora;
        Lista caravana;
        Terreno terreno;
        Estacion estacion;
        Moneda moneda;
        Bandido bandido;
        //oro, plata, bronce, platino, roca, carbón.
        Mina minaOro, minaPlata, minaBronce, minaPlatino, minaRoca, minaCarbon;
        Lista minas;
        crearLista(minas, comparaListaVagonVagones);
        int secuencia[5] = {1,2,3,4,5};
        int *punteroMatriz;
        punteroMatriz=secuencia;

        crearMina(minaOro, true, 13, 11, ip, anchoCasillero, altoCasillero, punteroMatriz, oro, renderer);
        crearMina(minaPlata, true, 3, 3, ip, anchoCasillero, altoCasillero, punteroMatriz, plata, renderer);
        crearMina(minaBronce, true, 3, 12, ip, anchoCasillero, altoCasillero, punteroMatriz, bronce,renderer);
        crearMina(minaPlatino, true, 16, 2, ip, anchoCasillero, altoCasillero, punteroMatriz, platino,renderer);
        crearMina(minaRoca, true, 18, 6, ip, anchoCasillero, altoCasillero, punteroMatriz, roca, renderer);
        crearMina(minaCarbon, true, 10, 7, ip, anchoCasillero, altoCasillero, punteroMatriz, carbon, renderer);

        crearLista(caravana, comparaListaVagonVagones);

        adicionarFinal(minas,&minaOro);
        adicionarFinal(minas,&minaPlata);
        adicionarFinal(minas,&minaBronce);
        adicionarFinal(minas,&minaPlatino);
        adicionarFinal(minas,&minaRoca);
        adicionarFinal(minas,&minaCarbon);

        adicionarPrincipio(caravana, ptroLocomotora);
        crearLocomotora(locomotora,0,0,anchoCasillero,altoCasillero,renderer);
        crearEstacion(estacion,posXE,posYE,anchoCasillero,altoCasillero,renderer);

        Terreno matrizTerreno[15][20];
        crearMatrizTerreno(terreno, matrizTerreno, filas,columnas,anchoCasillero,altoCasillero,renderer);

        /** Variables de manejo de intervalo y movimiento */

        int direccion1=2;
        int intervaloMoneda=1;
        int intervaloBandido=1;
        int intervaloMina=1;
        int subIntervalo=0;
        bool moverse = true;
        char titulo[255];
        bool hayBandido =false;
        bool hayMoneda=false;


        /**While del juego*/

        while(getEstado(locomotora))
        {

            /** Manejo de teclado */
            manejoDelTeclado (direccion1, locomotora, moverse);
            sprintf(titulo,"Clash of UNLa -- Monedas: %d",locomotora.monedas);


            if (moverse==true)
            {

                if (subIntervalo==10 || subIntervalo==0){

                    subIntervalo=0;

                    cambiarDireccion(caravana,direccion1);
                    reubicar(caravana);
                    //crearBandido(bandido, a, anchoCasillero,altoCasillero,p, vb, ib, renderer, hayBandido,intervaloBandido);
                    crearMoneda(moneda, anchoCasillero, altoCasillero, im, vm, renderer,intervaloMoneda,hayMoneda);

                    matarBandido(bandido, intervaloBandido, hayBandido);
                    eliminarMoneda(moneda,intervaloMoneda,hayMoneda);
                    generarTodasLasCajas(&minas, intervaloMina);

                    intervaloBandido++;
                    intervaloMoneda++;
                    intervaloMina++;

                }


                /** Dibujar */
                SDL_RenderClear(renderer);

                /**Dibujo de TDA*/
                dibujarTerreno(terreno, matrizTerreno,filas, columnas, renderer);
                dibujarMoneda(moneda, renderer, hayMoneda);
                dibujarCaravana(caravana, renderer);
                dibujarBandido(bandido, renderer, hayBandido);
                dibujarEstacion(estacion,renderer);
                dibujarMinas(&minas, renderer);
                getTextoRectang(renderer, 0, 0, texto, Fuente, &textura, &rectangulo);
                SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
                SDL_RenderPresent(renderer);

                /** Movimiento de tren y vagones*/
                moverCaravana(caravana,renderer,subIntervalo);

                /** Colisiones*/
                if (subIntervalo==9)
                {
                    colisionEstacion(estacion, locomotora, &caravana, direccion1, renderer);
                    chocarVagones (locomotora, &caravana);
                    chocarBordes (locomotora, direccion1);
                    choqueBandido(bandido, &caravana, hayBandido, direccion1);
                    colisionMinas(locomotora, &minas, &caravana, direccion1);
                    colisionMoneda(locomotora, moneda, hayMoneda, monedas);
                    actualizarItemComanda(&caravana,oros,platas,bronces, platinos, rocas, carbones,orosTotal,platasTotal,broncesTotal, platinosTotal, rocasTotal, carbonesTotal);
                    actualizarComanda(texto,monedas,oros,platas,bronces,platinos,rocas,carbones,comanda_monedas,comanda_oro,comanda_plata,comanda_bronce,comanda_platino,comanda_roca,
                          comanda_carbon);
                }


                /**Cambia la direccion de la locomotora*/
                subIntervalo++;

                //variable leída por archivo
                SDL_Delay(s);
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



