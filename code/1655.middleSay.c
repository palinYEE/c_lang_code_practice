#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int *array, int num){
    int i, j, least, temp;
    for(i=0; i<num-1; i++){
        least = i;
        for(j=i+1; j<num; j++){
            if(*(array+j) < *(array + least)){
                least = j;
            }
        }
        SWAP(*(array+i), *(array+least), temp);    
    }
}

int main(){
    int i;
    int N = 0;
    int numList[100000];
    int middle = 0;

    scanf("%d", &N);

    // numList = (int*)malloc(sizeof(int)*N);

    for(i=0; i<N; i++){
        scanf("%d", numList+i);
        if(i == 0){
            printf("%d", *(numList + i));
        }
        else{
            sort(numList, i+1);
            printf("%d", *(numList + i/2));
        }
    }
}