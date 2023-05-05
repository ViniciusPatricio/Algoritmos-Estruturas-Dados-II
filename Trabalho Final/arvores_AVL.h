#include "stdio.h"
#include "stdlib.h"
#include "lista.h"

typedef struct no NO;
struct no{ 
    int categoria;  // categoria da frase
    int altura;  
    int quantidade_categoria;  // quantas vezes a categoria apareceu
    TLista *lista_palavras;  // lista que irá armazenar as palavras
    NO *filho_esq;
    NO *filho_dir;
};

int altura(NO *no);
int maior(int x, int y);
NO *criarNO(int categoria, TLista *lista);
NO *rotacaoDireita(NO *no);
NO *rotacaoEsquerda(NO *no);
NO *rotacaoEsquerda(NO *no);
int fatorBalanceamento(NO *no);
NO *inserirArvore(NO *raiz, int categoria, TLista *lista_palavras);
void buscaCategoria(NO *raiz, int categoria);