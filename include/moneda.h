#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

/*
Definición del tipo Tipo de Dato para el manejo de la Moneda.
Atributos:
        *posX,
        *posY,
        *tiempoVida

Axiomas:
        *posX se definirá mediante un aleatorio.
        *posY se definirá mediante un aleatorio.
        *tiempoVida se determina en forma aleatoria al momento de crearla y no podrá superar los VM intervalos.

*/
/* Tipo de estructura de la Estación */

typedef struct
{
    int posX;
    int posY;
    int tiempoVida;

}Moneda;

/* Definición de Primitivas  */

/* PRE: La moneda no debe haber sido creada.
   POST: La moneda esta creada y lista para ser usada. */

void crear (moneda &Moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: La moneda es eliminada.

   moneda: Instacia sobre la cual se invoca a la primitiva */

void eliminar (moneda &Moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: Se devuelve la posición en X de la moneda

   moneda: Instacia sobre la cual se invoca a la primitiva*/

int getPosX (moneda &Moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: Se devuelve la posición en Y de la moneda

   moneda: Instacia sobre la cual se invoca a la primitiva*/

int getPosY (moneda &Moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: Se devuelve el tiempo de vida de la moneda.

   moneda: Instacia sobre la cual se invoca a la primitiva*/

int getTiempoVida (moneda &Moneda);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: El campo tiempoVida de la moneda se modifica por el valor pasado por parametro.

   moneda: Instacia sobre la cual se invoca a la primitiva.
   tiempoVida: Valor pasado por parametro.*/


void setTiempoVida (moneda &Moneda, int tiempoVida);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: El campo posX de la moneda se modifica por el valor pasado por parametro.

   moneda: Instacia sobre la cual se invoca a la primitiva.
   posX: Valor pasado por parametro. Nueva posicion en X. */


void setPosX (moneda &Moneda, int posX);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: El campo posY de la moneda se modifica por el valor pasado por parametro.

   moneda: Instacia sobre la cual se invoca a la primitiva.
   posY: Valor pasado por parametro. Nueva posicion en Y. */

void setPosY (moneda &Moneda, int posY);

/* PRE: La moneda debe haber sido creada mediante crear().
   POST: La moneda es generada durante un intervalo de tiempo aleatorio en un lugar aleatorio.

   moneda: Instacia sobre la cual se invoca a la primitiva.
*/

void generarMoneda (moneda &Moneda);

/* ? */

void sumarMoneda ();
