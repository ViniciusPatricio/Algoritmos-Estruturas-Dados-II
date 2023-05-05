#include "stdio.h"
#include "stdlib.h"

#define RED 1
#define BLACK 0

typedef struct NO No;

struct NO{
    int info;
    No *esq;
    No *dir;
    int cor;
};

int corNo(No *H){
    return  H == NULL ? BLACK : H->cor;
}

void trocaCor(No *H){
    H->cor = !H->cor;
    
    if(H->esq != NULL){
        H->esq->cor = !H->esq->cor;
    }
    if(H->dir != NULL){
        H->dir->cor = !H->dir->cor;
    }
}

// funções de rotações 

struct NO* rotacionaEsquerda(No* A){
    No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;

    return B;
}

struct NO* rotacionaDireita(No *A){
    No *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;

    return B;
}

No* move2EsqRED( No *H){
    trocaCor(H);
    if(corNo(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

No* move2DirRED(No *H){
    trocaCor(H);
    if(corNo(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}


No* balancear(No *H){
    if(corNo(H->dir) == RED){
        H = rotacionaEsquerda(H);
    }
    if(H->esq != NULL && corNo(H->dir) == RED  && corNo(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    if(corNo(H->esq) == RED && corNo(H->dir) == RED){
        trocaCor(H);
    }
    return H;
}

No *insereNo(No *H, int valor,int *resp){
    if(H == NULL){
        No *novo=malloc(sizeof(No));
        if(novo == NULL){
            *resp= 0;
            return NULL;
        }
        novo->info = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }
    if(valor == H->info){
        *resp=0;
    }
    else{
        if(valor<H->info){
            H->esq = insereNo(H->esq,valor,resp);
        }else{
            H->dir = insereNo(H->dir,valor,resp);
        }
    }

    if(corNo(H->dir) == RED && corNo(H->esq) == BLACK)
        H = rotacionaEsquerda(H);
    if(corNo(H->esq) == RED && corNo(H->esq->esq) == RED)
        H = rotacionaDireita(H);
    if(corNo(H->esq) == RED && corNo(H->dir) == RED)
        trocaCor(H);
    return H;
}

int insere_ArvLLRB(No *raiz, int valor){
    int resp;
    raiz = insereNo(raiz,valor,&resp);
    if(raiz != NULL){
        raiz->cor = BLACK;
    }
    return resp;
}



int main(){

    No *raiz = NULL;

    insere_ArvLLRB(raiz,5);















    return 0;
}