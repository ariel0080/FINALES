
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "producto.h"
#include "funciones.h"

void LP (void) // LIMPIA CONTENIDO DE PANTALLA
{
    printf("\n");
    system ("pause");
    system ("cls");
}
/*
void guardarArchivo(ArrayList* empleados, char* archNombre)

{
    char src[100];
    char dest[100];
    strcpy(src,archNombre);
    strcpy(dest, ".csv");
    strcat(src, dest);
    FILE* miArchivo;
    miArchivo = fopen(src,"w");
    char n[50];
    char d[50];

    fprintf(miArchivo,"NOMBRE,DIRECCION,ID,HORAS,SUELDO\n");
    for(int i=0;i<al_len(empleados);i++)
    {
        eEmpleado* tmp=al_get(empleados,i);
        get_Empleado_nombre(tmp,n);
        get_Empleado_direccion(tmp,d);

        fprintf(miArchivo,"%s,%s,%d,%d,%.2f\n",n,d,get_Empleado_id(tmp),get_Empleado_hora(tmp),get_Empleado_sueldo(tmp)); // aca cambiaste f por d
    }

    fclose(miArchivo);
}*/
