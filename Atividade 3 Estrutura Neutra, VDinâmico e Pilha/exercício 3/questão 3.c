#include "stdio.h"
#include "math.h"
#include "stdlib.h"

struct dadosVD{
    int tamanho;
    int ocupacao;
    void* *vetor;

};
typedef struct dadosVD TDados;

struct vetorDinamico{
    void *dados;
};
typedef struct vetorDinamico VDinamico;

VDinamico *criarVDinamico(){
    VDinamico *vetor_dinamico=malloc(sizeof(VDinamico));
    TDados *dados=malloc(sizeof(TDados));

    dados->tamanho=1;
    dados->ocupacao=0;
    dados->vetor=malloc(sizeof(void*)*dados->tamanho);
    vetor_dinamico->dados=dados;

}
typedef void (*TImprimirElemento)(void*);
void imprimirVetor(VDinamico *vetor, TImprimirElemento impressora){
    TDados *dados=vetor->dados;
    for(int i=0;i<dados->ocupacao+1;i++){
        impressora(dados->vetor[i]);
    }
}

void inserirVetor(VDinamico *vetor, void *carga, int pos){
    TDados *d=vetor->dados;
    if(pos>d->tamanho){
        d->tamanho=pow(2,ceil(log(pos))+1);
        d->vetor=realloc(d->vetor,sizeof(int)*d->tamanho);
    }
    d->vetor[pos-1]=carga;
    d->ocupacao++;
}

struct funcionario{
    char funcao;
    int  matricula;
    double salario;
};
typedef struct funcionario TFuncionario;

TFuncionario *criarFuncionario(char funcao, int matricula, double salario){
    TFuncionario *novo_funcionario=malloc(sizeof(TFuncionario));
    novo_funcionario->funcao=funcao;
    novo_funcionario->matricula=matricula;
    novo_funcionario->salario=salario;

    return novo_funcionario;

}
int comparaFuncionario(void *medida1, void *medida2){
    TFuncionario *funcionario1=medida1;
    TFuncionario *funcionario2=medida2;

    if(funcionario1->salario==funcionario2->salario){
        return 0;
    }else if(funcionario1->salario<funcionario2->salario){
        return -1;
    }else if(funcionario1->salario>funcionario2->salario){
        return 1;
    }

}
void imprimirFuncionario(void *funcionario){
    TFuncionario *new_funcionario=funcionario;
    printf("%c %d %lf\n",new_funcionario->funcao,new_funcionario->matricula,new_funcionario->salario);
}

int main(){

char funcao;
int matricula;
double salario;
int pos=1;

VDinamico *vetor_dinamico=criarVDinamico();
TDados *dado=vetor_dinamico->dados;

scanf("%c",&funcao);
while(funcao!='F'){
    scanf("%d %lf",&matricula,&salario);
    TFuncionario *novo_funcionario=criarFuncionario(funcao,matricula,salario);
    inserirVetor(vetor_dinamico,novo_funcionario,pos);
    printf("%c %d %lf\n",novo_funcionario->funcao,novo_funcionario->matricula,novo_funcionario->salario);
    pos++;
    scanf("%c",&funcao);
}
    
    //imprimirVetor(vetor_dinamico,imprimirFuncionario);

}