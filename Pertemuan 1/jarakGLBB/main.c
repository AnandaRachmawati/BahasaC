//Nama File         : jarakGLBB
//Deskripsi         : Menghitung jarak GLBB
//Pembuat           : Ananda Rachmawati Purwanto
//Tanggal Pembuatan : 22 Februari 2024

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus Lokal
    int v0,t,a;
    float S;

    //Algoritma
    printf("Masukan nilai v0: \n");
    scanf("%d", &v0);
    printf("Masukan nilai t : \n");
    scanf("%d", &t);
    printf("Masukan nilai a: \n");
    scanf("%d", &a);

    S = v0*t+0.5*(a*t*t);
    printf("%.2f", S);

    return 0;
}
