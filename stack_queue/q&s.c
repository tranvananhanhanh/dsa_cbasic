#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    char c;
    struct Node* pre;
    struct Node* next;
} Node;

Node* new(char s) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->c = s;
    t->pre = NULL;
    t->next = NULL;
    return t;
}

Node* top;
Node* tail;
Node* head;

// Stack
void stackinit() {
    top = NULL;
}

int stackempty() {
    return top == NULL;
}

void push(char s) {
    Node* t = new(s);
    if (top == NULL) {
        top = t;
    } else {
        t->next = top;
        top->pre = t;
        top = t;
    }
}

char pop() {
    Node* t = top;
    top = t->next;
    char key = t->c;
    free(t);
    return key;
}

// Queue
void queueinit() {
    head = NULL;
    tail = NULL;
}
//head & tail is point to a node not pre or next its all of a node

int qempty() {
    return head == NULL;
}
//fifo
//insert in last
void enqueue(int so) {
    Node* t = new(so);
    if (qempty()) {
        head = t;
        tail = t;
    } else {
        tail->next = t;
        t->pre = tail;
        tail = t;
    }
}
//get in first
char dequeue() {
    Node* t = head;
    char s = t->c;
    head = t->next;
    free(t);
    return s;
}

int main() {
    stackinit();
    queueinit();
    char xau[100];
    scanf("%s",xau);
    int x=strlen(xau);
    for(int i=0;i<x;i++){
        push(xau[i]);
        enqueue(xau[i]);
    }
    int r;
    while(stackempty()!=1&&qempty()!=1){
        char c2=pop();
        char c1=dequeue();
        printf("%c %c\n",c1,c2);
        if(c1!=c2){
            r=0;
            break;
        }
        r=1;
    }
    if(r==0){
        printf("No");
    }
    else{
        printf("Yes");
    }
    
    
    return 0;
}
