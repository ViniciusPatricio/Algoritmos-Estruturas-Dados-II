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
typedef int (*TCompara)(void*,void*);
typedef void (*TDestroyMedida)(void*); // assinatura de uma função
typedef void (*TImprimirElemento)(void*);


TELE *criarElementoLista(void *carga);
TLista *criarListaEncadeada();
void inserirFim(TLista *lista, void *carga);
void inserirInicio(TLista *lista, void *carga);
void inserirPosicao(TLista *lista, void *carga, int pos);
void inserirOrdenado(TLista *lista,void* carga,TCompara compare);
void removerInicio(TLista *lista,TDestroyMedida destroy);
void removerFinal(TLista *lista, TDestroyMedida destroy);
void removerPosicao(TLista *lista,int pos,TDestroyMedida destroy);
void *primeiroLista(TLista *lista);
void *ultimoLista(TLista *lista);
void *buscaPosicao(TLista *lista,int pos);
void *buscaELemento(TLista *lista,void *buscado,TCompara compare);
void verificaElemento(TLista *lista,void *buscado,TCompara compare);
int quantidadeLista(TLista *lista);
void *imprimirLista(TLista *lista,TImprimirElemento imprimir);