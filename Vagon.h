#ifndef VAGON_H_INCLUDED
#define VAGON_H_INCLUDED
//#include "Pila.h"
/**
    Definicion del Tipo de Dato para manejo de Vagones.
    Atributos:
    * id
    * estado
    * pesoMax
    * pesoUtilizado
    * item
    * Caja

    Axiomas:
    *pesoMax > 0
    *pesoUtilizado > 0

*/
/** Tipo de Enumerado Item */
enum Item{
    oro,
    plata,
    bronce,
    platino,
    roca,
    carbon
};
/** Tipo de Estructura del Vagon */

typedef struct Vagon{
        int id;
        bool estado;
        int pesoMax;
        int pesoUtilizado;
        Item item;
        Pila cajas;
        };

/** PRE: El vagon no debe haber sido creado
    POST: El vagon queda creado y preparado para ser utilizado,
    vagon.id=1;
    vagon.estado=true;
*/
void crearVagon(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El vagon es eliminado
*/
void eliminarVagon(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo radio pasa a tener el dato ingresado
*/
void setId(Vagon &vagon, int id);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  id
*/
int getId(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo estado pasa a tener el dato ingresado
*/
void setEstado(Vagon &vagon, bool estado);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  estado
*/
int getEstado(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo pesoMax pasa a tener el dato ingresado
*/
void setPesoMax(Vagon &vagon, int pesoMax);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  pesoMax
*/
int getPesoMax(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo PesoUtilizado pasa a tener el dato ingresado
*/
void setPesoUtilizado(Vagon &vagon, int pesoUtilizado);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  PesoUtilizado
*/
int getPesoUtilizado(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo item pasa a tener el dato ingresado
*/
void setItem(Vagon &vagon, Item item);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  item
*/
int getItem(Vagon &vagon);

/** PRE: Vagon creado con crearVagon()
    POST: El campo cajas pasa a tener el dato ingresado
*/
void setCajas(Vagon &vagon, Pila cajas);

/** PRE: Vagon creado con crearVagon()
    POST: Delvuelve el dato contenido en el campo  cajas
*/
int getCajas(Vagon &vagon);

#endif // VAGON_H_INCLUDED
