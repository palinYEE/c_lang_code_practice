#include<stdio.h>

int main(){
    int i, j, count;
    int n;
    int tempMax = 0, max = 0;
    int arr[100000] = {0, };

    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    
    max = arr[0];
    
    for(i=0; i<n; i++){
        j = n-i;
        count = i;
        while(j--){
            tempMax += *(arr + count);
            if(tempMax > max){
                max = tempMax;
            }
            count ++;
        }
        tempMax = 0;
    }
    
    printf("%d", max);

    return 0;
}