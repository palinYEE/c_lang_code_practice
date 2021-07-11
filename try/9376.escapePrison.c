#include<stdio.h>
const int MAX = 102;
const int INF = 987654321;

typedef struct 
{
    int y,x;
}Dir;

Dir moveDir[4] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};


void printMatrix(char matrix[][100],int h, int w, int i){
    int j, k;
    printf("\n ====================\n");
    printf("%d-th testCase matrix \n", i);
    // Check matrix
    for(j=0; j<h; j++){
        for(k=0; k<w; k++){
            printf("%c ", matrix[j][k]);
        }
        printf("\n");
    }
}
int main(){
    int testCase, h, w;
    char prison[100][100] = {0,};
    int i, j, k;

    scanf("%d", &testCase);

    for(i=0; i<testCase; i++){
        scanf("%d %d", &h, &w);
        for(j=0; j<h; j++){
            scanf("%s", prison[j]);
        }
        
        // prison check complete.
        // printMatrix(prison, h, w, i);
    }

    
    return 0;
}