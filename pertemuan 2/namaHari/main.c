#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus lokal
    int i;

    //Algoritma
    printf("masukan angka \n");
    scanf("%d", &i);

    if (i < 0 || i> 7){
        printf("Masukan nomor hari tidak tepat \n");
    }
    else{
        switch(i){
        case 1:
            printf("Senin \n");
            break;
        case 2:
            printf("Selasa \n");
            break;
        case 3:
            printf("Rabu \n");
            break;
        case 4:
            printf("Kamis \n");
            break;
        case 5:
            printf("Jum'at \n");
            break;
        case 6:
            printf("Sabtu \n");
            break;
        case 7:
            printf("Minggu \n");
            break;
        }
    }
    return 0;
}
