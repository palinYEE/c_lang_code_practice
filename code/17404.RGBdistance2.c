#include<stdio.h>

int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

int main(){
    int N;
    int arr[1001][3];
    int d[1001][3];

    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int ans = 1000 * 1000 + 1; // 가장 최대값

    for(int k=0; k<=2; k++){     // 첫 번째 집의 색깔
        for(int i=0; i<3; i++){
            if(i == k){
                d[1][i] = arr[1][i];    // 현재 색깔을 첫번째 집 색깔로 고정
            }else{
                d[1][i] = 1000 * 1000 + 1;
            }
        }
        for(int i=2; i<=N; i++){
            d[i][0] = min(d[i-1][1], d[i-1][2]) + arr[i][0];
            d[i][1] = min(d[i-1][0], d[i-1][2]) + arr[i][1];
            d[i][2] = min(d[i-1][0], d[i-1][1]) + arr[i][2];
        }

        for(int i=0; i<3; i++){
            if(i == k) continue;
            ans = min(ans, d[N][i]);
        }
    }

    printf("%d", ans);
    return 0;
}