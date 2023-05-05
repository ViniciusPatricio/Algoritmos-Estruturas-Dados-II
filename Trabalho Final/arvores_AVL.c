#include "stdio.h"
#include "stdlib.h"
#include "arvores_AVL.h"


int altura(NO *no){
    if(no == NULL){
        return 0;
    }
    return no->altura;
}

int maior(int x, int y){
    return x > y ? x : y;
}

NO *criarNO(int categoria, TLista *lista){
    NO *novo_no = malloc(sizeof(NO));
    novo_no->lista_palavras = criarLista();
    novo_no->categoria = categoria;
    copiarListas(novo_no->lista_palavras,lista);
    novo_no->filho_dir = NULL;
    novo_no->filho_esq = NULL;
    novo_no->altura = 1;
    novo_no->quantidade_categoria = 1;
    return novo_no;
}

NO *rotacaoDireita(NO *no){
    NO *x=no->filho_esq;
    NO *y=x->filho_dir;

    x->filho_dir = no;
    no->filho_esq = y;

    no->altura = maior(altura(no->filho_esq),altura(no->filho_dir)) + 1;
    x->altura = maior(altura(x->filho_esq),altura(x->filho_dir)) + 1;

    return x;
}

NO *rotacaoEsquerda(NO *no){
    NO *x=no->filho_dir;
    NO *y=x->filho_esq;

    x->filho_esq = no;
    no->filho_dir = y;

    no->altura = maior(altura(no->filho_dir),altura(no->filho_esq)) + 1;
    x->altura = maior(altura(x->filho_dir),altura(x->filho_esq)) + 1;

    return x;
}

int fatorBalanceamento(NO *no){
    if(no == NULL){
        return 0;
    }
    return altura(no->filho_esq) - altura(no->filho_dir); 
}

NO *inserirArvore(NO *raiz, int categoria, TLista *lista_palavras){
    if(raiz == NULL){
        raiz = criarNO(categoria, lista_palavras);
        return raiz;
    }
    if(categoria < raiz->categoria){
        raiz->filho_esq = inserirArvore(raiz->filho_esq, categoria, lista_palavras);
    }else if(categoria > raiz->categoria){
        raiz->filho_dir = inserirArvore(raiz->filho_dir, categoria, lista_palavras);
    }else{
        raiz->quantidade_categoria++;
        completarLista(raiz->lista_palavras,lista_palavras);
        return raiz;
    }
    raiz->altura = 1 + maior(altura(raiz->filho_esq),altura(raiz->filho_dir));
    int balance = fatorBalanceamento(raiz);

    if(balance > 1 && categoria < raiz->filho_esq->categoria){
        return rotacaoDireita(raiz);
    }
    if(balance < -1 && categoria > raiz->filho_dir->categoria){
        return rotacaoEsquerda(raiz);
    }
    if(balance > 1 && categoria > raiz->filho_esq->categoria){
        raiz->filho_esq = rotacaoEsquerda(raiz->filho_esq);
        return rotacaoDireita(raiz);
    }
    if(balance < -1 && categoria < raiz->filho_dir->categoria){
        raiz->filho_dir = rotacaoDireita(raiz->filho_dir);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}

void buscaCategoria(NO *raiz, int categoria){
    if(raiz == NULL){
      
    }else{
        if(raiz->categoria == categoria){
            printf("Categoria %d\n",raiz->categoria);
            imprimirLista(raiz->lista_palavras);
        }
        if(raiz->filho_esq != NULL){
            buscaCategoria(raiz->filho_esq,categoria);
        }
        if(raiz->filho_dir != NULL){
            buscaCategoria(raiz->filho_dir,categoria);
        }
    }
}
