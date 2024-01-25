#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
#include <stdbool.h>

bool is_integer(double value) {
    return value == (int)value;
}
typedef struct Node {
    char value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* top;  // for stack
Node* head; // for queue
Node* tail; // for queue

void push(char v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = v;
    temp->next = top;
    top = temp;
}

char pop() {
    if (top == NULL) {
        return 0;
    }
    char c = top->value;
    Node* p = top;
    top = top->next;
    free(p);
    return c;
}

void enqueue(char v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = v;
    temp->next = NULL;
    if (head == NULL && tail == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

char dequeue() {
    if (head == NULL) {
        return 0;
    }
    char c = head->value;
    Node* p = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(p);
    return c;
}

int isempty() {
    return top == NULL;
}

int queueisempty() {
    return head == NULL;
}

int main() {
    top = NULL;
    head = NULL;
    tail = NULL;

    double decimalNumber;
   
    scanf("%lf", &decimalNumber);

    // Chuyển đổi phần nguyên thành số nhị phân
    int integerPart = (int)decimalNumber;
    while (integerPart != 0) {
        int remainder = integerPart % 2;
        integerPart = integerPart / 2;
        push(remainder);
    }

    // Chuyển đổi phần thập phân thành số nhị phân
    double fractionalPart = decimalNumber - (int)decimalNumber;
    while (fractionalPart != 0) {
        double product = fractionalPart * 2;
        int bit = (int)product;
        enqueue(bit);
        fractionalPart = product - (int)product;
    }
    if(decimalNumber<1){
        printf("0");
    }


    // In ra phần nguyên nhị phân
    
    while (!isempty()) {
        int digit = pop();
        printf("%d", digit);
    }
    printf(".");
    if(is_integer(decimalNumber)){
        printf("0");
    }
    // In ra phần thập phân nhị phân
    
    while (!queueisempty()) {
        int digit = dequeue();
        printf("%d", digit);
    }
    printf("\n");

    return 0;
}
