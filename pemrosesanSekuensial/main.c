#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, j, N;
    int mean, sum;
    int A, B, C, D, E;

    printf("Masukan banyak nilai:", N);
    scanf("%d", &N);

    int T[N];
    for(i=0; i<N; i++){
        printf("Masukan nilai ke- %d:", i+1);
        scanf("%d", &T[i]);
    }

    sum=0;
    for(i=0; i<N; i++){
        sum = sum + T[i];

    }

    mean = sum/N;
    printf("Nilai rata-rata adalah: %d", mean);
    printf("\n");

    A=0;
    B=0;
    C=0;
    D=0;
    E=0;
    printf("Konversi nilai: ");
    for(i=0; i<N; i++){
        if (T[i] >=80 && T[i]<= 100){
            printf("A ");
            A = A + 1;
        }else if (T[i] >= 70 && T[i] <= 80 ){
            printf("B ");
            B = B + 1;
        } else if (T[i] >= 55 && T[i] <= 70 ){
            printf("C ");
            C = C + 1;
        } else if (T[i] >= 40 && T[i] <= 55 ) {
            printf("D ");
            D = D + 1;
        } else{
            printf("E ");
            E = E + 1;
        }
    }

    printf("\n");

    printf("Nilai A: %d \n", A);
    printf("Nilai B: %d \n", B);
    printf("Nilai C: %d \n", C);
    printf("Nilai D: %d \n", D);
    printf("Nilai E: %d \n", E);




    return 0;
}
