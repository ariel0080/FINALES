#include "ArrayList.h"

struct
{
    int id;
    char nombre[200];
    char email[200];
    char dni[200];
    char producto[200];
    char descripciones[300];
}typedef eProducto;


int set_eProducto_id(eProducto*,int);

int get_eProducto_id(eProducto*);

int set_eProducto_nombre(eProducto*,char*);

int get_eProducto_nombre(eProducto*,char*);

int set_eProducto_dni(eProducto*,char*);

int get_eProducto_dni(eProducto*,char*);

int set_eProducto_producto(eProducto*,char*);

int get_eProducto_producto(eProducto*,char*);

int set_eProducto_descriociones(eProducto*,char*);

int get_eProducto_descripciones(eProducto*,char*);

int compare(void*,void*);

//CONSTRUCTOR

eProducto* neweProducto(void);

//LISTAR

void listar(ArrayList*);

//COMPARA

int Existe_string_en_Array(ArrayList*,char*);

//Localidades

ArrayList* Generar_Clientes(ArrayList*);
int fLoc(void* pElement,void* loc);
