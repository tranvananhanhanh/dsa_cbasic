#include<stdio.h>
#define MAX 100
int x[MAX];
int N,M;
int T;
void ps(){
    for(int i=1;i<=N;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}


int check(int v, int k){
    if(k<N){
        //neu k<N tra ve true
        return 1;
    }
    //neu k=N kiem tra tong vt xem co =M ko
    return T+v==M;
}
void Try(int k){
    for(int v=1;v<=M-T-(N-k);v++){
        if(check(v,k)){
            x[k]=v;
            T=T+x[k];
            if(k==N){
                ps();
            }
            else{
                Try(k+ 1);
            }
            T=T-x[k];
        }
    }
}
int main(){
    N=3;M=5;T=0;
    Try(1);
    return 0;
}
