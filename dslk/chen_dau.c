#include<stdio.h>
#include<stdlib.h>
//cấu trúc 1 node gồm data vầ con trỏ next trỏ đến node mới
typedef struct  Node
{
    int value;
    struct Node *next;
} Node;

Node *make_node(int v){
    //tạo con trỏ p kiểu node cấp phát bộ nhớ động 
    Node *p=(Node*)malloc(sizeof(Node));
    //gán giá trị node 
    p->value=v;
    p->next=NULL;
    return p;
}

//vào là con trỏ nodê head **head, ta đang truy cập và thay đổi giá trị của con trỏ head thông qua một con trỏ tới con trỏ.cho phếp thay đổi vị trí và giá trị từ trong hàm 
void update_head(Node **head, Node *new_node)
{
    //gán np của node mới tạo head cũ 
    new_node->next = *head;
    // đổi head mới
    *head = new_node;
}

int main(){
    
    Node *head=NULL;
    Node *newnode=make_node(10);
    update_head(&head,newnode);
    Node *now=head;
    while(now!=NULL){
        printf("%d",now->value);
        now=now->next;
    }
    return 0;
}