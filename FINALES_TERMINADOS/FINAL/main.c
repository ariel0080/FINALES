#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "funciones.h"
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


    int seguir=1;
    int opcion;

    while(seguir==1)
    {
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 1TM --\n");
        printf("-------------------------------\n");
        printf(" 1. \n");
        printf(" 2. \n");
        printf(" 3. \n");
        printf(" 4. \n");
        printf(" 5. \n");
        printf(" 6. Salir");
        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
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
