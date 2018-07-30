#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "funciones.h"
#define tam_c 100

int main()
{


    ArrayList* lista_e;
    ArrayList* lista_loc;
    lista_e=al_newArrayList();
    eLocalidad localidades[30];

    FILE *fentrega;
    int parce;
    int seguir=1;
    int opcion;

    while(seguir==1)
    {
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 1TM --\n");
        printf("-------------------------------\n");
        printf(" 1. Cargar Archivo de Datos\n");
        printf(" 2. Imprimir Entregas\n");
        printf(" 3. Imprimir Localidades\n");
        printf(" 4. Generar Archivo de reparto para localidad\n");
        printf(" 5. Salir\n");
        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
         case 1:
            printf("Ingrese Nombre del archivo a leer (data.csv) :");
            char nombre[tam_c];
            consulta(nombre,tam_c-1);
            parce= parserEntrega(fentrega,lista_e,nombre);
            if(parce==0){printf("Carga exitosa");}else{printf("\nNO SE PUDO LEER ARCHIVO\n");}
            LP();
            break;
         case 2:
             if(!al_isEmpty(lista_e))
             {
                 listar_Entregas(lista_e);
             }
             else {printf("NO HAY DATOS CARGADOS PARA LISTAR");}
             LP();
            break;
         case 3:

             Imp_localidades()
             LP();
            break;
         case 4:
             LP();
            break;
        case 5:
            LP();
            seguir=0;
            break;
        default:
            LP();
            break;
        }
    }




    return 0;
}

