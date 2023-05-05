#include "stdio.h"
#include "stdlib.h"

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

typedef int (*TCompara)(void*,void*);

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

void *primeiroLista(TLista *lista){
    return lista->inicio->carga_util;
}

void *ultimoLista(TLista *lista){
    return lista->fim->carga_util;
}

void *buscaPosicao(TLista *lista,int pos){
    if(pos==1){
        primeiroLista(lista);
    }else if(pos==lista->qtde){
        ultimoLista(lista);
    }else if(pos>1 && pos<lista->qtde){
        int i=1;
        TELE *caminhador=lista->inicio;

        while(i!=pos){
            caminhador=caminhador->prox;
            i++;
        }
        return caminhador->carga_util;

    }else{
        printf("Posicao invalida\n");
    }
}



// *********************** MEDIDA CRIADA PARA EXEMPLO  *********************** //

typedef struct medida TMedida;
struct medida{
    int num;
};

TMedida *criarMedida(int num){
    TMedida *medida=malloc(sizeof(TMedida));
    medida->num=num;

    return medida;
}


int filaVazia(TLista *fila){
    int contador=0;

    for(int i=0;i<fila->qtde;i++){
        TMedida *medida=buscaPosicao(fila,i+1);
        if(medida->num==0){
            contador++;
        }

    }
    if(contador==fila->qtde){
        return 1;
    }else{
        return 0;
    }
}
int zeros_fila(TLista *fila){
    int contador=0;

    for(int i=0;i<fila->qtde;i++){
        TMedida *medida=buscaPosicao(fila,i+1);
        if(medida->num==0){
            contador++;
        }

    }
    return contador;
}

// ***************************** Main  ******************************* //
int main(){

    TLista *fila=criarListaEncadeada();
    int tempo_determinado;
    int tempo_aluno;

    scanf("%d",&tempo_determinado);
    while(scanf("%d",&tempo_aluno),tempo_aluno!=-3)
    {
        TMedida *nova_medida=criarMedida(tempo_aluno);
        inserirFim(fila,nova_medida);
    }
    
    TELE *caminhador=fila->inicio;
    int tempo_geral=0;
        
    while(filaVazia(fila)==0)
    {

    
        for(int i=0;i<fila->qtde;i++)
        { 
         TMedida *medida=buscaPosicao(fila,i+1);
            
            if(medida->num>tempo_determinado)
            {
                tempo_geral+=tempo_determinado;
                medida->num=medida->num-tempo_determinado;
            }else if(medida->num>0 && medida->num<=tempo_determinado && filaVazia(fila)==0 && zeros_fila(fila)!=fila->qtde-1)
            {
                tempo_geral+=tempo_determinado;
                medida->num=0;
            }else if(medida->num<tempo_determinado && zeros_fila(fila)==fila->qtde-1){
                tempo_geral+=medida->num;
                medida->num=0;
            }

        }
    }  
       printf("%d\n", tempo_geral);
      
    
}