#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=*a;  
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            //smaller in left
            swap(arr[i],arr[j]);
        }
    }
    //bigger in right 
    swap(arr[i+1],arr[high]);
    //postition of pivot in oder array
    return (i+1);
}
void quicksort(int arr[],int l,int h){
    if(l<h){
        int pi=partition(arr,l,h);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}