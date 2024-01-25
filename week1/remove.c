#include<stdio.h>
#include<string.h>
void removes(int *arr,int *size,int x){
    int *p1=arr; //con trỏ đầu tiên trỏn đến phần tử đầu tiên của mảng
    int *p2=arr; //con trỏ p2 để duyệt mảng
    while(p2<arr+*size){
        if(*p2!=x){
            //nếu khác x, gán giá trị p2 cho p1 và tăng p1
            *p1=*p2;
            p1++;
        }
        //tăng p2
        p2++;
    }
    //cập nhập lại kích thước mới  cho mảng
    *size=p1-arr;
}
int main(void){
    int x;
    scanf("%d",&x);
    int a[100];
    int k=0;
    while(1)
    {
        scanf("%d",&a[k]);
        if(a[k]==-1){break;

        }
        k++;
    }
    removes(a,&k,x);
    for(int i=0;i<k;i++){
        printf("%d ",a[i]);
    }
    return 0;
    

}