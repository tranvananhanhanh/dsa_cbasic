#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX
typedef struct Node{
    char name[MAX];
    float grade;
    struct  Node *pre;
    struct Node *next;        
}
Node *creatnewn