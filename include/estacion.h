#ifndef ESTACION_H_INCLUDED
#define ESTACION_H_INCLUDED

/*
Definición del tipo Tipo de Dato para el manejo de la Estación.
Atributos:
        *posXE,
        *posYE.

Axiomas:
        *posXE se definirá por el archivo propuesto por el docente.
        *posYE se definirá por el archivo propuesto por el docente.

*/
/* Tipo de estructura de la Estación */

typedef struct
{
    int posXE;
    int posYE;

}Estacion;

/* Definición de Primitivas  */

/* PRE: La estación no debe haber sido creada.
   POST: La estación esta creada y lista para ser usada. */

void crear (estacion &Estacion);

/* PRE: La estación debe haber sido creada mediante crear().
   POST: La estación es eliminada.

   estacion: Instacia sobre la cual se invoca a la primitiva */

void eliminar (estacion &Estacion);

/* PRE: La estación debe haber sido creada mediante crear().
   POST: Se devuelve la posición en X de la estación

   estacion: Instacia sobre la cual se invoca a la primitiva*/

int getPosXE (estacion &Estacion);

/* PRE: La estación debe haber sido creada mediante crear().
   POST: Se devuelve la posición en Y de la estación

   estacion: Instacia sobre la cual se invoca a la primitiva*/

int getPosYE (estacion &Estacion);

/* PRE: La estación debe haber sido creada mediante crear().
   POST: El campo posXE de la estación se modifica por el valor pasado por parametro.

   estacion: Instacia sobre la cual se invoca a la primitiva.
   posXE: Valor pasado por parametro. Nueva posicion en X. */

void setPosXE (estacion &Estacion, int posXE);

/* PRE: La estación debe haber sido creada mediante crear().
   POST: El campo posYE de la estación se modifica por el valor pasado por parametro.

   estacion: Instacia sobre la cual se invoca a la primitiva.
   posYE: Valor pasado por parametro. Nueva posicion en Y. */

void setPosYE (estacion &Estacion, int posYE);

/* ? */

void agregarVagon ();
