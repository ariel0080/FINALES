#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "producto.h"
#include "funciones.h"

int main()
{


    ArrayList* lDep1;
    ArrayList* lDep2;
    FILE *fProd1;
    FILE *fProd2;

    int seguir=1;

    int opcion;
    int opcion_origen;
    int opcion_destino;
    int opciondep;
    int fparce;
    int fsort;
    int prod;
    int producto;
    int can;
    int esta_en_1;
    int esta_en_2;

    lDep1=al_newArrayList();
    lDep2=al_newArrayList();

    while(seguir==1)
    {
        int elejir=1;
        int elejir3=1;
        int dep_origen;
        int dep_dest;
        printf("\n-------------------------------\n");
        printf("-- MENU FINAL 1TT --\n");
        printf("-------------------------------\n");
        printf(" 1. Cargar ambos depositos en memoria a partir de los archivos .csv\n");
        printf(" 2. Listar Depositos\n");
        printf(" 3. Mover Productos de un deposito a otro\n");
        printf(" 4. Descontar producto\n");
        printf(" 5. Adicionar producto\n");
        printf(" 6. Salir");
        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
        case 1:
            fparce=parserProducto(fProd1, lDep1,"dep0.csv");
            if (fparce==0)
                {printf("\n DEPOSITO 1 CARGADO\n");

                }
            else
            {
                printf("\n NO SE PUDO CARGAR DEPOSITO 1\n");
            }

            fparce=parserProducto(fProd2, lDep2,"dep1.csv");

            if (fparce==0)
                {printf("\n DEPOSITO 2 CARGADO\n");

                }
            else
            {
                printf("\n NO SE PUDO CARGAR DEPOSITO 2\n");
            }

            LP();
            break;
         case 2:
              while(elejir==1)
                {
                printf("\nSELECCIONE DEPOSITO [1,2] o 3 PARA VOLVER AL MENU PRINCIPAL: ");
                scanf("%d",&opciondep);
                fflush(stdin);

                if(opciondep==1)
                {
                     if(!al_isEmpty(lDep1))
                        {
                        if(lDep1!=NULL)
                        {

                        printf("#ELEMENTOS: %d\n", al_len(lDep1));
                        listarProductos(lDep1);

                        }

                        }
                        else{printf("\nNO HAY DATOS PARA GENERAR LISTADO\n");}

                        LP();
                }

                if(opciondep==2)
                {
                        if(!al_isEmpty(lDep2))
                            {
                            if(lDep2!=NULL)
                                {

                                    printf("#ELEMENTOS: %d\n", al_len(lDep2));
                                    listarProductos(lDep2);

                                }

                            }
                        else{printf("\nNO HAY DATOS PARA GENERAR LISTADO\n");}

                        LP();
                }
                if(opciondep==3){elejir=0;LP();}
                }
                break;

         case 3:


            while(elejir3==1)
                {
                printf("\nSELECCIONE DEPOSITO ORINGEN [1,2] o 3 PARA VOLVER AL MENU PRINCIPAL: ");
                scanf("%d",&opcion_origen);
                fflush(stdin);
                if(opcion_origen==3){elejir3=0;LP();break;}

                if (opcion_origen > 3 || opcion_origen < 1){printf("\n OPCION FUERA DE RANGO\n");LP();break;}

                printf("\nSELECCIONE DEPOSITO DESTINO [1,2] o 3 PARA VOLVER AL MENU PRINCIPAL: ");
                scanf("%d",&opcion_destino);
                fflush(stdin);
                if(opcion_destino==3){elejir3=0;LP();break;}

                if (opcion_destino > 3 || opcion_destino < 1){printf("\n OPCION FUERA DE RANGO\n");LP();break;}


                if (opcion_origen==opcion_destino){printf("\nHA SELECCIONADO EL MISMO DEPOSITO EN AMBOS CASOS, IMPOSIBLE MOVER PRODUCTOS");elejir3=0;LP();}

                else{


                        if(al_isEmpty(lDep1)!=1 && al_isEmpty(lDep2)!=1)
                        {
                                if(opcion_origen==1)
                                {
                                printf("\n#ELEMENTOS DEL DEPOSITO 1: %d\n", al_len(lDep1));
                                listarProductos(lDep1);
                                }

                                if(opcion_origen==2)
                                {
                                printf("\n#ELEMENTOS DEL DEPOSITO 2: %d\n", al_len(lDep2));
                                listarProductos(lDep2);
                                }


                        }

                        printf("\nINGRESE CODIGO DE PRODUCTO A MOVER\n");
                        scanf("%d",&prod);
                        fflush(stdin);
                        int movio;
                        if(opcion_origen==1)
                            {
                                movio = mover_Producto(lDep1,lDep2,prod);
                            }
                        if(opcion_origen==2)
                            {
                                movio = mover_Producto(lDep2,lDep1,prod);
                            }

                        if(movio==1){printf("MOVIEMIENTO EXITOSO\n");LP();}else {printf("\nNO SE PUDO MOVER EL PRODUCTO");LP();}



                        }
                        }//fin del while


                break;


         case 4:

             listarProductos(lDep1);
             listarProductos(lDep2);
             printf("\nINGRESE CODIGO DEL PRODUCTO: ");
             scanf("%d",&producto);
             fflush(stdin);
             if(producto > 15 || producto < 1){printf("\nOPCION FUERA DE RANGO\n");LP();break;}

             esta_en_1=encontrar_Producto(lDep1,producto);
             esta_en_2=encontrar_Producto(lDep2,producto);

             eProducto* auxProd;
             auxProd=neweProducto();

             if(esta_en_1!=-1)
             {
                 auxProd=al_get(lDep1,esta_en_1);
                 printf("\nIngrese Cantidad a descontar: ");
                 scanf("%d",&can);
                 fflush(stdin);

                 if (can>get_Producto_cantidad(auxProd))
                 {
                     printf("\nNO SE PUEDE QUITAR DICHA CANTIDAD");break;
                 }

                    else
                    {

                     set_producto_cantidad(auxProd,(get_Producto_cantidad(auxProd))-can);
                     al_set(lDep1,esta_en_1,auxProd);
                    }
             }
                 if(esta_en_2!=-1)
             {

                 auxProd=al_get(lDep2,esta_en_2);
                 printf("\nIngrese Cantidad a descontar: ");
                 scanf("%d",&can);
                 fflush(stdin);
                 if (can>get_Producto_cantidad(auxProd))
                 {
                     printf("\nNO SE PUEDE QUITAR DICHA CANTIDAD");break;
                 }

                    else

                    {set_producto_cantidad(auxProd,(get_Producto_cantidad(auxProd))-can);
                    al_set(lDep2,esta_en_2,auxProd);
                    }
             }
            LP();
            break;

         case 5:

             listarProductos(lDep1);
             listarProductos(lDep2);
             printf("\nINGRESE CODIGO DEL PRODUCTO: ");
             scanf("%d",&producto);
             fflush(stdin);
             if(producto > 15 || producto < 1){printf("\nOPCION FUERA DE RANGO\n");LP();break;}

             esta_en_1=encontrar_Producto(lDep1,producto);
             esta_en_2=encontrar_Producto(lDep2,producto);

             //eProducto* auxProd;
             auxProd=neweProducto();

             if(esta_en_1!=-1)
             {
                 auxProd=al_get(lDep1,esta_en_1);
                 printf("\nIngrese Cantidad a sumar: ");
                 scanf("%d",&can);
                 fflush(stdin);
                 set_producto_cantidad(auxProd,(get_Producto_cantidad(auxProd))+can);
                 al_set(lDep1,esta_en_1,auxProd);

             }
                 if(esta_en_2!=-1)
             {

                 auxProd=al_get(lDep2,esta_en_2);
                 printf("\nIngrese Cantidad a sumar: ");
                 scanf("%d",&can);
                 fflush(stdin);
                 set_producto_cantidad(auxProd,(get_Producto_cantidad(auxProd))+can);
                 al_set(lDep2,esta_en_2,auxProd);
             }

            LP();
            break;

        case 6:

            seguir=0;
            LP();
            break;
        default:
            LP();
            break;
        }
    }




    return 0;
}
