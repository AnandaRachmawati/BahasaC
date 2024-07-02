//Nama  : Ananda Rachmawati Purwanto
//NIM   : 24060123130061

#include <stdlib.h>
#include <stdio.h>


int maxArr(int T[], int N) {
    int max = T[0];
    for (int i = 1; i < N; i++) {
        if (T[i] > max) {
            max = T[i];
        }
    }
    return max;
}


void CountSort(int T[], int N) {
    int PanjangArrayCount = maxArr(T, N) + 1;
    int Count[PanjangArrayCount];
    int sortedArray[N];


    for (int i = 0; i < PanjangArrayCount; i++) {
        Count[i] = 0;
    }


    for (int i = 0; i < N; i++) {
        Count[T[i]]++;
    }


    for (int i = 0; i < PanjangArrayCount; i++) {
        printf("%d ada %d buah\n", i, Count[i]);
    }


    int index = 0;
    for (int i = 0; i < PanjangArrayCount; i++) {
        for (int j = 0; j < Count[i]; j++) {
            sortedArray[index] = i;
            index++;
        }
    }


    printf("\nData setelah di sorting : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");
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
    printf("\n");


    CountSort(T, N);

    return 0;
}
