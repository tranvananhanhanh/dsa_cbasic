#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Hàm tạo một Node mới
Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}
// Hàm chèn một Node vào cuối danh sách
Node* insertLast(Node* head, int v) {
    Node* p = head;

    // Trường hợp danh sách rỗng
    if (head == NULL) {
        return makeNode(v);
    }

    // Trường hợp thông thường
    while (p->next != NULL) {
        p = p->next;
    }

    Node* q = makeNode(v);
    p->next = q;

    return head;
}

// Hàm tìm giá trị lớn nhất trong danh sách
int findMaxValue(Node* head) {
    Node* p = head;
    int max = head->value;

    while (p != NULL) {
        if (p->value > max) {
            max = p->value;
        }
        p = p->next;
    }

    return max;
}

// Hàm chèn giá trị mới vào phía trước nút có giá trị lớn nhất
Node* insertBeforeMax(Node* head, int v) {
    int max = findMaxValue(head);

    // Tìm nút có giá trị lớn nhất và nút trước nó
    Node* p = head;
    Node* prev = NULL;
    while (p != NULL) {
        if (p->value == max) {
            // Chèn nút mới vào phía trước nút có giá trị lớn nhất
            Node* newNode = makeNode(v);
            if (prev == NULL) {
                newNode->next = head;
                return newNode;
            } else {
                newNode->next = p;
                prev->next = newNode;
                return head;
            }
        }
        prev = p;
        p = p->next;
    }

    return head;
}

// Hàm hiển thị danh sách
void printList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    char buff[100];
    int v;

    // Đọc dãy số vào bộ đệm
    fgets(buff, sizeof(buff), stdin);

    // Sử dụng strtok() để tách xâu bằng dấu khoảng cách
    char* token = strtok(buff, " ");

    // Tạo danh sách
    while (token != NULL) {
        head = insertLast(head, atoi(token)); // Lấy số hiện tại
        token = strtok(NULL, " ");
    }

    // Đọc giá trị cần chèn
    scanf("%d", &v);

    // Chèn giá trị vào sau nút có giá trị lớn nhất
    head = insertBeforeMax(head, v);

    // Hiển thị danh sách sau khi chèn
    printList(head);

    return 0;
}