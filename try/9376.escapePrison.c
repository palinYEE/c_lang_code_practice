#include<stdio.h>

/*
 $ : 죄수
 . : 빈 공간
 * : 벽
 # : 문
*/
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

        printf("\n ====================\n");
        printf("%d-th testCase matrix \n", i);
        // Check matrix
        for(j=0; j<h; j++){
            for(k=0; k<w; k++){
                printf("%c ", prison[j][k]);
            }
            printf("\n");
        }
        
        
    }

    
    return 0;
}