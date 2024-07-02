//Nama File         : luaskellLayang
//Deskripsi         : Menghitung Keliling dan Luas Layang-layang
//Pembuat           : Ananda Rachmawati Purwanto
//Tanggal Pembuatan : 27 Februari 2024


#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus Lokal
    float s1,s2,d1,d2;
    float Luas,Kell;

    //Algoritma

    printf("Masukan nilai s1(Sisi 1): \n");
    scanf("%f", &s1);

    printf("Masukan nilai s2(Sisi 2): \n");
    scanf("%f", &s2);

    printf("Masukan nilai diagonal 1: \n");
    scanf("%f", &d1);

    printf("Masukan nilai diagonal 2 : \n");
    scanf("%f", &d2);

    Luas = 0.5 * d1 * d2;

    Kell = 2 * (s1+s2);

    printf("Hasil Luas Layang-layang : %.2f", Luas);
    printf("Hasil Keliling layang-layang : %.2f", Kell);

    return 0;
}
