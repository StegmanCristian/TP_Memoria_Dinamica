#ifndef EJERCICIO_36_LIB
#define EJERCICIO_36_LIB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defino la estructura de los datos
typedef struct {
    char n[20];         //nombre 
    char a[20];         //apellido 
    int e;              //edad
    char t[20];         //telefono
    char m[60];         //mail
} datos;

// estructura de la lista
typedef struct{
	datos i;
	void *l;
}lista;

#endif
