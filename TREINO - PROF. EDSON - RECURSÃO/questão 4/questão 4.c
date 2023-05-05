#include "stdio.h"

int somaDosElementos(int vetor[],int n){
    if(n==1){
        return vetor[n-1];
    }else{
        return vetor[n-1]+somaDosElementos(vetor,n-1);
    }

};

void inverterVetor(int vetor[], int vetor_aux[], int n, int m){

if((n-1)==0){
    vetor_aux[m-1]=vetor[n-1];
}else{
    vetor_aux[m-n]=vetor[n-1];
    inverterVetor(vetor,vetor_aux,n-1,m);
};


};

void imprimirVetor(int vetor[],int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%d ",vetor[i]);
    };
};

void trocarConteudo(int vetor[],int vetor_aux[], int tamanho){
    for(int i=0;i<tamanho;i++){
        vetor[i]=vetor_aux[i];
    }
};


int main(){


int tamanho;
scanf("%d",&tamanho);

int vetor[tamanho];

for(int i=0;i<tamanho;i++){
    scanf("%d",&vetor[i]);
}


    int vetor_aux[tamanho];
    
    inverterVetor(vetor,vetor_aux,tamanho,tamanho);
    trocarConteudo(vetor,vetor_aux, tamanho);
    
    imprimirVetor(vetor,tamanho);

    printf("\n%d",somaDosElementos(vetor,tamanho));

    return 0;
}