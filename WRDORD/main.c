#include <stdio.h>
#include <stdlib.h>

void InsertionSORT(int T[], int N) {
    int i, pass, temp;

    for (pass = 1; pass < N; pass++) {
        temp = T[pass];
        i = pass - 1;
        while (i >= 0 && temp < T[i]) {
            T[i + 1] = T[i];
            i--;
        }
        T[i + 1] = temp;
    }
}

int main() {
    int i, j, N;

    scanf("%d", &N);
    int arr[N];
    int T[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &T[i]);
    }

    InsertionSORT(T, N);

    int A[N];
    j = 0;
    for (i = 2; i < N; i += 2) {
        A[j] = T[i];
        j++;
    }

    j--;
    for (i = 2; i < N; i += 2) {
        T[i] = A[j];
        j--;
    }

    for (i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", T[i]);
    }

    return 0;
}
