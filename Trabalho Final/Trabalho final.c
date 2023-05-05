#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "arvores_AVL.h"



int main(){
    
    int contador_palavras = 0;
    int flag_categoria = 0;
    int categoria;

    FILE *arquivo;
    arquivo = fopen("frases2.txt","r");

    char palavra[40];
    TLista *lista_palavras = criarLista();
    NO *raiz = NULL; // raiz da arvore AVL

    
    if(arquivo == NULL){
        printf("Arquivo nao encontrado\n");
    }else{
       while(!feof(arquivo)){
           
           fscanf(arquivo,"%s",palavra); // variável palavra recebe uma string do arquivo

           if(flag_categoria == 0 && strcmp(palavra,".") != 0){    // verifica se a string é a categoria da frase
                
                categoria = atoi(palavra);  // convertendo uma palavra em uma string.
                flag_categoria = 1;
               
           }

           if(strcmp(palavra,".") != 0 && strlen(palavra) >= 4){
               strlwr(palavra);
               contador_palavras++;
               TELE *nova_carga = criarElemento(palavra);
               inserirOrdenadoLista(lista_palavras,nova_carga);     
               
           }else if(strcmp(palavra,".") == 0){  // final da frase
                raiz = inserirArvore(raiz,categoria,lista_palavras);
                flag_categoria = 0; // ao chegar ao final da frase, a proxima string é uma categoria, então a flag é zerada.
                reiniciarLista(lista_palavras); // reiniciando a lista de palavras;

           }
       }
    }
    

    fclose(arquivo);
    printf("Palavras totais: %d\n",contador_palavras);
    buscaCategoria(raiz,0);    
    return 0;
   
}
