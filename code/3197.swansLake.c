#include<stdio.h>
#include<stdlib.h>

int findIndex(char *words, int col){
    int i;
    
    for(i=0; i<col; i++){
        if(*(words+i) == 'L'){
            return i;
        }    
    }
    return col+100;
}

void dayByDayRoute(char array[][1500], int row, int col){
    int i, j;
    char temp[1500][1500];
    // temp 배열 저장 
    for(i=0; i<row; i++){
        for(j=0;j<col; j++){
            temp[i][j] = array[i][j];
        }
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(array[i][j] == '.'){
                if(i-1 >= 0){
                    if(array[i-1][j] == 'X'){
                        temp[i-1][j] = '.';
                    }
                }
                if(j-1 >= 0){
                    if(array[i][j-1] == 'X'){
                        temp[i][j-1] = '.';
                    }
                }   
                if(i+1 < row){
                    if(array[i+1][j] == 'X'){
                        temp[i+1][j] = '.';
                    }
                }
                if(j+1 < col){
                    if(array[i][j+1] == 'X'){
                        temp[i][j+1] = '.';
                    }
                }  
            }
        }
    }

    // temp to ice 
    for(i=0; i<row; i++){
        for(j=0;j<col; j++){
            array[i][j] = temp[i][j];
        }
    }

}

// 백조끼리 만나는 루트 찾는 함수.
// 무한루프 생성됨 이를 해결해야 됨.
// 7,1 -> 8,1 -> 7,1 -> ...
// 이걸 어떻게 해결하면 좋누...
int checkRoutine(char array[][1500], int row, int col, int pointL[], int depth){
    int startPoint[2] = {0, };
    int result = 0;
    int i, j;

    printf("=============\n");
    printf("%d %d\n", pointL[0], pointL[1]);

    if(array[pointL[0]][pointL[1]] == 'L' && depth > 0){
        printf("[*] meet swans!!");
        return 1;
    }

    else{
        if(pointL[0]-1 >= 0){
            startPoint[0] = pointL[0] - 1;
            startPoint[1] = pointL[1];
            if(array[startPoint[0]][startPoint[1]] != 'X')
            {
                result = checkRoutine(array, row, col, startPoint, depth + 1);
            }
        }
        if(pointL[0]+1 <= row){
            startPoint[0] = pointL[0] + 1;
            startPoint[1] = pointL[1];
            if(array[startPoint[0]][startPoint[1]] != 'X'){
                result = checkRoutine(array, row, col, startPoint, depth + 1);
            }
        }
        if(pointL[1]-1 >= 0){
            startPoint[0] = pointL[0];
            startPoint[1] = pointL[1] - 1;
            if(array[startPoint[0]][startPoint[1]] != 'X'){
                result = checkRoutine(array, row, col, startPoint, depth + 1);
            }
        }
        if(pointL[1]+1 <= col){
            startPoint[0] = pointL[0];
            startPoint[1] = pointL[1] + 1;
            if(array[startPoint[0]][startPoint[1]] != 'X'){
                result = checkRoutine(array, row, col, startPoint, depth + 1);
            }
        }
    }
    return 0;
}

int main(){
    int i, j;
    int row, col;
    int meetBool;
    int pointL[2] = {0, };
    char ice[1500][1500];

    scanf("%d %d", &row, &col); 

    // 문제 입력
    for(i=0; i<row; i++){
        scanf("%s", ice[i]);
        pointL[1] = findIndex(ice[i], col);
        if(pointL[1] <= col){
            pointL[0] = i;
        }
    }
    dayByDayRoute(ice, row, col);
    meetBool = checkRoutine(ice, row, col, pointL, 0);
    printf("[*] Check ice array \n");
    for(i=0; i<row; i++){
        printf("%s \n", ice[i]);
    }
    return 0;
}