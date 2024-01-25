#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int n;
int permutation[MAX];
bool visited[MAX];

// Kiểm tra xem hai số có cùng chẵn hoặc cùng lẻ đứng cạnh nhau hay không
bool check(int a, int b) {
    return (a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1);
}

// in kq
void ps() {
    for (int i = 0; i < n; i++) {
        printf("%d", permutation[i]);
    }
    printf("\n");
}

void gen(int pos) {
    if (pos == n) {
        ps();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (pos == 0 || !check(permutation[pos - 1], i)) {
                visited[i] = true;
                permutation[pos] = i;
                gen(pos + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    if (n <= 1) {
        printf("Input error\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    gen(0);

    return 0;
}