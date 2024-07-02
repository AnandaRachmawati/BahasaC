//Nama File         : gayaSentr
//Deskripsi         : Menghitung Gaya Sentripetal
//Pembuat           : Ananda Rachmawati Purwanto
//Tanggal Pembuatan : 22 Februari 2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus Lokal
    float m,v,r;
    float F;

    // Algoritma
    printf("nilai m: \n");
    scanf("%f", &m);
    printf("nilai v: \n");
    scanf("%f", &v);
    printf("nilai r: \n");
    scanf("%f", &r);

    F = m * ((v*v)/r);
    printf("%.2f", F);

    return 0;
}
