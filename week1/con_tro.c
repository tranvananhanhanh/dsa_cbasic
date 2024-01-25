#include<stdio.h>
#include <conio.h>
int main(){
    int A = 1;
    int B = 2;
    int C = 3;
    int *P1, *P2;
    P1=&A;//1
    P2=&C;//3
    //gán giá trị p2 cho p1 sau tăng giá trị p2 lên 
    *P1=(*P2)++;
    printf("%d %d",*P1, *P2);//3,4
    P1=P2;//4
    P2=&B;//2
    *P1-=*P2;//2
    printf("%d %d",*P1, *P2);//2,2
    ++*P2;//3
    *P1*=*P2;//6
    printf("%d %d",*P1, *P2);//6,3
    A=++*P2**P1;//24
    P1=&A;
    printf("%d",A);//24
    *P2=*P1/=*P2;//6,6
    printf("%d %d",*P1, *P2);//6,6
    return 0;
    }