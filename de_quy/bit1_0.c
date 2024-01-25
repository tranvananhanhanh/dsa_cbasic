#include<stdio.h>
int n=5;
int x[100];
void ps(){
    for(int k=0;k<n;k++){
        printf("%d",x[k]);
    }
    printf("\n");
}
int TRY(int k){
    for(int v=0;v<=1;v++){
        if(x[k-1]+v<2){
            x[k]=v;
            if(k==n){
                ps();
            }
            else TRY(k+1);

        }
    }
}

int main(){
    x[0]=0;
    TRY(1);
}