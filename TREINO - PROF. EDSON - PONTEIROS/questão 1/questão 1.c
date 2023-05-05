#include "stdio.h"
#include "stdlib.h"

typedef struct Elemento_Lista TELE;
struct Elemento_Lista{
    void *carga_util;
    void *prox;
};
typedef struct Lista_Encadeada TLista;
struct Lista_Encadeada{
    int qtde;
    TELE *fim;
    TELE *inicio;
};

// *********************** FUNÇÕES DE CRIAÇÃO  *********************** //

TELE *criarElementoLista(void *carga){
    TELE *elemento_lista=malloc(sizeof(TELE));
    
    elemento_lista->carga_util=carga;
    elemento_lista->prox=NULL;

    return elemento_lista;
}

TLista *criarListaEncadeada(){
    TLista *lista=malloc(sizeof(TLista));
    
    lista->fim=NULL;
    lista->inicio=NULL;
    lista->qtde=0;
    
    return lista;
}

// *********************** FUNÇÕES DE INSERÇÃO  *********************** //

void inserirFim(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);

    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        lista->fim->prox=carga_util;
        lista->fim=carga_util;
    }
    lista->qtde++;
}


// *********************** MEDIDA CRIADA PARA EXEMPLO  *********************** //

typedef struct medida TMedida;
struct medida{
    int num;
};

TMedida *criarMedida(int num){
    TMedida *medida=malloc(sizeof(TMedida));
    medida->num=num;

    return medida;
}

void imprimirMedida(void *medida){
    TMedida *med=medida;
    printf("%d ",med->num);
}
int compararMedida(void *medida1, void *medida2){
    TMedida *med1=medida1; TMedida *med2=medida2;
    if(med1->num == med2->num){
        return 0;
    }if(med1->num < med2->num){
        return -1;
    }else if(med1->num > med2->num){
        return 1;
    }
}
typedef int (*TCompara)(void*,void*);
void *buscaELemento(TLista *lista,void *buscado,TCompara compare){
    TELE *caminhador=lista->inicio;
    while(caminhador!=NULL && compare(caminhador->carga_util,buscado)!=0){
        caminhador=caminhador->prox;
    }
    if(caminhador==NULL){
        return NULL;
    }else{
        return caminhador->carga_util;
    }
}
// *********************** FUNÇÕES DIVERSAS  *********************** //


typedef void (*TImprimirElemento)(void*);

void *imprimirLista(TLista *lista,TImprimirElemento imprimir){
    TELE *caminhador=lista->inicio;

    while(caminhador!=NULL){
        imprimir(caminhador->carga_util);
        caminhador=caminhador->prox;
    }

}

TLista *uniao(TLista *v1,TLista *v2){
	TLista *uniao=criarListaEncadeada();
    uniao->inicio=v1->inicio;
    uniao->fim=v1->fim;
    TELE *cam=v2->inicio;
    while(cam->prox!=NULL){

    }
	
}

int main(){

    TLista *lista1=criarListaEncadeada();
	TLista *lista2=criarListaEncadeada();
	int n1;
	while(scanf("%d",&n1),n1!=0){
		TMedida *nova_medida=criarMedida(n1);
        inserirFim(lista1,nova_medida);
	}
	while(scanf("%d",&n1),n1!=0){
		TMedida *nova_medida=criarMedida(n1);
        inserirFim(lista2,nova_medida);
	}
	printf("lista 1: ");
   imprimirLista(lista1,imprimirMedida);
	printf("\nlista 2: ");
   imprimirLista(lista2,imprimirMedida);
}