#include "stdio.h"
#include "stdlib.h"

typedef struct Elemento_Lista TELE;
struct Elemento_Lista{
    int carga;
    void *prox;
};
typedef struct Lista_Encadeada TLista;
struct Lista_Encadeada{
    int qtde;
    TELE *fim;
    TELE *inicio;
};

// *********************** FUNÇÕES DE CRIAÇÃO  *********************** //
TELE *criarElementoLista(int num){
	TELE *Elemento_Lista=malloc(sizeof(TELE));
	Elemento_Lista->carga=num;
	Elemento_Lista->prox=NULL;
	return Elemento_Lista;
}
TLista *criarLista(){
 TLista *lista=malloc(sizeof(TLista));

 lista->inicio=NULL;
 lista->fim=NULL;
 lista->qtde=0;

 return lista;
}
// *********************** FUNÇÕES DE INSERÇÃO  *********************** //
void inserirFim(TLista *lista, int carga){
	TELE *elemento_novo=criarElementoLista(carga);

	if(lista->inicio==NULL){
		lista->inicio=elemento_novo;
		lista->fim=elemento_novo;
	}else{
		lista->fim->prox=elemento_novo;
		lista->fim=elemento_novo;
	}
	lista->qtde++;
}

// *********************** FUNÇÕES DIVERSAS  *********************** //
void trocaCarga(TELE *cam1,TELE *cam2){
	int aux=cam1->carga;
	cam1->carga=cam2->carga;
	cam2->carga=aux;
}

void imprimirLista(TLista *lista){
	TELE *cam=lista->inicio;
	while(cam!=NULL){
		printf("%d ",cam->carga);
		cam=cam->prox;
	}
}
void inverterLista(TLista *lista,int i,int y,int z,TELE *cam1, TELE *cam2){
	if(lista->qtde%2==0){
		if(i==lista->qtde/2){
			cam1=lista->inicio;
			cam2=cam1->prox;
			while(y<i){
				cam1=cam2;
				cam2=cam2->prox;
				y++;
			}
			trocaCarga(cam1,cam2);
		
		}
				
		else{
			cam1=lista->inicio;
			cam2=lista->inicio;
			while(y<i){
				cam1=cam1->prox;
				y++;
			}
			while(z<lista->qtde-i+1){
				cam2=cam2->prox;
				z++;
			}
			
			trocaCarga(cam1,cam2);
			inverterLista(lista,i+1,1,1,lista->inicio,lista->inicio);
		}
	}
	
	
	else
	{	
		if(i!=1+(lista->qtde)/2){
		cam1=lista->inicio;
			cam2=lista->inicio;
			while(y<i){
				cam1=cam1->prox;
				y++;
			}
			while(z<lista->qtde-i+1){
				cam2=cam2->prox;
				z++;
			}
			
			trocaCarga(cam1,cam2);
			inverterLista(lista,i+1,1,1,lista->inicio,lista->inicio);
	}
		
	}
	
}


int main(){
	TLista *lista=criarLista();
        
	int entrada;

	while(scanf("%d",&entrada),entrada!=0){
		inserirFim(lista,entrada);
	}

	int i=1;
	inverterLista(lista,i,1,1,lista->inicio,lista->fim);
	imprimirLista(lista);  
        
}