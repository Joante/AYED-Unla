#include "Lista.h"


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(Lista &lista, PFComparacion funcComparacion) {
  lista.primero = finLista();
  lista.compara = funcComparacion;
}

/*----------------------------------------------------------------------------*/
bool listaVacia(Lista &lista) {

  return (primero(lista) == finLista());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista finLista() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista primero(Lista &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista siguiente(Lista &lista, PtrNodoLista ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finLista()))
    return ptrNodo->sgte;
  else
    return finLista();
}

/*----------------------------------------------------------------------------*/
PtrNodoLista anterior(Lista &lista, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrPrevio = finLista();
  PtrNodoLista ptrCursor = primero(lista);

  while (( ptrCursor != finLista()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista ultimo(Lista &lista) {

  /* el último nodo de la lista es el anterior al finLista() */
  return anterior(lista,finLista());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista crearNodoLista(PtrDato ptrDato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoLista ptrAux = new NodoLista;

  ptrAux->ptrDato = ptrDato;
  ptrAux->sgte = finLista();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarPrincipio(Lista &lista, PtrDato ptrDato) {

  /* crea el nodo */
  PtrNodoLista ptrNuevoNodo = crearNodoLista(ptrDato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarDespues(Lista &lista, PtrDato ptrDato, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrNuevoNodo = finLista();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,ptrDato);

  else {
    if (ptrNodo != finLista()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(ptrDato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarFinal(Lista &lista, PtrDato ptrDato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,ptrDato,ultimo(lista));
}
/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarAntes(Lista &lista, PtrDato ptrDato, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrNuevoNodo = finLista();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,ptrDato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,ptrDato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(Lista &lista, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != finLista())) {

    if (ptrNodo == primero(lista))
      lista.primero = siguiente(lista,primero(lista));

    else {
      ptrPrevio = anterior( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(Lista &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(Lista &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(Lista &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista localizarDato(Lista &lista, PtrDato ptrDato) {

   bool encontrado = false;
   PtrDato ptrDatoCursor;
   PtrNodoLista ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finLista()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    ptrDatoCursor = ptrCursor->ptrDato;
    if (lista.compara(ptrDatoCursor,ptrDato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finLista();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(Lista &lista, PtrDato ptrDato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoLista ptrNodo = localizarDato(lista,ptrDato);
  if (ptrNodo != finLista())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoLista insertarDato(Lista &lista, PtrDato ptrDato) {

  PtrNodoLista ptrPrevio = primero(lista);
  PtrNodoLista ptrCursor = primero(lista);
  PtrNodoLista ptrNuevoNodo;
  PtrDato ptrDatoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finLista()) && (! ubicado)) {

    ptrDatoCursor= ptrCursor->ptrDato;
    if (lista.compara(ptrDatoCursor,ptrDato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,ptrDato);
  else
    ptrNuevoNodo = adicionarDespues(lista,ptrDato,ptrPrevio);

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(Lista &lista) {

  Lista temp = lista;
  PtrNodoLista ptrCursor = primero(temp);
  crearLista(lista, temp.compara);
  while ( ptrCursor != finLista() ) {
        PtrDato ptrDato;
        ptrDato = ptrCursor ->ptrDato;
        insertarDato( lista, ptrDato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(Lista &lista){
  PtrNodoLista ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finLista() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/
