#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

typedef struct {
    int id;
    char name[MAX_LEN];
} Student;

//  linear probing
int linear_probe(int k, int m,int i) {
    return (k+i)% m;
}

// quadratic probing
int quadratic_probe(int k, int m, int c1, int c2, int i) {
    return (k + c1 * i + c2 * i * i) % m;
}

// Hàm băm phụ đầu tiên dùng cho phương pháp double hashing
int h1(int k) {
    return k % 13;
}

// Hàm băm phụ thứ hai dùng cho phương pháp double hashing
int h2(int k) {
    return 7 - (k % 7);
}

// Tìm kiếm sinh viên trong bảng băm
int search(Student** arr, int m, int id, char* probing_type, int c1, int c2) {
    int index;
    int i = 0;
    if (strcmp(probing_type, "linear") == 0) {
        while (index == -1 || (arr[index] != NULL && arr[index]->id != id)) {
            index = linear_probe(id, m, i);
            i++;
        }
    } else if (strcmp(probing_type, "quadratic") == 0) {
        index = quadratic_probe(id, m, c1, c2, i);
        while (arr[index] != NULL && arr[index]->id != id) {
            i++;
            index = quadratic_probe(id, m, c1, c2, i);
        }
    } else if (strcmp(probing_type, "double") == 0) {
        index = h1(id);
        while (arr[index] != NULL && arr[index]->id != id) {
            i++;
            index = (h1(id) + i * h2(id)) % m;
        }
    } else {
        printf("Invalid probing type.\n");
        return -1;
    }

    return index;
}

// Hiển thị tên tất cả sinh viên trong bảng băm
void print(Student** arr, int m) {
    for (int i = 0; i < m; i++) {
        if (arr[i] != NULL) {
            printf("%s ", arr[i]->name);
        }
    }
    printf("\n");
}

int main() {
    int m;
    char probing_type[MAX_LEN];
    int c1, c2;

    // Nhập số lượng sinh viên và phương pháp tìm kiếm
    scanf("%d %s", &m, probing_type);

    // Kiểm tra phương pháp tìm kiếm và nhập các tham số nếu cần
    if (strcmp(probing_type, "quadratic") == 0) {
        scanf("%d %d", &c1, &c2);
    } else if (strcmp(probing_type, "linear") != 0 && strcmp(probing_type, "double") != 0) {
        printf("Invalid probing type.\n");
        return 0;
    }

    // Khởi tạo bảng băm
    Student** arr = (Student**)calloc(m, sizeof(Student*));

    for (int i = 0; i < m; i++) {
        arr[i] = NULL;
    }

    // Nhập thông tin sinh viên
    for (int i = 0; i < m; i++) {
        int id;
        char name[MAX_LEN];
        scanf("%d", &id);
        getchar();
        fgets(name, MAX_LEN, stdin);
        name[strcspn(name, "\n")] = '\0';

        int index = search(arr, m, id, probing_type, c1, c2);
        if (index == -1) {
            return 0;
        } else if (arr[index] == NULL) {
            Student* new_student = (Student*)malloc(sizeof(Student));
            new_student->id = id;
            strcpy(new_student->name, name);
            arr[index] = new_student;
        } else {
            printf("Found student name %s id %d at position %d.\n", arr[index]->name, arr[index]->id, index);
        }
    }

    // Thực hiện các lệnh tương tác
    char command[MAX_LEN];
    while (1) {
        scanf("%s", command);
        if (command[0] == 'S' && command[1] == 'e' && command[2] == 'a' && command[3] == 'r' && command[4] == 'c' && command[5] == 'h') {
            int k;
            scanf("%d", &k);
            int index = search(arr, m, k, probing_type, c1, c2);
            if (index == -1) {
                return 0;
            } else if (arr[index] == NULL) {
                printf("Id %d not found.\n", k);
            } else {
                printf("Found student name %s id %d at position %d.\n", arr[index]->name, arr[index]->id, index);
            }
        } else if (command[0] == 'P' && command[1] == 'r' && command[2] == 'i' && command[3] == 'n' && command[4] == 't') {
            print(arr, m);
        } else if (command[0] == 'Q' && command[1] == 'u' && command[2] == 'i' && command[3] == 't') {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < m; i++) {
        if (arr[i] != NULL) {
            free(arr[i]);
        }
    }
    free(arr);

    return 0;
}
