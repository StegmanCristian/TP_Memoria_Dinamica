#ifndef EJERCICIO_35_LIB
#define EJERCICIO_35_LIB

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

// estructura de la pila
typedef struct{
	datos inf;
	void *lazo;
}pila;

//Prototipo de las funciones 

pila *cargadatos(void);

void carga_archivo(pila *);


#include "../funciones/funciones_ejercicio_35.cpp"


#endif
