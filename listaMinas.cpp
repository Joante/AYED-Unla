#include "listaMinas.h"

/******************************************************************************/
/* Definición de Tipos de Minas para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/
ResultadoComparacionMina compararMina(Mina dato1, Mina dato2) {
    /*if (dato1.sgte > dato2.sgte) {
        return MAYOR;
    }
    else if (dato1 < dato2) {
        return MENOR;
    }
    else {
    */
    if(dato1.posX == dato2.posX && dato1.posY == dato2.posY){
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de datos a ser creado.
*/
void crearListaMinas(ListaMinas &lista) {
  lista.primero = finMinas();
}

/*
  pre : lista Creada con crearListaMinas().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaMinas &lista) {

  return (primero(lista) == finMinas());
}

/*
  pre : lista Creada con crearListaMinas().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representación del finMinas de la lista.
*/
PtrNodoListaMinas finMinas() {
  return NULL;
}

/*
  pre : lista Creada con crearListaMinas().
  post: devuelve el puntero al primer elemento de la lista, o devuelve finMinas() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMinas primero(ListaMinas &lista) {
  return lista.primero;
}

/*
  pre : lista Creada con crearListaMinas().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve finMinas() si
        ptrNodo apuntaba a finMinas() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMinas siguiente(ListaMinas &lista, PtrNodoListaMinas ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finMinas()))
    return ptrNodo->sgte;
  else
    return finMinas();
}

/*
  pre : lista Creada con crearListaMinas().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve finMinas() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaMinas anterior(ListaMinas &lista, PtrNodoListaMinas ptrNodo) {

  PtrNodoListaMinas ptrPrevio = finMinas();
  PtrNodoListaMinas ptrCursor = primero(lista);

  while (( ptrCursor != finMinas()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : lista creada con crearListaMinas().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve finMinas() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoListaMinas ultimo(ListaMinas &lista) {

  /* el último nodo de la lista es el anterior al finMinas() */
  return anterior(lista,finMinas());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaMinas crearNodoListaMinas(Mina dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaMinas ptrAux = new NodoListaMinas;

  ptrAux->dato = dato;
  ptrAux->sgte = finMinas();

  return ptrAux;
}

/*
  pre : lista creada con crearListaMinas().
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMinas adicionarPrincipio(ListaMinas &lista, Mina dato) {

  /* crea el nodo */
  PtrNodoListaMinas ptrNuevoNodo = crearNodoListaMinas(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMinas().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a finMinas() no inserta
        nada y devuelve finMinas().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaMinas adicionarDespues(ListaMinas &lista, Mina dato, PtrNodoListaMinas ptrNodo) {

  PtrNodoListaMinas ptrNuevoNodo = finMinas();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != finMinas()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaMinas(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMinas().
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMinas adicionarFinal(ListaMinas &lista, Mina dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*
  pre : lista creada con crearListaMinas().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve finMinas(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaMinas adicionarAntes(ListaMinas &lista, Mina dato, PtrNodoListaMinas ptrNodo) {

  PtrNodoListaMinas ptrNuevoNodo = finMinas();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMinas(), no vacia. ptrNodo es distinto de finMinas().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarMina(ListaMinas &lista, Mina &dato, PtrNodoListaMinas ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finMinas()))
    ptrNodo->dato = dato;
}

/*
  pre : lista creada con crearListaMinas(), no vacia. ptrNodo es distinto de finMinas().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerMina(ListaMinas &lista, Mina &dato, PtrNodoListaMinas ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finMinas()))
    dato = ptrNodo->dato;
}

/*
  pre : lista creada con crearListaMinas().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a finMinas().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaMinas &lista, PtrNodoListaMinas ptrNodo) {

  PtrNodoListaMinas ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != finMinas())) {

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

/*...*/
void eliminarNodoPrimero(ListaMinas &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*...*/
void eliminarNodoUltimo(ListaMinas &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*
  pre : lista creada con crearListaMinas().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaMinas(ListaMinas &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}
/* Definición de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaMinas().
  post: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve finMinas().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o finMinas().
*/
PtrNodoListaMinas localizarMina(ListaMinas &lista, Mina dato) {

   bool encontrado = false;
   Mina datoCursor;
   PtrNodoListaMinas ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finMinas()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerMina(lista,datoCursor,ptrCursor);
    if (compararMina(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finMinas();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearListaMinas().
  post : elimina el dato de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarMina(ListaMinas &lista, Mina dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaMinas ptrNodo = localizarMina(lista,dato);
  if (ptrNodo != finMinas())
    eliminarNodo(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearListaMinas() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMinas insertarMina(ListaMinas &lista, Mina dato) {

  PtrNodoListaMinas ptrPrevio = primero(lista);
  PtrNodoListaMinas ptrCursor = primero(lista);
  PtrNodoListaMinas ptrNuevoNodo;
  Mina datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finMinas()) && (! ubicado)) {

    obtenerMina(lista,datoCursor,ptrCursor);
    if (compararMina(datoCursor,dato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues(lista,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la lista fue creada con crearListaMinas().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenar(ListaMinas &lista) {

  ListaMinas temp = lista;
  PtrNodoListaMinas ptrCursor = primero(temp);
  crearListaMinas(lista);
  while ( ptrCursor != finMinas() ) {
        Mina dato;
        obtenerMina( temp, dato, ptrCursor);
        insertarMina( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarListaMinas( temp );
}

/*
  pre : la lista fue creada con crearListaMinas().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud(ListaMinas &lista){
  PtrNodoListaMinas ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finMinas() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/

