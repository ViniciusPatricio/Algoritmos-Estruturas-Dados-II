#include "stdio.h"
#include "stdlib.h"
#include "math.h"


typedef struct no NO;
struct no{
    int chave;
    int altura;
    struct no *esq;
    struct no *dir;
};

int altura(NO *no){
    if(no==NULL){
        return 0;
    }
    return no->altura;
}
int maior(int x,int y){
    return x>y? x : y;
}

NO *criarNo(int chave){
    NO *novo_no=malloc(sizeof(NO));
    novo_no->chave=chave;
    novo_no->esq=NULL;
    novo_no->dir=NULL;
    novo_no->altura=1;

    return novo_no;
}

NO *rotacaoDireita(NO *raiz){
    NO *x=raiz->esq;
    NO *y=x->dir;

    x->dir=raiz;
    raiz->esq=y;    

    raiz->altura=maior(altura(raiz->esq),altura(raiz->dir)) + 1;
    x->altura=maior(altura(x->esq),altura(x->dir)) + 1;

    return x;
}

NO *rotacaoEsquerda(NO *raiz){
    NO *x=raiz->dir;
    NO *y=x->esq;

    x->esq=raiz;
    raiz->dir=y;

    raiz->altura=maior(altura(raiz->dir),altura(raiz->esq))+1;
    x->altura=maior(altura(x->dir),altura(x->esq))+1;

    return x;
}

int fatorBalanceameto(NO *no){
    if(no==NULL){
        return 0;
    }
    return altura(no->esq)-altura(no->dir);
}

NO *inserirAVL(NO *raiz, int chave){
    if(raiz==NULL){
        return criarNo(chave);
    }
    if(chave < raiz->chave){
        raiz->esq = inserirAVL(raiz->esq,chave);
    } else if(chave > raiz->chave){
        raiz->dir = inserirAVL(raiz->dir,chave);
    }else{
        return raiz;
    }

    raiz->altura= 1 + maior(altura(raiz->esq),altura(raiz->dir));
    int balance = fatorBalanceameto(raiz);

    if(balance > 1 && chave < raiz->esq->chave){
        printf("Rotacao a direita\n");
        return rotacaoDireita(raiz);
    }
    if(balance < -1 && chave > raiz->dir->chave){
        printf("Rotcao a esquerda\n");
        return rotacaoEsquerda(raiz);
    }
    if(balance > 1 && chave > raiz->esq->chave){
        printf("Rotacao a direita\n");
        raiz->esq=rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }
    if(balance < -1 && chave < raiz->dir->chave){
        raiz->dir=rotacaoDireita(raiz->dir);
        printf("Rotacao a esquerda\n");
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}


void imprimirFatorBalanceamento(NO *raiz){
    if(raiz!=NULL){
       imprimirFatorBalanceamento(raiz->esq);
       printf("%d(%d) ",raiz->chave,raiz->altura);
       imprimirFatorBalanceamento(raiz->dir);
    }
}

int main(){
    
    NO *raiz=NULL;
    raiz=inserirAVL(raiz,5);
    raiz=inserirAVL(raiz,4);
    raiz=inserirAVL(raiz,3);
    raiz=inserirAVL(raiz,6);
    raiz=inserirAVL(raiz,7);
    raiz=inserirAVL(raiz,8);
  

    imprimirFatorBalanceamento(raiz);
}



