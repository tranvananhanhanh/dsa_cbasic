
//sx trên mảng
#include<stdio.h>
#include<string.h>
//truyền đối số hay tham trỏ vào
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
//selectionsort up
void selec(int arr[],int len){
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(arr[min]>arr[j]){
                swap(&arr[min],&arr[j]);
                min=j;
            }
        }
    }
}
//insertionsort
void insert(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        // Move elements of a[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}
//bubble so sánh 2 bạn đứng cạnh nhau ai cao hơn cho lên trước 
void bubble(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}
void pra(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int arr[]={3,10,6,92,15,8,47,7};
    selec(arr,8);
    pra(arr,8);
}


//sx trên dslk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node* previous;
    struct Node* next;
} Node;

Node* createNode(char name[], float grade) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, MAX_LEN - 1);
    newNode->name[MAX_LEN - 1] = '\0';
    newNode->grade = grade;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, char name[], float grade) {
    Node* newNode = createNode(name, grade);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

// Selection Sort
void selectionSort(Node* head) {
    Node *i, *j, *min;
    float tempGrade;
    char tempName[MAX_LEN];

    for (i = head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->grade < min->grade) {
                min = j;
            }
        }
        // Swap data
        tempGrade = i->grade;
        i->grade = min->grade;
        min->grade = tempGrade;

        strncpy(tempName, i->name, MAX_LEN - 1);
        tempName[MAX_LEN - 1] = '\0';
        strncpy(i->name, min->name, MAX_LEN - 1);
        i->name[MAX_LEN - 1] = '\0';
        strncpy(min->name, tempName, MAX_LEN - 1);
        min->name[MAX_LEN - 1] = '\0';

        printList(head);
    }
}

// Insertion Sort
void insertionSort(Node* head) {
    Node *i, *key;
    float tempGrade;
    char tempName[MAX_LEN];

    for (i = head->next; i != NULL; i = i->next) {
        key = i;
        while (key->previous != NULL && key->grade < key->previous->grade) {
            // Swap data
            tempGrade = key->grade;
            key->grade = key->previous->grade;
            key->previous->grade = tempGrade;

            strncpy(tempName, key->name, MAX_LEN - 1);
            tempName[MAX_LEN - 1] = '\0';
            strncpy(key->name, key->previous->name, MAX_LEN - 1);
            key->name[MAX_LEN - 1] = '\0';
            strncpy(key->previous->name, tempName, MAX_LEN - 1);
            key->previous->name[MAX_LEN - 1] = '\0';

            key = key->previous;
        }

        printList(head);
    }
}

// Bubble Sort
void bubbleSort(Node* head) {
    int swapped;
    Node *ptr1, *lptr = NULL;
    float tempGrade;
    char tempName[MAX_LEN];

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap data
                tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                strncpy(tempName, ptr1->name, MAX_LEN - 1);
                tempName[MAX_LEN - 1] = '\0';
                strncpy(ptr1->name, ptr1->next->name, MAX_LEN - 1);
                ptr1->name[MAX_LEN - 1] = '\0';
                strncpy(ptr1->next->name, tempName, MAX_LEN - 1);
                ptr1->next->name[MAX_LEN - 1] = '\0';

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        printList(head);
    } while (swapped);
}

int main() {
    Node* head = NULL;
    char name[MAX_LEN];
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

    // Sorting based on the specified algorithm
    char algorithm[20];
    scanf("%s", algorithm);

    if (strcmp(algorithm, "SelectionSort") == 0) {
        selectionSort(head);
    } else if (strcmp(algorithm, "InsertionSort") == 0) {
        insertionSort(head);
    } else if (strcmp(algorithm, "BubbleSort") == 0) {
        bubbleSort(head);
    } else {
        printf("Wrong Command\n");
    }

    // Free memory
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
