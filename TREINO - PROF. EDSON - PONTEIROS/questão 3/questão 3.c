#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

// *********************** FUNÇÕES DE CRIAÇÃO  *********************** //

TELE *criarElementoLista(void *carga){
    TELE *elemento_lista=malloc(sizeof(TELE));
    
    elemento_lista->carga_util=carga;
    elemento_lista->prox=NULL;
    return elemento_lista;
}

TLista *criarListaEncadeada(){
    TLista *lista=malloc(sizeof(TLista));
    
    lista->fim=NULL;
    lista->inicio=NULL;
    lista->qtde=0;
    
    return lista;
}

// *********************** FUNÇÕES DE INSERÇÃO  *********************** //

void inserirFim(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);

    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        lista->fim->prox=carga_util;
        lista->fim=carga_util;
    }
    lista->qtde++;
}
void inserirInicio(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);
    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        carga_util->prox=lista->inicio;
        lista->inicio=carga_util;
    }
    lista->qtde++;
}

// *********************** MEDIDA CRIADA   *********************** //
typedef struct medida TMedida;
struct medida{
    char string[1000];
};

TMedida *criarMedida(char palavra[],int tam){
    TMedida *nova_medida=malloc(sizeof(TMedida));
    for(int i=0;i<tam;i++){
        nova_medida->string[i]=palavra[i];
    }
    return nova_medida;
}
void imprimirTMedida(TMedida *medida){
    for(int i=0;i<strlen(medida->string);i++){
        printf("%c",medida->string[i]);
    }
}
void imprimirString(char palavra[],int tam){
    for(int i=0;i<tam;i++){
        printf("%c",palavra[i]);
    }
    printf("\n");
}
int main(){
    char frase[1000];
    int numero_espacos=0;
    TLista *lista=criarListaEncadeada();
    scanf("%[^\n]%*c", frase);
    for(int i=0;frase[i]!='\0';i++){
       if(frase[i]==' '){
           numero_espacos++;
       }
    }

    char palavra[1000];
    int j=0;
    for(int i=0;i<strlen(frase);i++){
        if(frase[i]!=' '){
            palavra[j]=frase[i];
            j++;
        }else{
            TMedida *medida=criarMedida(palavra,j);    
            inserirFim(lista,medida);
            
        }
    }
    
}