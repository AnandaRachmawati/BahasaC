// Nama : Ananda Rachmawati Purwanto
// Nim  : 24060123130061
// Lab  : A1

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus Lokal
    int iA,iB;
    float operasi;

    char o;

    //Algoritma
    printf("============================Selamat Datang di kallSS======================= \n");
    printf("\n");
    printf("|===============Pilihan Operasi==============|==========Keluaran===========|\n");
    printf("|--------------------------------------------------------------------------|\n");
    printf("|                     a                      |             A + B           | \n");
    printf("|                     b                      |             A - B           |\n");
    printf("|                     c                      |             A * B           | \n");
    printf("|                     d                      |             A / B           |\n");
    printf("|                     e                      |             A div B         |\n");
    printf("|                     f                      |             A mod B         |\n");
    printf("");


    printf("Masukan angka 1: ");
    scanf("%d", &iA);
    printf("Masukan angka 2: ");
    scanf("%d", &iB);
    printf("Masukan pilihan operasi : ");
    scanf(" %c", &o );

    if (o != 'a' && o != 'b' && o != 'c' && o != 'd' && o != 'e' && o != 'f' ){
        printf("Bukan pilihan menu yang benar");
    }
    else{
        switch(o){
        case 'a':
            operasi = iA +iB;
            printf("%d", (int)operasi);
            break;

        case 'b':
            operasi = iA - iB;
            printf("%d", (int)operasi);
            break;

        case 'c':
            operasi = iA *iB;
            printf("%d", (int)operasi);
            break;


        case 'd':
            if (iB != 0) {
                operasi = iA / iB;
                printf("%.2f", operasi);
            } else {
                printf("Tidak Terdefinisi! \n");
            }
            break;


        case 'e':
            operasi = (int)(iA/iB);
            printf("%d", (int)operasi);
            break;


        case 'f':
            operasi = iA % iB;
            printf("%d", (int)operasi);
            break;


        }

    }

    return 0;
}
