//Nama      : Ananda Rachmawati Purwanto
//NIM       : 24060123130061
//Lab       : A1
//Deskripsi : Mengurut tabel integer [1...N] terurut mengecil dengan maksimum suksesif


#include <stdlib.h>
#include <stdio.h>


void SelectionSort(int T[], int N) {
    int i, j, k, minimal, penampung;
    for (i = 0; i < N - 1; i++) {
        minimal = i;
        for (j = i + 1; j < N; j++) {
            if (T[j] < T[minimal]) {
                minimal = j;
            }
        }
        if (minimal != i) {
            penampung = T[i];
            T[i] = T[minimal];
            T[minimal] = penampung;
        }

        printf("\n(Pass %d) i=%d TMin = T[%d] ---> ", i + 1, i + 1, minimal + 1);
        for (k = 0; k < N; k++) {
            printf("%d ", T[k]);
        }
    }
}

int main() {
    int i, N;
    printf("Banyak data : ");
    scanf("%d", &N);


    int T[N];
    for (i = 0; i < N; i++) {
        printf("data - %d = ", i + 1);
        scanf("%d", &T[i]);
    }


    printf("\n(Awal) = ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }

    SelectionSort(T, N);


    printf("\nData setelah di sorting : ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}
