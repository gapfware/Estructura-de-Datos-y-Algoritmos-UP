#include <stdio.h>
#include <stdlib.h>

typedef struct numeros{
        int num;
        float sueldo; 
        struct numeros *sig;
        }nodon;

void crearlista(nodon *h){
	printf("ingrese valor numerico");
	scanf("%d",&h->num);
	
	while(h->num != 0){
		printf("ingrese sueldo");
		scanf("%f",&h->sueldo);
		h->sig=(nodon *)malloc(sizeof(nodon));
		h=h->sig;
		printf("ingrese valor numerico");
	    scanf("%d",&h->num);
	}
	h->sig=NULL;
	
	}

void mostrarlista(nodon *h){
	while(h->sig != NULL){
		printf("%d \n",h->num);
		printf("%f \n",h->sueldo);
		h=h->sig;
		
	}
	
}
	void generar(nodon *h, nodon *a){
		while(h->sig != NULL){
			if(h->sueldo > 3000){
				a->num = h->num;
				a->sueldo = h->sueldo;
				a->sig=(nodon *)malloc(sizeof(nodon));
				a=a->sig;
			}
			h=h->sig;
		}
		a->sig=NULL;
	}

int main() {

	nodon *p=NULL;
	nodon *q=NULL;
	p=(nodon *)malloc(sizeof(nodon));
	q=(nodon *)malloc(sizeof(nodon));
    crearlista(p);
	mostrarlista(p);
	generar(p,q);
	printf("la nueva lista es \n");
	mostrarlista(q);
	
	return 0;
}
