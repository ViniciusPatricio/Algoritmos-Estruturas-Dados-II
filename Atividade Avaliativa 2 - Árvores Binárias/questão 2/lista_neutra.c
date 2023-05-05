#include "stdio.h"
#include "stdlib.h"
#include "lista_neutra.h"


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

void inserirInicio(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);
    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        carga_util->prox=lista->inicio;
        lista->inicio=carga_util;
    }
    lista->qtde++;
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

        lista->qtde++;

   }else{
       printf("Posicao Invalida\n");
   }
}

void inserirOrdenado(TLista *lista,void* carga,TCompara compare){
    TELE *novo=criarElementoLista(carga);
    if(lista->inicio==NULL){
        inserirInicio(lista,carga);
    }else{
        TELE *caminhador1=lista->inicio;  // caminhador posterior
        TELE *caminhador2=NULL;           // caminhador anterior     
        while(caminhador1!=NULL && compare(novo->carga_util,caminhador1->carga_util)==1){   // ( -1 = valor da esquerda é menor) ( 0 = valor da esquerda é igual da direita) 
            caminhador2=caminhador1;
            caminhador1=caminhador1->prox;                                                                   // (1 = valor da esquerda é maior)
        }

        if(caminhador2==NULL){
            inserirInicio(lista,carga);
        }else if(caminhador1==NULL){
            inserirFim(lista,carga);
        }else{
            novo->prox=caminhador2->prox;
            caminhador2->prox=novo;
            lista->qtde++;
        }
    }
}

// *********************** FUNÇÕES DE REMOÇÂO  *********************** //



void removerInicio(TLista *lista,TDestroyMedida destroy){ // removerInicio recebe uma lista e um função que remove uma medida genérica
    TELE *caminhador=lista->inicio;
    void *carga=caminhador->carga_util;
    if(lista->inicio==NULL){
        printf("Lista vazia\n");
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
        lista->inicio=lista->fim=NULL;
        //destroy(carga);
        free(caminhador);
        lista->qtde=0;
    }else{
        while(caminhador->prox!=lista->fim){
            caminhador=caminhador->prox;
            lista->qtde--;
         }

       // destroy(carga);
        free(lista->fim);
        lista->fim=caminhador;
        caminhador->prox=NULL;
        lista->qtde--;
        
    }    
}
void removerPosicao(TLista *lista,int pos,TDestroyMedida destroy){
   if(pos==1){
       removerInicio(lista,destroy);
   } else if(pos==lista->qtde){
       removerFinal(lista,destroy);
   }else if (pos>1 && pos<lista->qtde){
       int i=1;
       TELE *caminhador1=NULL;
       TELE *caminhador2=lista->inicio;

       while (i!=pos){
           caminhador1=caminhador2;
           caminhador2=caminhador2->prox;
           i++;
       }
       caminhador1->prox=caminhador2->prox;
       destroy(caminhador2->carga_util);
       free(caminhador2);
       lista->qtde--;

   }else{
       printf("Posicao Invalida\n");
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
void verificaElemento(TLista *lista,void *buscado,TCompara compare){
    if(buscaELemento(lista,buscado,compare)!=NULL){
        printf("Elemento esta na lista");
    }else{
        printf("Elemento nao esta na lista");
    }
}

// *********************** FUNÇÕES DIVERSAS  *********************** //

int quantidadeLista(TLista *lista){
    return lista->qtde;
}

void *imprimirLista(TLista *lista,TImprimirElemento imprimir){
    TELE *caminhador=lista->inicio;

    while(caminhador!=NULL){
        imprimir(caminhador->carga_util);
        caminhador=caminhador->prox;
    }

}

