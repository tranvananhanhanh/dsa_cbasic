#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ULL unsigned long long
#define M 10000

typedef struct Node {
    ULL key;
    struct Node *next;
} Node;

Node *hashtable[M];

int hash(ULL key) {
    return key % M;
}

// Chaining
void insert(ULL key) {
    int index = hash(key);
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = hashtable[index];
    temp->key = key;
    hashtable[index] = temp;
}

int find(ULL key) {
    int index = hash(key);
    Node *curr = hashtable[index];

    // Traverse the linked list to find the key
    while (curr) {
        if (curr->key == key) {
            return 1; // Key found
        }
        curr = curr->next;
    }

    return 0; // Key not found
}

int main() {
    char buff[M];
    char c[M];

    // Build the hash table
    while (1) {
        ULL i;
        fgets(c, M, stdin);
        if (c[0] == '*') {
            break;
        }
        sscanf(c, "%llu", &i);
        insert(i);
    }

    // Process queries
    while (fgets(buff, M, stdin)) {
        if (strcmp(buff, "***\n") == 0) {
            break;
        } else {
            char fi[M];
            ULL key;

            if (buff[0] == 'f') {
                sscanf(buff, "%s %llu", fi, &key);
                printf("%d\n", find(key));
            } else if (buff[0] == 'i') {
                sscanf(buff, "%s %llu", fi, &key);
                int found = find(key);
                printf("%d\n", found ? 0 : 1);
                if (!found) {
                    insert(key);
                }
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < M; ++i) {
        Node *current = hashtable[i];
        while (current) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}
