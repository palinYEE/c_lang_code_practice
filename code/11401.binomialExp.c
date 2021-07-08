#include<stdio.h>

int divSum(long long int a, long long int n, long long int p){
    if(n == 0){
        printf("p = %lld, a = %lld, n = %lld\n", p, a, n);
        printf("1\n");
        return 1;
    }
    
    long long int b = divSum(a, n/2, p)%p;
    long long int temp = (b * b)%p;

    if(n % 2 == 0){
        printf("p = %lld, a = %lld, n = %lld\n", p, a, n);
        printf("%lld\n",temp);
        return temp; 
    }else{
        printf("p = %lld, a = %lld, n = %lld\n", p, a, n);
        printf("%lld\n",temp);
        return (a * temp)%p;
    }
    
}

int binomial(long long int N, long long int K, long long int p){
    long long int temp = 1;
    long long int i, j;

    for(i = K; i>0; i--){
        temp *= i;
    }

    temp = divSum(temp, p-2, p);
    
    for(i = N; i>N-K; i--){
        temp = (temp*i)%p;
    }


    return temp;
}

int main(){
    long long int N, K;
    long long int b;
    long long int mod = 1000000007;
    scanf("%lld %lld", &N, &K);

    b = binomial(N, K, mod);

    printf("%lld\n", b);

    
    return 0;
}