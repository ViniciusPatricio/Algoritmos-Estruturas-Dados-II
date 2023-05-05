#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// *********************** MEDIDA CRIADA PARA EXEMPLO  *********************** //

typedef struct medida TMedida;
struct medida{
    int prioridade;
    char palavra[30];
};

void imprimirTMedida(void *medida){
    TMedida *med=medida;
    for(int i=0;med->palavra[i]!='\0';i++){
        printf("%c",med->palavra[i]);
    }
    printf("\n");
}

void destruirTMedida(void *medida){
    TMedida *med=medida;
    free(med);
}
int comparaTMedida(void *medida1, void *medida2){
    TMedida *med1=medida1; TMedida *med2=medida2;
    
    if(med1->prioridade == med2->prioridade)
    {
        return 0;
    }

    if(med1->prioridade > med2->prioridade)
    {
        return 1;
    }
    else if(med1->prioridade < med2->prioridade)
    {
        return -1;
    }
}

int prioridadeMedida(TMedida *medida){
    return medida->prioridade;
}


TMedida *criarMedida(int num, char vetor[]){
    TMedida *nova_medida=malloc(sizeof(TMedida));
    strcpy(nova_medida->palavra,vetor);
    nova_medida->prioridade=num;

    return nova_medida;
}


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

typedef int (*TCompara)(void*,void*);

void inserirFim(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);

    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        lista->fim->prox=carga_util;
        lista->fim=carga_util;
    }
    
}

void inserirInicio(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);
    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        carga_util->prox=lista->inicio;
        lista->inicio=carga_util;
    }
    
}




void inserirPosicao(TLista *lista, void *carga, int pos){
   
   if(pos>=1 && pos<=lista->qtde+1){
        int i=1;
        TELE *caminhador1=NULL;
        TELE *caminhador2=lista->inicio;

        while(i!=pos){
            caminhador1=caminhador2;
            caminhador2=caminhador2->prox;
            i++;
        }

        if(caminhador1==NULL){
            inserirInicio(lista,carga);
        }else if(caminhador2==lista->fim+1){
            inserirFim(lista,carga);
        }else{
            TELE *carga_util=criarElementoLista(carga);
            caminhador1->prox=carga_util;
            carga_util->prox=caminhador2;
        }


   }else{
       printf("Posicao Invalida\n");
   }
}

void inserirOrdenado(TLista *lista,void* carga,TCompara compare){
    TELE *novo_elemento=criarElementoLista(carga);
    if(lista->inicio==NULL){
        inserirInicio(lista,carga);
    }else{
        int pos=1;
        TELE *cam1=lista->inicio;
        TELE *cam2=NULL;
        while(cam1!=NULL && compare(cam1->carga_util,novo_elemento->carga_util)!=-1){
            if(compare(cam1->carga_util,novo_elemento->carga_util)==0){
                break;
            }
            
            cam2=cam1;
            cam1=cam1->prox;
            pos++;
        }

        if(pos==1){          
            TMedida *m=novo_elemento->carga_util;
            while(cam1!=NULL){
                TMedida *m1=cam1->carga_util;
                if(m1->prioridade==m->prioridade && strcmp(m->palavra,m1->palavra)==1){
                    pos++;
                    
                }
                cam1=cam1->prox;
            }
            
            inserirPosicao(lista,carga,pos);

        }else if(pos==lista->qtde){
            inserirFim(lista,carga);
        }else{
            TMedida *m=novo_elemento->carga_util;
            while(cam1!=NULL){
                TMedida *m1=cam1->carga_util;
                
                if(m1->prioridade==m->prioridade && strcmp(m->palavra,m1->palavra)==1){
                    
                    pos++;
                }
                cam1=cam1->prox;
            }
           
            inserirPosicao(lista,carga,pos);

        }
        
                       
    }
    lista->qtde++;
    
}

// *********************** FUNÇÕES DE REMOÇÂO  *********************** //

typedef void (*TDestroyMedida)(void*); // assinatura de uma função

void removerInicio(TLista *lista,TDestroyMedida destroy){ // removerInicio recebe uma lista e um função que remove uma medida genérica
    TELE *caminhador=lista->inicio;
    void *carga=caminhador->carga_util;
    if(lista->inicio==NULL){
       // printf("Lista vazia\n");
    }else if(lista->inicio==lista->fim){
        lista->fim=lista->inicio=NULL;
        //destroy(carga);
        free(caminhador);
        lista->qtde=0;
    }else{
        TELE *caminhador_prox=caminhador->prox;
        //destroy(carga);
        free(caminhador);
        lista->inicio=caminhador_prox;
        lista->qtde--;
    }
}

void removerFinal(TLista *lista, TDestroyMedida destroy){
    TELE *caminhador=lista->inicio;
    void *carga=lista->fim;
    
    if(lista->inicio==NULL){
        printf("Lista vazia\n");
    }else if(lista->inicio==lista->fim){
        lista->inicio=NULL;
        lista->fim=NULL;
        destroy(carga);
        free(caminhador);
        lista->qtde=0;
    }else{
        while(caminhador->prox!=lista->fim){
            caminhador=caminhador->prox;
            lista->qtde--;
         }

        destroy(carga);
        free(lista->fim);
        lista->fim=caminhador;
        caminhador->prox=NULL;
        lista->qtde--;
        
    }    
}

// *********************** FUNÇÕES DE BUSCA  *********************** //



void *primeiroLista(TLista *lista){
    return lista->inicio->carga_util;
}

void *ultimoLista(TLista *lista){
    return lista->fim->carga_util;
}

void *buscaPosicao(TLista *lista,int pos){
    if(pos==1){
        primeiroLista(lista);
    }else if(pos==lista->qtde){
        ultimoLista(lista);
    }else if(pos>1 && pos<lista->qtde){
        int i=1;
        TELE *caminhador=lista->inicio;

        while(i!=pos){
            caminhador=caminhador->prox;
            i++;
        }
        return caminhador->carga_util;

    }else{
        printf("Posicao invalida\n");
    }
}

// Vai ser utilizado typedef int (*TCompara)(void*,void*);


// *********************** FUNÇÕES DIVERSAS  *********************** //

typedef void (*TImprimirElemento)(void*);

void *imprimirLista(TLista *lista,TImprimirElemento imprimir){
    TELE *caminhador=lista->inicio;

    while(caminhador!=NULL){
        imprimir(caminhador->carga_util);
        caminhador=caminhador->prox;
    }

}



int main(){

    TLista *fila_prioridade=criarListaEncadeada();

    int comando;

    while(scanf("%d",&comando),comando!=0)
    {
             
        if(comando==1)
        {
            int prioridade;
            char palavra[30];

            scanf("%d",&prioridade);
            scanf("%s",&palavra);
            TMedida *nova_medida=criarMedida(prioridade,palavra);

           inserirOrdenado(fila_prioridade,nova_medida,comparaTMedida);

        }else if(comando==2)
        {
            
            TMedida *medida=fila_prioridade->inicio->carga_util;
            imprimirTMedida(medida);
            TELE *caminhador=fila_prioridade->inicio;
            fila_prioridade->inicio=caminhador->prox;
        }
    }
    
}