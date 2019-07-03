#ifndef CAJA_H
#define CAJA_H
#include <string>

using namespace std;

typedef struct{
    std::string material;   //Que material contiene la caja, es necesario???
    int capMax;         //Capacidad maxima de la caja dada por la secuencia
    int capActual;      //Para utilizar luego al ser robado etc
}Caja;


/*
Pre: no debe haber sido creada

Post: Devuelve una caja de material X y capacidad maxima = capacidad actual, dependiendo la secuencia de dicho material.

recibe la caja, el material y la secuencia actual
(capacidad de la caja) de dicho material.
*/

void crearCaja(Caja &caja);

/*
    Pre: Debe haber sido creada

    Post: Construye la caja en base al material y a la capacidad maxima.

    recibe la caja, el material y la secuencia actual
    (capacidad de la caja) de dicho material.
*/

void construirCaja (Caja &caja, std::string material, int capMax);

/*
Pre: la caja debe haber sido creada

Post: se elimina la caja

recibe la instancia de caja a ser eliminada
*/
void eliminarCaja(Caja caja);

/*
Pre: la caja debe haber sido creada

Post: Se setea el tipo de material de la caja

recibe la caja
*/

void setMaterialCaja (Caja &caja, std::string material);

/*
Pre: la caja debe haber sido creada

Post: Se devuelve el tipo de material de la caja

recibe la caja
*/
std::string getMaterialCaja(Caja &caja);


/*
Pre: la caja debe haber sido creada

Post: setea la capacidad maxima de la caja

*/

void setCapMaxCaja (Caja &caja, int capMax);

/*
Pre: la caja debe haber sido creada

Post: devuelve la capacidad maxima de la caja

*/
int getCapMaxCaja(Caja &caja);

/*
Pre: la caja debe haber sido creada

post: setea la capacidad actual de la caja
*/

void setCapActualCaja (Caja &caja, int capActual);

/*
Pre: la caja debe haber sido creada

post: devuelve la capacidad actual de la caja
*/
int getCapActualCaja(Caja &caja);


/*
Pre: la caja debe haber sido creada

post se resta a la capacidad actual de la caja el valor de menos, se devuelve el valor resultante, se actualiza el valor de "capacidad actual" de dicha caja por el resultado.
se recomienda eliminar todas las cajas de capActual 0




*/
void restarMaterialCaja(Caja &caja, int cantMenos);



#endif // CAJA_H
