#include "stdio.h"

int produtoDosElementos(int vetor[], int n){
	if(n==1){
		return vetor[n-1];
	}else{
		return vetor[n-1]*produtoDosElementos(vetor,n-1);
	}
}



int main(){

int tamanho;
scanf("%d",&tamanho);
int vetor[tamanho];

for(int i=0;i<tamanho;i++){
	scanf("%d",&vetor[i]);
}
	
	printf("%d",produtoDosElementos(vetor,tamanho));
	
	
	return 0;
}