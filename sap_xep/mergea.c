#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int p, int q, int r);

void mergesort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    int a[] = {1, 4, 3, 6};
    int n = sizeof(a) / sizeof(a[0]);

    mergesort(a, 0, n - 1);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

