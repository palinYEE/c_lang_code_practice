#include<stdio.h>

int fastfibo(long long int n){
    long long int temp1 = 0;
    long long int temp2 = 1;
    long long int temp = 0;

    long long int i;
    for(i=0; i<n; i++){
        
        temp1 = (temp1 + temp2)%1000000;
        
        // swap
        temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    }
    // printf("%d\n", temp1);

    return temp1;
}

int main(){
    long long int n;
    long long int output;

    scanf("%lld", &n);

    output = fastfibo(n);

    printf("%lld\n", output%1000000);
    return 0;
}