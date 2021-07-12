#include<stdio.h>

// timeout
void firstTry(int *arr, int n){
    int i, j, count;
    int tempMax = 0, max = 0;
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
    
    printf("[*] First try : %d\n", max);
}

// timeout
void secTry(int *arr, int n){
    int i, j, count;
    int tempMax = 0, max = 0;
    max = arr[0];

    for(i=0; i<n/2; i++){
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
        
        j = n-i;
        count = i + n/2;
        while(j--){
            tempMax += *(arr + count);
            if(tempMax > max){
                max = tempMax;
            }
            count ++;
        }
        tempMax = 0;
    }
    
    printf("[*] Second try : %d\n", max);
}

// Correct!!!!
void thridTry(int *arr, int n){
    int i, j, count;
    int tempMax = 0, max = 0;
    max = arr[0];
    tempMax = arr[0];

    for(i=1; i<n; i++){
        tempMax += *(arr + i);
        if(tempMax < *(arr + i)){
            tempMax = *(arr + i);
        }
        if(tempMax > max){
            max = tempMax;
        }
    }
    
    printf("[*] Thrid try : %d\n", max);
}

int main(){
    int i, j, count;
    int n;
    int tempMax = 0, max = 0;
    int arr[100000] = {0, };

    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    
    firstTry(arr, n);
    secTry(arr, n);
    thridTry(arr, n);
    return 0;
}