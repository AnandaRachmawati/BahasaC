#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main() {
    int n, k, i, j;
    int count;
    scanf("%d", &n);
    scanf("%d", &k);

    int T[n];
    for (i=0; i<n; i++){
        scanf("%d", &T[i]);
    }

    int light[n];
    for (i=0; i<n; i++){
        light[i]=0;
    }
    for (i=0; i<n; i++){
        if (T[i] == 1){
            for(j=i-k; j<=i+k;j++){
                if (j >=0 && j<n){
                    light[j] = 1;
                }
              }
            }
        }

    count=0;
    for (i=0; i<n; i++){
        if (light[i]==0){
            count++;
        }
    }
    printf("%d",count);


    return 0;
}
