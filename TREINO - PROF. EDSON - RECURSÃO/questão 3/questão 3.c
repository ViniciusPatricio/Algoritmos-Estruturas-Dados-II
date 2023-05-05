#include "stdio.h"
#include "string.h"
#include "ctype.h"

void imprimirVetor(char vetor[], int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%c",vetor[i]);
    }
    
};
int palindrome(char vetor[],int tamanho,int inicio, int fim){
	if(inicio<tamanho){
		if(vetor[inicio]==vetor[fim]){
			return 1+palindrome(vetor,tamanho,inicio+1,fim-1);
		}else{
			return 0 + palindrome(vetor,tamanho,inicio+1,fim-1);
		}
	}
	return 0;
}

  
int main(){
	int i=0;
	char palavra[1000];
	while(scanf("%c",&palavra[i]),palavra[i]!='X'){
		while(palavra[i]!='\n'){
			if(palavra[i]==' ' || !isalpha(palavra[i])){
				i--;
			}
			i++;
			scanf("%c",&palavra[i]);
		}
		if(palavra[0]!='\n'){
			if(palindrome(palavra,i,0,i-1)==i){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}
		i=0;
	}
	return 0;
}