//Nama File         : jarakPBola
//Deskripsi         : Menghitung jarak Bola
//Pembuat           : Ananda Rachmawati Purwanto
//Tanggal Pembuatan : 27 Februari 2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus Lokal
    float v0, t,g;
    float y;

    g = 9.80665;

    // Algoritma
    printf("Masukan nilai v0(Kecepatan awal): \n");
    scanf("%f", &v0);
    printf("Masukan nilai t(waktu) \n" );
    scanf("%f", &t);


    y = v0*t - 0.5*(g*t*t);

    printf("Jarak bola adalah %.2f", y);



    return 0;
}
