#include "stdio.h"

float valorAbsoluto(float n){
    if(n>=0){
        return n;
    }else{
        return -n;
    }
}


float raiz(int x, float xo, float e){
   if(valorAbsoluto(xo*xo-x)<=e){
       return xo;
   }else{
       raiz(x,(xo*xo+x)/(2*xo),e);
   }
}

int main(){

int x;
float xo,e;

scanf("%d %f %f",&x,&xo,&e);

while(x!=0 || xo!=0 || e!=0){

   printf("%.6f\n",raiz(x,xo,e));

    scanf("%d %f %f",&x,&xo,&e);
}





    return 0;
}