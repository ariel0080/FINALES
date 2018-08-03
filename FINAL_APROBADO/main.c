#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "eProducto.h"
#include "parse.h"


int main()
{


   /* 	NUEVO ARRAYLIST

	ArrayList* lDep1;
    	ArrayList* lDep2;

	NUEVO ARCHIVO

	FILE *fProd1;
        FILELE *fProd2;
        CONSTRUCTOR DE ARRAYLIST

	lDep1=al_newArrayList();
    	lDep2=al_newArrayList();*/
    ArrayList* AL;
    AL=al_newArrayList();
    int parse;

    ArrayList* AL_C;
    AL_C=al_newArrayList();


    int seguir=1;
    int opcion;

    while(seguir==1)
    {
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 02082018 --\n");
        printf("-------------------------------\n");
        printf(" 1. Cargar Archivo\n");
        printf(" 2. Imprimir Llamadas\n");
        printf(" 3. Imprimir Estadistica\n");
        printf(" 4. Generar archivo de Clientes\n");
        printf(" 5. Salir\n");

        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
         case 1:
             if(al_isEmpty(AL)==1)
            {
                char nomA[20];
                printf("\n Ingrese nombre de archivo a leer (data.csv): ");
                scanf("%s",&nomA);

                parse = parser_eProducto(AL,nomA);
                if(parse==0)
                {
                    printf("\nARCHIVO CARGADO CON EXITO A MEMORIA\n");
                }
                else
                {
                    printf("\nNO SE PUDO CARGAR EL ARCHIVO\n");
                }
            }
            else
                printf("\nEL ARCHIVO YA FUE LEIDO\n");
            LP();
            break;
         case 2:

              if(al_isEmpty(AL)==0)
              {
                  al_sort(AL,compare,1);
                  listar(AL);
              }
              else
                printf("\nNO HAY REGISTROS CARGADOS\n");
            LP();

            break;
         case 3:

                AL_C=Generar_Clientes(AL);
                //listarC(AL_C);printf("#%d",al_len(AL_C));
                contar_Cliente(AL,AL_C);
                contar_Producto(AL,AL_C);

            break;
         case 4:

              if(al_isEmpty(AL)==0)
              {
               AL_C=Generar_Clientes(AL);
               listarC(AL_C);
               printf("#%d REGISTROS",al_len(AL_C));
               guardarArchivo(AL_C,"clientes");
              }
              else
                printf("\nNO HAY REGISTROS CARGADOS\n");
            LP();
            break;
         case 5:
             seguir=0;
            break;
        default:
            LP();
            break;
        }
    }




    return 0;

}
