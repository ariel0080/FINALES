#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"
#include "funciones.h"
#include "parse.h"
#include "eProducto.h"


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

    ArrayList* AL_Loc;
    AL_Loc=al_newArrayList();

    ArrayList* Solo_una_Loc;
    Solo_una_Loc =al_newArrayList();

    int parse;


    int seguir=1;
    int opcion;

    while(seguir==1)
    {
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 1TM --\n");
        printf("-------------------------------\n");
        printf(" 1. Cargar archivo\n");
        printf(" 2. Listar productos cargados\n");
        printf(" 3. Imprimir Localidades\n");
        printf(" 4. Generar Archivo de reparto por localidad\n");
        printf(" 5. Salir\n");
        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
         case 1:
             if(al_isEmpty(AL)==1)
             {
                 parse = parser_eProducto(AL,"data.csv");
                 if(parse==0)
                 {
                    printf("\nARCHIVO CARGADO CON EXITO A MEMORIA\n");
                 }
                 else
                    {
                        printf("\nNO SE PUDO CARGAR EL ARCHIVO\n");
                    }
             }
             else printf("\nEL ARCHIVO YA FUE LEIDO\n");
             LP();
            break;
         case 2:
              if(al_isEmpty(AL)==0)
             {
                listar(AL);

             }
             else printf("\nNO HAY DATOS QUE LISTAR\n");
             LP();
            break;
         case 3:
             if(al_isEmpty(AL)==0)
             {
                 AL_Loc= Generar_Localidades(AL);
                 listar_Loc(AL_Loc);
             }
             else printf("\nNO HAY DATOS CON LOS QUE REALIZAR EL FILTRO DE LOCALIDADES\n");
             LP();
            break;
         case 4:
             if(al_isEmpty(AL)==0)
             {
            int elejir_localidad;
            char loc[100];
            printf("\nIngrese Localidad para generar archivo: \n");



                printf(" 1. Sarandi\n");
                printf(" 2. Quilmes\n");
                printf(" 3. Lomas\n");
                printf(" 4. Banfield\n");
                printf(" 5. Lanus\n");
                printf(" 6. Avellaneda\n");
                printf(" 7. Salir\n");
                scanf("%d",&elejir_localidad);
                fflush(stdin);

                switch(elejir_localidad)
                    {
                    case 1:
                    strcpy(loc,"Sarandi");
                    break;
                    case 2:
                    strcpy(loc,"Quilmes");
                    break;
                    case 3:
                    strcpy(loc,"Lomas");
                    break;
                    case 4:
                    strcpy(loc,"Banfield");
                    break;
                    case 5:
                    strcpy(loc,"Lanus");
                    break;
                    case 6:
                    strcpy(loc,"Avellaneda");
                    break;
                    case 7:
                    LP();
                    break;
                    default:
                    printf("Localidad Incorrecta\n");
                    break;
                    }
                    Solo_una_Loc=al_filter(AL,fLoc,loc);
                    listar(Solo_una_Loc);
                    guardarArchivo(Solo_una_Loc,loc);

             }
             else printf("\nNO HAY DATOS CON LOS QUE REALIZAR EL FILTRO DE LOCALIDADES\n");
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
