#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int c=*a;
    *b=*a;
    *a=c;
}
//chuyen node max nhat len dau
void heapify(int arr[],int N,int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<N&&arr[l]>arr[max]){
        max=l;
    }
    else if(r<N&&arr[r]>arr[max]){
        max=r;
    }
    if(max!=i){
        swap(&arr[i],&arr[max]);
        heapify(arr,N,max);

    }
}
void heapsortt(int arr[],int N){
    
    for(int i=N/2-1;i>=0;i--){
        heapify(arr,N,i);
    }
    for(int i=N-1;i>0;i--){
        //voi tung muc chuyen node max va node cuoi 
        
        swap(&arr[0],&arr[i]);
        //bo node max ra thuc hien heap voi phan con lai
        heapify(arr,i,0);
    }
}
void printa(int a[],int N){
    for(int i=0;i<N;i++){
        printf("%d",a[i]);
    }
}
int main(){
    int a[]={12,11,13,5,6,7};
    int N=sizeof(a)/sizeof(a[0]);
    heapsortt(a,N);
    printa(a,N);
}