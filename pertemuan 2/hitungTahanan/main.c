#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus Lokal
    int a,b,c,s;

    //Algoritma
    printf("Tahanan 1: \n");
    scanf("%d", &a);
    printf("Tahanan 2: \n");
    scanf("%d", &b);
    printf("Tahanan 3: \n");
    scanf("%d", &c);

    if ((a<0|| b<0 || c<0)||(a<0 && b<0 && c<0)){
        printf("Masukan tahanan tidak boleh negatif");
    }
    else{
        s = a + b + c;
        printf("Jumlah Tahanan: %d", s);
    }
    return 0;
}
