#include "../libs/ejercicio_36_lib.h"

int main()
{
	lista *p,*u,*aux,*r,*m;
	p=u=aux=r=NULL;
	FILE *parch;
	datos contactos;
	int cont=0;
	
    if((parch=fopen("contactos.dat","rb+"))==NULL)
	{
		printf("\n\t*** Error en la apertura del archivo 'contactos.dat' ***\n");
		printf("\n\t\tPor favor corrobore la existencia del mismo\n ");
		return 0;
	}
	while(!feof(parch))
   	{
    	fread(&contactos,sizeof(contactos),1,parch);
		strupr(contactos.a);
		strupr(contactos.n);
		printf("\n Se encontro el siguiente contacto:\n");
		printf("\n Apellido y Nombre: %s, %s  Edad: %d  TE: %s   Mail: %s\n\n",contactos.a,contactos.n,contactos.e,contactos.t,contactos.m);
		aux=(lista *)malloc(sizeof(lista));
		aux->i=contactos;
		r=p;
		if(p==NULL)
		{
			p=u=aux;
			u->l=NULL;
		}
		else
		{
			while(1)
			{
				if((strcmp(r->i.a,aux->i.a))>0)
				{
					aux->l=p;
					p=aux;
					break;
				}
				else
				{
					if((strcmp(r->i.a,aux->i.a))==0 && (strcmp(r->i.n,aux->i.n))>0)
					{
						aux->l=p;
						p=aux;
						break;
					}
					else
					{
						while((r->l)!=NULL)
						{
							m=(lista *)r->l;
							if((strcmp(m->i.a,aux->i.a))<0)
							{
								r=m;
								m=NULL;
							}
							else 
							{
								if((strcmp(m->i.a,aux->i.a))==0 && (strcmp(m->i.n,aux->i.n))>0)
								{
									aux->l=m;
									r->l=aux;
									m=NULL;
									break;
								}
								break;
							}
						}
						if(r==u)
						{
							u->l=aux;
							u=aux;
							u->l=NULL;
							break;
						}
						else break;
					}
				}
			}
		}	
    }
	fclose(parch);

	if((parch=fopen("contactos_ordenados.dat","wb"))==NULL)
	{
		printf("\n *** Error al crear archivo 'contactos_ordenados.dat' ***\n");
		return 0;
	}
	r=p;
	if(p==NULL)
	{
		printf("\n Lista vacia. \n");
		return 0;
	}
	printf("\n Contactos ordenados alfabeticamente:\n");
	printf("\n Apellido y Nombre \t Edad \t Telefono \t Mail \n");
	if (cont==0) //es el primero que se escribe
	{
		contactos=p->i;
		printf("\n %s, %s \t %d \t %s \t %s\n",contactos.a,contactos.n,contactos.e,contactos.t,contactos.m);
		fwrite(&contactos,sizeof(datos),1,parch);
		aux=p;
		p=(lista *)p->l;
		if(!p) u=NULL;
		free(aux);
		cont=1;
	}
	while(p!=NULL)
	{
		fseek(parch,0L,SEEK_END);
		contactos=p->i;
		printf("\n %s, %s \t %d \t %s \t %s\n",contactos.a,contactos.n,contactos.e,contactos.t,contactos.m);
		fwrite(&contactos,sizeof(datos),1,parch);
		aux=p;
		p=(lista *)p->l;
		if(!p) u=NULL;
		free(aux);
	}
	fclose(parch);
	return 0;
}
