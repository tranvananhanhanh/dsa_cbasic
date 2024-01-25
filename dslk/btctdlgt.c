#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 100
//mỗi lần tạo nút mới chú ý cấp phát bộ nhớ nếu k sẽ bị lỗi 

typedef struct Node {
    int value;
    struct Node *next;
} Node;
//truyền đại chỉ node đầu tiên 
void add(Node **head, int v) {
    Node *p = *head;
    if (p == NULL) {
        p = (Node*)malloc(sizeof(Node));
        p->value = v;
        p->next = NULL;
        *head = p;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->value = v;
        temp->next = NULL;
        p->next = temp;
    }
}

void addlast(Node **head, int k) {
    Node *p = *head;
    if (p == NULL) {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->value = k;
        temp->next = NULL;
        *head = temp;
    } else {
        while (p->next != NULL) {
            if (p->value == k) {
                return;
            }
            p = p->next;
        }
        if (p->value == k) {
            return;
        }
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->value = k;
        temp->next = NULL;
        p->next = temp;
    }
}

void addfirst(Node **head, int k) {
    Node *p = *head;
    if (p == NULL) {
        p = (Node*)malloc(sizeof(Node));
        p->value = k;
        p->next = NULL;
        *head = p;
    } else {
        while (p->next != NULL) {
            if (p->value == k) {
                return;
            }
            p = p->next;
        }
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->next = *head;
        temp->value = k;
        *head = temp;
    }
}
void addafter(Node **head,int u,int v){
    Node *p=*head;
    Node *p1=*head;
    Node *p2=(Node*)malloc(sizeof(Node));

    if(p==NULL){
        return ;
    }
    else{
        //hamf kieemr tra da ton tai 1 gtri chua
        while(p->next!=NULL){
            if(p->value==u){
                return;
            }
            p=p->next;
        }
        if (p->value == u) {
            return;
        }
        while(p1->value!=v){
            p1=p1->next;
        }
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->value=u;
        temp->next=p1->next;
        p1->next=temp;

    }


}
void addbefore(Node **head,int u,int v){
    Node *p=*head;
    Node *p1=*head;
    Node *p2=(Node*)malloc(sizeof(Node));
    if(p==NULL){
        return ;
    }
    else{
        //hamf kieemr tra da ton tai 1 gtri chua
        while(p->next!=NULL){
            if(p->value==u){
                return;
            }
            p=p->next;
        }
        if (p->value == u) {
            return;
        }
        while(p1->value!=v){
            p2=p1;
            p1=p1->next;
            
        }
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->value=u;
        temp->next=p1;
        p2->next=temp;
    }
    
}
void removee(Node **head,int k){
    Node *p=*head;
    Node *p1;
    if(p==NULL){
        return ;
    }
    else if(p->value==k)
    {
        *head=p->next;
        free(p);

    }
    
    else{
        while(p->value!=k){
            p1=p;
            p=p->next;
            if(p==NULL){
            return ;
        }
        }
        
        Node *temp=(Node*)malloc(sizeof(Node));
        temp=p;
        p1->next=temp->next;
        free(temp);

    }
}
void reverse(Node **head) {
    Node *current = *head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
int main() {
    int n;
    
    char s[20];
    int d;
    scanf("%d", &n);
    int a[MAXLEN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    Node* head = NULL;
    //nhập các giá trị danh sách liên kết
    for (int i = 0; i < n; i++) {
        add(&head, a[i]);
    }
    char buff[100];
    while(fgets(buff,sizeof(buff),stdin)){
        if(buff[0]=='#'){
            break;
        }
         char arg1[20];
    int arg2;
    int arg3;
    int k=0;
  
    int x=strlen(buff);
    
    for(int i=0;i<x;i++){
        if(buff[i]==' '){
            k++;
        }
    }
    if(k==1){
        sscanf(buff,"%s %d",arg1,&arg2);
        if(strcmp(arg1,"addlast")==0){
            addlast(&head,arg2);
        }
        else if(strcmp(arg1,"addfirst")==0){
            addfirst(&head,arg2);
        }
        else if(strcmp(arg1,"remove")==0){
            removee(&head,arg2);
        }
        else if(strcmp(arg1,"reverse")==0){
            reverse(&head);
        }        
    }
    if(k==2){
        sscanf(buff,"%s %d %d",arg1,&arg2,&arg3);
        if(strcmp(arg1,"addbefore")==0){
            addbefore(&head,arg2,arg3);
        }
        else{
            addafter(&head,arg2,arg3);
        }


    }
    
     

    }

    
    
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    return 0;
}