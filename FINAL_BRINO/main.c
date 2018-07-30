#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eLetra.h"
#include "parce.h"

int main()
{
    ArrayList* lL;
    lL=al_newArrayList();

    ArrayList* cantLetras;
    cantLetras = al_newArrayList();


    FILE *fLetras;
    FILE *pFile2;

    int parce;
    char pal[100];
    /*ArrayList* lDep2;
    FILE *fProd1;
    FILE *fProd2;
    int seguir=1;
    lDep1=al_newArrayList();
    lDep2=al_newArrayList();*/
    int seguir=1;
    int opcion;

    while(seguir==1)
    {
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 1TM --\n");
        printf("-------------------------------\n");
        printf(" 1. Cargar archivo datos.csv en memoria\n");
        printf(" 2. Completar lista segun corresponda vocal o consonante\n");
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
            if(al_isEmpty(lL)==1)
            {
                    parce = parser_eLetra(fLetras,lL,"datos.csv");
                    if(parce==0){printf("Carga exitosa");}else{printf("\nNO SE PUDO LEER ARCHIVO\n");}

            }
            else printf("\nYa se cargo la lista\n");

            LP();
            break;
         case 2:
             if(al_isEmpty(lL)==0)
            {
                   completar(lL);

            }
            else printf("\nNO SE HA CARGADO LISTA\n");
            listar(lL);

            LP();
            break;
         case 3:
             parce = parser_cl(pFile2,cantLetras,"letras.csv");


             printf("Ingrese Palabra: ");
             scanf("%s",pal);
             fflush(stdin);

             ConLetrasPalabra(cantLetras,pal);
             //listarS(cantLetras);

             for(int v=0;v<al_len(cantLetras);v++)
             {

                 c_l* auxl;
                 auxl=newc_l();
                 auxl=(c_l*)al_get(cantLetras,v);
                printf("%d--%c",auxl->cant,auxl->letra);system("pause");
                if((auxl->cant) > buscarElementoPrincipal((auxl->letra),lL))
                {
                    printf("NO SE PUEDE");
                    break;
                }
                else {printf("Se puede");break;}
             }

             LP();



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
