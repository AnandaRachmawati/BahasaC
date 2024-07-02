//Nama      : Ananda Rachmawati Purwanto
//NIM       : 24060123130061
//Lab       : A1
//Tanggal   : 30 Mei 2024
//Deskripsi : Mengurutkan tabel [1..N] dengan insertion sort

#include <stdio.h>
#include <stdlib.h>

void InsertionSORT(int T[], int N){
    int i;
    int pass;
    int temp;

    for(pass=1; pass<N; pass++){
        temp = T[pass];
        i = pass - 1;
        while(temp<T[i] && i>1){
            T[i+1] = T[i];
            i--;
        }
        if (temp >= T[i]){
            T[i+1] = temp;
        }
        else if (temp < T[i]){
            T[i+1] = T[i];
            T[i] = temp;

        }

    }
}

int main()
{
    // Kamus Lokal
    int N = 5;
    int T[]= {9,1,5,10,2};
    int i;

    //Algoritma
    printf("Data sebelum: 9,1,5,10,2");
    printf("\n");
    printf("Data sesudah:");
    InsertionSORT(T,N);
    for(i=0; i<N; i++){
        printf("%d ", T[i]);
    }
    return 0;
}
