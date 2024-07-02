//Nama  : Ananda Rachmawati Purwanto
//NIM   : 24060123130061

#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int T[], int N){
    int i, k;
    int pass;
    int temp;

    for (pass=0; pass<N-1; pass++){
        for(k=N-1; k>=pass+1; k--){
            if(T[k] < T[k-1]){
                temp = T[k];
                T[k] = T[k-1];
                T[k-1] = temp;
            }
        }
    }

}
int main()
{
    int N=5;
    int T[]= {9,1,5,10,2};
    int i;
    printf("Data sesudah:");
    BubbleSort(T,N);
    for (i=0; i<N; i++){
        printf("%d ", T[i]);
    }
    return 0;
}
