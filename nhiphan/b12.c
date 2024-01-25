#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root = NULL;

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

Node *search(Node *root, int k) {
    if (root == NULL || root->key == k) {
        return root;
    }

    if (k < root->key) {
        return search(root->leftChild, k);
    }

    return search(root->rightChild, k);
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
        printTreeInOrder(root->leftChild);
        printf("%d ", root->key);
        printTreeInOrder(root->rightChild);
    }
}

int treeHeight(Node *root) {
    if (root == NULL) {
        return -1; // Chiều cao của cây rỗng là -1
    }

    int leftHeight = treeHeight(root->leftChild);
    int rightHeight = treeHeight(root->rightChild);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int depth(Node *root, int k) {
    Node *node = search(root, k);

    if (node == NULL) {
        return -1; // Node không tồn tại trong cây
    }

    int d = 0;
    while (node != root) {
        d++;
        if (k < node->key) {
            node = node->leftChild;
        } else {
            node = node->rightChild;
        }
    }

    return d;
}

Node *findMin(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    Node *minNode = root;
    while (minNode->leftChild != NULL) {
        minNode = minNode->leftChild;
    }
    return minNode;
}

Node *findMax(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    Node *maxNode = root;
    while (maxNode->rightChild != NULL) {
        maxNode = maxNode->rightChild;
    }
    return maxNode;
}

int main() {
    char command[20];
    int key;

    while (1) {
        char c[100];
        fgets(c, sizeof(c), stdin);
        sscanf(c, "%s %d", command, &key);

        if (command[0] == '#') {
            break;
        }

        if (strcmp(command, "Insert") == 0) {
            root = insert(&root, key);
        } else if (strcmp(command, "Delete") == 0) {
            // Implement delete operation (not provided in the original requirements)
        } else if (strcmp(command, "Search") == 0) {
            Node *result = search(root, key);
            if (result != NULL) {
                printf("found %d\n", key);
            } else {
                printf("%d not found\n", key);
            }
        } else if (strcmp(command, "FindMin") == 0) {
            Node *minNode = findMin(root);
            if (minNode != NULL) {
                printf("Min is %d\n", minNode->key);
            } else {
                printf("Tree is empty\n");
            }
        } else if (strcmp(command, "FindMax") == 0) {
            Node *maxNode = findMax(root);
            if (maxNode != NULL) {
                printf("Max is %d\n", maxNode->key);
            } else {
                printf("Tree is empty\n");
            }
        } else if (strcmp(command, "PrintTree") == 0) {
            printTreeInOrder(root);
            printf("\n");
        } else if (strcmp(command, "TreeHeight") == 0) {
            int height = treeHeight(root);
            printf("Tree Height is %d\n", height);
        } else if (strcmp(command, "Depth") == 0) {
            int d = depth(root, key);
            if (d != -1) {
                printf("Depth of %d is %d\n", key, d);
            } else {
                printf("%d not found\n", key);
            }
        }
    }

    // Free allocated memory before exiting
    freeTree(root);

    return 0;
}
