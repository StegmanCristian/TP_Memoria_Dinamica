#include "../libs/ejercicio_35_lib.h"

int main()
{
	int crea, primera=0, auxiliar;
	pila *p=NULL,*aux=NULL;
	p=cargadatos();
	printf("\n Se cargaron los siguientes datos:\n");
	while(p!=NULL)
	{
		printf("\n Apellido y Nombre: %s, %s  Edad: %d  TE: %s   Mail: %s\n\n",p->inf.a,p->inf.n,p->inf.e,p->inf.t,p->inf.m);
		if(p->inf.e>21)
		{
			primera++;
			auxiliar=carga_archivo(p);
			if(primera==1) crea=auxiliar; 
		}
		aux=p;
		p=(pila *)p->lazo;
		free(aux);
	}
	if(crea==1) printf("\n Se creo archivo 'contactos.dat' donde se almacenaron los contactos con edad superior a 21 \n");
	return 0;
}




