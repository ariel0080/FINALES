#include "ArrayList.h"

struct
{
    int id;
    char producto[100];
    char direccion[100];
    char localidad[100];
    char recibe[100]
}typedef eProducto;


int set_eProducto_id(eProducto*,int);

int get_eProducto_id(eProducto*);

int set_eProducto_producto(eProducto*,char*);

int get_eProducto_producto(eProducto*,char*);

int set_eProducto_direccion(eProducto*,char*);

int get_eProducto_direccion(eProducto*,char*);

int set_eProducto_localidad(eProducto*,char*);

int get_eProducto_localidad(eProducto*,char*);

int set_eProducto_recibe(eProducto*,char*);

int get_eProducto_recibe(eProducto*,char*);


//CONSTRUCTOR

eProducto* neweProducto(void);

//LISTAR

void listar(ArrayList*);

//COMPARA

int Existe_string_en_Array(ArrayList*,char*);

//Localidades

ArrayList* Generar_Localidades(ArrayList*);
int fLoc(void* pElement,void* loc);
