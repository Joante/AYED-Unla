#ifndef CAJA_H
#define CAJA_H


typedef struct{
    string contenido;   //Que material contiene la caja, es necesario???
    int capMax;         //Capacidad maxima de la caja dada por la secuencia
    int capActual;      //Para utilizar luego al ser robado etc
}Caja;


/*
Pre: no debe haber sido creada

Post: Devuelve una caja de contenido X y capacidad maxima = capacidad actual, dependiendo la secuencia de dicho contenido.

recibe la caja, el contenido y la secuencia de dicho contenido.

*/
void crear(caja &caja);


/*
Pre: la caja debe haber sido creada

Post: se elimina la caja, devuelve true si fue exitoso, false si hubo algun error

recibe la instancia de caja a ser eliminada
*/
bool eliminar(caja &caja);


/*
Pre: la caja debe haber sido creada

Post: Se devuelve el tipo de contenido de la caja

recibe la caja
*/
string getContenido(caja &caja);


/*
Pre: la caja debe haber sido creada

Post: devuelve la capacidad maxima de la caja

*/
int getCapMax(caja &caja);


/*
Pre: la caja debe haber sido creada

post: devuelve la capacidad actual de la caja
*/
int getCapActual(caja &caja);


/*
Pre: la caja debe haber sido creada

post se resta a la capacidad actual de la caja el valor de menos, se devuelve el valor resultante, se actualiza el valor de "capacidad actual" de dicha caja por el resultado.
se recomienda eliminar todas las cajas de capActual 0

*/
int restarContenido(caja &caja, int menos);



#endif // CAJA_H
