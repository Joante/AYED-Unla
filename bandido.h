#ifndef BANDIDO_H_INCLUDED
#define BANDIDO_H _INCLUDED
#include "SDL.h"
#include "Lista.h"
#include "locomotora.h"
#include "Vagon.h"

/* falta agregar el .h de locomotora*/

/** Definicion del tipo de dato para manejo de atributos:
posX
posY
areaDeAtaque
cantidadSolicitada
itemSolicitado

Axiomas:

idk que va aca algun bello y sereno chamuyo probably, tell me why ain't nothing but a heartache

*/


/**Tipo de estructura del bandido*/
typedef struct
{
    int posX;
    int posY;
    int areaDeAtaque;
    int cantidadSolicitada; //aleatorio
    Item itemSolicitado; //aleatorio
    int tiempoDeVida; //aleatorio
    int anchoCasillero;
    int altoCasillero;
    SDL_Texture *imagen;
    SDL_Rect rectImag;

} Bandido;

/**
PRE:El bandido no debe haber sido creado
POST:El bandido queda creado y preparado para ser usado
*/

void constructor(Bandido &bandido);


/**
PRE:Bandido creado con constructor()
POST:El bandido es eliminado
Bandido:Instancia sobre la cual se invoca la primitiva
*/
void destructor(Bandido &bandido);




/**
PRE:Bandido creado con constructor()
POST:El campo posX pasa a contener el dato ingresado
Bandido:Instancia sobre la cual se invoca la primitiva
*/

void setPosX(Bandido &bandido,int posX);



/**
PRE:Bandido creado con constructor()
POST:devuelve el dato contenido en el campo posX
Bandido:Instancia sobre la cual se invoca la primitiva

*/
int getPosX(Bandido &bandido);






/**
PRE:Bandido creado con constructor()
POST:El campo posY pasa a contener el dato ingresado
Bandido:Instancia sobre la cual se invoca la primitiva
*/

void setPosY(Bandido &bandido,int posY);





/**
PRE:Bandido creado con constructor()
POST:devuelve el dato contenido en el campo posY
Bandido:Instancia sobre la cual se invoca la primitiva

*/
int getPosY(Bandido &bandido);






/**
PRE:Bandido creado con constructor()
POST:El campo areaDeAtaque pasa a contener el dato ingresado
Bandido:Instancia sobre la cual se invoca la primitiva
*/

void setAreaDeAtaque(Bandido &bandido,int areaDeAtaque);




/**
PRE:Bandido creado con constructor()
POST:devuelve el dato contenido en el campo areaDeAtaque
Bandido:Instancia sobre la cual se invoca la primitiva

*/
int getAreaDeAtaque(Bandido &bandido);



/**
PRE:Bandido creado con constructor()
POST:El campo cantidadSolicitada pasa a contener el dato ingresado
Bandido:Instancia sobre la cual se invoca la primitiva
*/

void setCantidadSolicitada(Bandido &bandido,int cantidadSolicitada);




/**
PRE:Bandido creado con constructor()
POST:devuelve el dato contenido en el campo cantidadSolicitada
Bandido:Instancia sobre la cual se invoca la primitiva

*/
int getCantidadSolicitada(Bandido &bandido);




/**
PRE:Bandido creado con constructor()
POST:El campo itemSolicitado pasa a contener el dato ingresado
Bandido:Instancia sobre la cual se invoca la primitiva
*/

void setItemSolicitado(Bandido &bandido,int itemSolicitado);




/**
PRE:Bandido creado con constructor()
POST:devuelve el dato contenido en el campo itemSolicitado
Bandido:Instancia sobre la cual se invoca la primitiva

*/
Item getItemSolicitado(Bandido &bandido);




/**
PRE:
    La instancia del TDA (Bandido) debe haberse creado (constructor) pero no debe estar destruida (destructor).
POST:
    Devuelve un objeto bandido
    Bandido:Instancia sobre la cual se invoca la primitiva

*/
void generarBandido(Bandido &bandido, int areaDeAtaque, int anchoCasillero, int altoCasillero, int maxPermitido, int maxIntervalo, int maxVida, SDL_Renderer* renderer, int intervaloBandido);


/**
PRE:
    La instancia del TDA (Bandido) debe haberse creado (constructor) pero no debe estar destruida (destructor).
POST:
    idk algo asi con palabras mas bellas.Si hay item roba, si no hay suficientes de x item destruye vagon si no hay vagon por lo tanto no hay item so destruye locomotora.
    Bandido:Instancia sobre la cual se invoca la primitiva

*/
//void robaBandido(Bandido &bandido, Locomotora &locomotora );


void dibujarBandido(Bandido &bandido, SDL_Renderer* renderer, bool hayBandido);

void crearBandido (Bandido &bandido, int areaDeAtaque, int anchoCasillero, int altoCasillero, int maxPermitido, int maxVida, int maxIntervalo, SDL_Renderer* renderer, bool &hayBandido, int intervaloBandido);

void matarBandido (Bandido &bandido, int &intervalo, bool &hayBandido);

void choqueBandido (Bandido &bandido, Lista *caravana, bool &hayBandido, int direccion);

void robar(Bandido &bandido, bool &hayBandido, Lista *caravana);

void robarCajas (Bandido &bandido, Vagon &vagon, Lista *caravana, bool &alcanzo);

void eliminarVagon (Bandido &bandido, Lista *caravana);

#endif // BANDIDO_H_INCLUDED

