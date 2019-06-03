#include"Vagon.h"
#include"SDL.h"
#include"SDL_image.h"
void constructorVagon(Vagon &vagon)
{
    vagon.id=1;
    vagon.estado=true;
}

void eliminarVagon(Vagon &vagon)
{

}

void setId(Vagon &vagon, int id)
{
    vagon.id=id;
}

int getId(Vagon &vagon)
{
    return vagon.id;
}
void setEstado(Vagon &vagon, bool estado)
{
    vagon.estado=estado;
}
int getEstado(Vagon &vagon)
{
    return vagon.estado;
}
void setPesoMax(Vagon &vagon, int pesoMax)
{
    vagon.pesoMax=pesoMax;
}
int getPesoMax(Vagon &vagon)
{
    return vagon.pesoMax;
}
void setPesoUtilizado(Vagon &vagon, int pesoUtilizado)
{
    vagon.pesoUtilizado;
}
int getPesoUtilizado(Vagon &vagon)
{
    return vagon.pesoUtilizado;
}
void setItem(Vagon &vagon, Item item)
{
    vagon.item=item;
}

int getItem(Vagon &vagon)
{
    return vagon.item;
}
void crearVagon(Vagon &vagon, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer)
{
    vagon.f=f;//coordenada logica y
    vagon.c=c;//coordenada logica x
    vagon.imagen=IMG_LoadTexture(renderer,"img/vagon.png");
    vagon.rectImag.y=f* altoCasillero;//coordenada de dibujo y
    vagon.rectImag.x= c* anchoCasillero;//coordenada de dibujo x
    vagon.rectImag.w= anchoCasillero;//ancho
    vagon.rectImag.h= altoCasillero;//alto
}
void dibujarVagon(Vagon &vagon, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, vagon.imagen,NULL,&(vagon.rectImag));
}
void destruirVagon(Vagon &vagon){
    SDL_DestroyTexture(vagon.imagen);
}

