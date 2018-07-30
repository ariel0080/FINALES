
#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "funciones.h"
#include "eEntrega.h"

void LP (void) // LIMPIA CONTENIDO DE PANTALLA
{
    printf("\n");
    system ("pause");
    system ("cls");
}

int consulta(char* dato, int caracteres)
{
    if(dato!=NULL)
    {
        fflush(stdin);
        fgets(dato,caracteres,stdin);
    int largo=0;
    while (*(dato+largo)!='\n')
        {
        largo++;
        }
    *(dato+largo)='\0';
    return 0;
    }
    else return -1;
}

//CONSTRUCTOR

eEntrega* newEntrega()
{
    eEntrega* returnAux = NULL;
    eEntrega* pEntrega = malloc(sizeof(eEntrega));
    returnAux = pEntrega;
    return returnAux;

}
