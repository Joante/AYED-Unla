#include "Pila.h"

using namespace std;

/******************************************************************************/
/* Funciones auxiliares */
/*------------------------------*/

PtrNodoPila crearNodoPila(PtrDato ptrDato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoPila ptrAux = new NodoPila;

  ptrAux->ptrDato = ptrDato;
  ptrAux->sgte = NULL;

  return ptrAux;
}

/*----------------------------------------------------------------------------*/

void eliminarNodoPila(Pila &pila) {

  PtrNodoPila ptrExCima;

  /* verifica que la pila no esté vacia y que nodo no sea fin*/
  if (! pilaVacia(pila)) {
      
      ptrExCima = cima(pila);      
      pila.primero = cima(pila)->sgte;
      
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrExCima;
  }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearPila(Pila &pila) {
  pila.primero = finPila();
}

/*----------------------------------------------------------------------------*/

PtrNodoPila finPila() {
  return NULL;
}

/*----------------------------------------------------------------------------*/

bool pilaVacia(Pila &pila){
  return (pila.primero == finPila());
}

/*----------------------------------------------------------------------------*/


PtrNodoPila cima(Pila &pila){
    return pila.primero;
}



/*----------------------------------------------------------------------------*/

PtrNodoPila agregar(Pila &pila, PtrDato ptrDato){
            
  /* crea el nodo */
  PtrNodoPila ptrNuevoNodo = crearNodoPila(ptrDato);
  
  ptrNuevoNodo->sgte = pila.primero;
  pila.primero = ptrNuevoNodo;
  
  return ptrNuevoNodo;   

}

/*----------------------------------------------------------------------------*/


PtrDato sacar(Pila &pila){
    PtrDato dato = NULL;
    PtrNodoPila nodo = cima(pila);
    if ((! pilaVacia(pila))){
        dato = nodo->ptrDato;
        eliminarNodoPila(pila);
    }
    return dato;
}

/*----------------------------------------------------------------------------*/

void eliminarPila(Pila &pila){
     while((! pilaVacia(pila))){
         eliminarNodoPila(pila);
     }
}

