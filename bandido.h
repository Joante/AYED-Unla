#ifndef BANDIDO_H_INCLUDED
#define BANDIDO_H _INCLUDED
#include "SDL.h"
#include "Lista.h"
#include "locomotora.h"
#include "Vagon.h"


/**
    Definicion del tipo de dato para manejo de atributos:
    int posX
    int posY
    int areaDeAtaque
    int cantidadSolicitada
    Item itemSolicitado
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
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve un objeto bandido
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void generarBandido(Bandido &bandido, int areaDeAtaque, int anchoCasillero, int altoCasillero, int maxPermitido, int maxIntervalo, int maxVida, SDL_Renderer* renderer, int intervaloBandido);


/**
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Se dibuja al bandido mediante SDL
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void dibujarBandido(Bandido &bandido, SDL_Renderer* renderer, bool hayBandido);

/**
    PRE: El bandido no debe haber sido creado.
    POST: Se construye el Bandido
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void crearBandido (Bandido &bandido, int areaDeAtaque, int anchoCasillero, int altoCasillero, int maxPermitido, int maxVida, int maxIntervalo, SDL_Renderer* renderer, bool &hayBandido, int intervaloBandido);


/**
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) y dibujado (dibujarBandido).
    POST: Se destruje el dibujo del bandido en la pantalla.
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void matarBandido (Bandido &bandido, int &intervalo, bool &hayBandido);

/**
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) y dibujado (dibujarBandido).
    POST: Maneja la colision contra el bandido
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void choqueBandido (Bandido &bandido, Lista *caravana, bool &hayBandido, int direccion);

/**
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) y dibujado (dibujarBandido).
    POST: Maneja el robo del bandido sobre la caravana.
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void robar(Bandido &bandido, bool &hayBandido, Lista *caravana);

/**
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) y dibujado (dibujarBandido).
    POST: Destruye cajas de algún vagon de la caravana.
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void robarCajas (Bandido &bandido, Vagon &vagon, Lista *caravana, bool &alcanzo);

/**
    PRE: La instancia del TDA (Bandido) debe haberse creado (constructor) y dibujado (dibujarBandido).
    POST: Elimina un vagon de la caravana.
    Bandido:Instancia sobre la cual se invoca la primitiva
*/
void eliminarVagon (Bandido &bandido, Lista *caravana);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se devuelve el tiempo de vida del Bandido
*/
int getTiempoDeVidaBandido (Bandido &bandido);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se setea el tiempo de vida del Bandido
*/
void setTiempoDeVidaBandido (Bandido &bandido, int tiempoDeVida);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se setea el ancho del casillero del Bandido
*/
void setAnchoCasilleroBandido (Bandido &bandido, int anchoCasillero);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se devuelve el ancho del casillero del Bandido
*/
int getAnchoCasilleroBandido (Bandido &bandido);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se setea el alto del casillero del Bandido
*/
void setAltoCasilleroBandido (Bandido &bandido, int altoCasillero);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se devuelve el alto del casillero del Bandido
*/
int getAltoCasilleroBandido (Bandido &bandido);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se setea la imagen del Bandido
*/
void setImagenBandido (Bandido &bandido, SDL_Texture imagen);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se devuelve la imagen del Bandido
*/
SDL_Texture getImagenBandido (Bandido &bandido);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se setea el rectImagen del Bandido
*/
void setRectBandido (Bandido &bandido, SDL_Rect rectImagen);

/**
    Pre: El bandido debe de haberse creado.
    Post: Se devuelve el rectImagen del Bandido
*/
SDL_Rect getRectBandido (Bandido &bandido);

#endif // BANDIDO_H_INCLUDED
