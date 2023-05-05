#include "stdio.h"

#define PAI(i)  (i/2)
#define ESQ(i) (i*2+1)
#define DIR(i) (i*2+2)

int  heapify( int vet[], int pai, int tam)
{
    int maior = pai;
    if((ESQ(pai) < tam) && (vet[ESQ(pai)] > vet[pai])){
        maior = ESQ(pai);
    };
    if(DIR(pai) < tam && vet[DIR(pai)]>vet[maior]){
        maior=DIR(pai);
    }
    if(maior != pai){
        return 1;
    }else{
        return 0;
    }

}

int verificar_heap(int vet[], int tam)
{
    int flag=0;
    int pos = (tam/2)-1;

    while( pos >= 0){
        if (heapify(vet,pos,tam)==1){
            flag=1;
            break;
        }
        pos--;
    }
    return flag;
}

int main(){

int N;
	
	while (scanf("%d", &N) != EOF) {
		int vetor_numeros[N];
        
        for(int i=0;i<N;i++){
            scanf("%d",&vetor_numeros[i]);
        }
        verificar_heap(vetor_numeros,N)== 1? printf("NAO\n") : printf("SIM\n");
	}
    return 0;
}