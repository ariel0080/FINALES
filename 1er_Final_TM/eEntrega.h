#include "Arraylist.h"
#define tam_c 100

struct
{
    int id;
    char producto[tam_c];
    char direccion[tam_c];
    char localidad[tam_c];
    char recibe[tam_c];

}typedef eEntrega;

struct
{
    int estado;
    char localidad[tam_c];

}typedef eLocalidad;



int set_En_id(eEntrega*,int id); //retorna 1 o -1
int get_En_id(eEntrega*); //rretorna el dato

int set_En_producto(eEntrega*,char*); //retorna si pudo o no
void get_En_producto(eEntrega*,char*); //no retorna el dato

int set_En_direccion(eEntrega*,char*);
void get_En_direccion(eEntrega*,char*);

int set_En_localidad(eEntrega*,char*);
void get_En_localidad(eEntrega*,char*);

int set_En_recibe(eEntrega*,char*);
void get_En_recibe(eEntrega*,char*);


void listar_Entregas(ArrayList*);

int filtro(void* eEntrega);

int set_eLocalidad_estado(eLocalidad*,int estado); //retorna 1 o -1
int get_eLocalidad_estado(eLocalidad*); //rret

int set_eLocalidad_localidad(eLocalidad*,char*);
void get_eLocalidad_localidad(eLocalidad*,char*);

