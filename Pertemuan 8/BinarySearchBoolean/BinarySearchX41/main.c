//Nama              : Ananda Rachmawati Purwanto
//NIM               : 24060123130061
//Tanggal Pembuatan : 14 Mei 2024
//Deskripsi         : Mencari harga X = 41 dalam Tabel T dengan Binary Search Boolean
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BinSearch(int T[], int N, int X, bool Found){
    int atas, bawah, tengah;
    int IX;

    atas = 1;
    bawah = N;
    Found = false;

    while (atas <= bawah && !Found){
        tengah = (atas+bawah)/2;
        if(X == T[tengah]){
            Found = true;
            IX = tengah;
        } else if (X < T[tengah]){
            bawah = tengah - 1;

        } else if(X > T[tengah]){
            atas = tengah + 1;
        }
    }

    if (Found == true){
        printf("%d\n",IX + 1);

    }
    else{
        printf("0\n");
    }

}

int main(){
    int T[13]={1, 4, 6, 7, 10, 12, 18, 21, 29, 30, 41, 44, 47};
    //int X = 41;
    int N = 13;
    bool Found;
    int X;

    printf("input nilai X: ");
    scanf("%d",&X);

    BinSearch(T,N,X,Found);

    return 0;
}
