#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "LIBRERIA_DE_TU_TIPO_DE_DATO"
#include "parse.h"


int parser_TUTIPODEDATO(FILE* pFile, ArrayList* listaLetras, char* nomArch)

{
    eLetra *auxLetra; //DECLARO EL TIPO DE ELEMENTO QUE VA A LEER DESDE EL ARCHIVO

// RECORDAR QUE TODAS LAS VARIABLES QUE LEE DEL ARCHIVO SON CHAR SIN IMPORTAR QUE DATO SEA

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


                auxLetra = neweLetra(); //RECIEN ACA SE ASIGNA MEMORIA PARA EL ELEMENTO
                    if(auxLetra!=NULL)
                        {

                        set_eLetra_nombre(auxLetra,nombre);
                        set_eLetra_vocal(auxLetra,ivocal);
                        set_eLetra_consonante(auxLetra,iconsonante);
                        set_eLetra_letra(auxLetra,letra[0]); // ASI SE SETEAN LOS CHARS
                        al_add(listaLetras,auxLetra);

                        }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: #%d\n", al_len(listaLetras));

    return 0;
}
