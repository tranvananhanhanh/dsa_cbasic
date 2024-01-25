#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char value;
    struct Node *next;
}Node;

Node *top;
void initstack(){
    top=NULL;
}
int isempty(){
    return top==NULL;
}
void push(char v){
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->value=v;
        temp->next=top;
        top=temp;
    
}
char pop(){
    if(isempty()){
        return 0;
    }
    char c=top->value;
    Node *p=top;
    top=top->next;
    free(p);
    return c;
}
int main(){
    char s[100];
    fgets(s,1000,stdin);
    initstack();
    for(int i=0;i<strlen(s);i++){
        if(s[i]!=')'){
            push(s[i]);
        }
        else{
            
            if(pop()=='('){
                printf("1");
                return 0;

            }

        }
    }
    printf("0");
}
