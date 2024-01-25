#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int value;
    struct Node* next;
} Node;

//chèn đầu
Node *insertfirst(Node *h,int v){
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=v;
    p->next=h;
    h=p;
    return p;

}
//chen o giua
Node *insertmid(Node *pr,int v){
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=v;
    p->next=pr->next;
    pr->next=p;

}
//chèn vào cuối 
Node *insertlast(Node *h,int v){
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=v;
    while(h!=NULL){
        h=h->next;
    }
    p=h;
}
//xoa dau 
Node *deletefirst(Node *h){
    Node *p=(Node*)malloc(sizeof(Node));
    
    p=h->next;
    h=p->next;
    free(p);
}
//xoa giua
Node *deletemid(Node *pr){
    Node *p=(Node*)malloc(sizeof(Node));
    p=pr->next;
    pr->next=p->next;
    free(p);

}
// xoa duoi vao la node truoc nut cuoi
Node *deletelast(Node *l){
    Node *p=(Node*)malloc(sizeof(Node));
    p=l->next->next;
    l->next=NULL;
    free(p);

}