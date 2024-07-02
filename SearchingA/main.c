//Nama  : Ananda Rachmawati Purwanto
//NIM   : 24060123130061
//Lab   : A1


#include <stdio.h>

void SeqSearchSentinel(int T[], int N, int X, int *IX) {
    int i;
    T[N] = X;
    i = 0;
    while (T[i] != X) {
        i++;
    }
    if (i < N) {
        *IX = i + 1;
    } else {
        *IX = 0;
    }
}

int main() {
    int T[6] = {5, 3, 8, 6, 7};
    int N = 5;
    int X = 8;
    int IX;

    SeqSearchSentinel(T, N, X, &IX);

    if (IX != 0) {
        printf("Elemen %d ditemukan pada indeks %d\n", X, IX);
    } else {
        printf("Elemen %d tidak ditemukan dalam array\n", X);
    }

    return 0;
}
