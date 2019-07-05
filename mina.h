#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED

#include "Pila.h"
#include "caja.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
/**
    Definici�n del tipo de Dato para el manejo de la mina.
    Atributos:
        enum item
        int posX
        int posY
        int intervaloProduccion
        Pila<Caja> cajas
        array secuencia

    Axiomas:

*/

/* Tipo de estructura de el mina */

typedef struct Mina{
    bool estado;
    int posX;
    int posY;
    int intervaloProduccion;
    Pila cajas;
    //Caja cajas;
    int secuencia[2];
    int anchoCasillero;
    int altoCasillero;
    int contadorSecuencia;
    std::string material;
    SDL_Texture *imagen;
    SDL_Rect rectImag;
} Mina;

/* Definici�n de Primitivas  */

/**
    PRE: La mina no debe haber sido creada.
    POST: La mina esta creada y listo para ser usada.
*/

void crearMina (Mina &mina);

/**
    PRE: La mina debe haber sido creada.
    POST: La mina esta construida y listo para ser usada.
*/

void construirMina(Mina &mina, bool estado,int posX, int posY, int intervaloProduccion, int anchoCasillero, int altoCasillero, int secuencia[],std::string material,SDL_Renderer* renderer);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: La mina es eliminada.
    Mina: Instacia sobre la cual se invoca a la primitiva
*/

void eliminarMina (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado el Estado mediante setEstado().
    POST: Se devuelve el estado de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

bool getEstadoMina (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea el estado de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setEstadoMina (Mina &mina, bool estado);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la posX mediante setPosX().
    POST: Se devuelve la posicionX seteada.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int  getPosX (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la posicionX de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setPosX (Mina &mina, int posX);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la posY mediante setPosY().
    POST: Se devuelve la posicion Y de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int getPosY (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la posicion Y de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setPosY (Mina &mina, int posY);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado el intervaloProduccion mediante setIntervaloProduccion().
    POST: Se devuelve el intervalo de produccion de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int getIntervaloProduccion (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea intervalo de produccion de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setIntervaloProduccion (Mina &mina, int intervaloProduccion);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la ListaCajas mediante setListaCajas().
    POST: Se devuelve la ListaCajas de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/
Pila getPilaCajas (Mina &mina);

//Caja getPilaCajas (Mina &mina);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la ListaCajas de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setPilaCajas (Mina &mina, Pila cajas);
//void setPilaCajas (Mina &mina, Caja cajas);


/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado la secuencia mediante setSecuencia().
    POST: Se devuelve la secuencia de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/


int * getSecuencia (Mina &mina);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea el material de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setMaterialMina (Mina &mina, std::string material);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado el material mediante setMateriaCaja().
    POST: Se devuelve el material de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

std::string getMaterialMina(Mina &mina);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea el contador de secuencia de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setContadorSecuencia (Mina &mina, int contadorSecuencia);

/**
    PRE: La mina debe haber sido creada mediante crear(), y se debe de haber seteado el contador de secuencia mediante setContadorSecuencia().
    POST: Se devuelve la secuencia de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

int getContadorSecuencia (Mina &mina);


/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se setea la secuencia de la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void setSecuencia (Mina &mina, int* secuencia);

/**
    PRE: La mina debe haber sido creada mediante crear().
    POST: Se dibuja la mina.
    Mina: Instacia sobre el cual se invoca a la primitiva
*/

void dibujarMina(Mina &mina, SDL_Renderer* renderer);

void producirCaja (Mina &mina);


#endif // MINA_H_INCLUDED
