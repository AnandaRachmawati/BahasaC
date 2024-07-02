//Nama File         : volBolaKerct
//Deskripsi         : Menghitung volume bola kerucut
//Pembuat           : Ananda Rachmawati Purwanto
//Tanggal Pembuatan : 27 Februari 2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
   //Kamus Lokal
   float r,Vb,Vk,PHI;
   PHI = 3.1415;


   // Algoritma
   printf("nilai r: \n");
   scanf("%f", &r);

   Vb = (4.0/3.0)*(PHI*r*r*r);
   Vk = 0.5 * Vb;

   printf("Volume Bola: %.2f \n", Vb);
   printf("Volume Kerucut: %.2f \n", Vk);
   return 0;
}
