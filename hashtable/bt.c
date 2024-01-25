#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20
#define HASH_SIZE 10

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *hashtable[HASH_SIZE];

int hashstring(const char a[]) {
    int i = 0;
    int j = 9;
    while (a[i] != '\0') {
        j = (31 * j + a[i]) % HASH_SIZE;
        i++;
    }
    return j;
}

void insert(char *word) {
    int index = hashstring(word);
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    temp->word = strdup(word);
    if (temp->word == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(temp);
        exit(EXIT_FAILURE);
    }
    temp->next = NULL;

    if (hashtable[index] == NULL) {
        hashtable[index] = temp;
    } else {
        temp->next = hashtable[index];
        hashtable[index] = temp;
    }
}

int check(char *word) {
    int index = hashstring(word);
    Node *curr = hashtable[index];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            printf("%s\n", word);
            return 1;
        }
        curr = curr->next;
    }
    printf("Not found\n");
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
            free(curr);

            printf("Deleted: %s\n", word);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("%s not found for deletion\n", word);
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *curr = hashtable[i];
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            free(temp->word);
            free(temp);
        }
        hashtable[i] = NULL;
    }
}

int main() {
    char apple[] = "qua tao";
    char cow[] = "con bo";
    insert(apple);
    insert(cow);

    check(apple);
    check(cow);

    delete(apple);
    delete(cow);

    // Free allocated memory
    freeHashTable();

    return 0;
}
