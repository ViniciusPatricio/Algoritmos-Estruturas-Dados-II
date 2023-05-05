// Al: Vinícius Patrício Medeiros da Silva
// nº: 21951799

#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0

typedef int bool; // foi definido bool para fica mais organizados as comparações, ao invés de ficar trabalhando com flags

typedef struct no No;
struct no{
    int chave;
    struct no *filho_esq, *filho_dir;
    int fator_bal; // fator de balanceamento (0,-1, ou 1)  adptação para árvore AVL (item b) )
};

No *criarArvore(){
    return NULL;
}

No *criarNo(int chave){
    No *novo_no=malloc(sizeof(No));
    novo_no->filho_esq=NULL;
    novo_no->filho_dir=NULL;
    novo_no->chave=chave;
    novo_no->fator_bal=0;

    return novo_no;
}

int maior(int a, int b){ // função criada para auxiliar a função da altura
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int altura(No *raiz){
    if(raiz==NULL) return -1; // isso retorna  -1 devido ao fato de uma árvore com apenas a raiz ter altura igual a zero
    else return 1 +maior(altura(raiz->filho_esq),altura(raiz->filho_dir)); // aqui vai verificar qual vai ser a maior altura
}

No *inserirArvore(No *raiz, No *novo_no){
    if(raiz == NULL){
        return novo_no;
    }else if(raiz->chave > novo_no->chave){
        raiz->filho_esq = inserirArvore(raiz->filho_esq,novo_no);
    }else{
        raiz->filho_dir = inserirArvore(raiz->filho_dir,novo_no);
    }
    return raiz;
}

void imprimirArvore(No *raiz){
    printf("(");
    if(raiz!=NULL){
        printf("%d",raiz->chave);
        
        imprimirArvore(raiz->filho_esq);
        imprimirArvore(raiz->filho_dir);
      
    }
     printf(")");
}

bool verificaAVL(No *raiz){
    int i,j;
    bool check = true;
    if(raiz){
        check = verificaAVL(raiz->filho_esq);
        
        if(check){
            check=verificaAVL(raiz->filho_dir);
        }
        if(check){
            i=altura(raiz->filho_esq);
            j=altura(raiz->filho_dir);    
            if( i-j> 1 ||  i-j <-1){
                check=false;
            }else{
                check=true;
            }       
        }

    }
   return check;
}

int atualizarBalanceamento(No *raiz){
    if(raiz==NULL){
        return 0;
    }
    int i = atualizarBalanceamento(raiz->filho_dir);
    int j = atualizarBalanceamento(raiz->filho_esq);
    raiz->fator_bal = i - j;
    return maior(i,j)+1;
}
void imprimirFatorBalanceamento(No *raiz){
    if(raiz!=NULL){
       imprimirFatorBalanceamento(raiz->filho_esq);
       printf("%d(%d) ",raiz->chave,raiz->fator_bal);
       imprimirFatorBalanceamento(raiz->filho_dir);
    }
}
No *rotacaoEsquerda(No *p){
	
	No *u, *v;
	u = p->filho_esq;
    printf("Rotacao a esquerda\n");
	if(u->fator_bal == -1) {   // LL
		p->filho_esq = u->filho_dir;
		u->filho_dir = p;
		p->fator_bal = 0;
		u->fator_bal = 0;
		return u;
	} else if (u->fator_bal == 1) {  // LR
		v = u->filho_dir;
		u->filho_dir = v->filho_esq;
		v->filho_esq = u;
		p->filho_esq = v->filho_dir;
		v->filho_dir = p;
		if(v->fator_bal == -1) p->fator_bal = 1;
		else p->fator_bal = 0;
		if(v->fator_bal == 1) u->fator_bal = -1;
		else u->fator_bal = 0;
		v->fator_bal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
		p->filho_esq = u->filho_dir;
		u->filho_dir = p;
		// p->bal = -1;    desnecessario pois o balanceamento de p nao chegou a ser mudado para -2
		u->fator_bal = 1;
		return u;
	}
}
No *rotacaoR(No *p){
	printf("Rotacao a direita\n");
	No *u, *v;
	u = p->filho_dir;
	if(u->fator_bal == 1) {   // RR
		p->filho_dir = u->filho_esq;
		u->filho_esq = p;
		p->fator_bal = 0;
		u->fator_bal = 0;
		return u;
	} else if (u->fator_bal == -1){  // RL
		v = u->filho_esq;
		u->filho_esq = v->filho_dir;
		v->filho_dir = u;
		p->filho_dir = v->filho_esq;
		v->filho_esq = p;
		if(v->fator_bal == 1) p->fator_bal = -1;
		else p->fator_bal = 0;
		if(v->fator_bal == -1) u->fator_bal = 1;
		else u->fator_bal = 0;
		v->fator_bal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
		p->filho_dir = u->filho_esq;
		u->filho_esq = p;
		u->fator_bal = -1;
		// p->bal = 1;    desnecessario pois o balanceamento de p nao chegou a ser mudado para 2
		return u;	
	}
}

int main(){

No *raiz=criarArvore();
No *no;
// construção da árvore
no=criarNo(5);
raiz=inserirArvore(raiz,no);
atualizarBalanceamento(raiz);


no=criarNo(4);
raiz=inserirArvore(raiz,no);
atualizarBalanceamento(raiz);


no=criarNo(3);
raiz=inserirArvore(raiz,no);
atualizarBalanceamento(raiz);


no=criarNo(6);
raiz=inserirArvore(raiz,no);
atualizarBalanceamento(raiz);


no=criarNo(7);
raiz=inserirArvore(raiz,no);
atualizarBalanceamento(raiz);


no=criarNo(8);
raiz=inserirArvore(raiz,no);
atualizarBalanceamento(raiz);


printf("\naltura: %d\n",altura(raiz));
imprimirArvore(raiz);
(verificaAVL(raiz)==true) ? printf("\nArvore balanceada\n") : printf("\nArvore nao balanceado\n");

atualizarBalanceamento(raiz);
imprimirFatorBalanceamento(raiz);


}