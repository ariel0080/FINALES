
#include "eProducto.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GETTERS Y SETTERS

int set_eProducto_id(eProducto* p,int c)
{
    int retorno = -1;
    if (p!=NULL)
    {
        p->id = c;
        retorno=1;
    }
    return retorno;
}

int get_eProducto_id(eProducto* p)
{
    return p->id;
}

int set_eProducto_producto(eProducto* p,char* prod)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->producto,prod);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_producto(eProducto* p,char* prod)
{
    strcpy(prod,p->producto);
    return 1;
}

int set_eProducto_direccion(eProducto* p,char* d)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->direccion,d);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_direccion(eProducto* p,char* d)
{
    strcpy(d,p->direccion);
    return 1;
}

int set_eProducto_localidad(eProducto* p,char* l)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->localidad,l);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_localidad(eProducto* p,char* l)
{
    strcpy(l,p->localidad);
    return 1;
}

int set_eProducto_recibe(eProducto* p,char* r)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->recibe,r);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_recibe(eProducto* p,char* r)
{
    strcpy(r,p->recibe);
    return 1;
}


//CONSTRUCTOR

eProducto* neweProducto(void)
{
    eProducto* returnAux = NULL;
    eProducto* pProducto = malloc(sizeof(eProducto));
    returnAux = pProducto;
    return returnAux;

}

// LISTAR

void listar(ArrayList* lista)
{
    printf("\n%-5s %-19s %-28s %-11s %-10s \n\n","ID","PRODUCTO","DIRECCION","LOCALIDAD","RECIBE"); // FORMATEO DE PARCE
    eProducto* aux;  // DECLARACION DE ELEMENTO
    for (int i=0; i<al_len(lista); i++ )
    {
        aux=(eProducto*)al_get(lista,i); // DESDE ACA TRABJO CON AUX

        int id;
        char p[100];
        char d[100];
        char l[100];
        char r[100];

        id = get_eProducto_id(aux);
        get_eProducto_producto(aux,p);
        get_eProducto_direccion(aux,d);
        get_eProducto_localidad(aux,l);
        get_eProducto_recibe(aux,r);
        printf("%-5d %-19s %-28s %-11s %-10s \n",id,p,d,l,r);

    }
}



int Existe_string_en_Array(ArrayList* AL,char* s) // 0 no lo encuentra, 1 existe -1 si algo anda mal
{
    int retorno = 0;
    if(AL!=NULL && s!=NULL)
    {
        eProducto* auxp;
        char localidad[100];

        for(int i=0; i<al_len(AL); i++)
        {
            auxp=al_get(AL,i);
            get_eProducto_localidad(auxp,localidad);
            if(strcmpi(localidad,s)==0)
            {
                retorno =1;
                break;
            }
        }

    }
    return retorno;
}




int fLoc(void* pElement,void* loc) //
{
    int returnaux = -1;
    if(pElement!=NULL)
    {
        eProducto *tmp =(eProducto*)pElement;
        loc = (char*)loc;

        char localidad[100];
        get_eProducto_localidad(tmp,localidad);


        if(strcmpi(loc,localidad)==0)
        {
            returnaux =0;
        }
        else
        {
            returnaux =1;
        }
    }


    return returnaux;
}

void listar_Loc(ArrayList* AL)
{
    printf("\n%-20s \n\n","LOCALIDAD"); // FORMATEO DE PARCE
    eProducto* aux;  // DECLARACION DE ELEMENTO
    for (int i=0; i<al_len(AL); i++ )
    {
        aux=(eProducto*)al_get(AL,i); // DESDE ACA TRABJO CON AUX

        char l[100];



        get_eProducto_localidad(aux,l);
        printf("%-20s \n",l);

    }
}

ArrayList* Generar_Localidades(ArrayList* AL)
{
    char localidad[100];
    ArrayList* AL_Loc;
    AL_Loc=al_newArrayList();

    eProducto* auxeProducto = al_get(AL,0);
    al_add(AL_Loc,auxeProducto);

    for(int i=1; i<al_len(AL); i++)
    {
        auxeProducto =(eProducto*)al_get(AL,i);
        get_eProducto_localidad(auxeProducto,localidad);
        if(Existe_string_en_Array(AL_Loc,localidad)==0)
        {
            al_add(AL_Loc,auxeProducto);
        }
    }
    return AL_Loc;
}


void guardarArchivo(ArrayList* AL,char* nomArch)

{
    FILE* miArchivo;
    char archivo[50];

    strcpy(archivo,nomArch);
    strcat(archivo,".csv");

    miArchivo = fopen(archivo,"w");
    int id;
    char p[100];
    char d[100];
    char l[100];
    char r[100];

    fprintf(miArchivo,"Id,Producto,Direccion,Localidad,Recibe\n");
    for(int i=0; i<al_len(AL); i++)
    {
        eProducto* tmp=al_get(AL,i);

        id=get_eProducto_id(tmp);
        get_eProducto_producto(tmp,p);
        get_eProducto_direccion(tmp,d);
        get_eProducto_localidad(tmp,l);
        get_eProducto_recibe(tmp,r);

        fprintf(miArchivo,"%d,%s,%s,%s,%s\n",id,p,d,l,r);
    }

    fclose(miArchivo);
}
