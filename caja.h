#ifndef CAJA_H
#define CAJA_H
#include <string>

/**
    Axiomas:
        int capMax > 0
        int capActual >= 0
*/

typedef struct{
    std::string contenido;
    int capMax;
    int capActual;
}Caja;



void crear(Caja &caja, int secuenciaActual);
/**
    Pre: no debe haber sido creada
    Post: Devuelve una caja de contenido X y capacidad maxima = capacidad actual, dependiendo la secuencia de dicho contenido.

    Recibe la caja, el contenido y la secuencia actual (capacidad de la caja) de dicho contenido.

*/
void crear(Caja &caja, std::string contenido, int secuenciaActual);

/**
    Pre: la caja debe haber sido creada

    Post: se elimina la caja

    Recibe la instancia de caja a ser eliminada
*/
void eliminar(Caja &caja);


/**
    Pre: la caja debe haber sido creada

    Post: Se devuelve el tipo de contenido de la caja

    Recibe la instancia de Caja
*/
std::string getContenido(Caja &caja);


/**
    Pre: la caja debe haber sido creada

    Post: devuelve la capacidad maxima de la caja

*/
int getCapMax(Caja &caja);


/**
    Pre: la caja debe haber sido creada

    Post: devuelve la capacidad actual de la caja
*/
int getCapActual(Caja &caja);


/**
    Pre: la caja debe haber sido creada

    Post: se resta a la capacidad actual de la caja el valor de menos,
    se devuelve el valor resultante, se actualiza el valor de "capacidad actual" de dicha caja por el resultado.

    Se recomienda eliminar todas las cajas de capActual=0
*/
int restarContenido(Caja &caja, int menos);

/**
    Pre: La caja debe haber sido creada.
    Post: Se devuelve la capacidad actual de la Caja.
*/
void setCapActual(Caja &caja, int capActual);

/**
    Pre: La caja debe haber sido creada.
    Post: Se setea el contenido de la Caja.
*/
void setContenido (Caja &caja, std::string material);

/**
    Pre: La caja debe haber sido creada.
    Post: Se el contenido maximo de la Caja.
*/
void setCapMax (Caja &caja, int capMax);


#endif // CAJA_H
