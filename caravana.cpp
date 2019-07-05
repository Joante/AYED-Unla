#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "caravana.h"

void cambiarDireccion(Lista &caravana, int direccion)
{
    PtrNodoLista nodo = primero(caravana);
    int direccionAnterior = getDireccion(*(Locomotora*)nodo->ptrDato);
    setDireccion(*(Locomotora*)nodo->ptrDato,direccion);
    nodo = siguiente(caravana,nodo);

    //cout << "La direccion de la Locomotora es: " << direccion << endl << "Estamos pasando la direccion: " << direccionAnterior << endl;
    if (nodo!=finLista()){
        cambiarDireccionVagones(nodo,direccionAnterior);}
}


void cambiarDireccionVagones (PtrNodoLista ptrNodo, int direccion)
{
    if(ptrNodo!=NULL)
    {
        //validar la direccion;
        int dirAnterior = getDireccion(*(Vagon*)ptrNodo->ptrDato);
        //cout << "La direccion de este vagon sera: " << direccion << " y la del vagon siguiente:" << dirAnterior << endl;
        if(dirAnterior!=direccion)
            setDireccion(*(Vagon*)ptrNodo->ptrDato,direccion);//cargo la nueva dirección
        cambiarDireccionVagones(ptrNodo->sgte,dirAnterior);
    }
}


void reubicar(Lista &caravana)
{
    PtrNodoLista nodo = primero(caravana);
    reubicarLocomotora(*(Locomotora*)nodo->ptrDato);

    nodo = siguiente(caravana, nodo);

    while(nodo!=finLista())
    {
        reubicarVagon(*(Vagon*)nodo->ptrDato);
        nodo = siguiente(caravana, nodo);
    }
}

void dibujarCaravana (Lista &caravana, SDL_Renderer* renderer)
{

    PtrNodoLista nodo = primero(caravana);
    dibujarLocomotora(*(Locomotora*)nodo->ptrDato,renderer);
    while(siguiente(caravana, nodo)!=finLista())
    {
        nodo=siguiente(caravana,nodo);
        dibujarVagon(*(Vagon*)nodo->ptrDato, renderer);
    }

}

void moverCaravana (Lista &caravana, SDL_Renderer* renderer, int subIntervalo)
{
    PtrNodoLista nodo = primero(caravana);
    moverLocomotora(*(Locomotora*)nodo->ptrDato, renderer, subIntervalo);
    while(siguiente(caravana, nodo)!=finLista())
    {
        nodo=siguiente(caravana,nodo);
        moverVagon(*(Vagon*)nodo->ptrDato, renderer, subIntervalo);
    }
}
