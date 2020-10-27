#include "../libs/ejercicio_35_lib.h"

void ejercicio_35(void)
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
	return;
}



pila *cargadatos(void)
{
	pila *f=NULL,*aux=NULL;
	datos info;
	int salir;
	do{
		printf("\n Ingrese a continuacion los siguientes datos de la persona:\n");
		printf("\n Nombre: ");
		fflush(stdin);
		scanf("%s",&info.n);
		printf(" Apellido: ");
		fflush(stdin);
		scanf("%s",&info.a);
		do{
			printf(" Edad: ");
			fflush(stdin);
			scanf("%d",&info.e);
			if(info.e>130) printf(" Por favor ingrese una edad correcta.\n");
		}while(info.e>130);
		printf(" Telefono: ");
		fflush(stdin);
		scanf("%s",&info.t);
		printf(" Mail: ");
		fflush(stdin);
		scanf("%s",&info.m);	
		
		aux=(pila *) malloc(sizeof(pila));
		aux->inf=info;
		aux->lazo=f;
		f=aux;
									
		printf("\n Desea continuar cargando datos?\n Presione: (0) NO \t (1) SI   :\t");  //indico el valor 1 aunque podria ser cualquiera distinto que 0
		fflush(stdin);
		scanf("%d",&salir);
	}while(salir!=0);
	return f;
}


int carga_archivo(pila *first)
{
	int nuevo=0,existente=0;
	datos persona;
	FILE *fp;
	if((fp=fopen("contactos.dat","rb+"))==NULL) // si no existe el archivo devuelve NULL pues modo lectura
	{
		if((fp=fopen("contactos.dat","wb+"))==NULL) // se crea el archivo pero si devuelve NULL es que se produjo un error
		{
			printf("*** Error en la creacion del archivo contactos.dat ***");
			return nuevo;
		}
		else nuevo=1;  //indica que el archivo es nuevo y que por lo tanto esta vacio
	}
	if(nuevo==0)
	{   //debemos corroborar que no exista la clave primaria 
		fread(&persona,sizeof(persona),1,fp);
		while(!feof(fp))
		{
			if((strcmp(persona.t,first->inf.t))==0) existente=1;//si ya existe no se carga (clave primaria el telefono ya que es unico )
			fread(&persona,sizeof(persona),1,fp);
		}
	}
	if(existente==0)
	{
		persona=first->inf;
		fwrite(&persona,sizeof(persona),1,fp);				
	}
	else printf("\n Registro de %s, %s ya existente\n",first->inf.a,first->inf.n);
	fclose(fp);	
	return nuevo;
}





