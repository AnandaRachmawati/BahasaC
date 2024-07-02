//Nama  : Ananda Rachmawati Purwanto
//NIM   : 24060123130061
//Lab   : A1

#include <stdio.h>
#define kode 100

void Matakuliah(int TABMK[], int *NMK, int MKX) {
    int pass;
    int temp;
    // Cek kode matkul belum ada
    for (int i = 0; i < *NMK; i++) {
        if (TABMK[i] == MKX) {
            return;
        }
    }
    if (*NMK < kode) {
        TABMK[*NMK] = MKX;
        (*NMK)++;
    }
    for (int pass = 0; pass < *NMK - 1; pass++) {
            for (int i = pass + 1; i < *NMK; i++) {
                if (TABMK[pass] > TABMK[i]) {
                    // Tukar elemen
                    temp = TABMK[pass];
                    TABMK[pass] = TABMK[i];
                    TABMK[i] = temp;
                }
            }
        }
}

int main() {
    int TABMK[kode] = {101, 102, 104, 105, 103};
    int NMK = 5;
    int MKX = 106;

    Matakuliah(TABMK, &NMK, MKX);

    printf("Tabel Mata Kuliah: ");
    for (int i = 0; i < NMK; i++) {
        printf("%d ", TABMK[i]);
    }
    printf("\nJumlah Mata Kuliah: %d\n", NMK);

    return 0;
}
