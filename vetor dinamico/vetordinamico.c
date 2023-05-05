#include "stdio.h"
#include "stdlib.h"
#include "vetordinamico.h"
#include "math.h"

struct dadosVD{
    int tam;
    int ocupacao;
    int *vetor;
};
typedef struct dadosVD TDados;


TVDinamico *criarVD(){
    TVDinamico *vd=malloc(sizeof(TVDinamico));
    TDados *d=malloc(sizeof(TDados));

    d->tam=1;
    d->ocupacao=0;
    d->vetor=malloc(sizeof(int)*d->tam);
    vd->dados=d;

    return vd;
}

void inserirVD(TVDinamico *vd, int carga, int pos){
    TDados *d=vd->dados;
    if(pos>d->tam){
        d->tam= pow(2,ceil(log(pos))+1);
        d->vetor=realloc(d->vetor,sizeof(int)*d->tam);
    }

    d->vetor[pos-1]=carga;
    d->ocupacao++;
}

int acessarVD(TVDinamico *vd, int pos){
    TDados *d=vd->dados;
    if(abs(pos)<d->tam){
        pos = (pos<0?d->tam+(pos+1):pos);
        return d->vetor[pos-1];
    }else{
        printf("Acesso fora do limite do vetor\n");
    }
}