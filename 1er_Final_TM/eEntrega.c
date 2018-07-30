#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eEntrega.h"


//SETTERS Y GETTERS

int set_En_id(eEntrega* e,int id) //retorna 1 o -1
{
    int retorno = -1;
     if (e!=NULL)
    {
        e->id = id;
        retorno=1;
    }
    return retorno;
}

int get_En_id(eEntrega* e) //rretorna el dato
{
    return e->id;
}

int set_En_producto(eEntrega* e,char* p)//retorna si pudo o no
{
    int retorno = -1;
    if (e!=NULL)
    {
        strcpy(e->producto,p);
        retorno=1;
    }
    return retorno;
}
void get_En_producto(eEntrega* e, char* p) //no retorna el dato
{
    strcpy(p,e->producto);

}

int set_En_direccion(eEntrega* e,char* d)
{
    int retorno = -1;
    if (e!=NULL)
    {
        strcpy(e->direccion,d);
        retorno=1;
    }
    return retorno;
}
void get_En_direccion(eEntrega* e,char* d)
{
    strcpy(d,e->direccion);
}

int set_En_localidad(eEntrega* e,char* d)
{
    int retorno = -1;
    if (e!=NULL)
    {
        strcpy(e->localidad,d);
        retorno=1;
    }
    return retorno;
}
void get_En_localidad(eEntrega* e,char* d)
{
    strcpy(d,e->localidad);
}

int set_En_recibe(eEntrega* e,char* d)
{
    int retorno = -1;
    if (e!=NULL)
    {
        strcpy(e->recibe,d);
        retorno=1;
    }
    return retorno;
}
void get_En_recibe(eEntrega* e,char* d)
{
    strcpy(d,e->recibe);
}


//GENERAR LISTADO

void listar_Entregas(ArrayList* lista)
{
    printf("\n%-5s %-20s %-27s %-15s %-15s\n\n","ID","PRODUCTO","DIRECCION","LOCALDAD","RECIBE");
    eEntrega* aux;
    for (int i=0; i<al_len(lista); i++ )
                {
                aux=(eEntrega*)al_get(lista,i);
                int id=get_En_id(aux);
                char prod[tam_c];
                char dire[tam_c];
                char local[tam_c];
                char reci[tam_c];

                get_En_producto(aux,prod);
                get_En_direccion(aux,dire);
                get_En_localidad(aux,local);
                get_En_recibe(aux,reci);


                printf("%-5d %-20s %-27s %-15s %-15s\n",id,prod,dire,local,reci);

                }
}

int filtro(void* e,void* l)
{
    int returnaux = -1;

    if(e!=NULL && l!=NULL)
    {
        returnaux =0;
        eEntrega *tmp=(eEntrega*)e;
        ArrayList *ltmp =(ArrayList*)l;

        localidad = get_En_localidad(tmp,localidad);

        strcpy(lista_loc[tam_c][0],localidad);

        if (sueldo > 20000.00)
        {
          returnaux =1;
        }
        else returnaux =0;
    }

    return returnaux;

}


int set_eLocalidad_estado(eLocalidad* e,int estado)
{
    int retorno = -1;
     if (e!=NULL)
    {
        e->estado = estado;
        retorno=1;
    }
    return retorno;
}
int get_eLocalidad_estado(eLocalidad* e)
{
    return e->estado;
}

int set_eLocalidad_localidad(eLocalidad* l,char* loc)
{
    int retorno = -1;
    if (e!=NULL)
    {
        strcpy(l->localidad,loc);
        retorno=1;
    }
    return retorno;
}

void get_eLocalidad_localidad(eLocalidad* e ,char* l)
{
    strcpy(l,e->localidad);
}


void Generar_listado_loc(ArrayList* lista,eLocalidad* l)
{
    char auxLoc[tam_c];
    eEntrega* aux;

    for(int i;i<al_len(lista);i++)
    {
        aux=(eEntrega*)al_get(lista,i);
        get_En_localidad(aux,auxLoc);
            for(j=0;j<30;j++)
                {
                    if(strcmp(l[j],auxLoc)==0){breaak;}
                }
            if(j==30){}
    }
}
