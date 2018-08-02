#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "funciones.h"
#include "parse.h"
#include "eLetra.h"


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
    FILE *feLetras;
    AL=al_newArrayList();

    ArrayList* AL_descendente;
    ArrayList* AL_ascendente;


    AL_descendente = al_newArrayList();
    //AL_ascendente = al_newArrayList();

    int seguir=1;
    int opcion;
    int parse;

    while(seguir==1)
    {
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 1TM --\n");
        printf("-------------------------------\n");
        printf(" 1. Cargar en memoria datos.csv\n");
        printf(" 2. Completar los campos restantes en el arraylist\n");
        printf(" 3. Comprobar\n");
        printf(" 4. Generar y listar\n");
        printf(" 5. Generar Archivos\n");
        printf(" 6. Salir");
        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
         case 1:
             if(al_isEmpty(AL)==1)
            {
                  parse = parser_eLetra(feLetras,AL,"datos.csv");
                  if(parse==0){printf("Carga exitosa");}else {printf("\nNO SE PUDO LEER ARCHIVO\n");}

            }
            else printf("\nYA SE ENCUENTRA EL ARCHIVO CARGADO EN MEMORIA\n");
            LP();
            listar(AL);
            LP();

            break;
         case 2:
             if(al_isEmpty(AL)==0)
            {
                  completar_ArrayList(AL);
            }
            else printf("\nHO HAY DATOS CARGADOS PARA REALIZAR OPERACION\n");
            LP();
            break;
         case 3:
             if(al_isEmpty(AL)==0)
             {
                 comprobar(AL);
             }
             else printf("\nHO HAY DATOS CARGADOS PARA REALIZAR OPERACION\n");
             LP();
             break;
         case 4:

             if(al_isEmpty(AL)==0)
             {
                AL_ascendente = al_clone(AL);
                AL_descendente = al_clone(AL);

                generar_y_listar_descendente(AL_descendente);

                al_sort(AL_descendente,compareeLetra,0);
                listar(AL_descendente);
                printf("CANTIDAD DE REGISTROS EN ARRAY_DESCENDENTE: #%d\n",al_len(AL_descendente));
                LP();

                AL_ascendente=generar_y_listar_ascendente(AL);

                al_sort(AL_ascendente,compareeLetra,1);
                listar(AL_ascendente);
                printf("CANTIDAD DE REGISTROS EN ARRAY_ASCEDENTE: #%d\n",al_len(AL_ascendente));
                LP();


             }
             else printf("\nHO HAY DATOS CARGADOS PARA REALIZAR OPERACION\n");
            LP();
            break;
         case 5:
                if(al_isEmpty(AL)==0 && al_len(AL_ascendente)!=-1 && al_len(AL_descendente)!=-1)
                {
                    generarArchivo(AL,"Original");
                    generarArchivo(AL_descendente,"Letras repetidas");
                    generarArchivo(AL_ascendente,"Sin letras repetidas");
                }
                else printf("\nHO HAY DATOS CARGADOS PARA REALIZAR OPERACION\n");
                LP();
            break;
        case 6:
            seguir=0;
            break;
        default:
            LP();
            break;
        }
    }




    return 0;

}
