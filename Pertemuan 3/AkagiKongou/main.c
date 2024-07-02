//Nama          : Ananda Rachmawati Purwanto
//NIM           : 24060123130061
//Lab           : A1
//Deskripsi     : menentukan alur perubahanangka A,B,C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus
    int A,B,C;

    //Algoritma
    printf("Angka yang dipilih oleh Akagi: ");
    scanf("%d",&A);

    printf("Angka yang dipilih oleh Kongou: ");
    scanf("%d",&B);

    for (int i = 0; B > 0; i++){
        printf("babak %d\n", i);
        C = A - B;
        printf("C = %d\n",C);
        A = B;
        printf("A = %d\n",A);
        B = C;
        printf("B = %d\n",B);
    }
    if (B == 0){
        printf("Pemenangnya Kongou");

    }
    else{
        printf("Pemenangnya Akagi");
    }
    return 0;
}
