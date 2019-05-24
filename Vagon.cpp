#include"Vagon.h"
void crearVagon(Vagon &vagon)
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

