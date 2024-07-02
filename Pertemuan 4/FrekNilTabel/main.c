//Nama File         : FrekNilTabel
//Deskripsi         : menampilkan nilai elemen tabel T yang frekuensi kemunculannya lebih dari satu kali
//Pembuat           : Ananda Rachmawati Purwanto
//Tanggal Pembuatan : 14 Maret 2024




#include<stdio.h>
#include<stdlib.h>

int main() {
    //Kamus

    int i, j, N, total;

    printf("Masukan jumlah elemen tabel: ");
    scanf("%d",&N);

    int T[N];


    for (i = 0; i < N; i++){
        printf("Masukan inputan ke %d: ", i+1);
        scanf("%d", &T[i]);
    }

    for (j = 0; j < N ; j++){
        total = 0;
        for(i = j + 1; i < N; i++){
            if (T[i]== T[j]){
                total++;
            }
        }
        if (total == 1){
            printf("%d ", T[j]);
        }
    }


}






