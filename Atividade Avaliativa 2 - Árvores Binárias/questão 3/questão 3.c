#include "stdio.h"
#include "stdlib.h"
#include "lista_neutra.h"

typedef struct no No;
struct no{   
    int chave;
    struct no *filho_esq, *filho_dir;
};

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

No *minimo(No *raiz){
    No *no_aux;
    No *no_min=raiz; 
    TLista *lista=criarListaEncadeada();  // lista que vai auxiliar no percorrimento
    inserirFim(lista,raiz);  // vai inserir na lista
    do{
        no_aux=primeiroLista(lista); // recebe o primeiro no da lista
        removerInicio(lista,destuirNo); // tira o primeiro no da lista
        if(no_aux!=NULL){  // esse no é vazio?
            if(no_min->chave>no_aux->chave){
                no_min=no_aux;
            }
            inserirFim(lista,no_aux->filho_esq);  // insere a sub-árvore esq da árvore
            inserirFim(lista,no_aux->filho_dir); // insere a sub-árvore dir da árvore
        }

    }while(quantidadeLista(lista)!=0); // vai continuar até a lista não ser vazia

    return no_min;
}

int existeChaveNegativa(No *raiz){
    int flag=0;
    No *no_aux;
    TLista *lista=criarListaEncadeada();  // lista que vai auxiliar no percorrimento
    inserirFim(lista,raiz);  // vai inserir na lista
    do{
        no_aux=primeiroLista(lista); // recebe o primeiro no da lista
        removerInicio(lista,destuirNo); // tira o primeiro no da lista
        if(no_aux!=NULL){  // esse no é vazio?
            if(no_aux->chave<0){
                flag=1;
                break;
            }
            inserirFim(lista,no_aux->filho_esq);  // insere a sub-árvore esq da árvore
            inserirFim(lista,no_aux->filho_dir); // insere a sub-árvore dir da árvore
        }

    }while(quantidadeLista(lista)!=0); // vai continuar até a lista não ser vazia

    return flag;

}

int verificaBusca(No *raiz){
   int flag=1;
    No *no_aux;
    TLista *lista=criarListaEncadeada();  // lista que vai auxiliar no percorrimento
    inserirFim(lista,raiz);  // vai inserir na lista
    do{
        no_aux=primeiroLista(lista); // recebe o primeiro no da lista
        removerInicio(lista,destuirNo); // tira o primeiro no da lista
        if(no_aux!=NULL){  // esse no é vazio?                    
            if(no_aux->filho_dir!=NULL && no_aux->chave > no_aux->filho_dir->chave ){
                flag=0;
                break;
            }
            
            if(no_aux->filho_esq!=NULL && no_aux->chave < no_aux->filho_esq->chave ){
                flag=0;
                break;
            }
        
            inserirFim(lista,no_aux->filho_esq);  // insere a sub-árvore esq da árvore
            inserirFim(lista,no_aux->filho_dir); // insere a sub-árvore dir da árvore
        }

    }while(quantidadeLista(lista)!=0); // vai continuar até a lista não ser vazia

    return flag;  
}

int main(){

    /*arvore criada manualmente
                5
               /  \
              4   7
              /   / \  
             2    6  8         
             \
              3


    */

    No *raiz=criarArvore();
    raiz=criarNo(5);
    raiz->filho_esq=criarNo(4);
    raiz->filho_esq->filho_esq=criarNo(2);
    raiz->filho_esq->filho_esq->filho_dir=criarNo(3);
    raiz->filho_dir=criarNo(7);
    raiz->filho_dir->filho_esq=criarNo(6);
    raiz->filho_dir->filho_dir=criarNo(8);
    

    

    No *no_min=minimo(raiz);
    printf("Menor elemento da arvore: %d\n",no_min->chave);
    printf("Existe chave negativa? ");
    existeChaveNegativa(raiz) == 1 ? printf("Sim\n") : printf("Nao\n");
    printf("Eh uma arvore? ");
    verificaBusca(raiz) == 1? printf("Sim\n") : printf("Nao\n");

    
    printf("\nO grafo1 criado eh uma arvore? ");
    /* a seguir sera implementado um grafo que não é uma árvore, tal grafo é dado por:
      
                        5
                       /  \
                      7   8
                     /   / \
                    3    3  2
    */
   No *grafo1=criarArvore();
   grafo1=criarNo(5);
   grafo1->filho_esq=criarNo(7);
   grafo1->filho_esq->filho_esq=criarNo(3);
   grafo1->filho_dir=criarNo(8);
   grafo1->filho_dir->filho_esq=criarNo(3);
   grafo1->filho_dir->filho_dir=criarNo(2);

    verificaBusca(grafo1) == 1? printf("Sim\n") : printf("Nao\n");
    no_min=minimo(grafo1);
    printf("Menor elemento da grafo: %d\n",no_min->chave);
    printf("Existe chave negativa? ");
    existeChaveNegativa(grafo1) == 1 ? printf("Sim\n") : printf("Nao\n");

    printf("\ngrafo2 criado eh uma arvore?\n");

    /* a seguir sera implementado um grafo que não é uma árvore, tal grafo é dado por:
      
                        5
                       /  \
                      4   8
                     /   / \
                    -3    3  2
    */

    No *grafo2=criarArvore();
   grafo2=criarNo(5);
   grafo2->filho_esq=criarNo(4);
   grafo2->filho_esq->filho_esq=criarNo(-3);
   grafo2->filho_dir=criarNo(8);
   grafo2->filho_dir->filho_esq=criarNo(3);
   grafo2->filho_dir->filho_dir=criarNo(2);

   verificaBusca(grafo2) == 1? printf("Sim\n") : printf("Nao\n");
    no_min=minimo(grafo2);
    printf("Menor elemento da grafo: %d\n",no_min->chave);
    printf("Existe chave negativa? ");
    existeChaveNegativa(grafo2) == 1 ? printf("Sim\n") : printf("Nao\n");

}
