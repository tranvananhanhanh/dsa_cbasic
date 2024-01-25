#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100

typedef struct Node {
    int id;
    char value[SIZE];
} Node;

// h1(k) = k % 13 và h2(k) = 7 - (k % 7).
int hash1(int k) {
    return k % 13;
}

int hash2(int k) {
    return 7 - (k % 7);
}

int hash(int k, int i) {
    return (hash1(k) + i * hash2(k)) % 40;  // Ensure the index is within array bounds
}

Node* new_node(int id, const char value[]) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->id = id;
    strcpy(t->value, value);
    return t;
}

void insert(int id, const char value[], Node** arr) {
    int index = hash1(id);
    Node* curr = new_node(id, value);

    int i = 1;
    while (arr[index] != NULL) {
        index = hash(id, i);
        i++;
    }

    arr[index] = curr;
}

int check(int id, Node** arr) {
    int i1 = hash1(id);
    int i=1; 
    int org = i1;
    while (arr[i1] != NULL) {
        if (arr[i1]->id == id) {
            return i1;
    
        }
        i1 = hash(id, i);
        i++;
        // kiểm tra xem đã duyệt qua các chỉ mục hết chưa, nếu có thoát ra khỏi vòng lặp để tránh vô hạn 
        if (i1 == org) {
            break;
        }
    }
    return -1;
}

void printarr(Node** arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL) {
            printf("%d %s %d\n", arr[i]->id, arr[i]->value, i);
        }
    }
}

void delete_node(int id, Node** arr) {
    int i = check(id, arr);
    if (i != -1) {
        free(arr[i]);
        arr[i] = NULL;
    } else {
        printf("not found");
    }
}

int main() {
    int n = 40;
    Node** arr = (Node**)malloc(n * sizeof(Node*));

    insert(11, "hoa", arr);
    insert(39, "an", arr);
    insert(13, "anh", arr);
    insert(26, "ca", arr);

    printarr(arr, n);
    printf("%d\n", check(39, arr));

    delete_node(26, arr);
    printf("%d\n", check(39, arr));

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
