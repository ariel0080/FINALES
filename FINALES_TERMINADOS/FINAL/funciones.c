#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "funciones.h"

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
/*
int buscarMaxId(ArrayList* empleados)

{
    eEmpleado* aux;
    int id;
    int maxId=-1;
    if (al_len(empleados)!=0)
        {
        for (int i=0; i<al_len(empleados); i++ )
                {
                    aux=(eEmpleado*)al_get(empleados,i);
                    id=get_Empleado_id(aux);
                    if(id>maxId){maxId=id;}
                }
        maxId++;
        }

return maxId;
}

int validarHora(char* hora)

{
    int auxHora = -1;
    int largo=0;
    while (*(hora+largo)!='\0')
        {
        if((*(hora+largo)) >='0' && (*(hora+largo))<='9'){largo++;}
        else {printf("Ha ingresado una hora incorrecta");LP();return auxHora;}
        }
    auxHora =atoi(hora);
    if(auxHora>240){auxHora=-1;}
    return auxHora;


}

int altaManual(ArrayList* pArrayListEmpleado)
{
    char campoIngresar[100];
    int horas;
    eEmpleado *auxEmpleado = neweEmpleado();

                printf("\nIngresar nombre: ");
                consulta(campoIngresar);
                set_Empleado_nombre(auxEmpleado,campoIngresar);

                printf("\nIngresar direccion: ");
                consulta(campoIngresar);
                set_Empleado_domicilio(auxEmpleado,campoIngresar);


                printf("\nIngresar horas trabajadas: ");
                consulta(campoIngresar);
                horas = validarHora(campoIngresar);


                while(horas==-1)
                    {

                        printf("\nIngresar horas trabajadas: ");
                        consulta(campoIngresar);
                        horas = validarHora(campoIngresar);
                    }


                set_Empleado_hora(auxEmpleado,horas);

                set_Empleado_id(auxEmpleado,buscarMaxId(pArrayListEmpleado));
                al_add(pArrayListEmpleado,auxEmpleado);
}
*/

