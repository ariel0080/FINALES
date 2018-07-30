#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eLetra.h"


eLetra* neweLetra(void)
{
    eLetra* returnAux = NULL;
    eLetra* pLetra = malloc(sizeof(eLetra));
    returnAux = pLetra;
    return returnAux;

}

c_l* newc_l(void)
{
    c_l* returnAux = NULL;
    c_l* pc_l = malloc(sizeof(c_l));
    returnAux = pc_l;
    return returnAux;

}
//SETTERS Y GETTERS

int set_eLetra_nombre(eLetra* l,char* nombre)
{
    int retorno = -1;
    if (l!=NULL)
    {
        strcpy(l->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

void get_eLetra_nombre(eLetra* l,char* nombre)
{
    strcpy(nombre,l->nombre);
}

int set_eLetra_letra(eLetra* l,char letra)
{
    char retorno = -1;
     if (l!=NULL)
    {
        l->letra = letra;
        retorno=1;
    }
    return retorno;
}

char get_eLetra_letra(eLetra* l)
{
    return l->letra;
}

int set_eLetra_vocal(eLetra* l,int vocal) //retorna 1 o -1
{
    int retorno = -1;
     if (l!=NULL)
    {
        l->vocal = vocal;
        retorno=1;
    }
    return retorno;
}

int get_eLetra_vocal(eLetra* l) //rretorna el dato
{
    return l->vocal;
}

int set_eLetra_consonante(eLetra* l,int consonante) //retorna 1 o -1
{
    int retorno = -1;
     if (l!=NULL)
    {
        l->consonante = consonante;
        retorno=1;
    }
    return retorno;
}

int get_eLetra_consonante(eLetra* l)
{
    return l->consonante;
}

int completar(ArrayList* l)
{
    if(l!=NULL)
    {
        char letra;
        eLetra* aux;
        for(int i;i<al_len(l);i++)
        {
            aux=(eLetra*)al_get(l,i);
            letra = get_eLetra_letra(aux);//printf("le-%c-",letra);
            if(letra == 'a' || letra =='e' || letra =='i'|| letra =='o'|| letra =='u')
            {

                set_eLetra_vocal(aux,1);
                set_eLetra_consonante(aux,0);
            }
            else
                {

                    set_eLetra_vocal(aux,0);
                    set_eLetra_consonante(aux,1);
                }
        }

    }

    else printf("NO SE PUDO COMPLETAR LA LISTA");
}


    void listar(ArrayList* lista)
{
    printf("\n%-5s %-10s %-10s %-10s \n\n","LETRA","NOMBRE","VOCAL","CONSONANTE","RECIBE");
    eLetra* aux;
    for (int i=0; i<al_len(lista); i++ )
                {
                aux=(eLetra*)al_get(lista,i);

                int v;
                int c;
                char letra;
                char nombre[30];

                letra = get_eLetra_letra(aux);
                get_eLetra_nombre(aux,nombre);
                v=get_eLetra_vocal(aux);
                c=get_eLetra_consonante(aux);

                printf("\n%-5c %-10s %-10d %-10d \n\n",letra,nombre,v,c);

                }
}


int buscarElementoPrincipal(char l,ArrayList* lista)
{
    eLetra* aux;
    int cont=0;
    for(int i=0;i<al_len(lista);i++)
    {
        aux=(eLetra*)al_get(lista,i);
        char letra;
        letra = get_eLetra_letra(aux);

        if(letra==l){cont++;}
    }

    return cont;
}

/*int buscarElementoPalabra(char l, char[] palabra)

    {
        int c=0;
        int i=0;
        while(char[i]!='\0')
        {
            if(char[i]==l){c++;}
        }

        return c;
    }*/
/*void completarArraySecundario(ArrayList* p,ArrayList* s)
{
    for(int a=0;a<al_len(s);a++)
    {
        for(int b=0;a<al_len(p);b++)
        buscarElementoPrincipal()
    }
}*/


void ConLetrasPalabra(ArrayList* s,char* palabra)
{
    c_l* aux;
    for(int a=0;a<strlen(palabra);a++)
    {
        for(int b=0;b<al_len(s);b++)
        {

            aux=(c_l*)al_get(s,b);
            if(palabra[a]==(aux->letra)){(aux->cant)++;}
        }
    }




}

 void listarS(ArrayList* lista)
{
    printf("\n%-10s %-10s \n\n","LETRA","CANT");
    c_l* aux;
    for (int i=0; i<al_len(lista); i++ )
                {
                aux=(eLetra*)al_get(lista,i);

                printf("\n%-5c %-10d \n\n",(aux->letra),(aux->cant));

                }
}


