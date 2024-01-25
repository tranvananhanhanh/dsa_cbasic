#include<stdio.h>

int fi(int n){
    if(n<=1){
        return n;
    }
    return fi(n-1)+fi(n-2);
}
int main(){
    for(int i=0;i<10;i++){
        printf("%d",fi(i));
    }
}