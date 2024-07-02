#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus Lokal
    int i;

    // Algoritma
    printf(" Masukan Angka \n");
    scanf("%d", &i);

    if (i == 0){
        printf("Nol \n");
    }
    else{
        if (i > 0){
            printf("Bulat Positif");
        }
        else{
            printf("Bulat Negatif");
        }
    }

    return 0;
}
