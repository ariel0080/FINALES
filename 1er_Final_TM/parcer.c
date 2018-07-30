
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eEntrega.h"


int parserEntrega(FILE* pFile, ArrayList* ListaEntrega, char* nomArch)

{
    eEntrega *auxEntrega;

    char id[100];
    int iid;
    char producto[tam_c];
    char direccion[tam_c];
    char localidad[tam_c];
    char recibe[tam_c];


    pFile=fopen(nomArch,"r");

    if(pFile== NULL)
    {
        return 1;
    }
    else
    {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,producto,direccion,localidad,recibe); //DESCARTO PRIMERA FILA DEL ARCHIVO POR CONTENER NOMBRES DE COLUMNAS
            while(!(feof(pFile)))
                {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,producto,direccion,localidad,recibe);

                iid = atoi(id);

                auxEntrega= newEntrega();

                if(auxEntrega!=NULL)
                {

                set_En_id(auxEntrega,iid);
                set_En_producto(auxEntrega,producto);
                set_En_direccion(auxEntrega,direccion);
                set_En_localidad(auxEntrega,localidad);
                set_En_recibe(auxEntrega,recibe);

                al_add(ListaEntrega,auxEntrega);
                }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: %d\n", al_len(ListaEntrega));

    return 0;
}
