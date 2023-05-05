#include "stdio.h"
#include "stdlib.h"

#define true 1
#define false 0

typedef struct Elemento_Arvore NO;  
typedef int bool;

struct Elemento_Arvore{
    int chave;         // conteúdo carregado, neste caso vai ser um valor inteiro
    NO *esq, *dir;  // os ramos de cada NO da Arvore
};

NO *Criar_Arvore(){
    return NULL;
}
NO *Adicionar_Arvore(NO *raiz, NO *novo_no){
    if(raiz==NULL){
        return novo_no;
    } else if(novo_no->chave <raiz->chave){ 
        raiz->esq=Adicionar_Arvore(raiz->esq, novo_no);
    }else{   
         raiz->dir=Adicionar_Arvore(raiz->dir,novo_no);     
    }
    return raiz;
}

NO *Busca(int chave,NO *raiz){
    if(raiz==NULL){
        return NULL;     
    }else if (raiz->chave==chave){
        return raiz;
    }else if (raiz->chave>chave){
        return(Busca(chave,raiz->esq));
    }else{
        return(Busca(chave,raiz->dir));
    }
}

NO *Criar_NO(int num){
    NO *novo_no=malloc(sizeof(NO));
    novo_no->dir=NULL;
    novo_no->esq=NULL;
    novo_no->chave=num;

    return novo_no;
}

void Verifica_Busca(int chave, NO *raiz){
    if(Busca(chave,raiz)==NULL){
        printf("A chave nao esta na arvore. \n");
    }else{
        printf("A chave esta na arvore.\n");
    }
}

int Numero_Nos(NO *raiz){
    if (raiz==NULL){
        return 0;
    }else{
        return(Numero_Nos(raiz->esq))
        +1
        + Numero_Nos(raiz->dir);
    }
}

void Exibir_Arvore(NO *raiz){
    if(raiz!=NULL){
       printf("%d",raiz->chave);
       printf("(");
       Exibir_Arvore(raiz->esq);
       Exibir_Arvore(raiz->dir);
       printf("(");
    }
}

int main(){

    NO *raiz=Criar_Arvore();  // criando a raiz da árvore
    int numero_elementos,i;  // i será usado como contador

    printf("Digite o numero de elemento: ");
    scanf("%d",&numero_elementos);

//******************* ADICIONADO ELEMENTOS NA ÁRVORE ******************** //
    for(i=0;i<numero_elementos;i++){
        int chave; NO *novo_no;
     
       printf("Digite o numero a ser adicionado:"); 
        scanf("%d",&chave);
       
        novo_no=Criar_NO(chave);
        raiz=Adicionar_Arvore(raiz,novo_no);
       
        printf("Numero adicionado\n");
    }
//*********************************************************************** //



//*******************  BUSCANDO ELEMENTO NA ÁRVORE  ******************** //
    int num_busca;
    printf("Digite o numero a ser buscado:");
    scanf("%d",&num_busca);

    Verifica_Busca(num_busca,raiz);

//*********************************************************************** //  
    
    Exibir_Arvore(raiz);
}