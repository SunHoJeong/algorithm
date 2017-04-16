//
//  1520_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 16..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int row, col;
int graph[501][501];
int d[501][501];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}};

int dp(int r, int c){
    if(r==0 && c==0){
        return 1;
    }
    
    if(d[r][c] != -1){
        return d[r][c];
    }
    
    d[r][c] = 0;
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr<0 || rr>=row || cc<0 || cc>=col)
            continue;
        
        if(graph[r][c] < graph[rr][cc]){
            d[r][c] += dp(rr,cc);
        }
    }
    
    return d[r][c];
}

int main(){
    scanf("%d%d", &row,&col);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            d[i][j] = -1;
        }
    }
    
    printf("%d\n",dp(row-1,col-1));
    
    return 0;
}
