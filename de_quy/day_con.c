#include<stdio.h>
#define MAX 100
int a[100],n,m;
void ps(){
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
void TRY(int k){
    if(k>n){
        ps();
        return;
    }
    for(int i=a[k-1]+1;i<=m+n-k;i++){
        a[k]=i;
        TRY(k+1);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    TRY(1);

}