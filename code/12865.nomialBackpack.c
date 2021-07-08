#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, n1, k1;
    int *W, *N;
    int sumWeight = 0, maxVal = 0, temp =0;

    scanf("%d %d", &n1, &k1);

    W = (int*)malloc(sizeof(int)*n1);
    N = (int*)malloc(sizeof(int)*k1);

    for(i=0; i<n1; i++){
        scanf("%d %d", W+i, N+i);
    }

    for(i=0; i<n1-1; i++){
        sumWeight += *(W+i);
        temp += *(N+i);
        for(j=i+1; j<n1; j++){
            if((sumWeight + *(W+j)) <= k1){
                sumWeight += *(W+j);
                temp += *(N+j);
            }
        }
        if(maxVal < temp){
            maxVal = temp;
        }
        temp = 0;
        sumWeight = 0;
    }

    printf("%d", maxVal);

    free(W);
    free(N);
}