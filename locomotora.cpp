#include "locomotora.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

void crearLocomotora(Locomotora &locomotora, int posY, int posX, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer)
{
    locomotora.posY=posY;//coordenada logica y
    locomotora.posX=posX;//coordenada logica x
    locomotora.imagen= IMG_LoadTexture(renderer,"img/c1/der/0.png");
    locomotora.rectImag.y=posY* altoCasillero;//coordenada de dibujo y
    locomotora.rectImag.x=posX* anchoCasillero;//coordenada de dibujo x
    locomotora.rectImag.w= anchoCasillero;//ancho
    locomotora.rectImag.h= anchoCasillero;//alto
    locomotora.estado=true;
    locomotora.monedas=0;
    locomotora.direccion=2;
    locomotora.anchoCasillero=anchoCasillero;
    locomotora.altoCasillero=altoCasillero;
}

void dibujarLocomotora(Locomotora &locomotora, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, locomotora.imagen,NULL,&(locomotora.rectImag));
}

void destruirLocomotora(Locomotora &locomotora)
{
    SDL_DestroyTexture(locomotora.imagen);
}

void setPosY (Locomotora &locomotora, int posY)
{
    locomotora.posY=posY;
}

void setPosX (Locomotora &locomotora, int posX)
{
    locomotora.posX=posX;
}

int getPosY (Locomotora &locomotora)
{
    return locomotora.posY;
}

int getPosX (Locomotora &locomotora)
{
    return locomotora.posX;
}

void setEstado (Locomotora &locomotora, bool estado)
{
    locomotora.estado=estado;
}

bool getEstado(Locomotora &locomotora)
{
    return locomotora.estado;
}

void setMonedas (Locomotora &locomotora, int monedas)
{
    locomotora.monedas=monedas;
}

int getMonedas(Locomotora &locomotora)
{
    return locomotora.monedas;
}

int getDireccion (Locomotora &locomotora)
{
    return locomotora.direccion;
}

SDL_Rect getRectImag (Locomotora &locomotora)
{

    return locomotora.rectImag;
}

void setDireccion (Locomotora &locomotora, int direccion)
{
    locomotora.direccion=direccion;

}

void setRectImag (Locomotora &locomotora, SDL_Rect imagen)
{
}

void reubicarLocomotora(Locomotora &locomotora)
{

    if (locomotora.direccion==0)
        locomotora.posY++;

    if (locomotora.direccion==1)
        locomotora.posY--;

    if (locomotora.direccion==2)
        locomotora.posX++;

    if (locomotora.direccion==3)
        locomotora.posX--;

//        colisionLimites(locomotora);
}

int direccionarLocomotora(Locomotora &locomotora, SDL_Event evento)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */

    int direccion1=getDireccion(locomotora);

    const unsigned char *keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_UP]&& locomotora.direccion!=0)
    {
        direccion1=1;
    }
    else if (keys[SDL_SCANCODE_DOWN] && locomotora.direccion!=1)
    {
        direccion1=0;
    }
    else if (keys[SDL_SCANCODE_RIGHT]&& locomotora.direccion!=3)
    {
        direccion1=2;
    }
    else if (keys[SDL_SCANCODE_LEFT]&& locomotora.direccion!=2)
    {
        direccion1=3;
    }
   // std::cout << "direccion 1: " << direccion1 << "\n";
    return direccion1;
}

void moverLocomotora(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */

    int direccion = locomotora.direccion;

    if (direccion == 0)
    {
        moverLocomotoraAAbajo(locomotora, renderer, intervalo);
    }
    else if (direccion == 1)
    {
        moverLocomotoraAArriba(locomotora, renderer, intervalo);

    }
    else if (direccion == 2)
    {
        moverLocomotoraALaDerecha(locomotora, renderer, intervalo);
    }
    else if (direccion == 3)
    {
        moverLocomotoraALaIzquierda(locomotora,  renderer,  intervalo);
    }
    //std::cout <<"\n( X:" << locomotora.posX << " Y:" << locomotora.posY <<")  \n";

}

void chocarBordes (Locomotora &locomotora, int direccion)
{
    /*
    abajo 0
    arriba 1
    derecha 2
    izquierda 3
    */
//15 y 20

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

    if (x<0 || x>19 || y<0 || y>14)
        setEstado(locomotora, false);

}

void moverLocomotoraALaDerecha(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo) //derecha
{
    locomotora.rectImag.x+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/der/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverLocomotoraALaIzquierda(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo) //izquierda
{
    locomotora.rectImag.x-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/izq/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverLocomotoraAAbajo(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo)
{
//abajo
    locomotora.rectImag.y+=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/aba/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void moverLocomotoraAArriba(Locomotora &locomotora, SDL_Renderer* renderer, int intervalo) //arriba
{
    locomotora.rectImag.y-=4;

    char urlImagen[50];
    strcpy (urlImagen,"img/c1/arr/");
    char integer_string[5];
    sprintf(integer_string, "%d", intervalo);
    strcat (urlImagen,integer_string);
    strcat (urlImagen,".png");
    locomotora.imagen= IMG_LoadTexture(renderer,urlImagen);
}

void colisionLimites (Locomotora &locomotora)
{

    if (locomotora.posY <0)
    {
        locomotora.estado=false;
    }
    else if (locomotora.posX <0)
    {
        locomotora.estado=false;
    }
    else if (locomotora.posY >14)
    {
        locomotora.estado=false;
    }
    else if (locomotora.posX >19)
    {
        locomotora.estado=false;
    }


}
void sumarMoneda (Locomotora &locomotora, bool &hayMoneda)
{
    if (hayMoneda){
    locomotora.monedas++;
    hayMoneda=false;
   // std::cout << "\n \n \n \n MONEDAS:" << locomotora.monedas << "\n \n \n \n";
    }
}

void chocarVagones (Locomotora &locomotora, Lista *caravana)
{
    bool chocar = false;
    int colision;
    PtrNodoLista nodo = primero(*caravana);
    nodo = siguiente(*caravana, nodo);

    while (nodo!=finLista() && chocar==false)
    {
        Vagon vagon = *(Vagon*)nodo->ptrDato;
        colision = colisionVagones(locomotora.rectImag, vagon.rectImag, locomotora.direccion);
        if (colision ==1)
        {
            locomotora.estado=false;
            std::cout<< "Choco" << std::endl;
        }
        nodo = siguiente(*caravana, nodo);
    }
}

int colisionVagones(SDL_Rect H, SDL_Rect M, int dir)
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


void colisionMinas (Locomotora &locomotora, Lista *minas, Lista *caravana, int &direccion){
    PtrNodoLista nodo = primero(*minas);
    while(nodo!=finLista())
    {
        colisionMina (locomotora, *(Mina*)nodo->ptrDato, caravana, direccion);
        nodo = siguiente(*minas, nodo);
    }
}

void colisionMina (Locomotora &locomotora, Mina &mina, Lista *caravana, int &direccion)
{

    int x = getPosX(locomotora);
    int y = getPosY(locomotora);
    int minaY, minaX;
    minaY = getPosY(mina);
    minaX = getPosX(mina);

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

    if (x==minaX && y==minaY)
            {
                sumarCaja(locomotora, caravana, mina);
                detenerse(locomotora,direccion);
            }

 }


 void detenerse(Locomotora &locomotora, int &direccion1)
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


void sumarCaja(Locomotora &locomotora, Lista *caravana, Mina &mina)
{
    /** grr
    primero vemos si hay un vagon vacio/de ese tipo.
    despues, vemos que haya espacio
    Si lo hay, sumamosCaja
    Si no lo hay, vacamos la produ de la mina
    */

    //hay lugar

    if (listaVacia(mina.cajas))
    {
        std::cout << "No hay nada que sumar, vuelva pronto!" << std::endl;

    }
    else
    {
        PtrNodoLista nodo = primero(*caravana);
        nodo = siguiente(*caravana, nodo);
        bool hayLugar = false;
        while (nodo!=finLista()&&!hayLugar)
        {
            Vagon vagon = *(Vagon*)nodo->ptrDato;
            if (vagon.item==vacio && vagon.pesoMax>(*(Caja*)mina.cajas.primero->ptrDato).capActual)
            {
                //si hay un vagon vacio le asignamos la caja
                hayLugar=true;
                setItem(*(Vagon*)nodo->ptrDato, mina.item);
            }
            else if (vagon.item==mina.item)
            {
                //si hay un vagon del mismo tipo, vemos si tiene lugar
                int pesoUsado=getPesoUtilizado(vagon);
                int pesoMax = getPesoMax(vagon);
                int pesoCaja= (*(Caja*)mina.cajas.primero->ptrDato).capActual;
                if(pesoUsado+pesoCaja<=pesoMax)
                {
                    hayLugar=true;
                }
            }
            if (!hayLugar)
                nodo = siguiente(*caravana, nodo);
        }

        if (hayLugar)
        {
            int i;
            PtrNodoLista nodoaux = mina.cajas.primero;
            agregar(((Vagon*)nodo->ptrDato)->cajas, nodoaux->ptrDato);
            i = ((Caja*)((Vagon*)nodo->ptrDato)->cajas.primero->ptrDato)->capActual;
            setPesoUtilizado(*(Vagon*)nodo->ptrDato,(getPesoUtilizado((*(Vagon*)nodo->ptrDato))+i));

            std::cout << "Sumamos: " << i << " , ahora tenemos: "<< getPesoUtilizado((*(Vagon*)nodo->ptrDato)) << std::endl;
            eliminarNodoPrimero(mina.cajas);

        }
        else
        {
            SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_INFORMATION,
                "HOLI, TE ROBO",
                "No tenes lugar para guardar esta caja",
                NULL);
            eliminarLista(mina.cajas);
        }

    }
}

void colisionMoneda(Locomotora &locomotora, Moneda &moneda, bool &hayMoneda, int &monedas)
{
    int x = getPosX(locomotora);
    int y = getPosY(locomotora);
    int monedaY, monedaX;
    monedaY = getPosY(moneda);
    monedaX = getPosX(moneda);

    if (monedaY==y && monedaX==x){
         sumarMoneda(locomotora, hayMoneda);
         monedas= getMonedas(locomotora);
    }
}
