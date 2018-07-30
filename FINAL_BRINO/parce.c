
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eLetra.h"
#include "parce.h"


int parser_eLetra(FILE* pFile, ArrayList* listaLetras, char* nomArch)

{
    eLetra *auxLetra;


    char letra[2];
    char nombre[30];
    char vocal[2];
    char consonante[2];
    int ivocal;
    int iconsonante;


    pFile=fopen(nomArch,"r");

    if(pFile== NULL)
    {
        return 1;
    }
    else
    {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", letra,nombre,vocal,consonante); //DESCARTO PRIMERA FILA DEL ARCHIVO POR CONTENER NOMBRES DE COLUMNAS
            while(!(feof(pFile)))
                {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", letra,nombre,vocal,consonante);

                ivocal=atoi(vocal);
                iconsonante=atoi(consonante);


                auxLetra = neweLetra();

                    if(auxLetra!=NULL)
                        {

                        set_eLetra_nombre(auxLetra,nombre);
                        set_eLetra_vocal(auxLetra,ivocal);
                        set_eLetra_consonante(auxLetra,iconsonante);
                        set_eLetra_letra(auxLetra,letra[0]);
                        al_add(listaLetras,auxLetra);

                        }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: #%d\n", al_len(listaLetras));

    return 0;
}

/////////////

int parser_cl(FILE* pFile, ArrayList* listaLetras, char* nomArch)

{
    c_l *auxLetra;


    char letra[10];
    char cant[10];
    int icant;


    pFile=fopen(nomArch,"r");

    if(pFile== NULL)
    {
        return 1;
    }
    else
    {
            //fscanf(pFile,"%[^,],%[^\n]\n", letra,cant); //DESCARTO PRIMERA FILA DEL ARCHIVO POR CONTENER NOMBRES DE COLUMNAS
            while(!(feof(pFile)))
                {

                fscanf(pFile,"%[^,],%[^\n]\n", letra,cant);

                icant=atoi(cant);



                auxLetra = newc_l();

                    if(auxLetra!=NULL)
                        {

                        auxLetra->letra = letra[0];
                        auxLetra->cant = icant;

                        al_add(listaLetras,auxLetra);

                        }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: #%d\n", al_len(listaLetras));

    return 0;
}

