#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Kamus Lokal
    int a,b,c;

    //Algoritma

    printf("Masukan sisi 1: \n");
    scanf("%d", &a);
    printf("Masukan sisi 2: \n");
    scanf("%d", &b);
    printf("Masukan sisi 3: \n");
    scanf("%d", &c);

    if (a <=0 || b<=0 || c<=0) {
        printf("Terdapat sisi yang bukan segitiga. \n");
    }
    else{
        if (a != b && b!=c && a!=c){
        printf("Segitiga Sembarang \n");
    }
        else if((a == b) || (a == c) || (b== c)){
            printf("Segitiga sama kaki \n");
        }
        else if (a == b && a==c){
            printf("Segitiga sama sisi \n");
        }
    }




    return 0;
}
