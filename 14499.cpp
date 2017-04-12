//
//  14499.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
int graph[21][21];
int dice[6];
/*
    0
1   2   3
    4
    5
 */
int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}}; //동 서 북 남

void east(){
    int temp1 = dice[1];
    int temp2 = dice[2];
    int temp3 = dice[3];
    int temp5 = dice[5];
    dice[1] = temp5;
    dice[2] = temp1;
    dice[3] = temp2;
    dice[5] = temp3;
}

void west(){
    int temp1 = dice[1];
    int temp2 = dice[2];
    int temp3 = dice[3];
    int temp5 = dice[5];
    dice[1] = temp2;
    dice[2] = temp3;
    dice[3] = temp5;
    dice[5] = temp1;
    
}

void north(){
    int temp0 = dice[0];
    int temp2 = dice[2];
    int temp4 = dice[4];
    int temp5 = dice[5];
    dice[0] = temp2;
    dice[2] = temp4;
    dice[4] = temp5;
    dice[5] = temp0;
}

void south(){
    int temp0 = dice[0];
    int temp2 = dice[2];
    int temp4 = dice[4];
    int temp5 = dice[5];
    dice[0] = temp5;
    dice[2] = temp0;
    dice[4] = temp2;
    dice[5] = temp4;
}

int main(){
    int row, col;
    int st_r, st_c;
    int cmdNum;
    
    scanf("%d%d%d%d%d", &row, &col, &st_r, &st_c, &cmdNum);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    int r = st_r;
    int c = st_c;
    
    for(int i=0; i<6; i++){//init dice
        dice[i] = 0;
    }
    
    for(int i=0; i<cmdNum; i++){
        int cmd;
        scanf("%d", &cmd);
        
        int rr = r+dir[cmd-1][0];
        int cc = c+dir[cmd-1][1];
        if(rr < 0 || rr >= row ||cc < 0 || cc >=col )
            continue;
        
        switch (cmd) {
            case 1:
                east();
                break;
            case 2:
                west();
                break;
            case 3:
                north();
                break;
            case 4:
                south();
                break;
        }
        
        if(graph[rr][cc] == 0){
            graph[rr][cc] = dice[5];
        }
        else{
            dice[5] = graph[rr][cc];
            graph[rr][cc] = 0;
        }
        printf("%d\n", dice[2]);
        
        r = rr;
        c = cc;
        
    }
    
    return 0;
}
