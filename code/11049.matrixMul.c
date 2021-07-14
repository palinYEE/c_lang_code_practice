#include<stdio.h>

/*
 - 행렬 곱셈 조건 : 앞의 행렬의 열 개수 == 뒤의 행렬의 행 개수
 - 접근 방식
    - Floyd-Warshall Algorithm과 비슷하게...?
    - 출처 : https://justicehui.github.io/ps/2018/10/28/BOJ11049/
*/
void printDp(int dp[][510], int n){
    int i, j;

    printf("==========\n");
    for(i=1; i<=n; i++){
        for(j=1; j<= n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int N;
    int arr[510][2];
    int dp[510][510];
    int i, j, k, l;
    int res;

    scanf("%d", &N);

    for(i=1; i<=N; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // 초기값 셋팅
    for(i=1; i<N; i++){
        dp[i][i+1] = arr[i][0] * arr[i][1] * arr[i+1][1];
    }

    // printDp(dp, N);

    //플루이드 와샬 알고리즘 활용
    for(j=2; j<=N; j++){
        for(i=1; i<=N-j; i++){
            k = i + j;
            for(l=i; l<k; l++){
                res = dp[i][l] + dp[l+1][k] + arr[i][0] * arr[l][1] * arr[k][1];
                if(!dp[i][k] || dp[i][k] > res) dp[i][k] = res;
            }
            // printDp(dp, N);
        }
    }

    printf("%d", dp[1][N]);

    return 0;
}