#include "ArrayList.h"

struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
}typedef eLetra;

//CONSTRUCTOR

eLetra* neweLetra(void);

//SETTERS Y GETTERS (1-SE LOGRO SETEAR; -1 HUBO ERROR)

int set_eLetra_nombre(eLetra* l,char* nombre);
int get_eLetra_nombre(eLetra* l,char* nombre);

int set_eLetra_vocal(eLetra* l,int v);
int get_eLetra_vocal(eLetra* l);

int set_eLetra_consonante(eLetra* l,int c);
int get_eLetra_consonante(eLetra* l);

int set_eLetra_letra(eLetra* l,char letra);
char get_eLetra_letra(eLetra* l);

void listar(ArrayList*);


int completar_eLetra(eLetra* l);

int consulta_user(char* dato, int caracteres);

void comprobar(ArrayList* AL);

void generar_y_listar_descendente(ArrayList* AL);

int compareeLetra(void* pLetraA,void* pLetraB);

ArrayList* generar_y_listar_ascendente(ArrayList* AL);


int Existe_letra_en_Array(ArrayList*,char);

void generarArchivo(ArrayList*,char*);

int fLetra(void* pElement,void* loc);
