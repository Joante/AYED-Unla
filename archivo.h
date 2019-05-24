#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>






typedef struct Parametro{
    int segundosIntervalo;
    int pillageMax;
    int AreaDeBandido;
    int posXEstacion;
    int posYEstacion;
    int intervaloMoneda;
    int vidaMoneda;
    int intervaloBandido;
    int vidaBandido;
};

typedef struct Comanda{
    int oro;
    int plata;
    int bronce;
    int platino;
    int roca;
    int carbon;
};


typedef struct Mina {
    int posX;
    int posY;
    std::string codItem;
    int intervaloProduccion;
    int listaSecuencia[5];
};

struct Nodo{
    Mina dato;
    Nodo* siguiente;
};


typedef struct ArchivoGral{
    Parametro parametro;
    Comanda comanda;
    Nodo* listaMina;    //juro que es provisorio
};


/*

Pre: ArchivoGral no debe haber sido creado

Post: Se crea un dato del tipo ArchivoGeneral
conteniendo todos los datos de los archivos "parametros.txt"
"comanda.txt" y "mina.txt"

*/


void crear(ArchivoGral &archivoGral);


/*
Pre: ArchivoGral debe haber sido creado.

Post: Se elimina el ArchivoGral

*/

void eliminar(ArchivoGral &archivoGral);


/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve una lista conteniendo todas las minas.
*/

void getListaMina(ArchivoGral &archivoGral, Nodo* listaMina);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve la cantidad de segundos
entre intervalos
*/

void getIntervaloSegundos(ArchivoGral &archivoGral, int& segundos);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve la posicion en eje X e Y de la estacion

recibe el archivo, y dos punteros a enteros donde almacenar las posiciones
de x e y
*/

void getPosicionEstacion(ArchivoGral &archivoGral,int& posX, int& posY);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve el area de ataque del bandido

recibe un puntero a int
*/

void getAreaBandido(ArchivoGral &archivoGral,int& area);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve el intervalo de creacion del bandido

recibe un puntero a int
*/

void getIntervaloBandido(ArchivoGral &archivoGral,int& intervalo);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve la vida maxima del bandido

recibe un puntero a int
*/

void getVidaBandido(ArchivoGral &archivoGral,int& vida);


/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve la maxima cantidad de recursos que puede el bandido pedir
al robar

recibe un puntero a int
*/

void getPillageBandido(ArchivoGral &archivoGral,int& pillage);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve el intervalo de creacion de Moneda

recibe un puntero a int
*/

void getIntervaloMoneda(ArchivoGral &archivoGral,int& intervalo);

/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve la vida maxima de moneda

recibe un puntero a int
*/

void getVidaMoneda(ArchivoGral &archivoGral,int& vida);


/*
Pre: ArchivoGral debe haber sido creado.

Post: se devuelve la comanda del item seleccionado

recibe el archivoGral, un int y un string con el nombre de la comanda a obtener
*/

void getComandaDe(ArchivoGral &archivoGral, int& com, string nombre);


#endif // ARCHIVO_H
