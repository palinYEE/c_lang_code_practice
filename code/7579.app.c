#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    int N, M;
    int arr[101][2] = {0, }; // 0 : 활성화, 1: 비활성화
    int dp[101][10000] = {0, };
    int min;
    int costSum = 0;

    scanf("%d %d", &N, &M); 
    for(int i=0; i<2; i++){
        for(int j=1; j<= N; j++){
            scanf("%d", &arr[j][i]);
        }
    }
    for(int i=1; i<=N; i++){
        costSum += arr[i][1];
    }
    
    for(int i=1; i<= N; i++){
        for(int j=0; j<=costSum; j++){
            if(j-arr[i][1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i][1]] + arr[i][0]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    for(int i=0; i<=costSum; i++){
        if(dp[N][i] >= M){
            printf("%d", i);
            break;
        }
    }


    return 0;
}