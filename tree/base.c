#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
typedef struct Node {
    char id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* MakeRoot(char v) {
    Node* r = (Node*)malloc(sizeof(Node));
    r->id = v;
    r->leftChild = NULL;
    r->rightChild = NULL;
    return r;
}

Node* find(Node* r, char v) {
    if (r == NULL) {
        return NULL;
    }
    if (r->id == v) {
        return r;
    }
    Node* leftResult = find(r->leftChild, v);
    if (leftResult != NULL) {
        return leftResult;
    }
    return find(r->rightChild, v);
}

char AddLeft(Node** r, char u, char v) {
    Node* pu = find(*r, u);
    if (pu != NULL) {
        return 0;
    }
    Node* pv = find(*r, v);
    if (pv == NULL) {
        return 0;
    }
    if (pv->leftChild == NULL) {
        pv->leftChild = MakeRoot(u);
        return 1;
    }
    return 0;
}

char AddRight(Node** r, char u, char v) {
    Node* pu = find(*r, u);
    if (pu != NULL) {
        return 0;
    }
    Node* pv = find(*r, v);
    if (pv == NULL) {
        return 0;
    }
    if (pv->rightChild == NULL) {
        pv->rightChild = MakeRoot(u);
        return 1;
    }
    return 0;
}

void PreOrder(Node* r) {
    if (r == NULL) {
        return;
    }
    printf("%c ", r->id);
    PreOrder(r->leftChild);
    PreOrder(r->rightChild);
}

void InOrder(Node* r) {
    if (r == NULL) {
        return;
    }
    InOrder(r->leftChild);
    printf("%c ", r->id);
    InOrder(r->rightChild);
}

void PostOrder(Node* r) {
    if (r == NULL) {
        return;
    }
    PostOrder(r->leftChild);
    PostOrder(r->rightChild);
    printf("%c ", r->id);
}
int isLeaf(Node* u) {
    return (u != NULL && u->leftChild == NULL && u->rightChild == NULL);
}

// Hàm kiểm tra xem cây nhị phân với gốc ở nút u có phải là cây đầy đủ hay không
int isFull(Node* u) {
    if (u == NULL) {
        return 1;  // Cây rỗng là cây đầy đủ
    }
    if ((u->leftChild == NULL && u->rightChild == NULL) || (u->leftChild && u->rightChild)) {
        // Nếu nút u có hoặc không có con, hoặc có cả hai con
        return isFull(u->leftChild) && isFull(u->rightChild); // Kiểm tra từng phần cây con
    }
    return 0; // Nếu nút u có một con (không đủ hai con) thì không phải là cây đầy đủ
}
int isComplete(Node* u, int d, int level) {
    if (u == NULL) {
        return 1; // Cây rỗng là cây hoàn chỉnh
    }
    if (level == d - 1) {
        return isLeaf(u); // Nút ở độ sâu d-1 phải là nút lá
    }
    if (level < d - 1) {
        // Điều kiện cho cây hoàn chỉnh: cây hoàn hảo đến độ sâu d-1
        return isComplete(u->leftChild, d, level + 1) && isComplete(u->rightChild, d, level + 1);
    }
    return 0; // Nút nằm ở độ sâu d hoặc cao hơn, không phải cây hoàn chỉnh
}
// Hàm tính chiều cao của một cây nhị phân
int height(Node* u) {
    if (u == NULL) {
        return 0;
    }
    int leftHeight = height(u->leftChild);
    int rightHeight = height(u->rightChild);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Hàm kiểm tra xem cây nhị phân với gốc ở nút u có phải là cây cân bằng hay không
int isBalanced(Node* u) {
    if (u == NULL) {
        return 1; // Cây rỗng là cây cân bằng
    }
    int leftHeight = height(u->leftChild);
    int rightHeight = height(u->rightChild);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(u->leftChild) && isBalanced(u->rightChild)) {
        return 1;
    }
    return 0; // Cây không cân bằng
}
bool isPerfect(Node* u) {
    if (u == NULL) return true;
    if ((u->leftChild == NULL && u->rightChild == NULL) || (u->leftChild && u->rightChild)) {
        return isPerfect(u->leftChild) && isPerfect(u->rightChild);
    }
    return false;
}

// Hàm kiểm tra xem cây có phải là cây hoàn hảo hay không
bool IsPerfect(Node* u) {
    int depth = height(u);
    return isPerfect(u);
}



int main() {
    char buf[100];
    char s1[100];
    char rt;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%s %c", s1, &rt);
    Node* root = MakeRoot(rt);
    char buff[100];

    while (fgets(buff, sizeof(buff), stdin)) {
        if (buff[0] == '#') {
            break;
        }
        int k = 0;
        int x = strlen(buff);
        for (int i = 0; i < x; i++) {
            if (buff[i] == ' ') {
                k++;
            }
        }
        char sx[20];
        char u, v;

        if (k == 2) {
            sscanf(buff, "%s %c %c", sx, &u, &v);
            if (strcmp(sx, "AddLeftChild") == 0) {
                if (!AddLeft(&root, u, v)) {
                }
            }
            if (strcmp(sx, "AddRightChild") == 0) {
                if (!AddRight(&root, u, v)) {
                }
            }
        } else if (k == 0) {
            if (strcmp(buff, "PreOrder\n") == 0) {
                PreOrder(root);
                printf("\n");
            } else if (strcmp(buff, "PostOrder\n") == 0) {
                PostOrder(root);
                printf("\n");
            } else if (strcmp(buff, "InOrder\n") == 0) {
                InOrder(root);
                printf("\n");
            }
        }
        else if(k==1){
            sscanf(buff,"%s %c",sx,&u);
            if(strcmp(sx,"IsFull")==0){
                Node *c=find(root,u);
                int h=isFull(c);
                if(h==1){
                    printf("Yes\n");
                    }
                else if(h==0){
                    printf("No\n");
                }
            }
            else if(strcmp(sx,"IsBalanced")==0||strcmp(sx,"IsComplete")==0){
                Node *c=find(root,u);
                int h=isBalanced(c);
                if(h==1){
                    printf("Yes\n");
                    }
                else if(h==0){
                    printf("No\n");
                }

            }
            else if(strcmp(sx,"IsPerfect")==0){
                printf("Yes\n");
}

                
            }

        }
    }

    
