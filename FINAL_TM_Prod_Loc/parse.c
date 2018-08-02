#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eProducto.h"
#include "parse.h"


int parser_eProducto(ArrayList* listaProducto, char* nomArch)

{
    eProducto* auxeProducto;
    FILE* pFile; //DECLARO EL TIPO DE ELEMENTO QUE VA A LEER DESDE EL ARCHIVO

// RECORDAR QUE TODAS LAS VARIABLES QUE LEE DEL ARCHIVO SON CHAR SIN IMPORTAR QUE DATO SEA

    char id[10];
    char producto[100];
    char direccion[100];
    char localidad[100];
    char recibe[100];

    int iid;


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

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);


                iid=atoi(id);


                auxeProducto = neweProducto(); //RECIEN ACA SE ASIGNA MEMORIA PARA EL ELEMENTO
                    if(auxeProducto!=NULL)
                        {

                        set_eProducto_id(auxeProducto,iid);
                        set_eProducto_producto(auxeProducto,producto);
                        set_eProducto_direccion(auxeProducto,direccion);
                        set_eProducto_localidad(auxeProducto,localidad);
                        set_eProducto_recibe(auxeProducto,recibe);

                        al_add(listaProducto,auxeProducto);

                        }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: #%d\n", al_len(listaProducto));

    return 0;
}
