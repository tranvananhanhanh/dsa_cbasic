#include<stdio.h>
#define N 20
int x[N];
int n;
int visited[N];

int check(int v,int k){
    //neu v chua xh thi v hop le
    return visited[v]==0;
}
void ps(){
    for(int i=1;i<=n;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}
void TRY(int k){
    for(int v=1;v<=n;v++){
        if(check(v,k)){
            x[k]=v;
            //bao hieu v da duoc sd
            visited[v]=1;
            if(k==n){
                ps();
            }
            else{
                TRY(k+1);
            }
            //khoi phuv trang thai danh dau cua v
            visited[v]=0;

        }
    }
}
int main(){
    n=4;
    for(int v=0;v<=n;v++){
        visited[v]=0;
    }
    TRY(1);
}