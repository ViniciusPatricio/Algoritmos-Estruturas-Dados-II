#include "stdio.h"

int pot(int num,int potencia){
    
    if(potencia==0){
        return 1;
    }else  if(potencia%2==0){
        return pot(num,potencia/2)*pot(num,potencia/2);
}else{
    return num*pot(num,potencia-1);
}

}



int main(){

    int entrada;
    int potencia;
    while(scanf("%d",&entrada)!=EOF){
        scanf("%d",&potencia);
        printf("%d\n",pot(entrada,potencia));
    }


}