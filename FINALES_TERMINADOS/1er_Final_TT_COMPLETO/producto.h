#include "ArrayList.h"

struct
{
    int producto;
    char descripcion[100];
    int cantidad;


}typedef eProducto;



//SETTERR Y GETTERS

int set_Producto_producto(eProducto* ,int); // SETEA DEVUELVE 1, SI NO SETEA DEVUELVE 0
int set_Producto_descripcion(eProducto* ,char*);
int set_producto_cantidad(eProducto* ,int );

int get_Producto_producto(eProducto*);
int get_Producto_descripcion(eProducto* p,char* descrip);
int get_Producto_cantidad(eProducto*);

//IMPRIME LISTADO

void listarProductos(ArrayList*);

int mover_Producto(ArrayList*, ArrayList* ,int );

int encontrar_Producto(ArrayList* ,int );
