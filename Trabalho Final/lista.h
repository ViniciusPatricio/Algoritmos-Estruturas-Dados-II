#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// ************************************** ESTRUTURA DA LISTA DE PALAVRAS  ************************************** //

typedef struct elementoLista TELE;
struct elementoLista{
    char palavra[40];   // as frases não teram palavras com mais de 40 caracteres
    TELE *prox;
};

typedef struct lista TLista;
struct lista{
    int tamanho;
    TELE *inicio;
    TELE *fim;
};

TELE *criarElemento(char palavra[40]);
TLista *criarLista();
int verificaElementoLista(TLista *lista,TELE *nova_carga);
void inserirOrdenadoLista(TLista *lista, TELE *nova_carga);
void imprimirLista(TLista *lista);
void reiniciarLista(TLista *lista);
void copiarListas(TLista *lista1, TLista *lista2);
void completarLista(TLista *lista1, TLista *lista2);

