#include "ArrayList.h"

struct
{
    char letra;
    char nombre[30];
    int vocal;
    int consonante;


}typedef eLetra;

struct
{   char letra;
    int cant;
}typedef c_l;

//CONSTRUCTOR

eLetra* neweLetra(void);
c_l* newc_l(void);

int set_eLetra_nombre(eLetra* l,char* nombre);
void get_eLetra_nombre(eLetra* l,char* nombre);
int set_eLetra_letra(eLetra* l,char letra);
char get_eLetra_letra(eLetra* l);
int set_eLetra_vocal(eLetra* l,int vocal); //retorna 1 o -1
int get_eLetra_vocal(eLetra* l); //rretorna el dato
int set_eLetra_consonante(eLetra* l,int consonante); //retorna 1 o -1
int get_eLetra_consonante(eLetra* l);


int completar(ArrayList* l);

int buscarElementoPrincipal(char l,ArrayList* lista);



