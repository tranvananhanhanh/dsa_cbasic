#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 100
typedef struct Node{
    char name[100];
    float grade;
    struct Node *pre;
    struct Node *next;
}Node;
Node *newnode(char n[],float s){
    Node *t=(Node*)malloc(sizeof(Node));
    t->grade=s;
    strncpy(t->name,n,MAXLEN-1);
    t->name[MAXLEN - 1] = '\0';
    t->pre=NULL;
    t->next=NULL;
    return t;
}
void append(Node **head, char n[], float s) {
    Node *newNode = newnode(n, s);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->pre=temp;
    }
}

void print(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%s ", p->name);
        p = p->next;
    }
}

//use 2p fast and slow , fast go twice -> have middle point
Node *split(Node *head){
    Node *fast=head;
    Node *slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *temp=slow->next;
    slow->next=NULL;
    return temp;
    
}
Node* merge(Node *left,Node *right){
    Node *result=NULL;
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    if (left->grade < right->grade) {
    left->next=merge(left->next,right);
    left->next->pre=left;
    left->pre=NULL;
    return left;
} else {
    right->next=merge(left,right->next);
    right->next->pre=right;
    right->pre=NULL;
    return right;

}
}
// Function to do merge sort 
Node *mergeSort(Node *head) 
{ 
    if (!head || !head->next) 
        return head; 
    Node *second = split(head); 
 
    // Recur for left and right halves 
    head = mergeSort(head); 
    second = mergeSort(second); 
 
    // Merge the two sorted halves 
    Node *p=merge(head,second); 
    
    return p;
} 
int main(){
    Node *head=NULL;
    char name[MAXLEN];
    float grade;

    // Input data
    while (1) {
        scanf("%s", name);
        if (name[0] == '#') {
            break;
        }
        scanf("%f", &grade);
        
        // Check if the grade is within the valid range
        if (grade >= 0 && grade <= 10) {
            append(&head, name, grade);
        }
    }
    
    Node *t=mergeSort(head);
    print(t);
}