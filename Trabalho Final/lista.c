#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lista.h"


#define true 1
#define false 0

// **************************** FUNÇÕES DE CRIAÇÂO  **************************** //

TELE *criarElemento(char palavra[40]){
    
    TELE *novo_elemento = malloc(sizeof(TELE));
    strcpy(novo_elemento->palavra,palavra);
    novo_elemento->prox = NULL;

    return novo_elemento;
}

TLista *criarLista(){
    
    TLista *nova_lista = malloc(sizeof(TLista));
    nova_lista->tamanho = 0;
    nova_lista->fim = NULL;
    nova_lista->inicio = NULL;

    return nova_lista;
}

// **************************** FUNÇÃO DE INSERÇÃO  **************************** //


int verificaElementoLista(TLista *lista,TELE *nova_carga){
    TELE *caminhador = lista->inicio;
    int flag = false;
    while (caminhador != NULL)
    {
        if(strcmp(caminhador->palavra,nova_carga->palavra) == 0){
            flag = true;
            break;
        }
        caminhador = caminhador->prox;
    }
    return flag;
}

void inserirOrdenadoLista(TLista *lista, TELE *nova_carga){

    if(lista->inicio == NULL){
        
        lista->inicio = nova_carga;
        lista->fim = nova_carga;

    }else{
        if(verificaElementoLista(lista,nova_carga) == false){  // insere se o elemento nao esta na lista
            TELE *caminhador1 = lista->inicio;
            TELE *caminhador2 = NULL;
            while(caminhador1 != NULL && strcmp(nova_carga->palavra,caminhador1->palavra) == 1){
                caminhador2 = caminhador1;
                caminhador1 = caminhador1->prox;
            }

            if(caminhador2 == NULL){ // inserir inicio
                nova_carga->prox = lista->inicio;
                lista->inicio = nova_carga;
            }else if(caminhador1 == NULL){ // inserir no fim
                lista->fim->prox = nova_carga;
                lista->fim = nova_carga;
            }else{
                nova_carga->prox = caminhador2->prox;
                caminhador2->prox = nova_carga;
            }
        }
    }

    lista->tamanho++;
}


// **************************** FUNÇÃO DIVERSAS  **************************** //

void imprimirLista(TLista *lista){  // função está adaptada para o trabalho
    TELE *caminhador = lista->inicio;
    int i = 0;
    if(caminhador == NULL){
        printf("Lista vazia\n");
    }
    while(caminhador != NULL && i < 10){
        printf("%s\n",caminhador->palavra);
        caminhador = caminhador->prox;
        i++;
    }
}

void reiniciarLista(TLista *lista){
    TELE *caminhador1 = lista->inicio;
    TELE *caminhador2 = caminhador1->prox;
    /*
    while(caminhador2 != NULL){
        free(caminhador1);
        caminhador1 = caminhador2;
        caminhador2 = caminhador2->prox;
    }
    free(caminhador1);
    */
    lista->tamanho = 0;
    lista->inicio = lista->fim = NULL;
}

void copiarListas(TLista *lista1, TLista *lista2){
    char palavra[40];
    TELE *caminhador = lista2->inicio;

    while(caminhador != NULL){     
        strcpy(palavra,caminhador->palavra);
        TELE *novo_elemento = criarElemento(palavra);
        inserirOrdenadoLista(lista1,novo_elemento);
        caminhador = caminhador->prox;        
    }
}

void completarLista(TLista *lista1, TLista *lista2){
    char palavra[40];
    TELE *caminhador = lista2->inicio;

    while(caminhador != NULL){
        strcpy(palavra,caminhador->palavra);
        TELE *novo_elemento = criarElemento(palavra);
        inserirOrdenadoLista(lista1,novo_elemento);
        caminhador = caminhador->prox;
    }
}