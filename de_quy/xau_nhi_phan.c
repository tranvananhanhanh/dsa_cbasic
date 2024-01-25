#include<stdio.h>
int n=2;
int x[100];
//in ra xâu nhị phân hiện tại
void printSolution(){
    for(int k=0;k<n;k++){
        printf("%d",x[k]);
    }
    printf("\n");
}
//bắt đầu sinh sâu nhị phân từ vị trií k
int TRY(int k){
    for(int v=0;v<=1;v++){
        //nhận 2 gtrị 0/1
        x[k]=v;
        //đến vị trí cuối cùng in ra xâu 
        if(k==n-1){
            printSolution();
        }
        // nếu chưa đến cuối sinh xâu nhị phân  từ vị trí cũ +1
        else TRY(k+1);
    }
}
int main(){
    TRY(0);
}