#include "../libs/ejercicio_35_lib.h"


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


void carga_archivo(pila *first)
{
	int existente=0;
	datos persona;
	FILE *fp;
	
	// Abrimos el archivo, si no existe el archivo lo crea
	
	if((fp=fopen("contactos.dat","ab+"))==NULL) //si devuelve NULL es que se produjo un error
	{
		printf("*** Error en la creacion del archivo contactos.dat ***");
		return;
	}
	
	//Debemos corroborar que no exista la clave primaria 
	
	fseek(fp,0L,SEEK_SET);  // Nos posicionamos en el comienzo del archivo para comparar los registros 
	fread(&persona,sizeof(persona),1,fp);
	
	while(!feof(fp))
	{
		if((strcmp(persona.t,first->inf.t))==0) existente=1;//si ya existe no se carga (clave primaria el telefono ya que es unico )
		fread(&persona,sizeof(persona),1,fp);
	}
	
	if(existente==0)  //Si entra, entonces no hay ningun registro coincidente
	{
		fseek(fp,0L,SEEK_END); //Nos posicionamos al final para escribir el registro 
		persona=first->inf;
		fwrite(&persona,sizeof(persona),1,fp);				
	}
	else printf("\n Registro de %s, %s ya existente\n",first->inf.a,first->inf.n);
	fclose(fp);	
	return;
}





