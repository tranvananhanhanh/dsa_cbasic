#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

// Định nghĩa cấu trúc Node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Hàm tạo một Node mới
Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}
Node* insertLastRecursive(Node* h, int v){
     if(h == NULL){
        return makeNode(v);
    }
    //gọi đệ quy với con trỏ chạy tiếp theo 
    h->next = insertLastRecursive(h->next, v);
    //trả về con trỏ cuối cùng 
    return h;
    }

// Hàm chèn một Node vào cuối danh sách
Node* insertLast(Node* head, int v) {
    Node* p = head;

    // Trường hợp danh sách rỗng
    if (head == NULL) {
        return makeNode(v);
    }

    // Trường hợp thông thường
    while (p->next != NULL) {
        p = p->next;
    }

    Node* q = makeNode(v);
    p->next = q;

    return head;
}

// Hàm hiển thị danh sách
void printList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

// Hàm xóa tất cả các node có giá trị v 
Node* removeAll(Node* head, int v){
    // remove all nodes having value v from the linked list headed by head
    if(head == NULL) 
        return NULL;
    
    if(head->value == v){
        Node* tmp = head; 
        head = head->next; 
        free(tmp);
        head = removeAll(head, v); // continue to remove other elements having value v
        return head;
    }

    head->next = removeAll(head->next, v);
    return head;
}

// Hàm đảo ngược thứ tự các node trong danh sách
Node* reverse(Node *head){
    Node* p = head;
    Node* pp = NULL;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}
int main(){
    char cmd[20];
    Node *head=NULL;
    char buff[MAX_LEN];
    fgets(buff,MAX_LEN,stdin);
    char *token=strok(buff," ");
    while(token!=NULL){
        head=insertLast(head,atoi(token));
        token=strtok(NULL," ");
    }
    while(scanf("%s",cmd)==1){
        if(strcmp(cmd,"addlast")==0){
            int k;
            scanf("%d",&k);
            Node *new=addlast(head,k);
        }
    }
    
}