/* 
Al: VINICIUS PATRICIO MEDEIROS DA SILVA
Nº: 21951799
Curso: ENGENHARIA DA COMPUTAÇÃO
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX 3 // número máximo de paginas por nó
#define MIN 1 // número mínimo de páginas por nó
#define true 1
#define false 0

// ****************************** ESTRUTURA DA MULTIWAY   ****************************** //

typedef struct ArvMway ArvMW;
struct ArvMway{
    int chaves[MAX];  // variável que guarda as chaves de cada nó da árvore
    int num_chaves;   // variável que guarda a informação de quantas chaves o nó da árvore possue
    ArvMW *filhos[MAX+1];    // esse vetor irá armazenar os endereços dos filhos do nó 
};



// ****************************** FUNÇAO DE CRIAÇÃO   ****************************** //


ArvMW *criarArvMW(){     // criando uma nova raiz/nó, alocando um espaço na memória para essa nova estrutura
    ArvMW *nova_raiz = (ArvMW*)malloc(sizeof(ArvMW));  
    nova_raiz ->num_chaves = 0;
    
    for(int i = 0; i<MAX+1;i++){   // como ele é um novo nó, os seus filhos são nulos, este laço está fazendo essa operação
        nova_raiz->filhos[i]=NULL;
    }
    return nova_raiz;
}


// ****************************** FUNÇAO DE AUXÍLIo   ****************************** //









int main(){







    return 0;
}