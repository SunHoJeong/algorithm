//
//  1261.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int graph[105][105];
int d[105][105];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int col, row;

void dp(int r, int c, int cnt){
    if(graph[r][c] == 1)
        cnt ++;
    
    d[r][c] = cnt;
    if(r==row && c==col){
        return;
    }
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(0 < rr && rr <= row && 0 < cc && cc <= col
           && d[rr][cc] > d[r][c]){
            dp(rr, cc, d[r][c]);
        }
    }
}

int main(){
    cin >> col >> row;
    
    for(int i=1; i<=row; i++){
        string str;
        cin >> str;
        for(int j=0; j<col; j++){
            if(str[j] == '0'){
                graph[i][j+1] = 0; //뚫림
            }
            else if(str[j] == '1'){
                graph[i][j+1] = 1; //막힘
            }
        }
    }
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            d[i][j] = 1000000000;
        }
    
    }
    
    dp(1,1,0);
    
    cout << d[row][col] << "\n";
    
    return 0;
}
