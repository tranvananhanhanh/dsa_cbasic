#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *newNode(int k) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = k;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

Node *insert(Node **root, int k) {
    if (*root == NULL) {
        *root = newNode(k);
        return *root;
    }

    if (k < (*root)->key) {
        (*root)->leftChild = insert(&((*root)->leftChild), k);
    } else if (k > (*root)->key) {
        (*root)->rightChild = insert(&((*root)->rightChild), k);
    }

    return *root;
}


void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->leftChild);
        freeTree(root->rightChild);
        free(root);
    }
}

void printTreeInOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printTreeInOrder(root->leftChild);        
        printTreeInOrder(root->rightChild);
    }
}



int main() {
    Node *root = NULL;
    char command[20];
    int key;
    while (1) {
        char c[100];
        fgets(c, sizeof(c), stdin);
        sscanf(c, "%s %d", command, &key);

        if (command[0] == '#') {
            break;
        }
        root = insert(&root, key);     
    }
    
    printTreeInOrder(root);

    // Free allocated memory before exiting
    freeTree(root);
    
    return 0;
}
