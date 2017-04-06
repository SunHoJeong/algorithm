//
//  1987_2_dfs.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

char graph[21][21];
bool visited[21][21];
bool alpha[30];
int dir[4][2] = {{-1,0},{0,1}, {1,0}, {0,-1} };
int ans = -1;
int row,col;


void dfs(int r, int c, int depth){
    if(depth > ans){
        ans = depth;
    }
    //cout << r << "," << c << "\n";
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        if(rr<1 || rr >row || cc<1 || cc > col)
            continue;
        
        if(!visited[rr][cc] && !alpha[graph[rr][cc]-'A']){
            visited[rr][cc] = true;
            alpha[graph[rr][cc]-'A'] = true;
            dfs(rr,cc,depth+1);
            visited[rr][cc] = false;
            alpha[graph[rr][cc]-'A'] = false;
        }
    }
}

int main(){
    cin >> row >> col;
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }
    visited[1][1] = true;
    alpha[graph[1][1]-'A'] = true;
    dfs(1,1,1);
    cout << ans << "\n";
    
    return 0;
}
