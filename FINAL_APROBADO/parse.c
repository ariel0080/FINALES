#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"
#include "eProducto.h"


int parser_eProducto(ArrayList* listaProd, char* nomArch)

{
    FILE *pFile;
    eProducto *auxeProducto; //DECLARO EL TIPO DE ELEMENTO QUE VA A LEER DESDE EL ARCHIVO

// RECORDAR QUE TODAS LAS VARIABLES QUE LEE DEL ARCHIVO SON CHAR SIN IMPORTAR QUE DATO SEA

    char id[200];
    char nombre[200];
    char email[200];
    char dni[200];
    char producto[200];
    char obser[300];

    int iid;


    pFile=fopen(nomArch,"r");

    if(pFile== NULL)
    {
        return 1;
        printf("NO SE PUDO CARGAR ARCHIVO");
    }
    else
    {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,email,dni,producto,obser); //DESCARTO PRIMERA FILA DEL ARCHIVO POR CONTENER NOMBRES DE COLUMNAS
            while(!(feof(pFile)))
                {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,email,dni,producto,obser);

                iid=atoi(id);


                auxeProducto = neweProducto(); //RECIEN ACA SE ASIGNA MEMORIA PARA EL ELEMENTO
                    if(auxeProducto!=NULL)
                        {
                       //printf("OK");
                        set_eProducto_id(auxeProducto,iid);
                        set_eProducto_nombre(auxeProducto,nombre);
                        set_eProducto_email(auxeProducto,email);
                        set_eProducto_dni(auxeProducto,dni);
                        set_eProducto_producto(auxeProducto,producto);
                        set_eProducto_descripciones(auxeProducto,obser);
                        al_add(listaProd,auxeProducto);
                        }
                }

        }
    fclose(pFile);

    printf("\nCANTIDAD DE REGISTROS PROCESADOS: #%d\n", al_len(listaProd));

    return 0;
}
