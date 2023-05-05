#include "stdio.h"
#include "stdlib.h"
#include "lista_neutra.h"
#include "string.h"

typedef struct no No;
struct no{   
    char chave[2];
    struct no *filho_esq, *filho_dir;
};

No *criarArvore(){
    return NULL;
}

No *criarNo(char chave[]){
    No *novo_no=malloc(sizeof(No));
    novo_no->chave[0]=chave[0];
    novo_no->chave[1]=chave[1];
    novo_no->filho_esq=NULL;
    novo_no->filho_dir=NULL;

    return novo_no;
}

void destuirNo(void *no){
    No *no_aux=no;
    no_aux->filho_esq=NULL;
    no_aux->filho_dir=NULL;
    free(no);
}

int verificaOperador(char operador[]){     //+, -, * ou /, **
    int flag=0;
    if(operador[0]=='*' || operador[0]=='-' || operador[0]=='*' || operador[0]=='/' && operador[1]=='\0'){
        flag=1;
    }
    if(operador[0]=='*' && operador[1]=='*'){
        flag=1;
    }
    return flag;
}
int verificaFolha(No *no){
    int flag=0;
    
    if(no->filho_esq==NULL || no->filho_dir==NULL){
        return flag=1;
    }
    
    return flag;
}


int expr_valida(No *raiz){
    int flag=1;
    No *no_aux;
    TLista *lista=criarListaEncadeada();  // lista que vai auxiliar no percorrimento
    inserirFim(lista,raiz);  // vai inserir na lista
    do{
        no_aux=primeiroLista(lista); // recebe o primeiro no da lista
        removerInicio(lista,destuirNo); // tira o primeiro no da lista
        if(no_aux!=NULL){  // esse no é vazio? 
            if(verificaFolha(no_aux)==1 && verificaOperador(no_aux->chave)==1){ // verifica se o operador é uma folha, caso seja, essa árvore de operação ta errada
                flag=0;
                break;
            }                                  
            inserirFim(lista,no_aux->filho_esq);  // insere a sub-árvore esq da árvore
            inserirFim(lista,no_aux->filho_dir); // insere a sub-árvore dir da árvore
        }

    }while(quantidadeLista(lista)!=0); // vai continuar até a lista não ser vazia

    if(raiz==NULL){ // se a arvore for vazia então não é válida
        flag=0;
    }

    return flag;
    
}
void imprimirChave(char chave[]){
    printf("%s",chave);
}

void percursoPreOrdem(No *raiz){
    if(raiz!=NULL){
        imprimirChave(raiz->chave);
        printf(" ");
        percursoPreOrdem(raiz->filho_esq);
        percursoPreOrdem(raiz->filho_dir);
    }
}
void percursoPosOrdem(No *raiz){
    if(raiz!=NULL){
        percursoPosOrdem(raiz->filho_esq);
        percursoPosOrdem(raiz->filho_dir);
        imprimirChave(raiz->chave);
        printf(" ");
    }
}

int main(){

/* árvore de operação dada no enunciado

            [*]
          /      \
        [+]        [-]
       /  \       /     \
      [a]  [b]   [-]       [*]
                /    \    /    \
               [c]  [d]   [e]  [f]

     (a+b) * (c - d) - e * f
*/


No *raiz=criarArvore();
char entrada[2];
entrada[0]='*';
raiz=criarNo(entrada);
entrada[0]='+';
raiz->filho_esq=criarNo(entrada);
entrada[0]='a';
raiz->filho_esq->filho_esq=criarNo(entrada);
entrada[0]='b';
raiz->filho_esq->filho_dir=criarNo(entrada);
entrada[0]='-';
raiz->filho_dir=criarNo(entrada);
entrada[0]='-';
raiz->filho_dir->filho_esq=criarNo(entrada);
entrada[0]='c';
raiz->filho_dir->filho_esq->filho_esq=criarNo(entrada);
entrada[0]='d';
raiz->filho_dir->filho_esq->filho_dir=criarNo(entrada);
entrada[0]='*';
raiz->filho_dir->filho_dir=criarNo(entrada);
entrada[0]='e';
raiz->filho_dir->filho_dir->filho_esq=criarNo(entrada);
entrada[0]='f';
raiz->filho_dir->filho_dir->filho_dir=criarNo(entrada);

printf("A arvore de expressao  (a+b) * (c - d) - e * f e valida: ");
expr_valida(raiz)==1? printf("Sim\n") : printf("Nao\n");
printf("Percurso Pre ordem: ");
percursoPreOrdem(raiz);
printf("\nPercurso Pos ordem: ");
percursoPosOrdem(raiz);
/* árvore de operação inválida para ver se a função expr_valida está funcionando

            [*]
          /      \
        [/]      [-]
       /   \      /   \
      [a]  [b]   [a]   [*]
                   
      (a**b)*(a-*)           
*/
No *raiz1=criarArvore();
entrada[0]='*';
raiz1=criarNo(entrada);
entrada[0]='/';
raiz1->filho_esq=criarNo(entrada);
entrada[0]='a';
raiz1->filho_esq->filho_esq=criarNo(entrada);
entrada[0]='b';
raiz1->filho_esq->filho_dir=criarNo(entrada);
entrada[0]='-';
raiz1->filho_dir=criarNo(entrada);
entrada[0]='a';
raiz1->filho_dir->filho_esq=criarNo(entrada);
entrada[0]='*';
raiz1->filho_dir->filho_dir=criarNo(entrada);

printf("\n");
printf("\nA arvore de expressao  (a/b)*(a-*) e valida: ");
expr_valida(raiz1)==1? printf("Sim\n") : printf("Nao\n");
printf("Percurso Pre ordem: ");
percursoPreOrdem(raiz1);
printf("\nPercurso Pos ordem: ");
percursoPosOrdem(raiz1);
}