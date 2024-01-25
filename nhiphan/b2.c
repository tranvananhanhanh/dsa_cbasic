#include <stdio.h>
#include <stdlib.h>

void find_triplets(int arr[], int n, int Q) {
    int i, left, right;
    int found;
    // Sắp xếp mảng theo thứ tự tăng dần
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Tìm kiếm các bộ ba số thỏa mãn
    for (i = 0; i < n - 2; i++) {
        left = i + 1;
        right = n - 1;

        while (left < right) {
            int current_sum = arr[i] + arr[left] + arr[right];

            if (current_sum == Q) {
                found=1;
                printf("%d %d %d\n", arr[i], arr[left], arr[right]);
                left++;
                right--;
            } else if (current_sum < Q) {
                left++;
            } else {
                right--;
            }
        }
    }
    if(found!=1){
        printf("Not found");
    }
}

int main() {
    int n, Q;

    // Nhập số phần tử trong mảng và số Q 
    scanf("%d %d", &n, &Q);

    // Nhập các phần tử của mảng 
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Tìm kiếm và hiển thị kết quả
    find_triplets(arr, n, Q);

    free(arr);
    return 0;
}
