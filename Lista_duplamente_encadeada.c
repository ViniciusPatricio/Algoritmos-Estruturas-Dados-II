#include "stdio.h"
#include "stdlib.h"


typedef struct Medida TMedida;
typedef struct Elemento_Lista TELE;
typedef struct Lista_Duplamente_Encadeada LDE;

struct Medida{
    int num1;
    int num2;
};

struct Elemento_Lista{
    TMedida *m;
    TELE *prox;
    TELE *ant;
};

struct Lista_Duplamente_Encadeada{
    int qtde;
    TELE *inicio;
    TELE *fim;
};

TELE *criarElemento(int num1,int num2){
    TELE *elemento=malloc(sizeof(TELE));
    elemento->m=malloc(sizeof(TMedida));

    elemento->m->num1=num1;
    elemento->m->num2=num2;
    elemento->prox=NULL;
    elemento->ant=NULL;

    return elemento;
}

LDE *criarLista(){
    LDE *lista=malloc(sizeof(LDE));
    lista->qtde=0;
    lista->inicio=NULL;
    lista->fim=NULL;
}

void inserirLista(LDE *lista, TELE *elemento){
    if(lista->inicio==NULL){
        lista->inicio=elemento;
        lista->fim=elemento;
    }else{
        elemento->ant=lista->fim;
        lista->fim->prox=elemento;
        lista->fim=elemento;
    }
    lista->qtde++;
}

int main(){
    int tamanho,i;
    int num1, num2;
    LDE *lista=criarLista();
    
    printf("Digite o tamanho da lista:");
    scanf("%d",&tamanho);

    for(i=0;i<tamanho;i++){
        scanf("%d %d",&num1,&num2);
        TELE *elemento=criarElemento(num1,num2);
        inserirLista(lista,elemento);
    }

    TELE *cam=lista->inicio;
    while(cam!=NULL){
       
       if(cam->ant!=NULL){
           printf("Num1: %d   Num2:%d",cam->ant->m->num1,cam->ant->m->num2);
       }
        printf("||Numeros atuais: Num1: %d   Num2:%d||",cam->m->num1,cam->m->num2);
        
        if(cam->prox!=NULL){
            printf("Num1: %d   Num2:%d\n",cam->prox->m->num1,cam->prox->m->num2);
        }
        cam=cam->prox;
           
    }
    

}
