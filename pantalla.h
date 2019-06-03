#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#endif
#import "Terreno.h"
///*
//Definición del tipo Tipo de Dato para el manejo de la Pantalla.
//Atributos:
//int id
//int dimensionX
//int dimensionY
//Terreno terreno
//int comanda[6]
//
//Axiomas:
//    dimensionX debe tener un valor entre 0 y 600
//    dimensionY debe tener un valor entre 0 y 600
//
//*/
///* Tipo de estructura de la Pantalla */
//
//typedef struct
//{
//    int id;
//    int dimensionX;
//    int dimensionY;
//    Terreno terreno;
//    int comanda[6];
//}Pantalla;
//
//
///* Definición de Primitivas  */
//
///* PRE: La pantalla no debe haber sido creada.
//   POST: La pantalla esta creada y lista para ser usada. */
//
//void crear (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: La pantalla es eliminada.
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva */
//
//void eliminar (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: Se devuelve el ID de la pantalla
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva*/
//
//int getId (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: Se devuelve la posición en X de la pantalla
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva*/
//
//int getDimensionX (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: Se devuelve la posición en Y de la pantalla
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva*/
//
//int getDimensionY (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: Se devuelve el terreno de la pantalla
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva*/
//
//Terreno getTerreno (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: Se devuelve los valores de la comanda
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva*/
//
//int getComanda (pantalla &Pantalla);
//
//
//
//
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: El campo monedas de la pantalla se modifica por el valor pasado por parametro.
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   monedas: Valor pasado por parametro.*/
//
//void setId (pantalla &Pantalla, int id);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: El campo monedas de la pantalla se modifica por el valor pasado por parametro.
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   monedas: Valor pasado por parametro.*/
//
//void setMonedas (pantalla &Pantalla, int tiempoVida);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: El campo dimensionX de la pantalla se modifica por el valor pasado por parametro.
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   dimensionX: Valor pasado por parametro. Nueva posicion en X. */
//
//void setDimensionX (pantalla &Pantalla, int dimensionX);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: El campo dimensionY de la pantalla se modifica por el valor pasado por parametro.
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   dimensionY: Valor pasado por parametro. Nueva posicion en Y. */
//
//void setDimensionY (pantalla &Pantalla, int dimensionY);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: El campo comanda de la pantalla se modifica por el valor pasado por parametro.
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   comada: Valor pasado por parametro.  */
//
//void setComanda (pantalla &Pantalla, int comanda);
//
//
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: La comanda aparece en la pantalla
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   */
//void mostrarComanda (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: Los valores adquiridos de monedas y lingotes aparecen en la pantalla
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//   evento: librería SDL, representa el estímulo exterior de perifericos, en este caso sera la presion de teclas
//*/
//void mostrarTotalesObtenidos (pantalla &Pantalla);
//
//
///* PRE: La pantalla debe haber sido creada mediante crear().
//   POST: El juego se pausa
//
//   pantalla: Instacia sobre la cual se invoca a la primitiva.
//*/
//void pausa (pantalla &Pantalla);
