#include "stdio.h"

int somaVetor(int vetor[], int tamanho, int inicio){
if(inicio==tamanho-1){
    return vetor[inicio];
}else{
    return vetor[inicio]+somaVetor(vetor,tamanho,inicio+1);
}

}


void inverterVetor(int vetor[],int inicio, int fim,int tamanho){
    if(tamanho%2==0){
        if(inicio+1==fim){
            int aux=vetor[inicio];
            vetor[inicio]=vetor[fim];
            vetor[fim]=aux;
        }else{
            int aux=vetor[inicio];
            vetor[inicio]=vetor[fim];
            vetor[fim]=aux;
            inverterVetor(vetor,inicio+1,fim-1,tamanho);
        }
    }

    else{
        if(inicio!=fim){
            int aux=vetor[inicio];
            vetor[inicio]=vetor[fim];
            vetor[fim]=aux;
            inverterVetor(vetor,inicio+1,fim-1,tamanho);
        }
    }
}
void imprimirVetor(int vetor[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",vetor[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int vetor[n];


    for(int i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    inverterVetor(vetor,0,n-1,n);
    imprimirVetor(vetor,n);
    printf("\n%d\n",somaVetor(vetor,n,0));
    
    
}