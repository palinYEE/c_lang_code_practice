#include<stdio.h>

// 피보나치 수열 함수
// 현재 코드는 시간이 매우 오래 걸림
// 탐욕 알고리즘을 이용한 방법을 생각해야 함.
long long int fibbo(long long int n){
    if(n<1)
    {
        return 0;
    }
    if ((n == 1) || (n == 2))
    {
        return 1;
    }
    return fibbo(n - 2)%1000000 + fibbo(n - 1)%1000000;
}

int main(){
    long long int n;
    long long int output;

    scanf("%lld", &n);

    printf("[*] 입력 변수 : %lld\n", n);
    output = fibbo(n);
    printf("[*] 결과 값 : %lld\n", output%1000000);
    return 0;
}