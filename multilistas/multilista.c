#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listas{
        char nombre[30];
        struct canciones *c; 
        struct listas *sig;
}nodol;

typedef struct canciones{
        char nombre[30];
        char inter[30];
        int duracion;
        struct canciones * sigc;
}nodoc;

void crearlistacanciones(nodoc *t){
	printf("ingrese nombre de la cancion: \n");
	scanf("%s",t->nombre);
	if(strcmp(t->nombre,"x")==0)
		t->sigc=NULL;
	else{
		printf("ingrese interprete: \n");
		scanf("%s",t->inter);
		printf("ingrese duracion \n ");
		scanf("%d",&t->duracion);
		t->sigc=(nodoc *)malloc(sizeof(nodoc));
		crearlistacanciones(t->sigc);
		
	}
   	
} 


void crearlistareprod(nodol *h){
	printf("\nIngrese nombre de la Playlist: ");
	scanf("%s",h->nombre);
	if(strcmp(h->nombre,"x")==0)
		h->sig=NULL;
	else{
	    h->c=(nodoc *)malloc(sizeof(nodoc));
		crearlistacanciones(h->c);
		h->sig=(nodol *)malloc(sizeof(nodol));
		crearlistareprod(h->sig);
		
	}
	
}

void mostrarlistacanciones(nodoc *t){
	if(t->sigc !=NULL){
		printf("%s ",t->nombre);
		printf("%s ",t->inter);
		printf("%d ",t->duracion);
		printf("\n");
		mostrarlistacanciones(t->sigc);
		
		
	}
	
}

void mostrarlistareprod(nodol *h){
	if(h->sig!=NULL){
		printf("%s \n",h->nombre);
		printf("\nlas canciones son: \n");
		mostrarlistacanciones(h->c);
		mostrarlistareprod(h->sig);
	}
}


int main(){
	nodol *p=NULL;
	p=(nodol *)malloc(sizeof(nodol));
	crearlistareprod(p);
	mostrarlistareprod(p);
	
}
