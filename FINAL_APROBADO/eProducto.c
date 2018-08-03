
#include "eProducto.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GETTERS Y SETTERS

int set_eProducto_id(eProducto* p,int c)
{
    int retorno = -1;
     if (p!=NULL)
    {
        p->id = c;
        retorno=1;
    }
    return retorno;
}

int get_eProducto_id(eProducto* p)
{
    return p->id;
}

int set_eProducto_nombre(eProducto* p,char* nom)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->nombre,nom);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_nombre(eProducto* p,char* nom)
{
    strcpy(nom,p->nombre);
    return 1;
}

int set_eProducto_email(eProducto* p,char* email)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->email,email);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_email(eProducto* p,char* email)
{
    strcpy(email,p->email);
    return 1;
}

int set_eProducto_dni(eProducto* p,char* dni)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->dni,dni);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_dni(eProducto* p,char* dni)
{
    strcpy(dni,p->dni);
    return 1;
}

int set_eProducto_producto(eProducto* p,char* producto)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->producto,producto);
        retorno=1;
    }
    return retorno;
}


int get_eProducto_producto(eProducto* p,char* producto)
{
    strcpy(producto,p->producto);
    return 1;
}

int set_eProducto_descripciones(eProducto* p,char* descripciones)
{
    int retorno = -1;
    if (p!=NULL)
    {
        strcpy(p->descripciones,descripciones);
        retorno=1;
    }
    return retorno;
}

int get_eProducto_descripciones(eProducto* p,char* descripciones)
{
    strcpy(descripciones,p->descripciones);
    return 1;
}
//CONSTRUCTOR

eProducto* neweProducto(void)
{
    eProducto* returnAux = NULL;
    eProducto* pProducto = malloc(sizeof(eProducto));
    returnAux = pProducto;
    return returnAux;

}

// LISTAR

void listar(ArrayList* lista)
{
    printf("%-3s %-15s %-35s %-10s %-20s\n\n","ID","NOMBRE","EMAIL","DNI","PRODUCTO"); // FORMATEO DE PARCE
    eProducto* aux;  // DECLARACION DE ELEMENTO
    for (int i=0; i<al_len(lista); i++ )
                {
                aux=(eProducto*)al_get(lista,i); // DESDE ACA TRABJO CON AUX

                int id;
                char nombre[200];
                char email[200];
                char dni[200];
                char producto[200];
                char obser[300];

                id = get_eProducto_id(aux);

                get_eProducto_nombre(aux,nombre);
                get_eProducto_email(aux,email);
                get_eProducto_dni(aux,dni);
                get_eProducto_producto(aux,producto);
                get_eProducto_producto(aux,obser);//printf("OB: %s",obser);system("pause");

                printf("%-3d %-15s %-35s %-10s %-20s\n",id,nombre,email,dni,producto);

                }
}

int compare(void* pEmployeeA,void* pEmployeeB)
{
    eProducto* tmp1=(eProducto*)pEmployeeA ;
    eProducto* tmp2=(eProducto*)pEmployeeB ;

    if((tmp1->id)>(tmp2->id))
    {
        return 1;
    }
    if((tmp1->id)<(tmp2->id))
    {
        return 0;
    }
    return 0;


}

ArrayList* Generar_Clientes(ArrayList* AL)
{
    char clientes[200];
    ArrayList* AL_C;
    AL_C=al_newArrayList();

    eProducto* auxeProducto = al_get(AL,0);
    al_add(AL_C,auxeProducto);

    for(int i=1;i<al_len(AL);i++)
        {
        auxeProducto =(eProducto*)al_get(AL,i);
        get_eProducto_nombre(auxeProducto,clientes);
        if(Existe_string_en_Array(AL_C,clientes)==0)
              {
                    al_add(AL_C,auxeProducto);
              }
        }
 return AL_C;
}

int Existe_string_en_Array(ArrayList* AL,char* s) // 0 no lo encuentra, 1 existe -1 si algo anda mal
{
    int retorno = 0;
    if(AL!=NULL && s!=NULL)
    {
        eProducto* auxp;
        char nombre[200];

        for(int i=0;i<al_len(AL);i++)
        {
            auxp=al_get(AL,i);
            get_eProducto_nombre(auxp,nombre);
            if(strcmpi(nombre,s)==0)
            {
                retorno =1;
                break;
            }
        }

    }
    return retorno;
}

void listarC(ArrayList* lista)
{
    printf("%-10s %-40s %-10s\n\n","NOMBRE","EMAIL","DNI"); // FORMATEO DE PARCE
    eProducto* aux;  // DECLARACION DE ELEMENTO
    for (int i=0; i<al_len(lista); i++ )
                {
                aux=(eProducto*)al_get(lista,i); // DESDE ACA TRABJO CON AUX

                int id;
                char nombre[200];
                char email[200];
                char dni[200];
                char producto[200];
                char obser[300];

                id = get_eProducto_id(aux);

                get_eProducto_nombre(aux,nombre);
                get_eProducto_email(aux,email);
                get_eProducto_dni(aux,dni);
                get_eProducto_producto(aux,producto);
                get_eProducto_producto(aux,obser);//printf("OB: %s",obser);system("pause");

                printf("%-10s %-40s %-10s\n",nombre,email,dni);

                }
}

void guardarArchivo(ArrayList* AL,char* nomArch)

{
    FILE* miArchivo;
    char archivo[50];

    strcpy(archivo,nomArch);
    strcat(archivo,".csv");

    miArchivo = fopen(archivo,"w");
    int id;
    char n[100];
    char e[100];
    char d[100];


    fprintf(miArchivo,"NOMBRE,EMAIL,DNI\n");
    for(int i=0;i<al_len(AL);i++)
    {
        eProducto* tmp=al_get(AL,i);


        get_eProducto_nombre(tmp,n);
        get_eProducto_email(tmp,e);
        get_eProducto_dni(tmp,d);


        fprintf(miArchivo,"%s,%s,%s\n",n,e,d);
    }

    fclose(miArchivo);
}

func{
    al

for(int j=0;j<al_len(AL);j++)
            {
                auxAL = (eProducto*)al_get(AL,j);
                get_eProducto_nombre(auxAL,nomAL);
                //printf("%s %s",nomAL_C,nomAL);system("pause");
                if(strcmp(nomAL_C,nomAL)==0)
                {

                    contador++;//printf("--%s--%s--%d",nomAL,nomAL_C,contador);system("pause");

                }

            }
}
int contar_Cliente(ArrayList* AL, ArrayList* AL_C)
{
    eProducto* aux;
    eProducto* auxAL;
    char dni[100];
    int contador=0;
    int max=0;
    char max_nom[100];
    char nomAL_C[100];
    char nomAL[100];


    for(int i=0;i<al_len(AL_C);i++)
    {
        aux = (eProducto*)al_get(AL_C,i);
        get_eProducto_nombre(aux,nomAL_C);


       if(contador>max)
                    {
                        max=contador;//printf("%d--",contador);
                        strcpy(max_nom,nomAL_C);


                    }
        contador=0;


    }
printf("NOMBRE: %s DNI: %s  CANTIDAD: %d",max_nom,max);
    return contador;
}

int contar_Producto(ArrayList* AL, ArrayList* AL_C)
{
    eProducto* aux;
    eProducto* auxAL;
    int contador=0;
    int max=0;
    char max_nom[100];
    char nomAL_C[100];
    char nomAL[100];


    for(int i=0;i<al_len(AL_C);i++)
    {
        aux = (eProducto*)al_get(AL_C,i);
        get_eProducto_producto(aux,nomAL_C);
            for(int j=0;j<al_len(AL);j++)
            {
                auxAL = (eProducto*)al_get(AL,j);
                get_eProducto_producto(auxAL,nomAL);
                //printf("%s %s",nomAL_C,nomAL);system("pause");
                if(strcmp(nomAL_C,nomAL)==0)
                {

                    contador++;//printf("--%s--%s--%d",nomAL,nomAL_C,contador);system("pause");

                }

            }
       if(contador>max)
                    {
                        max=contador;//printf("%d--",contador);
                        strcpy(max_nom,nomAL_C);

                    }
        contador=0;


    }
printf("Producto: %s %d",max_nom,max);
    return contador;
}
/*

int Existe_string_en_Array(ArrayList* AL,char* s) // 0 no lo encuentra, 1 existe -1 si algo anda mal
{
    int retorno = 0;
    if(AL!=NULL && s!=NULL)
    {
        eProducto* auxp;
        char localidad[100];

        for(int i=0;i<al_len(AL);i++)
        {
            auxp=al_get(AL,i);
            get_eProducto_localidad(auxp,localidad);
            if(strcmpi(localidad,s)==0)
            {
                retorno =1;
                break;
            }
        }

    }
    return retorno;
}




int fLoc(void* pElement,void* loc) //
{
    int returnaux = -1;
    if(pElement!=NULL)
    {
        eProducto *tmp =(eProducto*)pElement;
        loc = (char*)loc;

        char localidad[100];
        get_eProducto_localidad(tmp,localidad);


        if(strcmpi(loc,localidad)==0)
        {
            returnaux =0;
        }
        else
        {
            returnaux =1;
        }
    }


 return returnaux;
}

void listar_Loc(ArrayList* AL)
{
    printf("\n%-20s \n\n","LOCALIDAD"); // FORMATEO DE PARCE
    eProducto* aux;  // DECLARACION DE ELEMENTO
    for (int i=0; i<al_len(AL); i++ )
                {
                aux=(eProducto*)al_get(AL,i); // DESDE ACA TRABJO CON AUX

                char l[100];



                get_eProducto_localidad(aux,l);
                printf("%-20s \n",l);

                }
}

ArrayList* Generar_Localidades(ArrayList* AL)
{
    char localidad[100];
    ArrayList* AL_Loc;
    AL_Loc=al_newArrayList();

    eProducto* auxeProducto = al_get(AL,0);
    al_add(AL_Loc,auxeProducto);

    for(int i=1;i<al_len(AL);i++)
        {
        auxeProducto =(eProducto*)al_get(AL,i);
        get_eProducto_localidad(auxeProducto,localidad);
        if(Existe_string_en_Array(AL_Loc,localidad)==0)
              {
                    al_add(AL_Loc,auxeProducto);
              }
        }
 return AL_Loc;
}


void guardarArchivo(ArrayList* AL,char* nomArch)

{
    FILE* miArchivo;
    char archivo[50];

    strcpy(archivo,nomArch);
    strcat(archivo,".csv");

    miArchivo = fopen(archivo,"w");
    int id;
    char p[100];
    char d[100];
    char l[100];
    char r[100];

    fprintf(miArchivo,"Id,Producto,Direccion,Localidad,Recibe\n");
    for(int i=0;i<al_len(AL);i++)
    {
        eProducto* tmp=al_get(AL,i);

        id=get_eProducto_id(tmp);
        get_eProducto_producto(tmp,p);
        get_eProducto_direccion(tmp,d);
        get_eProducto_localidad(tmp,l);
        get_eProducto_recibe(tmp,r);

        fprintf(miArchivo,"%d,%s,%s,%s,%s\n",id,p,d,l,r);
    }

    fclose(miArchivo);
}*/
