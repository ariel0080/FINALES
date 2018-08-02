#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eLetra.h"
#include "parse.h"

// ###TU_TIPO_DE_DATO###


int parser_eLetra(FILE* pFile, ArrayList* AL_eLetra, char* nomArch)

{
    eLetra *auxeLetra; //DECLARO EL TIPO DE ELEMENTO QUE VA A LEER DESDE EL ARCHIVO

// RECORDAR QUE TODAS LAS VARIABLES QUE LEE DEL ARCHIVO SON CHAR[] SIN IMPORTAR QUE DATO SEA

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


                auxeLetra = neweLetra(); //RECIEN ACA SE ASIGNA MEMORIA PARA EL ELEMENTO
                    if(auxeLetra!=NULL)
                        {

                        set_eLetra_nombre(auxeLetra,nombre);
                        set_eLetra_vocal(auxeLetra,ivocal);
                        set_eLetra_consonante(auxeLetra,iconsonante);
                        set_eLetra_letra(auxeLetra,letra[0]); // ASI SE SETEAN LOS CHARS
                        al_add(AL_eLetra,auxeLetra);

                        }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: #%d\n", al_len(AL_eLetra));

    return 0;
}
