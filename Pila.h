#ifndef __PILA_H__
#define __PILA_H__

#ifndef NULL
#define NULL      0
#endif

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

/* Tipo de Informacion que esta contenida en los Nodos de la
   Pila, identificada como Dato. */
typedef void* PtrDato;

/* Tipo de Estructura de los Nodos de la Pila. */
struct NodoPila {
    PtrDato ptrDato; // dato almacenado
    NodoPila* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Pila, el cual se usa para recorrer
   la Pila y acceder a sus Datos. */
typedef NodoPila* PtrNodoPila;

/* Tipo de Estructura de la Lista */
struct Pila{
    PtrNodoPila primero;      // puntero al primer nodo de la pila
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la pila no debe haber sido creada.
  post: pila queda creada y preparada para ser usada.

  pila : estructura de datos a ser creado.
*/
void crearPila(Pila &pila);

/*----------------------------------------------------------------------------*/
/*
  pre : pila Creada con crearPila().
  post: devuelve la representacion de lo Siguiente al último Nodo de la pila,
        o sea el valor Null, que en esta implementacion representa el final de
        la pila.

  return: representación del fin de la pila.
*/
PtrNodoPila finPila();

/*----------------------------------------------------------------------------*/
/*
  pre : pila creada con crearPila().
  post: Devuelve true si pila esta vacia, sino devuelve false.

  pila: pila sobre la cual se invoca la primitiva.
*/
bool pilaVacia(Pila &pila);

/*----------------------------------------------------------------------------*/
/*
  pre : pila creada con crearPila().
  post: devuelve el puntero al primer elemento de la pila, o devuelve fin() si
        esta vacia

  pila: pila sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoPila cima(Pila &pila);

/*----------------------------------------------------------------------------*/
/*
  pre : pila creada con crearPila().
  post: agrega un nodo nuevo al principio de la pila con el dato proporcionado
        y devuelve un puntero a ese elemento.

  pila: pila sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la pila.
  return puntero al nodo adicionado.
*/
PtrNodoPila agregar(Pila &pila, PtrDato ptrDato);

/*----------------------------------------------------------------------------*/
/*
  pre : pila creada con crearPila().
  post: obtiene el ultimo dato agregado a la pila, elimina el nodo
        y devuelve un puntero al elemento anteriormente agregado.

  pila: pila sobre la cual se invoca la primitiva.
  dato : elemento obtenido de la pila.
  return puntero al nuevo ultimo nodo.
*/
PtrDato sacar(Pila &pila);

/*----------------------------------------------------------------------------*/
/*
  pre : pila creada con crearPila().
  post: elimina todos los Nodos de la pila quedando destruida e inhabilitada
        para su uso.

  pila: pila sobre la cual se invoca la primitiva.
*/
void eliminarPila(Pila &pila);



#endif
