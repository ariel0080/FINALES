#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "producto.h"


int parserProducto(FILE* pFile, ArrayList* pArrayListProductos, char* nomArch)

{
    eProducto *auxProducto;

    char producto[51];
    char descripcion[51];
    char cantidad[10];
    int icantidad;
    int iproducto;


    pFile=fopen(nomArch,"r");

    if(pFile== NULL)
    {
        return 1;
    }
    else
    {

        fscanf(pFile,"%[^,],%[^,],%[^\n]\n", producto, descripcion, cantidad); //DESCARTO PRIMERA FILA DEL ARCHIVO POR CONTENER NOMBRES DE COLUMNAS


        while(!(feof(pFile)))
        {

                fscanf(pFile,"%[^,],%[^,],%[^\n]\n", producto, descripcion, cantidad);

                icantidad = atoi(cantidad);
                iproducto = atoi(producto);
                auxProducto= neweProducto();

                if(auxProducto!=NULL)
                {
                char des[100];
                set_Producto_producto(auxProducto,iproducto);
                set_Producto_descripcion(auxProducto,descripcion);
                set_producto_cantidad(auxProducto,icantidad);
                get_Producto_descripcion(auxProducto,des);

               // printf("Prod: %d Des: %s Cant: %d",get_Producto_producto(auxProducto),des,get_Producto_cantidad(auxProducto));
                al_add(pArrayListProductos,auxProducto);
                }


    }
    }
    fclose(pFile);


    printf("\nCANTIDAD DE REGISTROS PROCESADOS: %d\n", al_len(pArrayListProductos));

    return 0;
}

