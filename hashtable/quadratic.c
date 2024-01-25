#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
typedef struct Node
{
    /* data */
    int id;
    char value[SIZE];
}Node;
int hashcode(int k,int n){
    return k%n;
}
Node *new(int id,char value[]){
    Node *t=(Node*)malloc(sizeof(Node));
    t->id=id;
    strcpy(t->value,value);
    return t;
}
void insert(int id,char value[],int n,Node **arr,int c1,int c2){
    int index=hashcode(id,n);
    Node *curr=new(id,value);
    int i=1;
    //nếu vị trí đã tồn tại 
    while(arr[index]!=NULL){
        //chuyển đến vị trí tiếp theo
            index=(index+c1*i+c2*i*i)%n;
            i++;
    }
    arr[index]=curr;
    }
int check(int id,int n,Node **arr,int c1,int c2){
    int i=hashcode(id,n);
    int org=i;
    while(arr[i]!=NULL){
        if(arr[i]->id==id){
            return i;
        }
        i=(i+c1*i+c2*i*i)%n;
        //kiểm tra xem đã duyệt qua các chỉ mục hết chưa, nếu có thoát ra khỏi vòng lặp để tránh vô hạn 
        if(i==org){
            break;
        }
    }
    return -1;
}
void printarr(Node **arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=NULL){
            printf("%d %s %d\n",arr[i]->id,arr[i]->value,i);
        }
    }
}
void delete(int id,int n,Node **arr,int c1,int c2){
    //tìm vị trí
    int i=check(id,n,arr,c1,c2);
    if(i!=-1){
        //giải phóng bộ nhớ
        free(arr[i]);
        //chuyển phần tử mảng thành null
        arr[i]=NULL;
    }
    else{
        printf("not found");
    }
}
int main(){
    int n=10;
    int c1=1,c2=2;
    Node **arr=(Node**)malloc(n*sizeof(Node*));
    insert(10,"hoa",10,arr,c1,c2);
    insert(12,"an",10,arr,c1,c2);
    insert(11,"anh",10,arr,c1,c2);
    insert(1,"ca",10,arr,c1,c2);
    
    delete(10,10,arr,c1,c2);
    printarr(arr,10);
    printf("%d",check(1,10,arr,c1,c2));
    
    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
