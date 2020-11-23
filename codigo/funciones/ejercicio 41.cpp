/*El depósito de la empresa CosmeFulanito necesita cargar su stock de repuestos en forma ordenada.
 Para dicha tarea se solicitó categorizar a los respuestos bajo la siguiente estructura de datos:

typedef struct{
   long partNumber;
   long serialNumber;
   char descripcion[40];       
   chat ubicacion[100];        
}repuestos_t;

Los repuestos no están ordenados, se solicita cargarlos en una lista, la cual ordene por descripción a los repuestos 
para luego guardarlos en un archivo de stock con organización secuencial.

Imprimir en pantalla la lista con cada inserción.
El archivo se generará cuando el usuario decide no cargar mas productos.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
   long partNumber;
   long serialNumber;
   char descripcion[40];       
   char ubicacion[100];        
}repuestos_t;

// estructura de la lista
typedef struct{
	repuestos_t i;
	void *l;
}lista;

lista* fcarga(void);

void farch(lista*);

int main()
{
	lista *p;
	
	p=fcarga(); //se ingresa el stock y se genera la lista devolviendo el puntero a el primer elemento de la misma 
	
	farch(p);  //se guarda en archivo
	
}


lista* fcarga(void)
{
	lista *primero, *ultimo,*r,*m, *aux;
	primero=ultimo=r=NULL;
	repuestos_t data;
	int salir;

	
	printf("\n ***Carga de Stock***\n");

	do{
		printf("\n Ingrese a continuacion los siguientes datos del producto:\n");
		printf("\n Numero de partida: ");
		fflush(stdin);
		scanf("%d",&data.partNumber);
		printf(" Numero de Serie: ");
		fflush(stdin);
		scanf("%d",&data.serialNumber);
		printf(" Descripcion: ");
		fflush(stdin);
		scanf("%s",&data.descripcion);
		printf(" Ubicacion: ");
		fflush(stdin);
		scanf("%s",&data.ubicacion);	
		
		aux=(lista*)malloc(sizeof(lista));
		aux->i=data;
		r=primero;
		
		if (primero==NULL)
		{
			primero=ultimo=aux;
			ultimo->l=NULL;
		}
		else
		{
			while(1)
			{
				if(strcmp(strupr(aux->i.descripcion),strupr(r->i.descripcion))<0)
				{
					aux->l=primero;
					primero=aux;
					break;
				}
				else
				{
					while(r->l!=NULL)
					{
						m=(lista*)r->l;
						if(strcmp(strupr(aux->i.descripcion),strupr(m->i.descripcion))>0)
						{
							r=m;
							m=NULL;
						}
						else
						{
							aux->l=m;
							r->l=aux;
							m=NULL;
							break;
						}
					}
					if(r==ultimo)
					{
						ultimo->l=aux;
						ultimo=aux;
						ultimo->l==NULL;
						break;
					}
					else break;
				}
				
			}
		}
		r=primero;
		printf("\n Descripcion;  Numero de Serie;  Numero de partida;  Ubicacion\n ");
		while(r!=NULL)
		{
			printf("\n %s;  %d;  %d;  %s;\n ",r->i.descripcion,r->i.serialNumber,r->i.partNumber,r->i.ubicacion);
			r=(lista*)r->l;			
		}
									
		printf("\n Desea continuar cargando datos?\n Presione: (0) NO \t (1) SI   :\t");  //indico el valor 1 aunque podria ser cualquiera distinto que 0
		fflush(stdin);
		scanf("%d",&salir);
	}while(salir!=0);

	return primero;
}	

void farch(lista* f)
{
	repuestos_t data;
	lista *aux;
	FILE *parch;
	int cont=0;
	
	if((parch=fopen("stock.dat","ab+"))==NULL)
	{
		printf("\n *** Error al crear archivo 'stock.dat' ***\n");
		return;
	}
	
	if(f==NULL)
	{
		printf("\n Lista vacia. \n");
		return ;
	}
	

	while(f!=NULL)
	{
		fseek(parch,0L,SEEK_END);
		data=f->i;
		fwrite(&data,sizeof(repuestos_t),1,parch);
		aux=f;
		f=(lista*)f->l;
		free(aux);
	}
	
	fclose(parch);
	return;
}



