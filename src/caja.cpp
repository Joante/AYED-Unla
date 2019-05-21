#include "caja.h"


void crear(Caja &caja, string contenido, int secuenciaActual){
    caja.contenido = contenido;
    caja.capMax = secuenciaActual;
    caja.capActual = caja.capMax;
}
