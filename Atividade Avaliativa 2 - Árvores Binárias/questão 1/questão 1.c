#include "stdio.h"
#include "stdlib.h"
#include "lista_neutra.h"


typedef struct no No;
struct no{   
    int chave;
    struct no *filho_esq, *filho_dir;
};

int contador_folhas;
int flag_busca;



No *criarArvore(){
    return NULL;
}

No *criarNo(int chave){
    No *novo_no=malloc(sizeof(No));
    novo_no->chave=chave;
    novo_no->filho_esq=NULL;
    novo_no->filho_dir=NULL;

    return novo_no;
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
void destuirNo(void *no){
    No *no_aux=no;
    no_aux->filho_esq=NULL;
    no_aux->filho_dir=NULL;
    free(no);
}

void largura(No *raiz){
    No *no_aux; 
    TLista *lista=criarListaEncadeada();  // lista que vai auxiliar no percorrimento
    inserirFim(lista,raiz);  // vai inserir na lista
    do{
        no_aux=primeiroLista(lista); // recebe o primeiro no da lista
        removerInicio(lista,destuirNo); // tira o primeiro no da lista
        if(no_aux!=NULL){  // esse no é vazio?
            printf("%d ",no_aux->chave);
            inserirFim(lista,no_aux->filho_esq);  // insere a sub-árvore esq da árvore
            inserirFim(lista,no_aux->filho_dir); // insere a sub-árvore dir da árvore
        }

    }while(quantidadeLista(lista)!=0); // vai continuar até a lista não ser vazia
}



int contaFolhas(No *raiz){
    if(raiz!=NULL){
        if(raiz->filho_esq!=NULL){
            contaFolhas(raiz->filho_esq);
        }

        if(raiz->filho_dir!=NULL){
            contaFolhas(raiz->filho_dir);
        }else if (raiz->filho_esq==NULL){
            contador_folhas++;
        }

    }
}

int busca(No *raiz, int chave){
    if(raiz!=NULL && flag_busca==0){
        
        if(raiz->chave==chave){
            return flag_busca=1;
        }

        if(raiz->filho_esq!=NULL){
            busca(raiz->filho_esq, chave);
        }

        if(raiz->filho_dir!=NULL){
            busca(raiz->filho_dir, chave);
        }

    }
    return flag_busca;
}

No *inserirArvoreInvertido(No *raiz, No *novo_no){
    if(raiz == NULL){
        return novo_no;
    }else if(raiz->chave < novo_no->chave){
        raiz->filho_esq = inserirArvoreInvertido(raiz->filho_esq,novo_no);
    }else{
        raiz->filho_dir = inserirArvoreInvertido(raiz->filho_dir,novo_no);
    }
    return raiz;
}


/* para que retorne outra árvore Raiz, mas com as sub-árvores esquerda e direita de todos os nós trocadas, basta pensarmos
 em trocar a desigualdalde na inserção, assim  será trocado cada sub-árvore. Para isso, devemos acessar cada elmento da árvore 
 dada na chama da função, neste caso eu pensei em  percorrer pela largura.
*/
No *espelho(No *raiz){
    No *raiz_nova=criarArvore();
    No *no_aux;
    TLista *lista=criarListaEncadeada();
    inserirFim(lista,raiz);
    do{
        no_aux=primeiroLista(lista);
        removerInicio(lista,destuirNo);
        if(no_aux!=NULL){
            No *no_aux2=criarNo(no_aux->chave);
            raiz_nova=inserirArvoreInvertido(raiz_nova,no_aux2);
            inserirFim(lista,no_aux->filho_esq);
            inserirFim(lista,no_aux->filho_dir);
        }

    }while(quantidadeLista(lista)!=0);

    return raiz_nova;
}
   

 

int main(){

    
    flag_busca=0;
    contador_folhas=0;


    int numero_elementos;

    printf("Digite o Numero de elementos da arvore: ");
    scanf("%d",&numero_elementos);

    No *raiz_espelho=criarArvore();
    No *raiz=criarArvore();
    int elemento;
    printf("Digite os elementos da arvore:\n");

    for(int i=0;i<numero_elementos;i++){
        scanf("%d",&elemento);
        
        No *novo_no=criarNo(elemento);
        raiz=inserirArvore(raiz,novo_no);
    }

    imprimirArvore(raiz);
    printf("\nNumero de folhas: %d",contaFolhas(raiz));
    
    printf("\nDigite um valor a ser verificado na arvore: ");
    int chave_verificar;
    scanf("%d",&chave_verificar);
    
    printf("\nO valor esta na arvore?");
    busca(raiz,chave_verificar) == 1? printf(" Sim\n") : printf(" Nao\n");

    printf("Percorrendo pela largura: ");
    largura(raiz);
    raiz_espelho=espelho(raiz);
    printf("\nRaiz espelhada: ");
    imprimirArvore(raiz_espelho);
}

