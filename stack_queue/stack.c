//tìm kiếm theo chiều rộng đường đi ngắn nhất
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int row,col;
    int step;
    struct Node *next;
    struct Node *parent;
   
    

} Node;
Node *head,*tail;
void initQueue(){
    head=NULL;
    tail=NULL;
}
Node *makenode(int r,int c,int step,Node *par){
    Node *p=(Node*)malloc(sizeof(Node));
    p->row=r;
    p->col=c;
    p->step=step;
    p->next=NULL;
    p->parent=par;
    return p;
}
int queueEmpty(){
    return head==NULL&&tail==NULL;
}
//đẩy vào cuói hàng đợi 
void push(Node *e){
    if(queueEmpty()){
        head=e;
        tail=e;
        return ;
    }
    tail->next=e;
    tail=e;
}
//lấy ở đầu hàng đợi 
Node *pop(){
    if(queueEmpty()){
        return NULL;
    }
    Node *p=head;
    head=head->next;
    if(head==NULL){
        tail=NULL;
    }
    return p;
}


