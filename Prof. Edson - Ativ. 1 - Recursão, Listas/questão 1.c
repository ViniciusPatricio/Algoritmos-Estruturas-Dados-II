#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define QUALIFY1 10
#define QUALIFY2 8
#define QUALIFY3 5
#define NUMERO_PILOTOS 24



typedef struct Pilotos TPilotos;
struct Pilotos{ // estrutura que representa o dado Piloto
    float tempo; // menor tempo que o piloto leva para comprir uma volta
    int numero; // numeração do piloto
    char equipe; 
    TPilotos *nextPtr;
    
};


typedef struct lista_encadeada TLista;
struct lista_encadeada{
    TPilotos *inicio;
    TPilotos *fim;
    int qtde;
};

// *********************** FUNÇÕES DE CRIAÇÃO  *********************** //



TPilotos *criarTPiloto(float tempo, int numero, char equipe){ // Criando a estrutura que representa os pilotos
    TPilotos *new_Ptr = malloc(sizeof(TPilotos));
    new_Ptr->tempo=tempo;
    new_Ptr->numero=numero;
    new_Ptr->equipe=equipe;
    new_Ptr->nextPtr=NULL;

    return new_Ptr;
}

TLista *criarLista(){   // função que criará a lista encadeada
    TLista *new_lista=malloc(sizeof(TLista));
    new_lista->inicio=NULL;
    new_lista->fim=NULL;
    new_lista->qtde=0;

    return new_lista;
}

TPilotos *copiarDadosPilotos(TPilotos *piloto){  // função que copiará os dados de um piloto, a finalidade dela é para auxiliar a ordenação da listaGeral de pilotos
    TPilotos *copia_piloto=malloc(sizeof(TPilotos));
    copia_piloto->tempo=piloto->tempo;
    copia_piloto->numero=piloto->numero;
    copia_piloto->equipe=piloto->equipe;
    copia_piloto->nextPtr=NULL;

    return copia_piloto;
}
// *********************** FUNÇÕES DE INSERÇÃO  *********************** //


void inserirLista(TLista *lista, TPilotos *new_piloto){

    if(lista->inicio==NULL){
        lista->inicio=new_piloto;
        lista->fim=new_piloto;
    }else{
        lista->fim->nextPtr=new_piloto;
        lista->fim=new_piloto;
    }
    lista->qtde;
}

void inserirOrdenadoLista(TLista *lista, TPilotos *new_piloto){ // função que insere ordenado, irá auxiliar na função de ordenação da listaGeral de pilotos
    if(lista->inicio==NULL){
        lista->inicio=new_piloto;
        lista->fim=new_piloto;
    }else{
        TPilotos *caminhador1=lista->inicio;
        TPilotos *caminhador2=NULL;

        while(caminhador1!=NULL && caminhador1->tempo<new_piloto->tempo){
            caminhador2=caminhador1;
            caminhador1=caminhador1->nextPtr;
        }
        if(caminhador1==NULL){
            lista->fim->nextPtr=new_piloto;
            lista->fim=new_piloto;
        }else if(caminhador2==NULL){
            new_piloto->nextPtr=lista->inicio;
            lista->inicio=new_piloto;
        }else{
            caminhador2->nextPtr=new_piloto;
            new_piloto->nextPtr=caminhador1;
        }

    }
    lista->qtde++;
}




// *********************** FUNÇÕES DIVERSAS PARA LISTA  *********************** //
void imprimirLista(TLista *lista){ 
    TPilotos *caminhador = lista->inicio;
    int i=1;
        printf(" -------------------------------\n");
        printf("| pos. | plto | eqp |   tempo  |\n");
    while(caminhador!=NULL){
        printf("|  %02d  |  %02d  |  %c  | %f |\n",i++,caminhador->numero,caminhador->equipe,caminhador->tempo);
        caminhador=caminhador->nextPtr;
    }   
        printf(" ------------------------------- ");
}

void ordenarListaPilotos(TLista *lista){ // função criada para ordena a lista de pilotos
    TLista *lista_aux=criarLista();
    TPilotos *caminhador=lista->inicio;

    while(caminhador!=NULL){
        TPilotos *copia_piloto=copiarDadosPilotos(caminhador);
        inserirOrdenadoLista(lista_aux,copia_piloto);
        caminhador=caminhador->nextPtr;
    }
    lista->inicio=lista_aux->inicio;
    lista->fim=lista_aux->fim;
    lista->qtde=lista_aux->qtde;
}


// *********************** FUNÇÕES DIRECIONDAS AO PROBLEMA PROPOSTO *********************** //



float gerarTempo(){  // função criada para gerar o tempo que um piloto leva para dar uma volta;
    float tempo= 1+rand()%5000000;
    tempo=tempo/1000000;

   return tempo;
}

int verificaIgualdade(TLista *lista, int numero_piloto, float tempo_gerado){ // função vai verificar se o numero gerado é diferente do anterior e dos elementos já retirados
    TPilotos *caminhador=lista->inicio;
    while(caminhador!=NULL){
        if(numero_piloto==caminhador->numero){
            break;
        }
        caminhador=caminhador->nextPtr;
    }
    if(tempo_gerado==caminhador->numero){
        return 1;
    }else{
        return 0;
    }
}

void zerarListaVolta(TLista *listaVoltas){ // função criada para zerar a ListaVolta a cada volta na pista
    TPilotos *caminhador1=listaVoltas->inicio;
    TPilotos *caminhador2 =caminhador1->nextPtr;
    while(caminhador2!=NULL){
        free(caminhador1);
        caminhador1=caminhador2;
        caminhador2=caminhador2->nextPtr;
    } // quando caminhador2 == NULL, o caminhador1 vai está na última posição da lista, com isso foi necessário fazer o free(caminhador1) logo a seguir
    free(caminhador1);
    listaVoltas->inicio=NULL;
    listaVoltas->fim=NULL;
    listaVoltas->qtde=0;
}

int verificaNumeroVetor(int vetor_carros[], int numero_carro, int tamanho){ // função que se o numero está no vetor, ajudará a sortear os numeros dos pilotos para nao repetir
    int flag=0;
    for(int i=0;i<tamanho;i++){
        if(vetor_carros[i]==numero_carro){
            flag=1;
        }

    }
    return flag;
}
void ordenarVetor(int vetor[], int tamanho){
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(vetor[i]<vetor[j]){
                int aux=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }
        }
    }
}

void imprimirVetor(int vetor[], int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%d ",vetor[i]);
    }
}

void guardarMenorTempo(TLista *lista, TPilotos *piloto){ // função que irá guardar o menor tempo de cada piloto sorteado para iniciar a volta.
    TPilotos *caminhador=lista->inicio;
    while(caminhador!=NULL){
        if(caminhador->numero==piloto->numero && caminhador->tempo>piloto->tempo){
            caminhador->tempo=piloto->tempo;
            break;
        }
        caminhador=caminhador->nextPtr;
    }
}
void vetordeCarrosPossiveis(TLista *lista,int vetor[]){ // criará vetor que armazena os números dos carros que estão participando do qualify, ajudará a sortear os numeros dos pilotos
    TPilotos *caminhador=lista->inicio;
    int i=0;
    while(caminhador!=NULL){
        vetor[i]=caminhador->numero;
        caminhador=caminhador->nextPtr;
        i++;
    }
}
void zerarVetor(int vetor[], int tamanho){ // zerando o vetor
    for(int i=0;i<tamanho;i++){
        vetor[i]=0;
    }
}

/* Esta função está seguindo a descrição da imagem de apoio disponível, elá irá primeiramente sortear
o número de carros que irão na volta, depois irá sortear que carros irão fazer isso e depois atribuir um
tempo aleatório para eles, esses valores serão guardaddos na listaVoltas, depois será verificado se esse
tempo gerado é o menor que cada piloto percorreu, caso seja, o valor será substituído da listaGeral (na 
função está denominado de lista), depois disso a listaVoltas será resetada, e tal processor será feito de 
acordo com o número de voltas.

*/
void qualify(TLista *lista, int voltas_max, int max_pilotos){ 
    srand(time(NULL));
    TLista *listaVoltas=criarLista();
    int vetor_carros_possiveis[max_pilotos];
    vetordeCarrosPossiveis(lista, vetor_carros_possiveis);
    ordenarVetor(vetor_carros_possiveis,max_pilotos); // o vetor foi ordenado para saber qual é o maior numero que o numero_carro vai assumir
    
   
    for(int i=0;i<voltas_max;i++){
        
        int numero_de_carros_pvolta= 1+(rand()%max_pilotos); //números de carros que irão fazer a volta
        int vetor_numero_carro[numero_de_carros_pvolta]; // vetor criado para guarda quem são os números dos pilotos

         zerarVetor(vetor_numero_carro,numero_de_carros_pvolta); 
        
        
        for(int j=0;j<numero_de_carros_pvolta;j++){
            int numero_carro=1+(rand() %vetor_carros_possiveis[max_pilotos-1]);
            int flag;
            
            do{
                flag=0;
            
            
             //essa condição foi criada para sortear apenas numeros de pilotos que estão na lista geral e que não estão no vetores de números, 
             //pois caso contrário pode acabar se repetindo um número 
                if(verificaNumeroVetor(vetor_numero_carro,numero_carro,numero_de_carros_pvolta)==0 && verificaNumeroVetor(vetor_carros_possiveis,numero_carro,max_pilotos)==1){
                    flag=1;
                    break;
                }

                if(flag==0){
                numero_carro=1+(rand() %vetor_carros_possiveis[max_pilotos-1]);
                }
	
            }while(flag==0);
            
            vetor_numero_carro[j]=numero_carro;
            
            float tempo_gerado=gerarTempo(); // gerando o número aleatório para o piloto
            while(verificaIgualdade(lista,numero_carro,tempo_gerado)==1){ // vai verificar se esse tempo gerado é igual ao tempo gerado anteriormente
                tempo_gerado=gerarTempo();
            }
            TPilotos *novo_piloto=criarTPiloto(tempo_gerado, numero_carro,'0');
            inserirLista(listaVoltas,novo_piloto);
        }
        
        // ** substituição do menor tempo dos pilotos ** //

        TPilotos *caminhador=listaVoltas->inicio;
        
        while(caminhador!=NULL){
            guardarMenorTempo(lista,caminhador);
            caminhador=caminhador->nextPtr;
        }


        zerarListaVolta(listaVoltas); //zerando a listaVoltas 
        
    }
    
}
// esta função irá criar a lista com os pilotos desclassificados de uma certa etapa
TLista *listadesclassificado(TLista *lista, int numero_Classificados){
    TLista *lista_descassificados=criarLista();
    TPilotos *caminhador=lista->inicio;

    for(int i=0;i<numero_Classificados-1;i++){
        caminhador=caminhador->nextPtr;
    }
    lista_descassificados->inicio=caminhador->nextPtr;
    lista_descassificados->fim=lista->fim;
    lista_descassificados->qtde=lista->qtde-numero_Classificados;
    
    lista->fim=caminhador;
    lista->qtde=numero_Classificados;
    caminhador->nextPtr=NULL;

    return lista_descassificados;
}

void zerarTempoListaGeral(TLista *lista_pilotos){
    TPilotos *caminhador=lista_pilotos->inicio;
    while(caminhador!=NULL){
        caminhador->tempo=5;
        caminhador=caminhador->nextPtr;
    }
}

TLista *criarListFinal(TLista *l1,TLista *l2, TLista *l3, TLista *l4){
    TLista *ListaFinal=criarLista();
    ListaFinal->inicio=l1->inicio;
    l1->fim->nextPtr=l2->inicio;
    l2->fim->nextPtr=l3->inicio;
    l3->fim->nextPtr=l4->inicio;
    ListaFinal->fim=l4->fim;
    
    return ListaFinal;
}

// *********************** FUNÇÂO PRINCIPAL *********************** //
int main(){
    char vetor[24]="AABBCCDDEEFFGGHHIIJJKKLL"; // esse vetor de char foi criado para ajudar implementar mais fácil a equipe dos pilotos
    srand(time(NULL));
    
    TLista *lista_pilotos_completa=criarLista();     

/* O laço abaixo gera uma lista  de 24 carros contendo o número, a equipe e o
  o tempo = 5 pois é o maior valor do tempo retornado pela função gerarTempo;
*/
    for(int i=0;i<NUMERO_PILOTOS;i++){     
        TPilotos *new_piloto=criarTPiloto(5,i+1,vetor[i]);
        inserirLista(lista_pilotos_completa,new_piloto);
    }

    
// ************************ PRIMEIRO QUALIFY ************************ //  

    printf("Q1\n");
    qualify(lista_pilotos_completa,10,24);
    ordenarListaPilotos(lista_pilotos_completa);
    
   imprimirLista(lista_pilotos_completa);
   TLista *lista1_descalificados=listadesclassificado(lista_pilotos_completa,17);
    printf("\n");
       


// ************************ SEGUNDO QUALIFY ************************ // 

printf("Q2\n");

zerarTempoListaGeral(lista_pilotos_completa);
qualify(lista_pilotos_completa,8,17);
ordenarListaPilotos(lista_pilotos_completa);
imprimirLista(lista_pilotos_completa);
TLista *lista2_descalificados=listadesclassificado(lista_pilotos_completa,10);
printf("\n");

// ************************ TERCEIRO QUALIFY ************************ //
printf("Q3\n");
zerarTempoListaGeral(lista_pilotos_completa);
qualify(lista_pilotos_completa,5,10);
ordenarListaPilotos(lista_pilotos_completa);
imprimirLista(lista_pilotos_completa);
TLista *lista3_descalificados=listadesclassificado(lista_pilotos_completa,1);
// ************************ GRID LARGADA ************************ //
printf("\nGRID LARGADA\n");
TLista *listaFinal=criarListFinal(lista_pilotos_completa,lista3_descalificados,lista2_descalificados,lista1_descalificados);
imprimirLista(listaFinal);
}