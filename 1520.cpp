//
//  1520.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 3..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int graph[505][505];
int d[505][505];
bool visited[505][505];
int col, row;

int dp(int r, int c){
    if(r==1 && c==1){
        d[r][c] =1;
        return d[r][c];
    }
    
    if(d[r][c] > 0){
        return d[r][c];
    }
    
    if(!visited[r-1][c] && graph[r][c] != 0 && graph[r][c] < graph[r-1][c]){
        visited[r-1][c] = true;
        d[r][c] += dp(r-1, c);
        visited[r-1][c] = false;
    }
    if(!visited[r][c+1] && graph[r][c] != 0 && graph[r][c] < graph[r][c+1]){
        visited[r][c+1] = true;
        d[r][c] += dp(r, c+1);
        visited[r][c+1] = false;
    }
    if(!visited[r+1][c] && graph[r][c] != 0 && graph[r][c] < graph[r+1][c]){
        visited[r+1][c] = true;
        d[r][c] += dp(r+1, c);
        visited[r+1][c] = false;
    }
    if(!visited[r][c-1] && graph[r][c] != 0 && graph[r][c] < graph[r][c-1]){
        visited[r][c-1] = true;
        d[r][c] += dp(r, c-1);
        visited[r][c-1] = false;
    }
    
    
    return d[r][c];
}

int main(){
    int row, col;
    cin >> row >> col;

    for(int i=0; i<=row+1; i++){
        for(int j=0; j<=col+1; j++){
            graph[i][j] = 0;
            visited[i][j] = false;
        }
    }
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }

    int ans = dp(row,col);
    cout << ans << "\n";
    
    return 0;
}
