#include<stdio.h>

void matrixMul(int M1[][5], int M2[][5], int outM[][5], int N){
    int tempM[5][5] = {0, };
    int i, j, k, count, tempCol;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                tempM[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            outM[i][j] = tempM[i][j]%1000; 
        }
    }
}

int main(){
    int N, B;
    int i, j;
    int M[5][5] = {0,};
    int tempM[5][5] = {0,};

    scanf("%d %d", &N, &B);

    // Setting matrix
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &M[i][j]);
            tempM[i][j] = M[i][j];
        }
    }

    // Multiplicate matrix
    for(i=0; i<B-1; i++){
        matrixMul(tempM, M, tempM, N);
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ", tempM[i][j]);
        }
        printf("\n");
    }
}
