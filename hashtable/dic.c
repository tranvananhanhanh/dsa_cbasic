#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 20
#define HASH_SIZE 10
typedef struct Node
{   
    char word[MAX_LENGTH];
    struct Node *next;
    /* data */
}Node;
Node *hashtable[HASH_SIZE];
int hashstring(const char a[]){
    int i=0;
    int j=9;
    while(a[i]!='\0'){
        j=(31*j+a[i])%HASH_SIZE;
        i++;
    }
    return j;
}
//chaining 
void insert(char *word){
    int index=hashstring(word);
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->next=NULL;
    strcpy(temp->word,word);
    if(hashtable[index]==NULL){
        hashtable[index]=temp;
    }
    else{
        //cho node temp lên đầu
        temp->next=hashtable[index];
        //trả lại vị trí đầu
        hashtable[index]=temp;
    }
}
int check(char *word){
    int index=hashstring(word);
    Node *curr=hashtable[index];
    //kiểm tra xem có tồn tại trong dslk đơn k
    while(curr){
        if(strcmp(curr->word,word)==0){
                printf("%s",word);
                return 1;
        }
        curr=curr->next;
    }
    printf("Not found");
    return 0;
}
void delete(char *word) {
    int index = hashstring(word);
    Node *curr = hashtable[index];
    Node *prev = NULL;

    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            if (prev == NULL) {
                // Node to be deleted is the first node in the linked list
                hashtable[index] = curr->next;
            } else {
                prev->next = curr->next;
            }

            // Free memory for the word and the node
            free(curr->word);
            printf("Deleted: %s\n", word);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("%s not found for deletion\n", word);
}

int main(){
    char apple[]="qua tao";
    char cow[]="con bo";
    insert(apple);
    delete(apple);
    check(apple);
    check(cow);
}
