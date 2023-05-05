#include "stdio.h"

void menorElementoInicio(int vetor[], int tamanho, int inicio){

int menor = vetor[0];
int indice_menor =0;
for (int i=inicio;i<tamanho;i++){
    if(menor>vetor[i]){
        menor = vetor[i];
        indice_menor=i;
    }
    
}
   if(indice_menor!=0){
       vetor[indice_menor]=vetor[0];
       vetor[0]=menor;
   }
};




void ordenamentoVetor(int vetor[], int tamanho){

int n = tamanho;    
printf("1");
if(n!=0){
   menorElementoInicio(vetor,tamanho,tamanho-n);
   n--;
   ordenamentoVetor(vetor,tamanho);
   
}else{
    
}


};

void imprimirVetor(int vetor[],int tamanho){
    printf("elementos do vetor criado:");
    for(int i=0;i<tamanho;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}


int main(){


int tamanho;

printf("Tamanho do vetor:"); scanf("%d",&tamanho);

int vetor[tamanho];

printf("digite os elementos do vetor:\n");

for(int i=0;i<tamanho;i++){
    scanf("%d",&vetor[i]);
};

imprimirVetor(vetor,tamanho);


ordenamentoVetor(vetor,tamanho);
printf("vetor ordenado\n");
imprimirVetor(vetor,tamanho);
}