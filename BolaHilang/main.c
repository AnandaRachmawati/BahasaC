#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int i,j;
    int a, b;
    bool found;

    int TA[a];
    for (i=0; i<a; i++){
        scanf("%d", &TA[i]);
    }

    int TB[b];
    for (i=0; i<b; i++){
        scanf("%d", &TB[i]);
    }
    if(b==0){
        for (i=0; i<a; i++){
            printf("%d", TA[i]);
        }
    } else {
        for (i=0; i<a; i++){
            found= false;
            for (j=0; i<b; j++);
            if (TA[i]==TB[j]){
                TB[j]=0;
                found= true;
            }
        }
        if (!found){
            printf("%d",TA[i]);
        }


    }
    return 0;
}
