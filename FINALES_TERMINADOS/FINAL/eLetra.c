#include "eLetra.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>



// CONSTRUCTOR DE ELEMENTO STRUCT ELETRA

eLetra* neweLetra(void)
{
    eLetra* returnAux = NULL;
    eLetra* pLetra = malloc(sizeof(eLetra));
    returnAux = pLetra;
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


int get_eLetra_nombre(eLetra* l,char* nombre)
{
    strcpy(nombre,l->nombre);
    return 1;
}


int set_eLetra_vocal(eLetra* l,int v)
{
    int retorno = -1;
     if (l!=NULL)
    {
        l->vocal = v;
        retorno=1;
    }
    return retorno;
}

int get_eLetra_vocal(eLetra* l)
{
    return l->vocal;
}
int set_eLetra_consonante(eLetra* l,int c)
{
    int retorno = -1;
     if (l!=NULL)
    {
        l->consonante = c;
        retorno=1;
    }
    return retorno;
}

int get_eLetra_consonante(eLetra* l)
{
    return l->consonante;
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


// GENERAR LISTADO

void listar(ArrayList* AL)
{
    printf("\n%-5s %-10s %-10s %-10s \n\n","LETRA","NOMBRE","VOCAL","CONSONANTE"); // FORMATEO DE PARCE
    eLetra* auxeLetra;  // DECLARACION DE ELEMENTO
    for (int i=0; i<al_len(AL); i++ )
                {
                auxeLetra=(eLetra*)al_get(AL,i); // DESDE ACA TRABJO CON AUX

                int v;
                int c;
                char letra;
                char nombre[30];

                letra = get_eLetra_letra(auxeLetra); //CHAR
                get_eLetra_nombre(auxeLetra,nombre); //STRING LO ASIGNA  ANOMBRE
                v=get_eLetra_vocal(auxeLetra); //ENTERO
                c=get_eLetra_consonante(auxeLetra); //ENTERO

                printf("%-5c %-10s %-10d %-10d \n",letra,nombre,v,c);

                }
}

//FUNCION COMPLETAR

int completar_eLetra(eLetra* l)
{
    char letra;
    letra = get_eLetra_letra(l);

    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
    {
            set_eLetra_consonante(l,0);
            set_eLetra_vocal(l,1);
    }
    else
    {
        set_eLetra_consonante(l,1);
        set_eLetra_vocal(l,0);
    }
}

int completar_ArrayList(ArrayList* AL)
{
    int retorno=-1;
    if(AL!=NULL)
    {
        eLetra* auxeLetra;
        retorno = 1;
        for(int i=0;i<al_len(AL);i++)
        {
            auxeLetra = (eLetra*)al_get(AL,i);
            completar_eLetra(auxeLetra);
        }
    }


    return retorno;
}

// FUNCION PARA EL PUNTO 3

int consulta_user(char* dato, int caracteres)
{
    if(dato!=NULL)
    {
        fflush(stdin);
        fgets(dato,caracteres,stdin);
    int largo=0;
    while (*(dato+largo)!='\n')
        {
        largo++;
        }
    *(dato+largo)='\0';
    return 0;
    }
    else return -1;
}

int buscarLetra_ArrayList(ArrayList* AL, char letra)
{
    int retorno = -1;
    eLetra* auxeLetra;
    char letra_array;
    for(int i=0;i<al_len(AL);i++)
    {
        auxeLetra=al_get(AL,i);
        letra_array= get_eLetra_letra(auxeLetra);
        if(letra==letra_array)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void comprobar(ArrayList* AL)
{
    ArrayList* auxArrayList;
    auxArrayList = al_newArrayList();
    auxArrayList = al_clone(AL);
    char* palabra;
    palabra =(char*)malloc(sizeof(char)*100);
    LP();
    printf("\n\n\t POR FAVOR INGRESE PALABRA A COMPROBAR: ");
    consulta_user(palabra,199);
    palabra = strlwr(palabra);
    int i;

    for(i=0;i<strlen(palabra);i++)
    {
        int indice_letra= buscarLetra_ArrayList(auxArrayList,palabra[i]);

        if (indice_letra!=-1)
        {
            al_remove(auxArrayList,indice_letra);

        }
        else
        {
            printf("NO SE PUEDE REALIZAR LA OPERACION, HAY MAS LETRAS EN LA PALABRA QUE EN EL ARRAYLIST");
            break;
        }



        if(i==strlen(palabra)-1)
        {
            printf("\nEXISTEN LAS LETRAS NECESARIAS EN EL ARRAY PARA FORMAR LA PALABRA INGRESADA\n");
        }


    }
        al_deleteArrayList(auxArrayList);

}

int contar_letra(ArrayList* AL, char l)
{
    eLetra* auxeLetra;
    int contador=0;

    for(int i=0;i<al_len(AL);i++)
    {
        auxeLetra = (eLetra*)al_get(AL,i);
        if(l==get_eLetra_letra(auxeLetra))
        {
            contador++;
        }
    }

    return contador;
}

void generar_y_listar_descendente(ArrayList* AL)
{
    int contar;
    for(int i=0;i<al_len(AL);i++)
    {
        eLetra* auxeLetra;
        auxeLetra = (eLetra*)al_get(AL,i);
        contar = contar_letra(AL,get_eLetra_letra(auxeLetra));
        if(contar<2)
        {
            al_remove(AL,i);
        }
    }
}

int compareeLetra(void* pLetraA,void* pLetraB)
{
    eLetra* tmp1=(eLetra*)pLetraA ;
    eLetra* tmp2=(eLetra*)pLetraB ;

    if((tmp1->letra)>(tmp2->letra))
    {
        return 1;
    }
    if((tmp1->letra)<(tmp2->letra))
    {
        return -1;
    }
    return 0;


}


ArrayList* generar_y_listar_ascendente(ArrayList* AL)

{
    char letra;

    ArrayList* AL_ascendente;
    AL_ascendente=al_newArrayList();

    eLetra* auxeLetra= al_get(AL,0);
    al_add(AL_ascendente,auxeLetra);

    for(int i=1;i<al_len(AL);i++)
        {
        auxeLetra =(eLetra*)al_get(AL,i);
        letra=get_eLetra_letra(auxeLetra);
        if(Existe_letra_en_Array(AL_ascendente,letra)==0)
              {
                    al_add(AL_ascendente,auxeLetra);
              }
        }
 return AL_ascendente;
}

int Existe_letra_en_Array(ArrayList* AL,char l)
{
    int retorno = 0;
    if(AL!=NULL && l!=NULL)
    {
        eLetra* auxl;
        char letra;

        for(int i=0;i<al_len(AL);i++)
        {
            auxl=al_get(AL,i);
            letra=get_eLetra_letra(auxl);
            if(tolower(letra)==tolower(l))
            //if(strcmpi(letra,l)==0)
            {
                retorno =1;

                break;
            }
        }

    }
    return retorno;
}


void generarArchivo(ArrayList* AL,char* nomArch)
{
    FILE* miArchivo;
    char archivo[50];

    strcpy(archivo,nomArch);
    strcat(archivo,".csv");

    miArchivo = fopen(archivo,"w");
    char l;
    char n[100];
    int v;
    int c;

    fprintf(miArchivo,"LETRA,NOMBRE,VOCAL,CONSONANTE\n");
    for(int i=0;i<al_len(AL);i++)
    {
        eLetra* tmp=al_get(AL,i);

        l=get_eLetra_letra(tmp);
        get_eLetra_nombre(tmp,n);
        v = get_eLetra_vocal(tmp);
        c = get_eLetra_consonante(tmp);

        fprintf(miArchivo,"%c,%s,%d,%d\n",l,n,v,c);
    }

    fclose(miArchivo);
}
