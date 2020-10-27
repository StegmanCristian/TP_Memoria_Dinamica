#include "../libs/ejercicio_35_lib.h"

int main()
{
	pila *p=NULL,*aux=NULL;
	p=cargadatos();
	printf("\n Se cargaron los siguientes datos:\n");
	while(p!=NULL)
	{
		printf("\n Apellido y Nombre: %s, %s  Edad: %d  TE: %s   Mail: %s\n\n",p->inf.a,p->inf.n,p->inf.e,p->inf.t,p->inf.m);
		if(p->inf.e>21) carga_archivo(p); 
		aux=p;
		p=(pila *)p->lazo;
		free(aux);
	}
	printf("\n Se almacenaron los contactos con edad superior a 21 en el archivo 'contactos.dat' \n");
	return 0;
}




