#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Lista.h"
#include "Vagon.h"
#include "locomotora.h"
#include "Pila.h"
#ifndef CARAVANA_H_INCLUDED
#define CARAVANA_H_INCLUDED

void cambiarDireccionVagones (PtrNodoLista ptrNodo, int direccion);
void cambiarDireccion(Lista &caravana, int direccion);
void reubicar(Lista &caravana);
void dibujarCaravana (Lista &caravana, SDL_Renderer* renderer);
void moverCaravana (Lista &caravana, SDL_Renderer* renderer, int subIntervalo);

#endif

