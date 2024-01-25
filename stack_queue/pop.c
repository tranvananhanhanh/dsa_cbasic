#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char c;
    struct Node *next; 
}Node;
//bản chất stack là danh sách liên kết đơn chiều từ top =head
Node *makenode(char x){
    Node *p=(Node*)malloc(sizeof(Node));
    p->c=x;
    p->next=NULL;
    return p;
}
Node *top;
//khởi tạo stack
void initStack(){
    top=NULL;
}
//kiểm tra stack có rỗng k bằng cách con trỏ top nút trên cùng có =NULL không
int stackempty(){
    return top==NULL;
}
//chèn 1 giá trị mới trên đầu nút mới =vị trí sau top , gán top = nút mới
void push(char x){
    Node *p=makenode(x);
    p->next=top;
    top=p;
}
//lấy nút ở cuối stack kiểm tra xem có rỗng k ,lấy giá trị node top , tạo 1 nút mới gán =nút top gán, gán top =nút tiếp theo , giải phóng bộ nhớ nút tạm thời
char pop(){
    if(stackempty()){
        return ' ';
    }
    char x=top->c;
    Node *p=top;
    top=top->next;
    free(p);
    return x;
}
char s[1000];
int match(char a,char b){
    if(a=='('&&b==')'){
        return 1;
    }
    if(a=='['&&b==']'){
        return 1;
    }
    if(a=='{'&&b=='}'){
        return 1;
    }
    return 0;
}
int check(char *s){
    initStack();
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            push(s[i]);
        }
        else{
            if(stackempty()){
                return 0;
            }
            char c=pop();
            if(!match(c,s[i])){
                return 0;
            }
        }
    }
    return stackempty();

}
int main(){
    scanf("%s",s);
    int a=check(s);
    printf("%d",a);
    return 0;
}


