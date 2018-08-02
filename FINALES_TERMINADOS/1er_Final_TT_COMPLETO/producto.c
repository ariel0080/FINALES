#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

//CONSTRUCTOR

eProducto* neweProducto(void)
{
    eProducto* returnAux = NULL;
    eProducto* pProducto = malloc(sizeof(eProducto));
    returnAux = pProducto;
    return returnAux;

}

//SETTERS Y GETTERS

int set_Producto_producto(eProducto* p,int ppp)
{
    int retorno = -1;
     if (p!=NULL)
    {
        p->producto = ppp;
        retorno=1;
    }
    return retorno;
}

int set_Producto_descripcion(eProducto* p,char* nd)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->descripcion,nd);
        retorno=1;
    }
    return retorno;
}
int set_producto_cantidad(eProducto* p,int c)
{
    int retorno = -1;
     if (p!=NULL)
    {
        p->cantidad = c;
        retorno=1;
    }
    return retorno;
}

int get_Producto_producto(eProducto* p)
{
    return p->producto;

}

int get_Producto_descripcion(eProducto* p,char* descrip)
{
    strcpy(descrip,p->descripcion);
    return 1;
}

int get_Producto_cantidad(eProducto* p)
{
    return p->cantidad;
}


//LISTADO DE PRODUCTOS

void listarProductos(ArrayList* pp)
{
    printf("\n%-20s %-20s %-5s\n\n","PRODUCTO","DESCRIPCION","CANTIDAD");
    eProducto* aux;
    for (int i=0; i<al_len(pp); i++ )
                {
                aux=(eProducto*)al_get(pp,i);
                char des[100];
                get_Producto_descripcion(aux,des);
                printf("%-20d %-20s %-5d\n",get_Producto_producto(aux),des,get_Producto_cantidad(aux));

                }
}

int mover_Producto(ArrayList* orig, ArrayList* dest,int producto)
{

    int retorno = -1;
    eProducto* auxp=neweProducto();
    int prod;
    for(int i=0;i<al_len(orig);i++)
    {
        auxp=al_get(orig,i);
        prod= get_Producto_producto(auxp);
        if(prod==producto)
        {

            auxp = al_pop(orig,i);
            al_add(dest,auxp);
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int encontrar_Producto(ArrayList* l,int producto) //devuelva el indice donde esta el producto o -1 si no lo encuentra
{
    int retorno = -1;
    eProducto* auxp=neweProducto();
    int prod;
    for(int i=0;i<al_len(l);i++)
    {
        auxp=al_get(l,i);
        prod= get_Producto_producto(auxp);
        if(prod==producto)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
