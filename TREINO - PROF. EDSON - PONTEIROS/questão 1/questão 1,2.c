    #include "stdio.h"
    #include "stdlib.h"

    typedef struct Elemento_Lista TELE;
    struct Elemento_Lista{
        int carga;
        void *prox;
    };

    typedef struct Lista_Encadeada TLista;
    struct Lista_Encadeada{
        int qtde;
        TELE *inicio;
        TELE *fim;
    };

    // *********************** FUNÇÕES DE CRIAÇÃO  *********************** //
    TELE *criarElementoLista(int num){
        TELE *Elemento_Lista=malloc(sizeof(TELE));

        Elemento_Lista->carga=num;
        Elemento_Lista->prox=NULL;

        return Elemento_Lista;
    }
    TLista *criarLista(){
        TLista *lista=malloc(sizeof(TLista));

        lista->inicio=NULL;
        lista->fim=NULL;
        lista->qtde=0;

        return lista;
    }

    // *********************** FUNÇÕES DE INSERÇÃO  *********************** //
    void inserirFim(TLista *lista, int carga){
        TELE *elemento_novo=criarElementoLista(carga);

        if(lista->inicio==NULL){
            lista->inicio=elemento_novo;
            lista->fim=elemento_novo;
        }else{
            lista->fim->prox=elemento_novo;
            lista->fim=elemento_novo;
        }
        lista->qtde++;
    }
    // *********************** FUNÇÕES DIVERSAS  *********************** //
    void imprimirLista(TLista *lista){
        TELE *cam=lista->inicio;
        while(cam!=NULL){
            printf("%d ",cam->carga);
            cam=cam->prox;
        }
    }

    int busca(TLista *lista, int num){
        TELE *cam=lista->inicio;
        int flag=0;
        while(cam!=NULL){
            if(cam->carga==num){
                flag=1;
            }
            cam=cam->prox;
        }
        return flag;
    }
    
    TLista *listaUniao(TLista *l1, TLista *l2){
        TLista *lista=criarLista();
        TELE *cam1=l1->inicio;
        while(cam1!=NULL){
            inserirFim(lista,cam1->carga);
            cam1=cam1->prox;
        }
        TELE *cam2=l2->inicio;
        while(cam2!=NULL){
            if(busca(l1,cam2->carga)==0){
                inserirFim(lista,cam2->carga);
            }
            cam2=cam2->prox;
        }
        return lista;
    }
        
    TLista *listaIntersecao(TLista *l1,TLista *l2){
        TLista *lista=criarLista();
        TELE *cam = l2->inicio;
        while(cam!=NULL){
            if(busca(l1,cam->carga)==1){
                inserirFim(lista,cam->carga);
            }
            cam=cam->prox;
        }
        return lista;
    }

    void elementoRepetido(TLista *lista){
        TELE *cam=lista->inicio;
        while(cam!=NULL){
            TELE *cam1=lista->inicio;
            TELE *anterior=NULL;
            while(cam1!=NULL){
                if(cam1->carga==cam->carga && cam1!=cam){
                    anterior->prox=cam1->prox;
                }
                anterior=cam1;
                cam1=cam1->prox;
            }
            cam=cam->prox;
        }
 }

    int main(){
        TLista *lista1=criarLista();
        TLista *lista2=criarLista();
        int entrada;

        while(scanf("%d",&entrada),entrada!=0){
            inserirFim(lista1,entrada);
        }
        while(scanf("%d",&entrada),entrada!=0){
            inserirFim(lista2,entrada);
        }
        printf("Lista 1: ");
        imprimirLista(lista1);
        printf("\nLista 2: ");
        imprimirLista(lista2);
        printf("\nUniao: ");
        TLista *lista3=listaUniao(lista1,lista2);
        //elementoRepetido(lista3);
        imprimirLista(lista3);
        printf("\nIntersecao: ");
        TLista *lista4=listaIntersecao(lista1,lista2);
		//elementoRepetido(lista4);
        imprimirLista(lista4);
    }