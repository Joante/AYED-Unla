#ifndef LOCOMOTORA_H_INCLUDED
#define LOCOMOTORA_H_INCLUDED

/*
Definición del tipo Tipo de Dato para el manejo de la Locomotora.
Atributos:
  boolean estado;
  int posX;
  int posY;
  int locomotoras;
  ListaVagon listaVagones;

Axiomas:
    posX debe tener un valor entre 0 y 600
    posY debe tener un valor entre 0 y 600

*/
/* Tipo de estructura de la Locomotora */

typedef struct
{
    bool estado;
    int posX;
    int posY;
    int monedas;
//falta la implementacion de lista para la lista de vagones
}Locomotora;


/* Definición de Primitivas  */

/* PRE: La locomotora no debe haber sido creada.
   POST: La locomotora esta creada y lista para ser usada. */

void crear (Locomotora &locomotora);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: La locomotora es eliminada.

   locomotora: Instacia sobre la cual se invoca a la primitiva */

void eliminar (Locomotora &locomotora);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: Se devuelve la posición en X de la locomotora

   locomotora: Instacia sobre la cual se invoca a la primitiva*/

int getPosX (Locomotora &locomotora);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: Se devuelve la posición en Y de la locomotora

   locomotora: Instacia sobre la cual se invoca a la primitiva*/

int getPosY (Locomotora &locomotora);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: Se devuelve la cantidad de monedas que posee la locomotora

   locomotora: Instacia sobre la cual se invoca a la primitiva*/

int getMonedas (Locomotora &locomotora);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: Se devuelve el estado de la locomotora.

   locomotora: Instacia sobre la cual se invoca a la primitiva*/

bool getEstado (Locomotora &locomotora);


//ListaVagon getListaVagones (Locomotora &locomotora)-- falta implementacion de lista vagones



/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: El campo monedas de la locomotora se modifica por el valor pasado por parametro.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
   monedas: Valor pasado por parametro.*/

void setMonedas (Locomotora &locomotora, int tiempoVida);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: El campo posX de la locomotora se modifica por el valor pasado por parametro.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
   posX: Valor pasado por parametro. Nueva posicion en X. */

void setPosX (Locomotora &locomotora, int posX);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: El campo posY de la locomotora se modifica por el valor pasado por parametro.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
   posY: Valor pasado por parametro. Nueva posicion en Y. */

void setPosY (Locomotora &locomotora, int posY);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: El edtado de la locomotora se modifica por el valor pasado por parametro.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
   posX: Valor pasado por parametro.  */

void setEstado (Locomotora &locomotora, bool estado);



//void setListaVagones (ListaVagones lista, Locomotora &locomotora)-- falta implementacion de lista vagones


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: La locomotora cambia su ubicacion en la grilla de terreno segun la direccion correspondiente.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
   evento: librería SDL, representa el estímulo exterior de perifericos, en este caso sera la presion de teclas
*/
void moverse (Locomotora &locomotora, SDL_Event evento);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: La locomotora frena al haber chocado contra una mina, la estacion, un bandido o los limites del terreno.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
   evento: librería SDL, representa el estímulo exterior de perifericos, en este caso sera la presion de teclas
*/
void pararLocomotora (Locomotora &locomotora, SDL_Event evento);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: Se cambia el estado de la locomotora y se pierde el juego.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
*/
void colisionVagones (Locomotora &locomotora);


/* PRE: La locomotora debe haber sido creada mediante crear().
   POST: Se cambia el estado de la locomotora y se pierde el juego.

   locomotora: Instacia sobre la cual se invoca a la primitiva.
*/
void colisionVagones (Locomotora &locomotora);
